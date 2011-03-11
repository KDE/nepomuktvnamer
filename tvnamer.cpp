/*
   This file is part of the Nepomuk KDE project.
   Copyright (C) 2011 Sebastian Trueg <trueg@kde.org>

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

#include <tvdb/client.h>
#include <tvdb/series.h>
#include <tvdb/season.h>
#include <tvdb/episode.h>

#include <QtGui/QInputDialog>
#include <QtCore/QDate>

#include <KUrl>
#include <KMessageBox>
#include <KApplication>
#include <KLocale>
#include <KJob>
#include <KDebug>

#include <Nepomuk/Vocabulary/NMM>
#include <nepomuk/simpleresource.h>
#include <nepomuk/simpleresourcegraph.h>
#include <nepomuk/datamanagement.h>


TVNamer::TVNamer(QObject *parent)
    : QObject(parent)
{
    m_client = new Tvdb::Client( this );
    connect( m_client, SIGNAL( finished( Tvdb::Series ) ), SLOT( slotFinished( Tvdb::Series ) ) );
    connect( m_client, SIGNAL( multipleResultsFound( QList<Tvdb::Series> ) ), SLOT( slotMultipleResultsFound( QList<Tvdb::Series> ) ) );
}

void TVNamer::lookupFile(const KUrl &url)
{
    m_seriesIds.clear();
    m_series.clear();
    m_url = url;

    TVShowFilenameAnalyzer analyzer;
    m_fileNameResult = analyzer.analyzeFilename(url.toLocalFile());
    if(m_fileNameResult.isValid()) {
        m_client->getSeriesByName( m_fileNameResult.name );
    }
    else {
        KMessageBox::sorry(0, i18nc("@info", "Failed to extract TV Show details from filename <filename>%1</filename>.", url.fileName()));
        qApp->quit();
    }
}

void TVNamer::slotFinished(const Tvdb::Series &series)
{
    // found a series - check if it has the requested season and episode
    if(checkSeries(series)) {
        m_series << series;
    }
    // lookup the next series or report the result
    lookupNextSeries();
}

void TVNamer::slotMultipleResultsFound(const QList<Tvdb::Series> &series)
{
    // we need to get the details for all series to be able to check season and episode counts
    // for that we can simply drop all details and only remember the ids
    foreach(const Tvdb::Series& s, series) {
        m_seriesIds << s.id();
    }
    lookupNextSeries();
}

bool TVNamer::checkSeries(const Tvdb::Series &series) const
{
    return(series.numSeasons() >= m_fileNameResult.season &&
           series[m_fileNameResult.season].numEpisodes() >= m_fileNameResult.episode);
}

void TVNamer::lookupNextSeries()
{
    if(!m_seriesIds.isEmpty()) {
        m_client->getSeriesById(m_seriesIds.takeFirst());
    }
    else {
        // now m_series does contain all real candidates
        // if there is more than one - ask the user to choose
        if(m_series.count() == 1) {
            // ask the user if this is correct
            if(KMessageBox::questionYesNo(0,
                                          i18nc("@info",
                                                "Is <filename>%1</filename> episode <emphasis>%2x%3</emphasis> from <emphasis>%4</emphasis>?",
                                                m_url.fileName(),
                                                QString::number(m_fileNameResult.season).rightJustified(2, '0'),
                                                QString::number(m_fileNameResult.episode).rightJustified(2, '0'),
                                                m_series[0].name())
                                          ) == KMessageBox::Yes) {
                saveToNepomuk(m_series[0]);
            }
            else {
                qApp->quit();
            }
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
                saveToNepomuk(m_series[i]);
            }
            else {
                qApp->quit();
            }
        }

        else {
            KMessageBox::sorry(0, i18nc("@info",
                                        "Could not find a TV show matching <emphasis>%1</emphasis> with season <emphasis>%2</emphasis> and episode <emphasis>%3</emphasis>.",
                                        m_fileNameResult.name, m_fileNameResult.season, m_fileNameResult.episode));
            qApp->quit();
        }
    }
}

void TVNamer::saveToNepomuk(const Tvdb::Series &series)
{
    kDebug() << "saving to nepomuk...";

    Nepomuk::SimpleResource episodeRes(m_url);
    Nepomuk::NMM::TVShow(&episodeRes).setEpisodeNumber(m_fileNameResult.episode);
    Nepomuk::NMM::TVShow(&episodeRes).setSeason(m_fileNameResult.season);
    Nepomuk::NMM::TVShow(&episodeRes).addTitle(series[m_fileNameResult.season][m_fileNameResult.episode].name());
    Nepomuk::NMM::TVShow(&episodeRes).setSynopsis(series[m_fileNameResult.season][m_fileNameResult.episode].overview());

    Nepomuk::SimpleResource seriesRes;
    Nepomuk::NMM::TVSeries(&seriesRes).addTitle(series.name());
    Nepomuk::NMM::TVSeries(&seriesRes).addNieDescription(series.overview());
    Nepomuk::NMM::TVSeries(&seriesRes).addHasEpisode(episodeRes.uri());

    Nepomuk::SimpleResourceGraph graph;
    graph << seriesRes << episodeRes;

    kDebug() << "Merging" << graph;

    connect(Nepomuk::storeResources(graph), SIGNAL(result(KJob*)),
            this, SLOT(slotSaveToNepomukDone(KJob*)));
}

void TVNamer::slotSaveToNepomukDone(KJob *job)
{
    kDebug() << job;
    if(job->error()) {
        KMessageBox::error(0, i18nc("@info", "Failed to store information in Nepomuk (<message>%1</message>)", job->errorString()));
    }
    else {
        KMessageBox::information(0, i18nc("@info", "Successfully stored information in Nepomuk."));
    }
    qApp->quit();
}

#include "tvnamer.moc"
