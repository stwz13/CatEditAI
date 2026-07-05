import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: button

    property string symbol
    property bool buttonEnabled: true
    property bool active: false
    property color backgroundColor: "#5746A3"
    property color activeColor: "#9D8FE0"
    property color disabledColor: "#D8CEF8"
    property color symbolColor: "white"
    property color disabledSymbolColor: "#5B5273"
    property bool visualEnabled: buttonEnabled

    signal clicked
    signal pressed
    signal released

    width: Theme.itemSizeMedium
    height: width
    radius: width / 2
    color: !button.visualEnabled ? button.disabledColor
                                  : button.active ? button.activeColor : button.backgroundColor
    opacity: button.visualEnabled ? 1.0 : 0.65

    Label {
        anchors.centerIn: parent
        color: button.visualEnabled ? button.symbolColor : button.disabledSymbolColor
        font.pixelSize: Theme.fontSizeMedium
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: button.symbol
    }

    MouseArea {
        anchors.fill: parent
        enabled: button.buttonEnabled
        onClicked: button.clicked()
        onPressed: button.pressed()
        onReleased: button.released()
        onCanceled: button.released()
    }
}
