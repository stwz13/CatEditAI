import QtQuick 2.0
import Sailfish.Silica 1.0

Flickable {
    id: strip

    property bool actionsEnabled: true
    property bool visualEnabled: actionsEnabled
    property color primary: "#5746A3"
    property color accent: "#8B7FD4"
    property color lavender: "#9D8FE0"
    property color lilac: "#C4B9F2"
    property color mint: "#7EC8D4"
    property color textColor: "#1E1833"
    property color softCardColor: "#F3EFFE"
    property color secondaryTextColor: "#5C5480"
    property color primaryForeground: "#FFFFFF"
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

    height: Theme.itemSizeMedium * 0.78
    contentWidth: row.width
    contentHeight: height
    flickableDirection: Flickable.HorizontalFlick
    boundsBehavior: Flickable.DragOverBounds
    clip: true

    Row {
        id: row
        y: Math.max(0, (strip.height - height) / 2)
        height: Theme.itemSizeMedium * 0.72
        spacing: Theme.paddingSmall

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 1.05
            height: parent.height
            text: strip.backgroundText
            backgroundColor: strip.primary
            disabledColor: strip.softCardColor
            labelColor: strip.primaryForeground
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.backgroundClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.78
            height: parent.height
            text: strip.enhanceText
            backgroundColor: strip.accent
            disabledColor: strip.softCardColor
            labelColor: strip.primaryForeground
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.enhanceClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.72
            height: parent.height
            text: strip.styleText
            backgroundColor: strip.mint
            disabledColor: strip.softCardColor
            labelColor: strip.textColor
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.styleClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.62
            height: parent.height
            text: strip.bwText
            backgroundColor: strip.lavender
            disabledColor: strip.softCardColor
            labelColor: strip.primaryForeground
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.bwClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.70
            height: parent.height
            text: strip.sepiaText
            backgroundColor: strip.lilac
            disabledColor: strip.softCardColor
            labelColor: strip.textColor
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.sepiaClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.62
            height: parent.height
            text: strip.blurText
            backgroundColor: strip.accent
            disabledColor: strip.softCardColor
            labelColor: strip.primaryForeground
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.blurClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.82
            height: parent.height
            text: strip.sharpenText
            backgroundColor: strip.lavender
            disabledColor: strip.softCardColor
            labelColor: strip.primaryForeground
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.sharpenClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.66
            height: parent.height
            text: strip.edgesText
            backgroundColor: strip.mint
            disabledColor: strip.softCardColor
            labelColor: strip.textColor
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.edgesClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.84
            height: parent.height
            text: strip.cartoonText
            backgroundColor: strip.primary
            disabledColor: strip.softCardColor
            labelColor: strip.primaryForeground
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.cartoonClicked()
        }

        AppActionButton {
            width: Theme.itemSizeExtraLarge * 0.72
            height: parent.height
            text: strip.invertText
            backgroundColor: strip.mint
            disabledColor: strip.softCardColor
            labelColor: strip.textColor
            disabledLabelColor: strip.secondaryTextColor
            buttonEnabled: strip.actionsEnabled
            visualEnabled: strip.visualEnabled
            labelSize: Theme.fontSizeExtraSmall
            contentMargin: Theme.paddingSmall
            onClicked: strip.invertClicked()
        }
    }
}
