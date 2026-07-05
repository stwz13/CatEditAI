#include "neuralstyleengine.h"

#include <QElapsedTimer>
#include <QFile>
#include <QtGlobal>

#ifdef CATEDIT_NCNN
#include "net.h"
#include "styletransfer.param.bin.h"

namespace {

struct StyleNetState {
    ncnn::Net net;
    QString modelPath;
    bool loaded = false;
    bool failed = false;
};

StyleNetState &styleNetState()
{
    static thread_local StyleNetState state;
    return state;
}

bool loadStyleNet(const QString &modelPath)
{
    StyleNetState &state = styleNetState();
    if (state.loaded && state.modelPath == modelPath)
        return true;
    if (state.failed && state.modelPath == modelPath)
        return false;

    state.net.clear();
    state.loaded = false;
    state.failed = false;
    state.modelPath.clear();

    if (modelPath.isEmpty() || !QFile::exists(modelPath)) {
        state.failed = true;
        return false;
    }

    ncnn::Option opt;
    opt.num_threads = 2;
    opt.use_vulkan_compute = false;
    state.net.opt = opt;

    if (state.net.load_param(styletransfer_param_bin) != 0) {
        state.failed = true;
        return false;
    }

    const QByteArray localPath = modelPath.toLocal8Bit();
    if (state.net.load_model(localPath.constData()) != 0) {
        state.failed = true;
        return false;
    }

    state.modelPath = modelPath;
    state.loaded = true;
    return true;
}

void resetStyleNetState()
{
    StyleNetState &state = styleNetState();
    state.net.clear();
    state.modelPath.clear();
    state.loaded = false;
    state.failed = false;
}

} // namespace
#endif

NeuralStyleEngine &NeuralStyleEngine::instance()
{
    static NeuralStyleEngine engine;
    return engine;
}

void NeuralStyleEngine::setModelPath(const QString &path)
{
    m_modelPath = path;
    m_loadAttempted = false;
    m_loaded = false;
#ifdef CATEDIT_NCNN
    resetStyleNetState();
#endif
}

bool NeuralStyleEngine::isAvailable() const
{
#ifdef CATEDIT_NCNN
    return ensureLoaded();
#else
    return false;
#endif
}

bool NeuralStyleEngine::ensureLoaded() const
{
#ifdef CATEDIT_NCNN
    if (m_loaded)
        return true;
    if (m_loadAttempted)
        return false;

    m_loadAttempted = true;
    m_loaded = loadStyleNet(m_modelPath);
    return m_loaded;
#else
    return false;
#endif
}

QImage NeuralStyleEngine::applyStyle(const QImage &source, qint64 *preprocessMs,
                                     qint64 *inferenceMs, qint64 *postprocessMs) const
{
#ifdef CATEDIT_NCNN
    if (source.isNull() || !ensureLoaded())
        return QImage();

    const int width = source.width();
    const int height = source.height();
    if (width <= 0 || height <= 0)
        return QImage();

    const int maxSide = 512;
    int inferWidth = width;
    int inferHeight = height;
    if (qMax(width, height) > maxSide) {
        if (width >= height) {
            inferWidth = maxSide;
            inferHeight = qMax(1, height * maxSide / width);
        } else {
            inferHeight = maxSide;
            inferWidth = qMax(1, width * maxSide / height);
        }
    }

    QElapsedTimer stageTimer;
    stageTimer.start();

    QImage rgbImage = source.convertToFormat(QImage::Format_RGB888);
    ncnn::Mat input = ncnn::Mat::from_pixels_resize(rgbImage.constBits(), ncnn::Mat::PIXEL_RGB,
                                                    width, height, inferWidth, inferHeight);

    if (preprocessMs)
        *preprocessMs = stageTimer.elapsed();

    stageTimer.restart();

    StyleNetState &state = styleNetState();
    ncnn::Extractor extractor = state.net.create_extractor();
    extractor.set_light_mode(true);
    extractor.input("input1", input);

    ncnn::Mat output;
    if (extractor.extract("output1", output) != 0)
        return QImage();

    if (inferenceMs)
        *inferenceMs = stageTimer.elapsed();

    stageTimer.restart();

    QImage styled(inferWidth, inferHeight, QImage::Format_RGB888);
    output.to_pixels(styled.bits(), ncnn::Mat::PIXEL_RGB);

    QImage result = styled;
    if (inferWidth != width || inferHeight != height) {
        result = styled.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    if (postprocessMs)
        *postprocessMs = stageTimer.elapsed();

    return result;
#else
    Q_UNUSED(source)
    Q_UNUSED(preprocessMs)
    Q_UNUSED(inferenceMs)
    Q_UNUSED(postprocessMs)
    return QImage();
#endif
}
