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

#include <QDateTime>
#include <QVariant>

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
            setData(series.name(), i18n("Release date"), episode.firstAired());
            setData(series.name(), i18n("Title"), episode.name());
            setData(series.name(), i18n("Season Number"), episode.season().seasonNumber());
            setData(series.name(), i18n("Episode Number"), episode.episodeNumber());
        }
        else {
            setData(series.name(), i18n("Release date"), QDate());
            removeData(series.name(), i18n("Title"));
            removeData(series.name(), i18n("Season Number"));
            removeData(series.name(), i18n("Episode Number"));
        }
    }
    else {
        kDebug() << "Failed to find last episode of" << series.name();
    }
}

K_EXPORT_PLASMA_DATAENGINE(nepomuktvshow, NepomukTVShowEngine)
