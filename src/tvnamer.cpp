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
#include "nmm/tvseason.h"
#include "nfo/image.h"
#include "nfo/webdataobject.h"
#include "nco/contact.h"

#include <tvdb/client.h>
#include <tvdb/series.h>
#include <tvdb/season.h>
#include <tvdb/episode.h>
#include <tvdb/banner.h>

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
#include <KConfig>
#include <KConfigGroup>
#include <KMimeType>

#include <Nepomuk/Vocabulary/NMM>
#include <nepomuk/simpleresource.h>
#include <nepomuk/simpleresourcegraph.h>
#include <nepomuk/datamanagement.h>
#include <nepomuk/storeresourcesjob.h>

#include <Soprano/Vocabulary/RDFS>
#include <Soprano/Vocabulary/NAO>

using namespace Soprano::Vocabulary;


TVNamer::TVNamer(QObject *parent)
    : QObject(parent),
      m_quiet(false)
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
            if(!m_quiet)
                KMessageBox::sorry(0, i18nc("@info", "Failed to extract TV Show details from filename <filename>%1</filename>.", url.fileName()));
            // report error case
            qApp->exit(-1);
        }
    }
}

void TVNamer::lookupFolder(const KUrl &folder)
{
    QDirIterator it(folder.toLocalFile(), QDir::Files, QDirIterator::Subdirectories);
    while(it.hasNext()) {
        const QString path = it.next();
        // only check videos. We do not want to mark archives or subtitles as tv shows
        if(KMimeType::findByPath(path)->name().contains(QLatin1String("video"))) {
            TVShowFilenameAnalyzer analyzer;
            TVShowFilenameAnalyzer::AnalysisResult fileNameResult = analyzer.analyzeFilename(path);
            if(fileNameResult.isValid()) {
                m_fileNameResults[fileNameResult.name.toLower()].insert(path, fileNameResult);
            }
        }
    }

    if(m_fileNameResults.isEmpty()) {
        if(!m_quiet)
            KMessageBox::sorry(0, i18nc("@info", "Could not find any file names which contained TV Shows in <filename>%1</filename>.", folder.prettyUrl()));
        // not an error
        qApp->exit(0);
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
    if(!series[season][episode].overview().isEmpty()) {
        episodeRes.setSynopsis(series[season][episode].overview());
    }
    if(series[season][episode].firstAired().isValid()) {
        episodeRes.setReleaseDate(QDateTime(series[season][episode].firstAired(), QTime(), Qt::UTC));
    }
    episodeRes.setGenres(series.genres());
    return episodeRes;
}

void TVNamer::updateFileIndexerConfig()
{
    KConfig cfg("nepomukstrigirc");
    QStringList folders = cfg.group("General").readPathEntry( "folders", QStringList() << QDir::homePath() );
    const QString bannerPath = KGlobal::dirs()->locateLocal("appdata", QLatin1String("banners/"), true);
    if(!folders.contains(bannerPath)) {
        folders << bannerPath;
        cfg.group("General").writePathEntry( "folders", folders );
    }
}

KUrl TVNamer::downloadBanner(const QString& seriesName, const QUrl &bannerUrl) const
{
    const KUrl localUrl = KGlobal::dirs()->locateLocal("appdata", QLatin1String("banners/") + seriesName + QLatin1String("/") + KUrl(bannerUrl).fileName(), true);
    if(!QFile::exists(localUrl.toLocalFile())) {
        KIO::CopyJob* job = KIO::copy(bannerUrl, localUrl, KIO::HideProgressInfo);
        if(!job->exec()) {
            return KUrl();
        }
    }
    return localUrl;
}

void TVNamer::slotSaveToNepomukDone(KJob *job)
{
    kDebug() << job;
    if(job->error()) {
        if(!m_quiet)
            KMessageBox::error(0, i18nc("@info", "Failed to store information in Nepomuk (<message>%1</message>)", job->errorString()));
        if(m_fileNameResults.isEmpty()) {
            qApp->exit(-2);
        }
    }
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
        updateFileIndexerConfig();

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
        if(!series.imdbId().isEmpty()) {
            // TODO: this is not nice: the DMS does not allow to simply use an http URL as object
            Nepomuk::NFO::WebDataObject imdbRes(series.imdbUrl());
            seriesRes.addProperty(RDFS::seeAlso(), imdbRes.uri());
            graph << imdbRes;
        }
        // grab a max of 3 banners - one of each type
        foreach(Tvdb::Banner::BannerType type, QList<Tvdb::Banner::BannerType>() << Tvdb::Banner::PosterBanner << Tvdb::Banner::GraphicalBanner << Tvdb::Banner::FanartBanner) {
            foreach(const Tvdb::Banner& banner, series.banners()) {
                if(banner.type() == type &&
                   (banner.language() == series.language() ||
                    banner.language() == KGlobal::locale()->language())) {
                    const KUrl localUrl = downloadBanner(series.name(), banner.bannerUrl());
                    if(!localUrl.isEmpty()) {
                        Nepomuk::NFO::Image banner(localUrl);
                        seriesRes.addDepiction(banner.uri());
                        graph << banner;
                        break;
                    }
                }
            }
        }

        // create all the regular actor resources which we will add to all episodes
        QList<Nepomuk::NCO::Contact> regularActors;
        foreach(const QString& actor, series.actors()) {
            Nepomuk::NCO::Contact contact;
            contact.setFullname(actor);
            regularActors << contact;
            graph << contact;
        }

        // the seasons we store
        QHash<int, Nepomuk::NMM::TVSeason> seasons;

        // add all the episodes to the graph
        for(QHash<QString, TVShowFilenameAnalyzer::AnalysisResult>::const_iterator it = files.constBegin();
            it != files.constEnd(); ++it) {
            const Tvdb::Episode episode = series[it.value().season][it.value().episode];

            // create the basic episode
            Nepomuk::NMM::TVShow episodeRes = createNepomukResource(QUrl::fromLocalFile(it.key()), it.value().season, it.value().episode, series);

            // add the season
            if(!seasons.contains(it.value().season)) {
                Nepomuk::NMM::TVSeason seasonRes;
                seasonRes.setSeasonNumber(it.value().season);
                seasonRes.setSeasonOf(seriesRes.uri());
                seriesRes.addSeason(seasonRes.uri());
                // grab a banner
                foreach(const Tvdb::Banner& banner, series[it.value().season].banners()) {
                    if(banner.language() == series.language() ||
                       banner.language() == KGlobal::locale()->language()) {
                        const KUrl localUrl = downloadBanner(series.name(), banner.bannerUrl());
                        if(!localUrl.isEmpty()) {
                            Nepomuk::NFO::Image banner(localUrl);
                            seasonRes.addDepiction(banner.uri());
                            graph << banner;
                            break;
                        }
                    }
                }

                seasons.insert(it.value().season, seasonRes);
            }
            seasons[it.value().season].addSeasonEpisode(episodeRes.uri());
            episodeRes.setIsPartOfSeason(seasons[it.value().season].uri());

            // we make the seasons sub-resources of the episodes since they do not make sense without them
            episodeRes.addProperty(NAO::hasSubResource(), seasons[it.value().season].uri());

            // add all the actors
            foreach(const Nepomuk::NCO::Contact& actor, regularActors) {
                episodeRes.addActor(actor.uri());
                episodeRes.addProperty(NAO::hasSubResource(), actor.uri());
            }
            // add the guest stars
            foreach(const QString& guestStar, episode.guestStars()) {
                Nepomuk::NCO::Contact contact;
                contact.setFullname(guestStar);
                episodeRes.addActor(contact.uri());
                episodeRes.addProperty(NAO::hasSubResource(), contact.uri());
                graph << contact;
            }
            if(!episode.director().isEmpty()) {
                Nepomuk::NCO::Contact contact;
                contact.setFullname(episode.director());
                graph << contact;
                episodeRes.addDirector(contact.uri());
            }
            foreach(const QString& writer, episode.writers()) {
                Nepomuk::NCO::Contact contact;
                contact.setFullname(writer);
                graph << contact;
                episodeRes.addWriter(contact.uri());
            }

            seriesRes.addEpisode(episodeRes.uri());
            episodeRes.setSeries(seriesRes.uri());
            graph << episodeRes;
        }

        // add the seasons to the graph
        foreach(const Nepomuk::NMM::TVSeason& season, seasons.values()) {
            graph << season;
        }

        // add the series to the graph (after the episodes)
        graph << seriesRes;

        connect(Nepomuk::storeResources(graph, Nepomuk::IdentifyNew, Nepomuk::OverwriteProperties), SIGNAL(result(KJob*)),
                this, SLOT(slotSaveToNepomukDone(KJob*)));
    }
    else {
        // FIXME: if no series is found the tvnamer claims success anyway
        if(!m_quiet)
            KMessageBox::information(0, i18nc("@info", "Successfully stored information in Nepomuk."));
        qApp->exit(0);
    }
}

#include "tvnamer.moc"
