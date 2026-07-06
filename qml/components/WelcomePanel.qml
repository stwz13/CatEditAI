import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: welcome

    property color textColor: "#1E1833"
    property color primary: "#5746A3"
    property color accent: "#8B7FD4"
    property color softCardColor: "#F3EFFE"
    property color cardColor: "#FFFFFF"
    property bool actionsEnabled: true
    property string galleryText
    property string filesText

    signal galleryClicked
    signal filesClicked

    Row {
        anchors.centerIn: parent
        width: Math.min(parent.width - 2 * Theme.horizontalPageMargin, Theme.itemSizeExtraLarge * 6)
        spacing: Theme.paddingMedium

        Rectangle {
            width: (parent.width - parent.spacing) / 2
            height: Theme.itemSizeLarge + Theme.paddingLarge
            radius: Theme.paddingMedium
            color: galleryArea.pressed ? welcome.softCardColor : welcome.cardColor
            border.color: welcome.primary
            border.width: 2

            Column {
                anchors.centerIn: parent
                spacing: Theme.paddingSmall / 2

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: welcome.primary
                    font.pixelSize: Theme.fontSizeLarge
                    text: "▦"
                }

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: welcome.textColor
                    font.pixelSize: Theme.fontSizeSmall
                    font.bold: true
                    text: welcome.galleryText
                }
            }

            MouseArea {
                id: galleryArea
                anchors.fill: parent
                enabled: welcome.actionsEnabled
                onClicked: welcome.galleryClicked()
            }
        }

        Rectangle {
            width: (parent.width - parent.spacing) / 2
            height: Theme.itemSizeLarge + Theme.paddingLarge
            radius: Theme.paddingMedium
            color: filesArea.pressed ? welcome.softCardColor : welcome.cardColor
            border.color: welcome.accent
            border.width: 2

            Column {
                anchors.centerIn: parent
                spacing: Theme.paddingSmall / 2

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: welcome.accent
                    font.pixelSize: Theme.fontSizeLarge
                    text: "⌁"
                }

                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: welcome.textColor
                    font.pixelSize: Theme.fontSizeSmall
                    font.bold: true
                    text: welcome.filesText
                }
            }

            MouseArea {
                id: filesArea
                anchors.fill: parent
                enabled: welcome.actionsEnabled
                onClicked: welcome.filesClicked()
            }
        }
    }
}
