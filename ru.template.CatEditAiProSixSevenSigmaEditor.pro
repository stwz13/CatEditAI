TARGET = ru.template.CatEditAiProSixSevenSigmaEditor

CONFIG += \
    auroraapp

PKGCONFIG += \

OPENCV_BUILD_NAME = $$basename(OUT_PWD)
OPENCV_BUILD_PATH = $$PWD/third_party/opencv/build/$$OPENCV_BUILD_NAME/opencv
OPENCV_SOURCE_PATH = $$PWD/third_party/opencv/source

!exists($$OPENCV_BUILD_PATH/lib) {
    warning("Local OpenCV libraries were not found for this kit/configuration.")
}

opencv_library_install.path = /usr/share/ru.template.CatEditAiProSixSevenSigmaEditor/lib/
opencv_library_install.files = \
    $$OPENCV_BUILD_PATH/lib/libopencv_core.so.407 \
    $$OPENCV_BUILD_PATH/lib/libopencv_imgproc.so.407
opencv_library_install.CONFIG = no_check_exist
INSTALLS += opencv_library_install

INCLUDEPATH += \
    $$OPENCV_BUILD_PATH/include \
    $$OPENCV_BUILD_PATH \
    $$OPENCV_SOURCE_PATH/modules/core/include \
    $$OPENCV_SOURCE_PATH/modules/imgproc/include \
    $$OPENCV_SOURCE_PATH/include

LIBS += \
    $$OPENCV_BUILD_PATH/lib/libopencv_core.so.407 \
    $$OPENCV_BUILD_PATH/lib/libopencv_imgproc.so.407

NCNN_BUILD_NAME = $$OPENCV_BUILD_NAME
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
models_install.files = models/mosaic.bin
INSTALLS += models_install

SOURCES += \
    src/imageprocessor.cpp \
    src/main.cpp \
    src/neuralstyleengine.cpp \
    src/processingworker.cpp \
    src/resultimageprovider.cpp

HEADERS += \
    src/imageprocessor.h \
    src/neuralstyleengine.h \
    src/processingworker.h \
    src/resultimageprovider.h \
    src/styletransfer.param.bin.h

DISTFILES += \
    rpm/ru.template.CatEditAiProSixSevenSigmaEditor.spec

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.template.CatEditAiProSixSevenSigmaEditor.ts \
    translations/ru.template.CatEditAiProSixSevenSigmaEditor-ru.ts \
