import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: tray

    property bool actionsEnabled: true
    property bool visualEnabled: actionsEnabled
    property color primary: "#5746A3"
    property color accent: "#8B7FD4"
    property color lilac: "#C4B9F2"
    property color lavender: "#9D8FE0"
    property color mint: "#7EC8D4"
    property color cardColor: "#FFFFFF"
    property color textColor: "#1E1833"
    property color softCardColor: "#F3EFFE"
    property color secondaryTextColor: "#5C5480"
    property color cardBorder: "#B8A9E8"
    property color primaryForeground: "#FFFFFF"
    property string filtersTitle
    property string correctionTitle
    property string backgroundText
    property string enhanceText
    property string styleText
    property string bwText
    property string sepiaText
    property string blurText
    property string sharpenText
    property string edgesText
    property string cartoonText
    property string invertText
    property string brightnessText
    property string contrastText
    property string saturationText
    property string applyText

    property int mode: 0

    signal backgroundClicked
    signal enhanceClicked
    signal styleClicked
    signal bwClicked
    signal sepiaClicked
    signal blurClicked
    signal sharpenClicked
    signal edgesClicked
    signal cartoonClicked
    signal invertClicked
    signal correctionChanged(int brightness, int contrast, int saturation)
    signal correctionApplied

    radius: Theme.paddingMedium
    color: tray.cardColor
    border.color: tray.cardBorder
    border.width: 1

    Column {
        anchors.fill: parent
        anchors.margins: Theme.paddingSmall
        spacing: Theme.paddingSmall

        Row {
            width: parent.width
            height: Theme.itemSizeMedium * 0.48
            spacing: Theme.paddingSmall / 2

            Rectangle {
                width: (parent.width - parent.spacing) / 2
                height: parent.height
                radius: height / 2
                color: tray.mode === 0 ? tray.primary : tray.softCardColor
                border.color: tray.mode === 0 ? tray.primary : tray.cardBorder
                border.width: 1

                Label {
                    anchors.centerIn: parent
                    color: tray.mode === 0 ? tray.primaryForeground : tray.textColor
                    font.pixelSize: Theme.fontSizeExtraSmall
                    font.bold: true
                    text: tray.filtersTitle
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: tray.mode = 0
                }
            }

            Rectangle {
                width: (parent.width - parent.spacing) / 2
                height: parent.height
                radius: height / 2
                color: tray.mode === 1 ? tray.primary : tray.softCardColor
                border.color: tray.mode === 1 ? tray.primary : tray.cardBorder
                border.width: 1

                Label {
                    anchors.centerIn: parent
                    color: tray.mode === 1 ? tray.primaryForeground : tray.textColor
                    font.pixelSize: Theme.fontSizeExtraSmall
                    font.bold: true
                    text: tray.correctionTitle
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: tray.mode = 1
                }
            }
        }

        FilterStrip {
            width: parent.width
            height: tray.mode === 0 ? Theme.itemSizeMedium * 0.78 : 0
            visible: tray.mode === 0
            actionsEnabled: tray.actionsEnabled
            visualEnabled: tray.visualEnabled
            primary: tray.primary
            accent: tray.accent
            lilac: tray.lilac
            lavender: tray.lavender
            mint: tray.mint
            textColor: tray.textColor
            softCardColor: tray.softCardColor
            secondaryTextColor: tray.secondaryTextColor
            primaryForeground: tray.primaryForeground
            backgroundText: tray.backgroundText
            enhanceText: tray.enhanceText
            styleText: tray.styleText
            bwText: tray.bwText
            sepiaText: tray.sepiaText
            blurText: tray.blurText
            sharpenText: tray.sharpenText
            edgesText: tray.edgesText
            cartoonText: tray.cartoonText
            invertText: tray.invertText
            onBackgroundClicked: tray.backgroundClicked()
            onEnhanceClicked: tray.enhanceClicked()
            onStyleClicked: tray.styleClicked()
            onBwClicked: tray.bwClicked()
            onSepiaClicked: tray.sepiaClicked()
            onBlurClicked: tray.blurClicked()
            onSharpenClicked: tray.sharpenClicked()
            onEdgesClicked: tray.edgesClicked()
            onCartoonClicked: tray.cartoonClicked()
            onInvertClicked: tray.invertClicked()
        }

        AdjustmentPanel {
            width: parent.width
            height: tray.mode === 1 ? parent.height - y : 0
            visible: tray.mode === 1
            actionsEnabled: tray.actionsEnabled
            textColor: tray.textColor
            secondaryTextColor: tray.secondaryTextColor
            primary: tray.primary
            softCardColor: tray.softCardColor
            primaryForeground: tray.primaryForeground
            brightnessText: tray.brightnessText
            contrastText: tray.contrastText
            saturationText: tray.saturationText
            applyText: tray.applyText
            onValuesChanged: tray.correctionChanged(brightness, contrast, saturation)
            onApplyClicked: tray.correctionApplied()
        }
    }
}
