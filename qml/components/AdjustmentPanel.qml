import QtQuick 2.0
import Sailfish.Silica 1.0

Column {
    id: panel

    property bool actionsEnabled: true
    property color textColor: "#1E1833"
    property color secondaryTextColor: "#5C5480"
    property color primary: "#5746A3"
    property color softCardColor: "#F3EFFE"
    property color primaryForeground: "#FFFFFF"
    property string brightnessText
    property string contrastText
    property string saturationText
    property string applyText

    signal valuesChanged(int brightness, int contrast, int saturation)
    signal applyClicked

    property bool ready: false
    property bool suppressChanges: false
    property real gap: Theme.paddingSmall / 2
    property real applyButtonHeight: Math.min(Theme.itemSizeMedium * 0.58,
                                              Math.max(Theme.itemSizeMedium * 0.42,
                                                       height * 0.26))
    property real rowHeight: (height - applyButtonHeight - gap * 3) / 3

    spacing: gap

    function emitValues() {
        if (ready && actionsEnabled && !suppressChanges)
            valuesChanged(brightnessSlider.value, contrastSlider.value, saturationSlider.value)
    }

    Component.onCompleted: ready = true

    Row {
        width: parent.width
        height: panel.rowHeight
        spacing: Theme.paddingSmall

        Label {
            id: brightnessLabel
            width: parent.width * 0.30
            height: parent.height
            color: panel.textColor
            font.pixelSize: Theme.fontSizeExtraSmall
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            maximumLineCount: 1
            elide: Text.ElideRight
            text: panel.brightnessText
        }

        CompactSlider {
            id: brightnessSlider
            width: parent.width - brightnessLabel.width - parent.spacing
            height: parent.height
            minimumValue: -80
            maximumValue: 80
            stepSize: 5
            value: 0
            sliderEnabled: panel.actionsEnabled
            fillColor: panel.primary
            handleColor: panel.primary
            trackColor: panel.softCardColor
            onValueChanged: panel.emitValues()
        }
    }

    Row {
        width: parent.width
        height: panel.rowHeight
        spacing: Theme.paddingSmall

        Label {
            id: contrastLabel
            width: parent.width * 0.30
            height: parent.height
            color: panel.textColor
            font.pixelSize: Theme.fontSizeExtraSmall
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            maximumLineCount: 1
            elide: Text.ElideRight
            text: panel.contrastText
        }

        CompactSlider {
            id: contrastSlider
            width: parent.width - contrastLabel.width - parent.spacing
            height: parent.height
            minimumValue: -60
            maximumValue: 80
            stepSize: 5
            value: 0
            sliderEnabled: panel.actionsEnabled
            fillColor: panel.primary
            handleColor: panel.primary
            trackColor: panel.softCardColor
            onValueChanged: panel.emitValues()
        }
    }

    Row {
        width: parent.width
        height: panel.rowHeight
        spacing: Theme.paddingSmall

        Label {
            id: saturationLabel
            width: parent.width * 0.30
            height: parent.height
            color: panel.textColor
            font.pixelSize: Theme.fontSizeExtraSmall
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            maximumLineCount: 1
            elide: Text.ElideRight
            text: panel.saturationText
        }

        CompactSlider {
            id: saturationSlider
            width: parent.width - saturationLabel.width - parent.spacing
            height: parent.height
            minimumValue: -80
            maximumValue: 100
            stepSize: 5
            value: 0
            sliderEnabled: panel.actionsEnabled
            fillColor: panel.primary
            handleColor: panel.primary
            trackColor: panel.softCardColor
            onValueChanged: panel.emitValues()
        }
    }

    AppActionButton {
        width: parent.width
        height: panel.applyButtonHeight
        text: panel.applyText
        backgroundColor: panel.primary
        disabledColor: panel.softCardColor
        labelColor: panel.primaryForeground
        disabledLabelColor: panel.secondaryTextColor
        buttonEnabled: panel.actionsEnabled
        contentMargin: Theme.paddingSmall
        onClicked: {
            panel.applyClicked()
            panel.suppressChanges = true
            brightnessSlider.value = 0
            contrastSlider.value = 0
            saturationSlider.value = 0
            panel.suppressChanges = false
        }
    }
}
