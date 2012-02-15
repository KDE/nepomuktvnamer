#!/usr/bin/python
# -*- coding: utf-8 -*-

## This file is part of the Nepomuk KDE project.
## Copyright (C) 2012 Sebastian Trueg <trueg@kde.org>
##
## This library is free software; you can redistribute it and/or
## modify it under the terms of the GNU Lesser General Public
## License as published by the Free Software Foundation; either
## version 2.1 of the License, or (at your option) version 3, or any
## later version accepted by the membership of KDE e.V. (or its
## successor approved by the membership of KDE e.V.), which shall
## act as a proxy defined in Section 6 of version 3 of the license.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public
## License along with this library.  If not, see <http://www.gnu.org/licenses/>.

from tvdb_api import Tvdb
from PyKDE4.soprano import Soprano
from PyQt4 import QtCore
from datetime import date, datetime
import sys

t = Tvdb()

# constants used in checkNewEpisode
_CNE_FINISHED = 0
_CNE_AIRING = 1
_CNE_WAITING = 2

# string lists filled by checkNewEpisode
newEpisodes = []
upcomingEpisodes = []

def prettyPrintDate(d):
    if d == None:
        return 'unknown date'
    else:
        return datetime.strptime(str(d), '%Y-%m-%d').strftime('%d %B %Y')

def checkNewEpisode(name, s, e):
    result = _CNE_AIRING
    series = t[name]
    season = None
    if s in series and e+1 in series[s]:
        season = series[s]
        episode = season[e+1]

    elif s+1 in series and 1 in series[s+1]:
        season = series[s+1]
        episode = season[1]

    if not season is None:
        firstaired = episode['firstaired']
        if firstaired < str(date.today()):
            if firstaired != None:
                newEpisodes.append('%s - "%s" (%sx%s) first aired %s.' % (name, episode['episodename'], episode['seasonnumber'].zfill(2), episode['episodenumber'].zfill(2), prettyPrintDate(firstaired)))

            else:
                result = _CNE_WAITING

        else:
            upcomingEpisodes.append('%s - "%s" (%sx%s) will air %s.' % (name, episode['episodename'], episode['seasonnumber'].zfill(2), episode['episodenumber'].zfill(2), prettyPrintDate(firstaired)))

    else:
        result = _CNE_FINISHED

    return result


def main():
    app = QtCore.QCoreApplication(sys.argv)
    
    noNewEpisodes = []
    waitingForEmision = []

    model = Soprano.Client.DBusModel('org.kde.NepomukStorage', '/org/soprano/Server/models/main')
    it = model.executeQuery('select ?l bif:lower(?l) AS ?l_sort max(1000*?sn + ?en) as ?last where { ?r a nmm:TVSeries. ?r nie:title ?l . ?e nmm:series ?r . ?e nmm:episodeNumber ?en . ?e nmm:season ?sn . } ORDER BY ?l_sort', Soprano.Query.QueryLanguageSparql)
    while it.next():
        season = it['last'].literal().toInt() / 1000
        episode = it['last'].literal().toInt() % 1000
        name = it['l'].toString().toLatin1().data()
        result = checkNewEpisode(name, season, episode)

        if result == 0:
            noNewEpisodes += [name]

        elif result == 2:
            waitingForEmision += [name]

    print "New Episodes:\n\t" + "\t".join([s + '\n' for s in newEpisodes])

    print "Upcoming Episodes:\n\t" + "\t".join([s + '\n' for s in upcomingEpisodes])

    print "Waiting for new emision date:\n\t" + ", ".join(waitingForEmision)

    print "\nNo new episodes for:\n\t" + ", ".join(noNewEpisodes)

if __name__ == "__main__":
    main()
