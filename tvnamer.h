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

#ifndef TVNAMER_H
#define TVNAMER_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include <KUrl>

#include "tvshowfilenameanalyzer.h"

#include <tvdb/series.h>

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
    void lookupFile(const KUrl& url);

private Q_SLOTS:
    void slotFinished( const Tvdb::Series& series );
    void slotMultipleResultsFound( const QList<Tvdb::Series>& series );
    void lookupNextSeries();
    void slotSaveToNepomukDone(KJob*);

private:
    /**
     * Compare a series against m_fileNameResult to see if it is a candidate.
     */
    bool checkSeries(const Tvdb::Series& series) const;

    /**
     * Saves the information to Nepomuk. Uses m_url, the episode
     * number from m_fileNameResult and the details in \p series.
     *
     * Shows a wait dialog and quits once done.
     */
    void saveToNepomuk(const Tvdb::Series& series);

    Tvdb::Client* m_client;
    TVShowFilenameAnalyzer::AnalysisResult m_fileNameResult;

    // the url we are looking up
    KUrl m_url;

    /// ids to lookup in multi result mode
    QList<int> m_seriesIds;

    /// the final candidates that will be proposed to the user
    QList<Tvdb::Series> m_series;
};

#endif
