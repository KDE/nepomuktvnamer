// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import Qt 4.7
import org.kde.plasma.graphicswidgets 0.1 as PlasmaWidgets
import org.kde.plasma.core 0.1 as PlasmaCore
import org.kde.plasma.graphicslayouts 4.7 as GraphicsLayouts
import org.kde.plasma.components 0.1 as PlasmaComponents

Item {
    width: 2000
    height: 3000

    PlasmaCore.DataSource {
          id: tvshowSource
          dataEngine: "nepomuktvshow"
          connectedSources: sources
      }

    Component {
        id: sectionHeading
        Rectangle {
            width: parent.width
            height: childrenRect.height
            color: "lightsteelblue"

            Text {
                text: section
                font.bold: true
            }
        }
    }

    ListView {
        section.property: "releaseGroup"
        section.delegate: sectionHeading
        anchors.fill: parent
        clip: true

        // sort by release date starting with the newest one
        // but put the already released episodes first
        model: PlasmaCore.SortFilterModel {
            sourceModel: PlasmaCore.SortFilterModel {
                sourceModel: PlasmaCore.DataModel {
                dataSource: tvshowSource
                }
                filterRole: "releaseGroup"
                filterRegExp: "New Episode"
                sortRole: "releaseDate"
                sortOrder: Qt.DescendingOrder
            }
            sortRole: "releaseGroup"
            sortOrder: Qt.AscendingOrder
        }

        delegate: PlasmaComponents.ListItem {
            Image {
                id: banner
                source: depiction
                height: 80
                fillMode: Image.PreserveAspectFit
                anchors.top: parent.top
                anchors.left: parent.left
            }
            Column {
                anchors.top: parent.top
                anchors.left: banner.right
                anchors.leftMargin: 5
                spacing: 2
                Text {
                    text: DataEngineSource
                    font.bold: true
                }
                Text {
                    text: seasonNumber + "x" + episodeNumber + " - " + title
                }
                Text {
                    text: "Released: " + Qt.formatDate(releaseDate, Qt.TextDate)
                }
            }
        }
    }
}
