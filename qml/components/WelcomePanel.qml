import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: welcome

    property color textColor: "#1E1833"
    property color secondaryTextColor: "#5C5480"
    property color primary: "#5746A3"
    property color accent: "#8B7FD4"
    property color softCardColor: "#F3EFFE"
    property color cardColor: "#FFFFFF"
    property color cardBorder: "#B8A9E8"
    property bool actionsEnabled: true
    property string titleText
    property string promptText
    property string galleryText
    property string filesText

    signal galleryClicked
    signal filesClicked

    Column {
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: -Theme.paddingLarge
        }
        width: Math.min(parent.width - 2 * Theme.horizontalPageMargin, Theme.itemSizeExtraLarge * 5.5)
        spacing: Theme.paddingLarge

        Column {
            width: parent.width
            spacing: Theme.paddingMedium

            Label {
                width: parent.width
                color: welcome.textColor
                font.pixelSize: Theme.fontSizeExtraLarge
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                text: welcome.titleText
            }

            Rectangle {
                anchors.horizontalCenter: parent.horizontalCenter
                width: Theme.itemSizeLarge * 0.55
                height: 3
                radius: height / 2
                color: welcome.primary
                opacity: 0.85
            }

            Label {
                width: parent.width
                color: welcome.secondaryTextColor
                font.pixelSize: Theme.fontSizeMedium
                horizontalAlignment: Text.AlignHCenter
                text: welcome.promptText
            }
        }

        Rectangle {
            width: parent.width
            radius: Theme.paddingLarge
            color: welcome.cardColor
            border.color: welcome.cardBorder
            border.width: 1

            Column {
                width: parent.width

                Item {
                    width: parent.width
                    height: Theme.itemSizeLarge + Theme.paddingSmall

                    Rectangle {
                        anchors.fill: parent
                        anchors.margins: Theme.paddingSmall / 2
                        radius: Theme.paddingMedium
                        color: galleryArea.pressed ? welcome.softCardColor : "transparent"
                    }

                    Rectangle {
                        id: galleryIcon
                        anchors {
                            left: parent.left
                            leftMargin: Theme.paddingLarge
                            verticalCenter: parent.verticalCenter
                        }
                        width: Theme.itemSizeMedium * 0.72
                        height: width
                        radius: width / 2
                        color: welcome.softCardColor

                        Label {
                            anchors.centerIn: parent
                            color: welcome.primary
                            font.pixelSize: Theme.fontSizeSmall
                            text: "▦"
                        }
                    }

                    Label {
                        anchors {
                            left: galleryIcon.right
                            right: galleryChevron.left
                            leftMargin: Theme.paddingMedium
                            rightMargin: Theme.paddingSmall
                            verticalCenter: parent.verticalCenter
                        }
                        color: welcome.textColor
                        font.pixelSize: Theme.fontSizeMedium
                        elide: Text.ElideRight
                        text: welcome.galleryText
                    }

                    Label {
                        id: galleryChevron
                        anchors {
                            right: parent.right
                            rightMargin: Theme.paddingLarge
                            verticalCenter: parent.verticalCenter
                        }
                        color: welcome.secondaryTextColor
                        font.pixelSize: Theme.fontSizeLarge
                        text: "›"
                    }

                    MouseArea {
                        id: galleryArea
                        anchors.fill: parent
                        enabled: welcome.actionsEnabled
                        onClicked: welcome.galleryClicked()
                    }
                }

                Rectangle {
                    width: parent.width - Theme.paddingLarge * 2
                    height: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: welcome.cardBorder
                    opacity: 0.55
                }

                Item {
                    width: parent.width
                    height: Theme.itemSizeLarge + Theme.paddingSmall

                    Rectangle {
                        anchors.fill: parent
                        anchors.margins: Theme.paddingSmall / 2
                        radius: Theme.paddingMedium
                        color: filesArea.pressed ? welcome.softCardColor : "transparent"
                    }

                    Rectangle {
                        id: filesIcon
                        anchors {
                            left: parent.left
                            leftMargin: Theme.paddingLarge
                            verticalCenter: parent.verticalCenter
                        }
                        width: Theme.itemSizeMedium * 0.72
                        height: width
                        radius: width / 2
                        color: welcome.softCardColor

                        Label {
                            anchors.centerIn: parent
                            color: welcome.accent
                            font.pixelSize: Theme.fontSizeSmall
                            text: "⌁"
                        }
                    }

                    Label {
                        anchors {
                            left: filesIcon.right
                            right: filesChevron.left
                            leftMargin: Theme.paddingMedium
                            rightMargin: Theme.paddingSmall
                            verticalCenter: parent.verticalCenter
                        }
                        color: welcome.textColor
                        font.pixelSize: Theme.fontSizeMedium
                        elide: Text.ElideRight
                        text: welcome.filesText
                    }

                    Label {
                        id: filesChevron
                        anchors {
                            right: parent.right
                            rightMargin: Theme.paddingLarge
                            verticalCenter: parent.verticalCenter
                        }
                        color: welcome.secondaryTextColor
                        font.pixelSize: Theme.fontSizeLarge
                        text: "›"
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
    }
}
