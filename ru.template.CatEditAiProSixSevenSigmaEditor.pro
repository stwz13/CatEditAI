TARGET = ru.template.CatEditAiProSixSevenSigmaEditor

CONFIG += \
    auroraapp

PKGCONFIG += \

NCNN_BUILD_NAME = $$basename(OUT_PWD)
NCNN_BUILD_PATH = $$PWD/third_party/ncnn/build/$$NCNN_BUILD_NAME
NCNN_SOURCE_PATH = $$PWD/third_party/ncnn/source

exists($$NCNN_BUILD_PATH/lib/libncnn.so) {
    DEFINES += CATEDIT_NCNN

    ncnn_library_install.path = /usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/lib/
    ncnn_library_install.files = $$NCNN_BUILD_PATH/lib/libncnn.so*
    ncnn_library_install.CONFIG = no_check_exist
    INSTALLS += ncnn_library_install

    INCLUDEPATH += \
        $$NCNN_BUILD_PATH/install/include \
        $$NCNN_BUILD_PATH/install/include/ncnn \
        $$NCNN_SOURCE_PATH/src

    LIBS += -L$$NCNN_BUILD_PATH/lib -lncnn
} else {
    warning("Local ncnn libraries were not found for this kit/configuration.")
}

models_install.path = /usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/models/
models_install.files = \
    models/mosaic.bin \
    models/u2netp.ncnn.param \
    models/u2netp.ncnn.bin
INSTALLS += models_install

SOURCES += \
    src/imagefilters.cpp \
    src/imageprocessor.cpp \
    src/main.cpp \
    src/neuralstyleengine.cpp \
    src/processingworker.cpp \
    src/resultimageprovider.cpp \
    src/segmentationengine.cpp

HEADERS += \
    src/imagefilters.h \
    src/imageprocessor.h \
    src/neuralstyleengine.h \
    src/processingworker.h \
    src/resultimageprovider.h \
    src/segmentationengine.h \
    src/styletransfer.param.bin.h

DISTFILES += \
    rpm/ru.template.CatEditAiProSixSevenSigmaEditor.spec

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.template.CatEditAiProSixSevenSigmaEditor.ts \
    translations/ru.template.CatEditAiProSixSevenSigmaEditor-ru.ts \
