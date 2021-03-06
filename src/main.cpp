/*
   Copyright (C) 2011-2012 by Sebastian Trueg <trueg at kde.org>

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

#include <KApplication>
#include <KCmdLineArgs>
#include <KAboutData>
#include <KUrl>

#include "tvnamer.h"
#include "nepomuktvnamer-config.h"

int main( int argc, char *argv[] )
{
    KAboutData aboutData( "nepomuktvnamer",
                          "nepomuktvnamer",
                          ki18n("Nepomuk Shell"),
                          NEPOMUKTVNAMER_VERSION,
                          ki18n("The Nepomuk TV Namer tries to extract TV Show name, season, and episode from the file name of the given file (or all files in a given directory).\n"
                                "If found fetches details from thetvdb.com and stores the results in Nepomuk.\n"
                                "If no TV Show information could be extracted from the filename -1 is returned. If communication with Nepomuk failed -2 is returned."),
                          KAboutData::License_GPL,
                          ki18n("(c) 2011-2012, Sebastian Trüg"),
                          KLocalizedString(),
                          "http://nepomuk.kde.org" );
    aboutData.addAuthor(ki18n("Sebastian Trüg"), ki18n("Maintainer"), "trueg@kde.org");

    aboutData.setProgramIconName( QLatin1String( "nepomuk" ) );

    KCmdLineArgs::init( argc, argv, &aboutData );
    KCmdLineOptions options;
    options.add("quiet").add("q", ki18n("Try to be quiet by not showing any error message boxes to the user."));
    options.add("+uri", ki18n("The URL(s) to the video file(s) to annotate."));
    KCmdLineArgs::addCmdLineOptions( options );
    KCmdLineArgs* args = KCmdLineArgs::parsedArgs();

    KApplication app;
    QApplication::setQuitOnLastWindowClosed( false );

    TVNamer tvnamer;
    tvnamer.setQuiet(args->isSet("quiet"));
    if ( args->count() ) {
        KUrl::List urls;
        for(int i = 0; i < args->count(); ++i)
            urls << args->url(i);
        QMetaObject::invokeMethod(&tvnamer, "lookupFiles", Qt::QueuedConnection, Q_ARG(KUrl::List, urls));
        return app.exec();
    }
    else {
        return 1;
    }
}
