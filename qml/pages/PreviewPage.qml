import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    allowedOrientations: Orientation.All

    property string resultSource
    property string originalSource
    property color primary: "#5746A3"
    property color accent: "#9D8FE0"

    Rectangle {
        anchors.fill: parent
        color: "#3F326E"
    }

    Image {
        id: previewImage
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: controls.top
            margins: Theme.paddingMedium
        }
        source: controls.showOriginal && page.originalSource.length > 0
                ? page.originalSource : page.resultSource
        fillMode: Image.PreserveAspectFit
        cache: false
    }

    Row {
        id: controls

        property bool showOriginal: false

        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: Theme.paddingLarge
        }
        height: Theme.itemSizeMedium
        spacing: Theme.paddingLarge

        IconCircleButton {
            symbol: "◐"
            buttonEnabled: page.originalSource.length > 0
            active: controls.showOriginal
            backgroundColor: page.primary
            activeColor: page.accent
            onPressed: controls.showOriginal = true
            onReleased: controls.showOriginal = false
        }
    }
}
