#include <QtQuick>
#include <auroraapp.h>

#include <QQmlContext>

#include "imageprocessor.h"
#include "neuralstyleengine.h"
#include "resultimageprovider.h"
#include "segmentationengine.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.template"));
    application->setApplicationName(QStringLiteral("CatEditAiProSixSevenSigmaEditor"));

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    ResultImageProvider *resultProvider = new ResultImageProvider;
    QScopedPointer<ImageProcessor> imageProcessor(new ImageProcessor(resultProvider));

    const QString modelsDir =
            Aurora::Application::pathTo(QStringLiteral("models")).toLocalFile();

    NeuralStyleEngine::instance().setModelPath(modelsDir + QStringLiteral("/mosaic.bin"));
    SegmentationEngine::instance().setModelPaths(modelsDir + QStringLiteral("/u2netp.ncnn.param"),
                                               modelsDir + QStringLiteral("/u2netp.ncnn.bin"));

    view->engine()->addImageProvider(QStringLiteral("result"), resultProvider);
    view->rootContext()->setContextProperty(QStringLiteral("imageProcessor"),
                                            imageProcessor.data());
    view->setSource(
        Aurora::Application::pathTo(QStringLiteral("qml/CatEditAiProSixSevenSigmaEditor.qml")));
    view->show();

    return application->exec();
}
