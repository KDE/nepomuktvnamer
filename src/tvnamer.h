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

#ifndef TVNAMER_H
#define TVNAMER_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include <KUrl>

#include "tvshowfilenameanalyzer.h"

#include <tvdb/series.h>

#include <nepomuk2/simpleresource.h>

class KJob;
namespace Tvdb {
class Client;
}

class TVNamer : public QObject
{
    Q_OBJECT

public:
    TVNamer(QObject *parent = 0);

public Q_SLOTS:
    void setQuiet(bool quiet) { m_quiet = quiet; }
    void lookupFile(const KUrl& url);
    void lookupFolder(const KUrl& folder);

private Q_SLOTS:
    void slotFinished( const Tvdb::Series& series );
    void slotMultipleResultsFound( const QList<Tvdb::Series>& series );
    void decideFinalSeries();
    void slotSaveToNepomukDone(KJob*);
    /// look up the series in m_fileNameResults
    void lookupSeries();
    void saveToNepomuk();

private:
    /**
     * Compare a series against m_fileNameResult to see if it is a candidate.
     */
    bool checkSeries(const Tvdb::Series& series) const;

    Nepomuk2::SimpleResource createNepomukResource(const KUrl& url, int season, int episode, const Tvdb::Series& series);

    /**
     * Adds the banner folder to the indexer config.
     */
    void updateFileIndexerConfig();

    KUrl downloadBanner(const QString& seriesName, const QUrl& bannerUrl) const;

    bool m_quiet;

    Tvdb::Client* m_client;

    /// maps tv show names to a map of paths to results
    QHash<QString, QHash<QString, TVShowFilenameAnalyzer::AnalysisResult> > m_fileNameResults;

    /// maps names from m_fileNameResults to actual shows
    QHash<QString, Tvdb::Series> m_nameSeriesHash;

    QString m_currentlyLookedUpSeriesName;
    QString m_currentlyLookedUpSeriesNormalizedName;
    QString m_currentlyLookedUpSeriesYear;

    // the url we are looking up
    KUrl m_url;

    /// the final candidates that will be proposed to the user
    QList<Tvdb::Series> m_series;
};

#endif
