import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: button

    property string text
    property color backgroundColor: "#5746A3"
    property color disabledColor: "#F3EFFE"
    property color labelColor: "white"
    property color disabledLabelColor: "#5C5480"
    property color borderColor: "#B8A9E8"
    property bool buttonEnabled: true
    property bool visualEnabled: buttonEnabled
    property int labelSize: Theme.fontSizeExtraSmall
    property real contentMargin: Theme.paddingMedium

    signal clicked

    height: Theme.itemSizeLarge
    radius: Math.min(Theme.paddingMedium, height / 2)
    color: button.visualEnabled ? button.backgroundColor : button.disabledColor
    border.color: button.visualEnabled ? Qt.rgba(1, 1, 1, 0.12) : button.borderColor
    border.width: 1
    opacity: button.visualEnabled ? 1.0 : 0.72

    Label {
        anchors.centerIn: parent
        width: parent.width - 2 * button.contentMargin
        color: button.visualEnabled ? button.labelColor : button.disabledLabelColor
        font.pixelSize: button.labelSize
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        elide: Text.ElideRight
        maximumLineCount: 1
        text: button.text
    }

    MouseArea {
        anchors.fill: parent
        enabled: button.buttonEnabled
        onClicked: button.clicked()
    }
}
