/*
   Copyright 2012 Sebastian Trueg <trueg@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License or (at your option) version 3 or any later version
   accepted by the membership of KDE e.V. (or its successor approved
   by the membership of KDE e.V.), which shall act as a proxy
   defined in Section 14 of version 3 of the license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "kio_tvshow.h"

#include <Nepomuk/ResourceManager>
#include <Nepomuk/Vocabulary/NMM>
#include <Nepomuk/Vocabulary/NIE>
#include <Nepomuk/Vocabulary/NFO>
#include <Nepomuk/Query/FileQuery>
#include <Nepomuk/Query/ComparisonTerm>
#include <Nepomuk/Query/ResourceTypeTerm>
#include <Nepomuk/Query/LiteralTerm>
#include <Nepomuk/Query/AndTerm>

#include <KUrl>
#include <kio/global.h>
#include <klocale.h>
#include <kio/job.h>
#include <KUser>
#include <KDebug>
#include <KLocale>
#include <KComponentData>

#include <Soprano/Vocabulary/NAO>
#include <Soprano/QueryResultIterator>
#include <Soprano/Model>
#include <Soprano/Node>
#include <Soprano/LiteralValue>

#include <QtCore/QDate>
#include <QtCore/QCoreApplication>
#include <QStringList>

using namespace KIO;
using namespace Nepomuk::Vocabulary;
using namespace Soprano::Vocabulary;


namespace {
    KIO::UDSEntry createFolderUDSEntry( const QString& name, const QString& displayName )
    {
        KIO::UDSEntry uds;
        uds.insert( KIO::UDSEntry::UDS_NAME, name );
        uds.insert( KIO::UDSEntry::UDS_DISPLAY_NAME, displayName );
        uds.insert( KIO::UDSEntry::UDS_FILE_TYPE, S_IFDIR );
        uds.insert( KIO::UDSEntry::UDS_MIME_TYPE, QString::fromLatin1( "inode/directory" ) );
        uds.insert( KIO::UDSEntry::UDS_ACCESS, 0700 );
        uds.insert( KIO::UDSEntry::UDS_USER, KUser().loginName() );
        return uds;
    }

    KIO::UDSEntry createSeriesUDSEntry( const KUrl& nepomukUri,
                                        const QString& name,
                                        const QString& displayName,
                                        const QString& comment,
                                        const QDateTime& created,
                                        const QDateTime& modified )
    {
        UDSEntry uds = createFolderUDSEntry(name, displayName);
        uds.insert( KIO::UDSEntry::UDS_COMMENT, comment );
        uds.insert( KIO::UDSEntry::UDS_NEPOMUK_URI, nepomukUri.url() );
        uds.insert( KIO::UDSEntry::UDS_DISPLAY_TYPE, i18n("TV Series") );
        uds.insert( KIO::UDSEntry::UDS_MODIFICATION_TIME, modified.toTime_t() );
        uds.insert( KIO::UDSEntry::UDS_CREATION_TIME, created.toTime_t() );
        return uds;
    }
}


Nepomuk::TvshowProtocol::TvshowProtocol( const QByteArray& poolSocket, const QByteArray& appSocket )
    : KIO::SlaveBase( "tvshow", poolSocket, appSocket )
{
}


Nepomuk::TvshowProtocol::~TvshowProtocol()
{
}


void Nepomuk::TvshowProtocol::listDir( const KUrl& url )
{
    // root folder
    if(url.path().length() <= 1) {
        // list all tv shows including title, description, and an optional depiction (for now we simply take one of them)
        Soprano::QueryResultIterator it
                = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select distinct ?r ?t ?d where { "
                                                                                                      "?r a %1 . "
                                                                                                      "?r %2 ?t . "
                                                                                                      "?r %3 ?d . "
                                                                                                      "?r %4 ?cd . "
                                                                                                      "?r %5 ?md . }")
                                                                                  .arg(Soprano::Node::resourceToN3(NMM::TVSeries()),
                                                                                       Soprano::Node::resourceToN3(NIE::title()),
                                                                                       Soprano::Node::resourceToN3(NIE::description()),
                                                                                       Soprano::Node::resourceToN3(NAO::created()),
                                                                                       Soprano::Node::resourceToN3(NAO::lastModified())),
                                                                                  Soprano::Query::QueryLanguageSparql);
        while(it.next()) {
            UDSEntry uds = createSeriesUDSEntry(it["r"].uri(),
                                                it["t"].toString(),
                                                it["t"].toString(),
                                                it["d"].toString(),
                                                it["cd"].literal().toDateTime(),
                                                it["md"].literal().toDateTime());
            listEntry(uds, false);
        }
        listEntry(UDSEntry(), true);
        finished();
    }

    // all other URLS
    else {
        const QStringList pathTokens = url.path().split('/', QString::SkipEmptyParts);
        if(pathTokens.count() == 1) {
            // list one TV Series: list seasons
            Soprano::QueryResultIterator it
                    = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select distinct ?s where { "
                                                                                                          "?r nmm:series ?tv . "
                                                                                                          "?tv nie:title %1 . "
                                                                                                          "?r nmm:season ?s . }")
                                                                                      .arg(Soprano::Node::literalToN3(pathTokens.first())),
                                                                                      Soprano::Query::QueryLanguageSparql);
            while(it.next()) {
                const QString name = pathTokens.first() + QLatin1String(" - ") + i18n("Season %1", it["s"].literal().toInt());
                UDSEntry uds = createFolderUDSEntry(name, name);
                listEntry(uds, false);
            }
            listEntry(UDSEntry(), true);
            finished();
        }
        else if(pathTokens.count() == 2) {
            const QString seriesTitle = pathTokens[0];
            const int season = pathTokens[1].mid(pathTokens[1].lastIndexOf(' ')+1).toInt();
            Soprano::QueryResultIterator it
                    = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select distinct * where { "
                                                                                                          "?r a nmm:TVShow ; "
                                                                                                          "nmm:season %1 ; "
                                                                                                          "nmm:series [ nie:title %2 ] ; "
                                                                                                          "nie:title ?t ; "
                                                                                                          "nmm:episodeNumber ?e ; "
                                                                                                          "nie:url ?url ; "
                                                                                                          "nmm:releaseDate ?rd ; "
                                                                                                          "nmm:synopsis ?d . }")
                                                                                      .arg(Soprano::Node::literalToN3(season),
                                                                                           Soprano::Node::literalToN3(seriesTitle)),
                                                                                      Soprano::Query::QueryLanguageSparql);
            while(it.next()) {
                const QString episodeName = seriesTitle + QString::fromLatin1(" - %1x%2 - ").arg(season, 2, 10, QLatin1Char('0')).arg(it["e"].literal().toInt(), 2, 10, QLatin1Char('0')) + it["t"].toString();
                UDSEntry uds;
                uds.insert( KIO::UDSEntry::UDS_NAME, episodeName );
                uds.insert( KIO::UDSEntry::UDS_FILE_TYPE, S_IFREG );
                uds.insert( KIO::UDSEntry::UDS_DISPLAY_TYPE, i18n("TV Show") );
                uds.insert( KIO::UDSEntry::UDS_ACCESS, 0700 );
                uds.insert( KIO::UDSEntry::UDS_USER, KUser().loginName() );
                uds.insert( KIO::UDSEntry::UDS_CREATION_TIME, it["rd"].literal().toDateTime().toTime_t() );
                uds.insert( KIO::UDSEntry::UDS_COMMENT, it["d"].toString() );
                uds.insert( KIO::UDSEntry::UDS_URL, KUrl(it["url"].uri()).url() );
                listEntry(uds, false);
            }
            listEntry(UDSEntry(), true);
            finished();
        }
        else {
            error( KIO::ERR_CANNOT_ENTER_DIRECTORY, url.prettyUrl() );
        }
    }
}


void Nepomuk::TvshowProtocol::mkdir( const KUrl &url, int permissions )
{
    Q_UNUSED(permissions);
    error( ERR_UNSUPPORTED_ACTION, url.prettyUrl() );
}


void Nepomuk::TvshowProtocol::get( const KUrl& url )
{
    error( ERR_UNSUPPORTED_ACTION, url.prettyUrl() );
}


void Nepomuk::TvshowProtocol::put( const KUrl& url, int permissions, KIO::JobFlags flags )
{
    Q_UNUSED(permissions);
    Q_UNUSED(flags);

    error( KIO::ERR_UNSUPPORTED_ACTION, url.prettyUrl() );
}


void Nepomuk::TvshowProtocol::copy( const KUrl& src, const KUrl& dest, int permissions, KIO::JobFlags flags )
{
    Q_UNUSED(src);
    Q_UNUSED(dest);
    Q_UNUSED(permissions);
    Q_UNUSED(flags);

    error( ERR_UNSUPPORTED_ACTION, src.prettyUrl() );
}


void Nepomuk::TvshowProtocol::rename( const KUrl& src, const KUrl& dest, KIO::JobFlags flags )
{
    Q_UNUSED(src);
    Q_UNUSED(dest);
    Q_UNUSED(flags);

    error( ERR_UNSUPPORTED_ACTION, src.prettyUrl() );
}


void Nepomuk::TvshowProtocol::del( const KUrl& url, bool isfile )
{
    Q_UNUSED(isfile);
    error( ERR_UNSUPPORTED_ACTION, url.prettyUrl() );
}


void Nepomuk::TvshowProtocol::mimetype( const KUrl& url )
{
    // FIXME
    error( ERR_UNSUPPORTED_ACTION, url.prettyUrl() );
}


void Nepomuk::TvshowProtocol::stat( const KUrl& url )
{
    // for basic functionality we only need to stat the folders
    const QStringList pathTokens = url.path().split('/', QString::SkipEmptyParts);
    if(pathTokens.count() == 1) {
        // stat series folder
        Soprano::QueryResultIterator it
                = Nepomuk::ResourceManager::instance()->mainModel()->executeQuery(QString::fromLatin1("select distinct * where { "
                                                                                                      "?r a nmm:TVSeries ; "
                                                                                                      "nie:title %1 ; "
                                                                                                      "nao:created ?cd ; "
                                                                                                      "nao:lastModified ?md ; "
                                                                                                      "nie:description ?d . } LIMIT 1")
                                                                                  .arg(Soprano::Node::literalToN3(pathTokens[0])),
                                                                                  Soprano::Query::QueryLanguageSparql);
        if(it.next()) {
            statEntry(createSeriesUDSEntry(it["r"].uri(),
                                           pathTokens[0],
                                           pathTokens[0],
                                           it["d"].toString(),
                                           it["cd"].literal().toDateTime(),
                                           it["md"].literal().toDateTime()));
            finished();
        }
        else {
            error( ERR_DOES_NOT_EXIST, url.prettyUrl() );
        }
    }
    else if(pathTokens.count() == 2) {
        // stat season folder
        statEntry(createFolderUDSEntry(pathTokens[0], pathTokens[1]));
        finished();
    }
    else {
        // FIXME
        error( ERR_UNSUPPORTED_ACTION, url.prettyUrl() );
    }
}


extern "C"
{
    KDE_EXPORT int kdemain( int argc, char **argv )
    {
        // necessary to use other kio slaves
        KComponentData( "kio_tvshow" );
        QCoreApplication app( argc, argv );

        kDebug(7102) << "Starting tvshow slave " << getpid();

        if (argc != 4) {
            kError() << "Usage: kio_tvshow protocol domain-socket1 domain-socket2";
            exit(-1);
        }

        Nepomuk::TvshowProtocol slave(argv[2], argv[3]);
        slave.dispatchLoop();

        kDebug(7102) << "Tvshow slave Done";

        return 0;
    }
}
