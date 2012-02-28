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

#include "tvnamerservice.h"

#include <nepomuk/resourcewatcher.h>
#include <Nepomuk/Vocabulary/NFO>
#include <Nepomuk/Vocabulary/NMM>
#include <Nepomuk/File>

#include <Soprano/Model>
#include <Soprano/QueryResultIterator>
#include <Soprano/Node>

#include <QtCore/QProcess>
#include <QFile>

#include <KStandardDirs>
#include <KDebug>
#include <KDirNotify>

using namespace Nepomuk::Vocabulary;

TVNamerService::TVNamerService(QObject *parent, const QVariantList &)
    : Nepomuk::Service(parent)
{
    // set up the watcher for newly created nfo:Video resources
    Nepomuk::ResourceWatcher* watcher = new Nepomuk::ResourceWatcher(this);
    watcher->addType(NFO::Video());
    connect(watcher, SIGNAL(resourceCreated(Nepomuk::Resource,QList<QUrl>)),
            this, SLOT(slotVideoResourceCreated(Nepomuk::Resource,QList<QUrl>)));
    watcher->start();

    // set up the watcher for newly created TV Shows
    watcher = new Nepomuk::ResourceWatcher(this);
    watcher->addType(NMM::TVShow());
    connect(watcher, SIGNAL(resourceCreated(Nepomuk::Resource,QList<QUrl>)),
            this, SLOT(slotTVShowResourceCreated(Nepomuk::Resource)));
    connect(watcher, SIGNAL(resourceTypeAdded(Nepomuk::Resource,Nepomuk::Types::Class)),
            this, SLOT(slotTVShowResourceCreated(Nepomuk::Resource)));
    watcher->start();
}

TVNamerService::~TVNamerService()
{
}

void TVNamerService::slotVideoResourceCreated(const Nepomuk::Resource &res, const QList<QUrl> &types)
{
    // all we need to do is call the nepomuktvnamer executable on the newly created file
    if(res.isFile()) {
        const QString path = res.toFile().url().toLocalFile();
        if(QFile::exists(path)) {
            kDebug() << "Calling" << KStandardDirs::findExe(QLatin1String("nepomuktvnamer")) << path;
            QProcess::startDetached(KStandardDirs::findExe(QLatin1String("nepomuktvnamer")), QStringList() << QLatin1String("--quiet") << path);
        }
    }
}

void TVNamerService::slotTVShowResourceCreated(const Nepomuk::Resource &res)
{
    kDebug() << res.resourceUri();
    // inform KIO about the change
    Soprano::QueryResultIterator it = mainModel()->executeQuery(QString::fromLatin1("select ?s ?t where { "
                                                                                    "%1 nmm:series [ nie:title ?t ] ; "
                                                                                    "nmm:isPartOfSeason [ nmm:seasonNumber ?s ] "
                                                                                    "} LIMIT 1")
                                                                .arg(Soprano::Node::resourceToN3(res.resourceUri())),
                                                                Soprano::Query::QueryLanguageSparql);
    if(it.next()) {
        kDebug() << QString::fromLatin1("tvshow:/%1/%1 - Season %2")
                    .arg(it["t"].toString())
                    .arg(it["s"].literal().toInt(), 2, 10, QLatin1Char('0'));
        org::kde::KDirNotify::emitFilesAdded(QString::fromLatin1("tvshow:/%1/%1 - Season %2")
                                             .arg(it["t"].toString())
                                             .arg(it["s"].literal().toInt()));
    }
}

#include <kpluginfactory.h>
#include <kpluginloader.h>

NEPOMUK_EXPORT_SERVICE( TVNamerService, "nepomuktvnamerservice" )

#include "tvnamerservice.moc"
