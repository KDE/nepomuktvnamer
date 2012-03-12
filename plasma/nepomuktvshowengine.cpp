/*
   This file is part of the Nepomuk KDE project.
   Copyright (C) 2012 Sebastian Trueg <trueg@kde.org>
   
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) version 3, or any
   later version accepted by the membership of KDE e.V. (or its
   successor approved by the membership of KDE e.V.), which shall
   act as a proxy defined in Section 6 of version 3 of the license.
   
   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "nepomuktvshowengine.h"
#include "nepomuktvshowservice.h"

#include <Soprano/Model>
#include <Soprano/QueryResultIterator>
#include <Soprano/Node>

#include <Nepomuk/Resource>
#include <Nepomuk/ResourceManager>
#include <nepomuk/resourcewatcher.h>

#include <Nepomuk/Vocabulary/NMM>

#include <tvdb/client.h>
#include <tvdb/series.h>
#include <tvdb/season.h>
#include <tvdb/episode.h>

#include <QDate>
#include <QTime>
#include <QVariant>
#include <QTimer>

#include <KLocale>

using namespace Nepomuk::Vocabulary;


NepomukTVShowEngine::NepomukTVShowEngine(QObject *parent, const QVariantList& args)
    :  Plasma::DataEngine(parent, args)
{
}

void NepomukTVShowEngine::init()
{
    // set up the watcher for newly created TV Shows
    Nepomuk::ResourceWatcher* watcher = new Nepomuk::ResourceWatcher(this);
    watcher->addType(NMM::TVShow());
    connect(watcher, SIGNAL(resourceCreated(Nepomuk::Resource,QList<QUrl>)),
            this, SLOT(slotTVShowResourceCreated(Nepomuk::Resource)));
    connect(watcher, SIGNAL(resourceTypeAdded(Nepomuk::Resource,Nepomuk::Types::Class)),
            this, SLOT(slotTVShowResourceCreated(Nepomuk::Resource)));
    watcher->start();

    // set up the timer which will update the release grouping every 24 hours
    m_releaseGroupingTimer = new QTimer(this);
    connect(m_releaseGroupingTimer, SIGNAL(timeout()), this, SLOT(updateAllReleaseGroupings()));
    m_releaseGroupingTimer->setSingleShot(true);
    m_releaseGroupingTimer->start(QTime::currentTime().secsTo(QTime(23, 59, 59, 999))*1000);

    // update sources after a Nepomuk restart
    connect(Nepomuk::ResourceManager::instance(), SIGNAL(nepomukSystemStarted()),
            this, SLOT(updateSources()));
}

QStringList NepomukTVShowEngine::sources() const
{
    // fetch all available series
    QStringList titles;
    Soprano::QueryResultIterator it
            = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select distinct ?t where { ?r a nmm:TVSeries ; nie:title ?t . }"),
                                                                              Soprano::Query::QueryLanguageSparql);
    while(it.next()) {
        titles << it["t"].toString();
    }
    return titles;
}

Plasma::Service *NepomukTVShowEngine::serviceForSource(const QString &source)
{
    return new NepomukTVShowService(this, source);
}

bool NepomukTVShowEngine::sourceRequestEvent(const QString &name)
{
    Q_ASSERT(!containerDict().contains(name));

    // insert a dummy data block
    setData(name, DataEngine::Data());

    return updateSourceEvent(name);
}

bool NepomukTVShowEngine::updateSourceEvent(const QString &name)
{
    // fetch the information
    Tvdb::Client* client = new Tvdb::Client( this );
    client->setFlags(Tvdb::Client::FetchFullDetails);
    connect( client, SIGNAL( finished( Tvdb::Series ) ), SLOT( slotFinishedSeriesLookup( Tvdb::Series ) ) );
    connect( client, SIGNAL( multipleResultsFound( QList<Tvdb::Series> ) ), SLOT( slotMultipleSeriesResultsFound( QList<Tvdb::Series> ) ) );
    client->getSeriesByName(name);
    return true;
}

void NepomukTVShowEngine::slotFinishedSeriesLookup(const Tvdb::Series &series)
{
    if(series.isValid()) {
        m_seriesCache.insert(series.name(), series);
        updateSeries(series.name());
    }
    else {
        kDebug() << "Failed to lookup series on theTvdb.";
    }

    sender()->deleteLater();
}

void NepomukTVShowEngine::slotMultipleSeriesResultsFound(const QList<Tvdb::Series> &series)
{
    // we do it the simple way for now. TODO: store the tvdb id in Nepomuk
    m_seriesCache.insert(series.first().name(), series.first());
    updateSeries(series.first().name());
    sender()->deleteLater();
}

void NepomukTVShowEngine::slotTVShowResourceCreated(const Nepomuk::Resource &res)
{
    // check the series to see if we have a to update the next episode
    Soprano::QueryResultIterator it
            = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select ?t where { "
                                                                                                  "%1 nmm:series [ a nmm:TVSeries ; nie:title ?t ] } LIMIT 1")
                                                                              .arg(Soprano::Node::resourceToN3(res.resourceUri())),
                                                                              Soprano::Query::QueryLanguageSparql);
    if(it.next()) {
        const QString name = it["t"].toString();
        if(m_seriesCache.contains(name)) {
            updateSeries(name);
        }
        else {
            updateSourceEvent(name);
        }
    }
}

void NepomukTVShowEngine::updateAllReleaseGroupings()
{
    foreach(const QString& name, m_seriesCache.keys()) {
        updateSeriesReleaseGrouping(name);
    }

    // update again at the end of the day
    m_releaseGroupingTimer->start(QTime::currentTime().secsTo(QTime(23, 59, 59, 999))*1000);
}

void NepomukTVShowEngine::updateSources()
{
    // we simply tell the clients about all sources in case plasma was started before Nepomuk
    foreach(const QString& s, sources()) {
        if(!m_seriesCache.contains(s)) {
            emit sourceAdded(s);
        }
    }
}

void NepomukTVShowEngine::updateSeries(const QString &name)
{
    Tvdb::Series series = m_seriesCache[name];

    // get the latest episode we have
    Soprano::QueryResultIterator it
            = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select max(1000*?sn + ?en) as ?last where { "
                                                                                                  "?e nmm:series [ a nmm:TVSeries ; nie:title %1 ] ; "
                                                                                                  "nmm:episodeNumber ?en ; "
                                                                                                  "nmm:season ?sn . }")
                                                                              .arg(Soprano::Node::literalToN3(series.name())),
                                                                              Soprano::Query::QueryLanguageSparql);
    if(it.next()) {
        const int s = it["last"].literal().toInt() / 1000;
        const int e = it["last"].literal().toInt() % 1000;

        // determine the next available episode
        Tvdb::Episode episode;
        if(series.hasSeason(s) && series[s].hasEpisode(e+1)) {
            episode = series[s][e+1];
        }
        else if(series.hasSeason(s+1) && series[s+1].hasEpisode(1)) {
            episode = series[s+1][1];
        }

        if(episode.isValid()) {
            setData(series.name(), QLatin1String("releaseDate"), episode.firstAired());
            setData(series.name(), QLatin1String("title"), episode.name());
            setData(series.name(), QLatin1String("seasonNumber"), episode.season().seasonNumber());
            setData(series.name(), QLatin1String("episodeNumber"), episode.episodeNumber());
        }
        else {
            setData(series.name(), QLatin1String("releaseDate"), QString());
            removeData(series.name(), QLatin1String("title"));
            removeData(series.name(), QLatin1String("seasonNumber"));
            removeData(series.name(), QLatin1String("episodeNumber"));
        }
        updateSeriesReleaseGrouping(name);

        // get a depiction in case we do not already have one. We prefere the wide banners
        if(!query(name).contains(i18n("Depiction"))) {
            it = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select ?u where { "
                                                                                                     "?r a nmm:TVSeries ; "
                                                                                                     "nie:title %1 ; "
                                                                                                     "nfo:depiction [ "
                                                                                                     "nie:url ?u ; "
                                                                                                     "nfo:height ?h ; "
                                                                                                     "nfo:width ?w "
                                                                                                     "] } "
                                                                                                     "ORDER BY DESC(?w/?h) LIMIT 1")
                                                                                 .arg(Soprano::Node::literalToN3(series.name())),
                                                                                 Soprano::Query::QueryLanguageSparql);
            if(it.next()) {
                setData(name, QLatin1String("depiction"), it["u"].uri().toLocalFile());
            }
        }
    }
    else {
        kDebug() << "Failed to find last episode of" << series.name();
    }
}

void NepomukTVShowEngine::updateSeriesReleaseGrouping(const QString &name)
{
    const QDate date = query(name)[QLatin1String("releaseDate")].value<QDate>();
    if(date.isValid()) {
        if(date < QDate::currentDate()) {
            setData(name, QLatin1String("releaseGroup"), i18n("New Episode Available"));
        }
        else {
            setData(name, QLatin1String("releaseGroup"), i18n("New Episode Upcoming"));
        }
    }
    else {
        setData(name, QLatin1String("releaseGroup"), i18n("Series Finished"));
    }
}

K_EXPORT_PLASMA_DATAENGINE(nepomuktvshow, NepomukTVShowEngine)
