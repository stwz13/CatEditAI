#include "segmentationengine.h"

#include <QElapsedTimer>
#include <QFile>
#include <QtGlobal>

#ifdef CATEDIT_NCNN
#include "net.h"

namespace {

constexpr int kInputSize = 320;

struct SegmentationNetState {
    ncnn::Net net;
    QString paramPath;
    QString binPath;
    bool loaded = false;
    bool failed = false;
};

SegmentationNetState &segmentationNetState()
{
    static thread_local SegmentationNetState state;
    return state;
}

bool loadSegmentationNet(const QString &paramPath, const QString &binPath)
{
    SegmentationNetState &state = segmentationNetState();
    if (state.loaded && state.paramPath == paramPath && state.binPath == binPath)
        return true;
    if (state.failed && state.paramPath == paramPath && state.binPath == binPath)
        return false;

    state.net.clear();
    state.loaded = false;
    state.failed = false;
    state.paramPath.clear();
    state.binPath.clear();

    if (paramPath.isEmpty() || binPath.isEmpty() || !QFile::exists(paramPath)
            || !QFile::exists(binPath)) {
        state.failed = true;
        return false;
    }

    ncnn::Option opt;
    opt.num_threads = 2;
    opt.use_vulkan_compute = false;
    state.net.opt = opt;

    const QByteArray localParam = paramPath.toLocal8Bit();
    const QByteArray localBin = binPath.toLocal8Bit();
    if (state.net.load_param(localParam.constData()) != 0
            || state.net.load_model(localBin.constData()) != 0) {
        state.failed = true;
        return false;
    }

    state.paramPath = paramPath;
    state.binPath = binPath;
    state.loaded = true;
    return true;
}

void resetSegmentationNetState()
{
    SegmentationNetState &state = segmentationNetState();
    state.net.clear();
    state.paramPath.clear();
    state.binPath.clear();
    state.loaded = false;
    state.failed = false;
}

} // namespace
#endif

SegmentationEngine &SegmentationEngine::instance()
{
    static SegmentationEngine engine;
    return engine;
}

void SegmentationEngine::setModelPaths(const QString &paramPath, const QString &binPath)
{
    m_paramPath = paramPath;
    m_binPath = binPath;
    m_loadAttempted = false;
    m_loaded = false;
#ifdef CATEDIT_NCNN
    resetSegmentationNetState();
#endif
}

bool SegmentationEngine::isAvailable() const
{
#ifdef CATEDIT_NCNN
    return ensureLoaded();
#else
    return false;
#endif
}

bool SegmentationEngine::ensureLoaded() const
{
#ifdef CATEDIT_NCNN
    if (m_loaded)
        return true;
    if (m_loadAttempted)
        return false;

    m_loadAttempted = true;
    m_loaded = loadSegmentationNet(m_paramPath, m_binPath);
    return m_loaded;
#else
    return false;
#endif
}

QImage SegmentationEngine::replaceBackground(const QImage &source, const QColor &color,
                                             qreal *backgroundPercent, qint64 *preprocessMs,
                                             qint64 *inferenceMs, qint64 *postprocessMs) const
{
#ifdef CATEDIT_NCNN
    if (source.isNull() || !ensureLoaded())
        return QImage();

    const int width = source.width();
    const int height = source.height();
    if (width <= 0 || height <= 0)
        return QImage();

    QElapsedTimer stageTimer;
    stageTimer.start();

    QImage rgbImage = source.convertToFormat(QImage::Format_RGB888);
    ncnn::Mat input = ncnn::Mat::from_pixels_resize(rgbImage.constBits(), ncnn::Mat::PIXEL_RGB,
                                                    width, height, kInputSize, kInputSize);

    const float meanVals[3] = {0.485f * 255.f, 0.456f * 255.f, 0.406f * 255.f};
    const float normVals[3] = {1.f / (0.229f * 255.f), 1.f / (0.224f * 255.f),
                               1.f / (0.225f * 255.f)};
    input.substract_mean_normalize(meanVals, normVals);

    if (preprocessMs)
        *preprocessMs = stageTimer.elapsed();

    stageTimer.restart();

    SegmentationNetState &state = segmentationNetState();
    ncnn::Extractor extractor = state.net.create_extractor();
    extractor.set_light_mode(true);
    extractor.input("in0", input);

    ncnn::Mat maskOutput;
    if (extractor.extract("out0", maskOutput) != 0)
        return QImage();

    if (inferenceMs)
        *inferenceMs = stageTimer.elapsed();

    stageTimer.restart();

    QImage smallMask(kInputSize, kInputSize, QImage::Format_Grayscale8);
    for (int y = 0; y < kInputSize; ++y) {
        uchar *line = smallMask.scanLine(y);
        const float *row = maskOutput.row(y);
        for (int x = 0; x < kInputSize; ++x)
            line[x] = uchar(qBound(0, int(row[x] * 255.f + 0.5f), 255));
    }

    const QImage fullMask = smallMask.scaled(width, height, Qt::IgnoreAspectRatio,
                                             Qt::SmoothTransformation);

    const uchar replacement[3] = {uchar(color.red()), uchar(color.green()), uchar(color.blue())};
    const int total = width * height;
    int backgroundPixels = 0;

    for (int y = 0; y < height; ++y) {
        uchar *line = rgbImage.scanLine(y);
        const uchar *maskLine = fullMask.constScanLine(y);
        for (int x = 0; x < width; ++x) {
            if (maskLine[x] < 128) {
                line[x * 3 + 0] = replacement[0];
                line[x * 3 + 1] = replacement[1];
                line[x * 3 + 2] = replacement[2];
                ++backgroundPixels;
            }
        }
    }

    if (backgroundPercent)
        *backgroundPercent = qreal(backgroundPixels) * 100.0 / qreal(total);

    if (postprocessMs)
        *postprocessMs = stageTimer.elapsed();

    return rgbImage;
#else
    Q_UNUSED(source)
    Q_UNUSED(color)
    Q_UNUSED(backgroundPercent)
    Q_UNUSED(preprocessMs)
    Q_UNUSED(inferenceMs)
    Q_UNUSED(postprocessMs)
    return QImage();
#endif
}
