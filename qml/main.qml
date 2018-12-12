import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.4
import "styles"

ApplicationWindow {
    id: root

    minimumWidth: 320
    minimumHeight: 600

    visible: true

    title: qsTr("IM list QML example")
    color: "white"

    TabView {
        id: tabView
        anchors.fill: parent
        anchors.margins: 4
        currentIndex: 0

        Tab {
            title: qsTr("Contacts")
            ContactsList { anchors.fill: parent }
        }

        Tab {
            title: qsTr("Chats")
            Item {}
        //  Rectangle { color: "blue" }
        }

        style: MainTabStyle { tabRadius: 5 }

        Keys.onEscapePressed: {
            console.log("Escape pressed!");
            event.accepted = true;
        }
    }
}

