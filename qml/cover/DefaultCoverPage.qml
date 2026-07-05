import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    objectName: "defaultCover"

    CoverTemplate {
        objectName: "applicationCover"
        primaryText: qsTr("CatEdit AI")
        secondaryText: qsTr("Offline photo editor")
        icon {
            source: Qt.resolvedUrl("../icons/CatEditAiProSixSevenSigmaEditor.svg")
            sourceSize { width: icon.width; height: icon.height }
        }
    }
}
