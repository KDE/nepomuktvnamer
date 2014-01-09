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

#include "tvseasonduplicatescleaningjob.h"

#include <QList>
#include <QMultiHash>

#include <Soprano/Model>
#include <Soprano/QueryResultIterator>
#include <Soprano/BindingSet>
#include <Soprano/Vocabulary/NAO>

#include <Nepomuk2/ResourceManager>
#include <Nepomuk2/DataManagement>

#include <KDebug>
#include <KService>

using namespace Nepomuk2;
using namespace Soprano;


TVSeasonDuplicatesCleaningJob::TVSeasonDuplicatesCleaningJob(QObject *parent, const QVariantList &)
    : Nepomuk2::CleaningJob(parent)
{
}

void TVSeasonDuplicatesCleaningJob::execute()
{
    int cnt = 0;
    Soprano::Model* model = Nepomuk2::ResourceManager::instance()->mainModel();
    while(1) {
        QMultiHash<QUrl, QUrl> duplicates;
        QueryResultIterator it = model->executeQuery("select ?r1 ?r2 where { "
                                                     "?r1 a nmm:TVSeason; nmm:seasonOf ?s ; nmm:seasonNumber ?n . "
                                                     "?r2 a nmm:TVSeason ; nmm:seasonOf ?s ; nmm:seasonNumber ?n . "
                                                     "FILTER(STR(?r1)>STR(?r2)) . } LIMIT 200",
                                                     Soprano::Query::QueryLanguageSparql);
        while(it.next()) {
            duplicates.insert(it[0].uri(), it[1].uri());
            ++cnt;
        }

        if(duplicates.isEmpty() || shouldQuit())
            break;

        foreach(const QUrl& res, duplicates.uniqueKeys()) {
            if(shouldQuit()) break;
            QList<QUrl> rl = duplicates.values(res);
            rl.prepend(res);
            if(!Nepomuk2::mergeResources(rl)->exec()) {
                kError() << "Merging TVSeason resources failed for some reason. Stopping cleaning job.";
                return;
            }
        }
    }

    kDebug() << "Total of" << cnt << "TV Season duplicates merged.";
}

NEPOMUK_EXPORT_CLEANINGJOB(TVSeasonDuplicatesCleaningJob, "nepomuktvseriesduplicatescleaner")
