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

#ifndef _NEPOMUK_KIO_TVSHOW_H_
#define _NEPOMUK_KIO_TVSHOW_H_

#include <kio/slavebase.h>

#include <QtCore/QDate>

namespace Nepomuk2 {
    class TvshowProtocol : public KIO::SlaveBase
    {
    public:
        TvshowProtocol( const QByteArray& poolSocket, const QByteArray& appSocket );
        virtual ~TvshowProtocol();

        void listDir( const KUrl& url );
        void mkdir( const KUrl &url, int permissions );
        void get( const KUrl& url );
        void put( const KUrl& url, int permissions, KIO::JobFlags flags );
        void copy( const KUrl& src, const KUrl& dest, int permissions, KIO::JobFlags flags );
        void rename( const KUrl& src, const KUrl& dest, KIO::JobFlags flags );
        void del( const KUrl& url, bool isfile );
        void mimetype( const KUrl& url );
        void stat( const KUrl& url );
    };
}

#endif
