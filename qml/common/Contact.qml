import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    property string contactName
    property string contactPresence
    property string avatarUrl
    property bool online
    property var backgroundColor: String("#EBEDEE")
    property var separatorColor: String("#DDE0DF")

    property var offlineColor: String("#FF645F")
    property var onlineColor: String("#5ABE50")
    property var presenceTextColor: String("#8D8E8E")

    Item {
        id: avatarItem
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 12
        height: parent.height - 14
        width: height

        Image {
            id: avatarImage
            width: parent.width;  height: parent.height
            sourceSize: Qt.size(parent.width, parent.height)

            smooth: true
            visible: false
            // asynchronous: true
            source: avatarUrl
        }

        Rectangle {
            id: mask

            width: parent.width;  height: parent.height
            radius: parent.height/2
            smooth: true
            visible: false
        }

        OpacityMask {
            anchors.fill: avatarImage
            source: avatarImage
            maskSource: mask
        }
    }

    Item {
        width: 12;  height: width
        anchors.right: avatarItem.right
        anchors.bottom: avatarItem.bottom
        Rectangle {
            width: parent.width;  height: width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            radius: width/2
            color: backgroundColor
        }
        Rectangle {
            width: parent.width-4;  height: width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            radius: width/2
            color: online ? onlineColor : offlineColor
        }
    }

    Item {
        id: contactText
        height: parent.height
        anchors.left: avatarItem.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 12
        Text {
            id: contactNameText
            width: parent.width;  height: parent.height/2 - 4
            anchors.top: parent.top
            anchors.topMargin: 2
            verticalAlignment: Text.AlignVCenter
            text: contactName
        }
        Text {
            id: contactPresenceText
            width: parent.width;  height: parent.height/2 - 8
            anchors.top: contactNameText.bottom
            verticalAlignment: Text.AlignVCenter
            font.pointSize: contactNameText.font.pointSize-1
            color: presenceTextColor
            text: contactPresence
        }
        Rectangle {
            id: separatorLine
            width: parent.width;  height: 1
            color: separatorColor
            anchors.bottom: parent.bottom
        }
    }
}
