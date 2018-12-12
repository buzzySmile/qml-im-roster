import QtQuick 2.0
import QtGraphicalEffects 1.0
import "common"

Rectangle {
    id: contactList
    property var background: String("#EBEDEE")
    property var highlightHover: String("#DDE0DF")
    property var highlightSelection: String("#757676")
    color: background
    clip: true

    signal currentContactChange(var id)

    ListView {
        id: listView
        anchors.fill: parent
        anchors.topMargin: 5

        opacity: 1
        boundsBehavior: Flickable.DragAndOvershootBounds
        maximumFlickVelocity: 2500
        snapMode: ListView.SnapToItem

        model: contactsModel
        delegate: Contact {
            contactName: name
            contactPresence: presenceTime
            avatarUrl: avatar
            online: isOnline

            width: listView.width
            height: 55
            color: listView.currentIndex === index ? "transparent" : (mouseArea.containsMouse ? highlightHover : background)
            backgroundColor: listView.currentIndex === index ? "transparent" : (mouseArea.containsMouse ? highlightHover : background)
            separatorColor: listView.currentIndex === index ? "transparent" : highlightHover
            smooth: mouseArea.containsMouse

            MouseArea {
                id: mouseArea
                anchors.left: parent.left
                anchors.fill: parent

                hoverEnabled: true

                onClicked: {
                    listView.currentIndex = index
                    contactList.currentContactChange(contactsModel.get(index).id)
                }

                onDoubleClicked:{
                    console.log(contactsModel.get(index).id, 'double clicked');
                }
            }
        }

        highlight:
            Rectangle {
                color: highlightSelection
                radius: 3

                anchors.fill: listView.currentItem

                //width: listView.width; height: 40;
                //y: listView.currentItem.y;
                //Behavior on y { SpringAnimation { spring: 1; damping: 0.1 } }
            }
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.NoHighlightRange
    }
}
