/*
   This file is part of the Nepomuk KDE project.
   Copyright (C) 2011-2012 Sebastian Trueg <trueg@kde.org>

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

#include "tvnamer.h"
#include "tvshowfilenameanalyzer.h"

#include "nmm/tvshow.h"
#include "nmm/tvseries.h"
#include "nfo/image.h"

#include <tvdb/client.h>
#include <tvdb/series.h>
#include <tvdb/season.h>
#include <tvdb/episode.h>

#include <QtGui/QInputDialog>
#include <QtCore/QDate>
#include <QtCore/QDirIterator>

#include <KUrl>
#include <KMessageBox>
#include <KApplication>
#include <KLocale>
#include <KJob>
#include <KDebug>
#include <KStandardDirs>
#include <KIO/CopyJob>

#include <Nepomuk/Vocabulary/NMM>
#include <nepomuk/simpleresource.h>
#include <nepomuk/simpleresourcegraph.h>
#include <nepomuk/datamanagement.h>
#include <nepomuk/storeresourcesjob.h>


TVNamer::TVNamer(QObject *parent)
    : QObject(parent)
{
    m_client = new Tvdb::Client( this );
    m_client->setFlags(Tvdb::Client::FetchFullDetails);
    connect( m_client, SIGNAL( finished( Tvdb::Series ) ), SLOT( slotFinished( Tvdb::Series ) ) );
    connect( m_client, SIGNAL( multipleResultsFound( QList<Tvdb::Series> ) ), SLOT( slotMultipleResultsFound( QList<Tvdb::Series> ) ) );
}

void TVNamer::lookupFile(const KUrl &url)
{
    if(QFileInfo(url.toLocalFile()).isDir()) {
        lookupFolder(url);
    }
    else {
        m_series.clear();
        m_url = url;

        TVShowFilenameAnalyzer analyzer;
        TVShowFilenameAnalyzer::AnalysisResult fileNameResult = analyzer.analyzeFilename(url.toLocalFile());
        if(fileNameResult.isValid()) {
            m_fileNameResults[fileNameResult.name].insert(url.toLocalFile(), fileNameResult);
            lookupSeries();
        }
        else {
            KMessageBox::sorry(0, i18nc("@info", "Failed to extract TV Show details from filename <filename>%1</filename>.", url.fileName()));
            qApp->quit();
        }
    }
}

void TVNamer::lookupFolder(const KUrl &folder)
{
    QDirIterator it(folder.toLocalFile(), QDir::Files, QDirIterator::Subdirectories);
    while(it.hasNext()) {
        const QString path = it.next();
        TVShowFilenameAnalyzer analyzer;
        TVShowFilenameAnalyzer::AnalysisResult fileNameResult = analyzer.analyzeFilename(path);
        if(fileNameResult.isValid()) {
            m_fileNameResults[fileNameResult.name.toLower()].insert(path, fileNameResult);
        }
    }

    if(m_fileNameResults.isEmpty()) {
        KMessageBox::sorry(0, i18nc("@info", "Could not find any file names which contained TV Shows in <filename>%1</filename>.", folder.prettyUrl()));
        qApp->quit();
    }
    else {
        m_nameSeriesHash.clear();
        lookupSeries();
    }
}


void TVNamer::slotFinished(const Tvdb::Series &series)
{
    // found a series - check if it has the requested seasons and episodes
    if(checkSeries(series)) {
        m_series << series;
    }
    // lookup the next series or report the result
    decideFinalSeries();
}

void TVNamer::slotMultipleResultsFound(const QList<Tvdb::Series> &series)
{
    // we need to get the details for all series to be able to check season and episode counts
    // for that we can simply drop all details and only remember the ids
    foreach(const Tvdb::Series& s, series) {
        if(checkSeries(s)) {
            m_series << s;
        }
    }
    decideFinalSeries();
}

bool TVNamer::checkSeries(const Tvdb::Series &series) const
{
    //
    // We check the series' episode numbers for all the files we look up
    //
    const QHash<QString, TVShowFilenameAnalyzer::AnalysisResult>& files = m_fileNameResults[m_currentlyLookedUpSeriesName];
    for(QHash<QString, TVShowFilenameAnalyzer::AnalysisResult>::const_iterator it = files.constBegin();
        it != files.constEnd(); ++it) {
        if(series.numSeasons() < it.value().season ||
           series[it.value().season].numEpisodes() < it.value().episode) {
            return false;
        }
    }
    return true;
}

void TVNamer::decideFinalSeries()
{
    // now m_series does contain all real candidates
    // if there is more than one - ask the user to choose
    if(m_series.count() == 1) {
        m_nameSeriesHash.insert(m_currentlyLookedUpSeriesName, m_series.first());
    }

    else if(m_series.count() > 1) {
        QStringList seriesTitles;
        Q_FOREACH( const Tvdb::Series& s, m_series ) {
            QString title = s.name();
            if ( s.firstAired().isValid() )
                title.append( QString::fromLatin1( " (%1)" ).arg( s.firstAired().year() ) );
            title.append( QLatin1String( " - " ) );
            title.append( qApp->fontMetrics().elidedText( s.overview(), Qt::ElideRight, 300 ) );
            seriesTitles.append( title );
        }

        int i = seriesTitles.indexOf( QInputDialog::getItem( 0,
                                                             i18n( "Multiple Matches" ),
                                                             i18n( "Multiple matching series found. Please select one" ),
                                                             seriesTitles,
                                                             0,
                                                             false ) );
        if ( i >= 0 ) {
            // no need to lookup the series - we already have all details
            m_nameSeriesHash.insert(m_currentlyLookedUpSeriesName, m_series[i]);
        }
        else {
            // no matching series for this name
            m_nameSeriesHash.insert(m_currentlyLookedUpSeriesName, Tvdb::Series());
        }
    }

    else {
        // no matching series for this name
        m_nameSeriesHash.insert(m_currentlyLookedUpSeriesName, Tvdb::Series());
    }

    lookupSeries();
}

Nepomuk::SimpleResource TVNamer::createNepomukResource(const KUrl& url, int season, int episode, const Tvdb::Series &series)
{
    Nepomuk::NMM::TVShow episodeRes(url);
    episodeRes.setEpisodeNumber(episode);
    episodeRes.setSeason(season);
    episodeRes.setTitle(series[season][episode].name());
    episodeRes.setSynopsis(series[season][episode].overview());
    episodeRes.setReleaseDate(QDateTime(series[season][episode].firstAired(), QTime(), Qt::UTC));
    episodeRes.setGenres(series.genres());

    return episodeRes;
}

void TVNamer::slotSaveToNepomukDone(KJob *job)
{
    kDebug() << job;
    if(job->error())
        KMessageBox::error(0, i18nc("@info", "Failed to store information in Nepomuk (<message>%1</message>)", job->errorString()));

    saveToNepomuk();
}

void TVNamer::lookupSeries()
{
    m_series.clear();

    //
    // Look up the first name which has not been looked up yet
    //
    for(QHash<QString, QHash<QString, TVShowFilenameAnalyzer::AnalysisResult> >::const_iterator it = m_fileNameResults.constBegin();
        it != m_fileNameResults.constEnd(); ++it) {
        if(!m_nameSeriesHash.contains(it.key())) {
            m_currentlyLookedUpSeriesName = it.key();
            m_client->getSeriesByName(it.key());
            return;
        }
    }

    //
    // If we get here we did lookup all series names and m_nameSeriesHash is filled
    //
    saveToNepomuk();
}

void TVNamer::saveToNepomuk()
{
    if(!m_fileNameResults.isEmpty()) {
        const QHash<QString, TVShowFilenameAnalyzer::AnalysisResult> files = m_fileNameResults.begin().value();
        const QString name = m_fileNameResults.begin().key();
        m_fileNameResults.erase(m_fileNameResults.begin());

        const Tvdb::Series series = m_nameSeriesHash[name];
        if(!series.isValid()) {
            // continue to the next
            saveToNepomuk();
            return;
        }

        Nepomuk::SimpleResourceGraph graph;

        // get all the series information
        Nepomuk::NMM::TVSeries seriesRes;
        seriesRes.setTitle(series.name());
        seriesRes.addDescription(series.overview());
        foreach(const QUrl& bannerUrl, series.bannerUrls() + series.posterUrls()) {
            const KUrl localUrl = KGlobal::dirs()->locateLocal("appdata", QLatin1String("banners/") + series.name() + QLatin1String("/") + KUrl(bannerUrl).fileName(), true);
            if(!QFile::exists(localUrl.toLocalFile())) {
                KIO::CopyJob* job = KIO::copy(bannerUrl, localUrl);
                if(!job->exec()) {
                    continue;
                }
            }
            Nepomuk::NFO::Image banner(localUrl);
            seriesRes.addDepiction(banner.uri());
            graph << banner;
        }

        // add all the episodes to the graph
        for(QHash<QString, TVShowFilenameAnalyzer::AnalysisResult>::const_iterator it = files.constBegin();
            it != files.constEnd(); ++it) {
            Nepomuk::NMM::TVShow episodeRes = createNepomukResource(QUrl::fromLocalFile(it.key()), it.value().season, it.value().episode, series);
            seriesRes.addEpisode(episodeRes.uri());
            episodeRes.setSeries(seriesRes.uri());
            graph << episodeRes;
        }

        // add the series to the graph (after the episodes)
        graph << seriesRes;

        connect(Nepomuk::storeResources(graph), SIGNAL(result(KJob*)),
                this, SLOT(slotSaveToNepomukDone(KJob*)));
    }
    else {
        KMessageBox::information(0, i18nc("@info", "Successfully stored information in Nepomuk."));
        qApp->quit();
    }
}

#include "tvnamer.moc"
