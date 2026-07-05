import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Pickers 1.0
import "../components"

Page {
    id: page
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    property string selectedPath
    property string selectedFileName

    property color pageGradientTop: "#C4B9F2"
    property color pageGradientBottom: "#E8E2FA"
    property color primary: "#5746A3"
    property color accent: "#8B7FD4"
    property color lilac: "#C4B9F2"
    property color lavender: "#9D8FE0"
    property color mint: "#7EC8D4"
    property color cardColor: "#FFFFFF"
    property color softCardColor: "#F3EFFE"
    property color cardBorder: "#B8A9E8"
    property color textColor: "#1E1833"
    property color secondaryTextColor: "#5C5480"
    property color primaryForeground: "#FFFFFF"

    function processSelectedContent(properties) {
        if (!properties || !properties.filePath)
            return

        selectedPath = properties.filePath
        selectedFileName = properties.fileName || ""
        imageProcessor.process(selectedPath)
    }

    function openFullscreenPreview() {
        if (!imageProcessor.hasImage)
            return

        pageStack.push(Qt.resolvedUrl("PreviewPage.qml"), {
                           resultSource: imageProcessor.resultSource,
                           originalSource: imageProcessor.originalSource
                       })
    }

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: page.pageGradientTop }
            GradientStop { position: 1.0; color: page.pageGradientBottom }
        }
    }

    SilicaFlickable {
        objectName: "flickable"
        anchors.fill: parent
        contentHeight: height

        PullDownMenu {
            MenuItem {
                text: qsTr("Choose from gallery")
                enabled: !imageProcessor.busy
                onClicked: pageStack.push(imagePickerComponent)
            }

            MenuItem {
                text: qsTr("Choose from files")
                enabled: !imageProcessor.busy
                onClicked: pageStack.push(filePickerComponent)
            }

            MenuItem {
                text: qsTr("Export to gallery")
                enabled: imageProcessor.hasImage && !imageProcessor.busy
                onClicked: imageProcessor.exportResult()
            }

            MenuItem {
                text: qsTr("Reset to original")
                enabled: imageProcessor.hasImage && !imageProcessor.busy
                onClicked: imageProcessor.reset()
            }

            MenuItem {
                text: qsTr("Choose another photo")
                enabled: !imageProcessor.busy
                onClicked: pageStack.push(imagePickerComponent)
            }
        }

        Item {
            id: workspace
            width: parent.width
            height: page.height

            WelcomePanel {
                anchors.fill: parent
                visible: !imageProcessor.hasImage
                actionsEnabled: !imageProcessor.busy
                textColor: page.textColor
                secondaryTextColor: page.secondaryTextColor
                primary: page.primary
                accent: page.accent
                softCardColor: page.softCardColor
                cardColor: page.cardColor
                cardBorder: page.cardBorder
                titleText: qsTr("CatEdit AI")
                promptText: qsTr("Choose a photo")
                galleryText: qsTr("Gallery")
                filesText: qsTr("Files")
                onGalleryClicked: pageStack.push(imagePickerComponent)
                onFilesClicked: pageStack.push(filePickerComponent)
            }

            Item {
                id: editorView
                anchors.fill: parent
                visible: imageProcessor.hasImage

                EditingTray {
                    id: editingTray
                    objectName: "editingTray"
                    anchors {
                        left: parent.left
                        right: parent.right
                        bottom: parent.bottom
                        margins: Theme.horizontalPageMargin
                        bottomMargin: Theme.paddingMedium
                    }
                    height: Math.min(page.height * 0.28, Theme.itemSizeExtraLarge * 2.2)
                    actionsEnabled: !imageProcessor.busy
                    visualEnabled: true
                    primary: page.primary
                    accent: page.accent
                    lilac: page.lilac
                    lavender: page.lavender
                    mint: page.mint
                    cardColor: page.cardColor
                    textColor: page.textColor
                    softCardColor: page.softCardColor
                    secondaryTextColor: page.secondaryTextColor
                    cardBorder: page.cardBorder
                    primaryForeground: page.primaryForeground
                    filtersTitle: qsTr("Filters")
                    correctionTitle: qsTr("Adjust")
                    backgroundText: qsTr("Background")
                    enhanceText: qsTr("Auto")
                    styleText: qsTr("AI Style")
                    bwText: qsTr("B/W")
                    sepiaText: qsTr("Sepia")
                    blurText: qsTr("Blur")
                    sharpenText: qsTr("Sharpen")
                    edgesText: qsTr("Edges")
                    cartoonText: qsTr("Cartoon")
                    invertText: qsTr("Invert")
                    brightnessText: qsTr("Light")
                    contrastText: qsTr("Contrast")
                    saturationText: qsTr("Color")
                    applyText: qsTr("Apply")
                    onBackgroundClicked: imageProcessor.removeBackground()
                    onEnhanceClicked: imageProcessor.enhance()
                    onStyleClicked: imageProcessor.neuralStyle()
                    onBwClicked: imageProcessor.blackWhite()
                    onSepiaClicked: imageProcessor.sepia()
                    onBlurClicked: imageProcessor.blur()
                    onSharpenClicked: imageProcessor.sharpen()
                    onEdgesClicked: imageProcessor.edges()
                    onCartoonClicked: imageProcessor.cartoon()
                    onInvertClicked: imageProcessor.invert()
                    onCorrectionChanged: imageProcessor.adjustLive(brightness, contrast, saturation)
                    onCorrectionApplied: imageProcessor.commitAdjustment()
                }

                PreviewPanel {
                    objectName: "previewPanel"
                    anchors {
                        left: parent.left
                        right: parent.right
                        top: parent.top
                        bottom: editingTray.top
                        margins: Theme.horizontalPageMargin
                        topMargin: Theme.paddingSmall
                        bottomMargin: Theme.paddingSmall
                    }
                    resultSource: imageProcessor.resultSource
                    originalSource: imageProcessor.originalSource
                    canUndo: imageProcessor.canUndo
                    busy: imageProcessor.busy
                    statusText: imageProcessor.statusText
                    primary: page.primary
                    accent: page.lavender
                    cardColor: page.cardColor
                    cardBorder: page.cardBorder
                    statusColor: page.secondaryTextColor
                    onUndoClicked: imageProcessor.undo()
                    onFullscreenClicked: page.openFullscreenPreview()
                }
            }
        }
    }

    Component {
        id: imagePickerComponent

        ImagePickerPage {
            onSelectedContentPropertiesChanged: page.processSelectedContent(selectedContentProperties)
        }
    }

    Component {
        id: filePickerComponent

        FilePickerPage {
            nameFilters: ["*.jpg", "*.jpeg", "*.png", "*.bmp", "*.gif", "*.webp"]
            onSelectedContentPropertiesChanged: page.processSelectedContent(selectedContentProperties)
        }
    }
}
