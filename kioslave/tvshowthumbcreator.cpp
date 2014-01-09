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

#include "tvshowthumbcreator.h"

#include <Nepomuk2/ResourceManager>
#include <Nepomuk2/Vocabulary/NFO>
#include <Nepomuk2/Vocabulary/NMM>
#include <Nepomuk2/Vocabulary/NIE>

#include <Soprano/QueryResultIterator>
#include <Soprano/Node>
#include <Soprano/LiteralValue>
#include <Soprano/Model>

#include <KUrl>
#include <KDebug>

#include <QStringList>
#include <QImage>


TVShowThumbCreator::TVShowThumbCreator()
{
}

bool TVShowThumbCreator::create(const QString &path, int width, int height, QImage &img)
{
    // The previewJob does the scaling for us
    Q_UNUSED(width);
    Q_UNUSED(height);

    // although the docs state that path is always local this is not correct
    KUrl url(path);
    const QStringList pathTokens = url.path().split('/', QString::SkipEmptyParts);

    // get a series poster
    if(pathTokens.count() == 1) {
        // we query the depiction which has the best aspect ratio: the rough heuristic is an image which is higher than it is wide
        const QString seriesName = pathTokens[0];
        Soprano::QueryResultIterator it
                = Nepomuk2::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select ?u where { "
                                                                                                      "?r a nmm:TVSeries ; "
                                                                                                      "nie:title %1 ; "
                                                                                                      "nfo:depiction ?d . "
                                                                                                      "?d nie:url ?u ; "
                                                                                                      "nfo:height ?h ; "
                                                                                                      "nfo:width ?w . "
                                                                                                      "} ORDER BY DESC(?h-?w) LIMIT 1")
                                                                                  .arg(Soprano::Node::literalToN3(seriesName)),
                                                                                  Soprano::Query::QueryLanguageSparql);
        if(it.next()) {
            img.load(it["u"].uri().toLocalFile());
            return true;
        }
    }

    // get a season poster
    else if(pathTokens.count() == 2) {
        const QString seriesName = pathTokens[0];
        const int season = pathTokens[1].mid(pathTokens[1].lastIndexOf(' ')+1).toInt();
        Soprano::QueryResultIterator it
                = Nepomuk2::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select ?u where { "
                                                                                                       "?r a nmm:TVSeason ; "
                                                                                                       "nmm:seasonOf [ nie:title %1 ] ; "
                                                                                                       "nmm:seasonNumber %2 ; "
                                                                                                       "nfo:depiction ?d . "
                                                                                                       "?d nie:url ?u ; "
                                                                                                       "nfo:height ?h ; "
                                                                                                       "nfo:width ?w . "
                                                                                                       "} ORDER BY DESC(?h-?w) LIMIT 1")
                                                                                  .arg(Soprano::Node::literalToN3(seriesName))
                                                                                  .arg(season),
                                                                                  Soprano::Query::QueryLanguageSparql);
        if(it.next()) {
            img.load(it["u"].uri().toLocalFile());
            return true;
        }
    }

    // fallback
    return false;
}
