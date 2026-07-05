import QtQuick 2.0
import Sailfish.Silica 1.0

Column {
    id: panel

    property string resultSource
    property string originalSource
    property bool canUndo: false
    property bool busy: false
    property color primary: "#5746A3"
    property color accent: "#9D8FE0"
    property color cardColor: "#FFFFFF"
    property color cardBorder: "#B8A9E8"
    property color statusColor: "#5C5480"
    property string statusText

    signal undoClicked
    signal fullscreenClicked

    spacing: Theme.paddingSmall

    Rectangle {
        id: frame
        width: parent.width
        height: panel.height - controls.height - statusLine.height - parent.spacing * 2
        radius: Theme.paddingMedium
        color: panel.cardColor
        border.color: panel.cardBorder
        border.width: 1

        property bool showOriginal: false
        property string visibleSource: showOriginal && panel.originalSource.length > 0
                                       ? panel.originalSource : panel.resultSource

        Image {
            anchors.fill: parent
            anchors.margins: Theme.paddingMedium
            source: frame.visibleSource
            fillMode: Image.PreserveAspectFit
            cache: false
        }

        BusyIndicator {
            anchors.centerIn: parent
            running: panel.busy
            visible: panel.busy
        }
    }

    Label {
        id: statusLine
        width: parent.width
        color: panel.statusColor
        font.pixelSize: Theme.fontSizeExtraSmall
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        maximumLineCount: 2
        visible: panel.busy || panel.statusText.length > 0
        height: visible ? implicitHeight : 0
        opacity: visible ? 1.0 : 0.0
        text: panel.statusText
    }

    Row {
        id: controls
        anchors.horizontalCenter: parent.horizontalCenter
        height: Theme.itemSizeMedium
        spacing: Theme.paddingLarge

        IconCircleButton {
            symbol: "↶"
            buttonEnabled: panel.canUndo && !panel.busy
            visualEnabled: panel.canUndo
            backgroundColor: panel.primary
            activeColor: panel.accent
            onClicked: panel.undoClicked()
        }

        IconCircleButton {
            symbol: "◐"
            buttonEnabled: !panel.busy
            visualEnabled: true
            active: frame.showOriginal
            backgroundColor: panel.primary
            activeColor: panel.accent
            onPressed: frame.showOriginal = true
            onReleased: frame.showOriginal = false
        }

        IconCircleButton {
            symbol: "⛶"
            buttonEnabled: !panel.busy
            visualEnabled: true
            backgroundColor: panel.primary
            activeColor: panel.accent
            onClicked: panel.fullscreenClicked()
        }
    }
}
