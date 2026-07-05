import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: slider

    property real minimumValue: -100
    property real maximumValue: 100
    property real stepSize: 5
    property real value: 0
    property bool sliderEnabled: true
    property color trackColor: "#D8CEF8"
    property color fillColor: "#5746A3"
    property color handleColor: "#5746A3"

    function clamp(rawValue) {
        return Math.max(minimumValue, Math.min(maximumValue, rawValue))
    }

    function stepped(rawValue) {
        return Math.round(rawValue / stepSize) * stepSize
    }

    function setFromPosition(pos) {
        if (track.width <= 0)
            return

        var normalized = Math.max(0, Math.min(1, pos / track.width))
        value = clamp(stepped(minimumValue + normalized * (maximumValue - minimumValue)))
    }

    Rectangle {
        id: track
        anchors {
            left: parent.left
            right: valueLabel.left
            rightMargin: Theme.paddingSmall
            verticalCenter: parent.verticalCenter
        }
        height: Math.max(4, Theme.paddingSmall / 2)
        radius: height / 2
        color: slider.trackColor
        opacity: slider.sliderEnabled ? 1.0 : 0.55

        Rectangle {
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
            }
            width: handle.x + handle.width / 2
            height: parent.height
            radius: parent.radius
            color: slider.fillColor
        }

        Rectangle {
            id: handle
            width: Theme.paddingLarge * 0.9
            height: width
            radius: width / 2
            color: slider.handleColor
            y: (track.height - height) / 2
            x: Math.max(0, (track.width - width) *
               ((slider.value - slider.minimumValue) /
                (slider.maximumValue - slider.minimumValue)))
        }

        MouseArea {
            anchors.fill: parent
            enabled: slider.sliderEnabled
            onPressed: slider.setFromPosition(mouse.x)
            onPositionChanged: if (pressed) slider.setFromPosition(mouse.x)
        }
    }

    Label {
        id: valueLabel
        anchors {
            right: parent.right
            verticalCenter: parent.verticalCenter
        }
        width: Theme.itemSizeMedium * 0.62
        color: slider.fillColor
        font.pixelSize: Theme.fontSizeExtraSmall
        font.bold: true
        horizontalAlignment: Text.AlignRight
        text: slider.value > 0 ? "+" + slider.value : slider.value
    }
}
