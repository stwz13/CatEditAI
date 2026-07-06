#include "processingworker.h"

#include "imagefilters.h"
#include "neuralstyleengine.h"
#include "segmentationengine.h"

#include <QColor>
#include <QDateTime>
#include <QDir>
#include <QElapsedTimer>
#include <QFileInfo>
#include <QImageReader>
#include <QStandardPaths>
#include <QUrl>

namespace {

QString localPath(const QString &path)
{
    const QUrl url(path);
    if (url.isLocalFile())
        return url.toLocalFile();
    return path;
}

int clampedColor(int value)
{
    return qBound(0, value, 255);
}

QImage boostedContrastAndSaturationImage(const QImage &source)
{
    QImage image = source.convertToFormat(QImage::Format_RGB888);
    const double contrastFactor = 1.22;
    const double saturationFactor = 1.35;

    for (int y = 0; y < image.height(); ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < image.width(); ++x) {
            uchar *pixel = line + x * 3;

            int red = clampedColor(int((pixel[0] - 128) * contrastFactor + 128.5));
            int green = clampedColor(int((pixel[1] - 128) * contrastFactor + 128.5));
            int blue = clampedColor(int((pixel[2] - 128) * contrastFactor + 128.5));
            const int luminance = (red * 299 + green * 587 + blue * 114) / 1000;

            red = clampedColor(int(luminance + (red - luminance) * saturationFactor + 0.5));
            green = clampedColor(int(luminance + (green - luminance) * saturationFactor + 0.5));
            blue = clampedColor(int(luminance + (blue - luminance) * saturationFactor + 0.5));

            pixel[0] = uchar(red);
            pixel[1] = uchar(green);
            pixel[2] = uchar(blue);
        }
    }

    return image;
}

QImage autoEnhancedImage(const QImage &source)
{
    QImage image = source.convertToFormat(QImage::Format_RGB888);
    const int width = image.width();
    const int height = image.height();
    const int total = width * height;
    if (total <= 0)
        return image;

    double redSum = 0.0;
    double greenSum = 0.0;
    double blueSum = 0.0;

    for (int y = 0; y < height; ++y) {
        const uchar *line = image.constScanLine(y);
        for (int x = 0; x < width; ++x) {
            const uchar *pixel = line + x * 3;
            redSum += pixel[0];
            greenSum += pixel[1];
            blueSum += pixel[2];
        }
    }

    const double redAverage = redSum / total;
    const double greenAverage = greenSum / total;
    const double blueAverage = blueSum / total;
    const double grayAverage = (redAverage + greenAverage + blueAverage) / 3.0;
    const double redScale = redAverage > 1.0 ? grayAverage / redAverage : 1.0;
    const double greenScale = greenAverage > 1.0 ? grayAverage / greenAverage : 1.0;
    const double blueScale = blueAverage > 1.0 ? grayAverage / blueAverage : 1.0;

    int minLuminance = 255;
    int maxLuminance = 0;
    for (int y = 0; y < height; ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < width; ++x) {
            uchar *pixel = line + x * 3;
            const int red = clampedColor(int(pixel[0] * redScale + 0.5));
            const int green = clampedColor(int(pixel[1] * greenScale + 0.5));
            const int blue = clampedColor(int(pixel[2] * blueScale + 0.5));
            pixel[0] = uchar(red);
            pixel[1] = uchar(green);
            pixel[2] = uchar(blue);

            const int luminance = (red * 299 + green * 587 + blue * 114) / 1000;
            minLuminance = qMin(minLuminance, luminance);
            maxLuminance = qMax(maxLuminance, luminance);
        }
    }

    if (maxLuminance - minLuminance < 8)
        return boostedContrastAndSaturationImage(image);

    const double contrastScale = 255.0 / double(maxLuminance - minLuminance);
    for (int y = 0; y < height; ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < width; ++x) {
            uchar *pixel = line + x * 3;
            pixel[0] = uchar(clampedColor(int((pixel[0] - minLuminance) * contrastScale + 0.5)));
            pixel[1] = uchar(clampedColor(int((pixel[1] - minLuminance) * contrastScale + 0.5)));
            pixel[2] = uchar(clampedColor(int((pixel[2] - minLuminance) * contrastScale + 0.5)));
        }
    }

    return boostedContrastAndSaturationImage(image);
}

QImage blackWhiteImage(const QImage &source)
{
    QImage image = source.convertToFormat(QImage::Format_RGB888);
    for (int y = 0; y < image.height(); ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < image.width(); ++x) {
            uchar *pixel = line + x * 3;
            const uchar gray = uchar((pixel[0] * 299 + pixel[1] * 587 + pixel[2] * 114) / 1000);
            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;
        }
    }
    return image;
}

QImage sepiaImage(const QImage &source)
{
    QImage image = source.convertToFormat(QImage::Format_RGB888);
    for (int y = 0; y < image.height(); ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < image.width(); ++x) {
            uchar *pixel = line + x * 3;
            const int red = pixel[0];
            const int green = pixel[1];
            const int blue = pixel[2];
            pixel[0] = uchar(clampedColor(int(0.393 * red + 0.769 * green + 0.189 * blue)));
            pixel[1] = uchar(clampedColor(int(0.349 * red + 0.686 * green + 0.168 * blue)));
            pixel[2] = uchar(clampedColor(int(0.272 * red + 0.534 * green + 0.131 * blue)));
        }
    }
    return image;
}

QImage adjustedImage(const QImage &source, int brightness, int contrast, int saturation)
{
    QImage image = source.convertToFormat(QImage::Format_RGB888);
    const double contrastFactor = 1.0 + qBound(-90, contrast, 150) / 100.0;
    const double saturationFactor = 1.0 + qBound(-90, saturation, 150) / 100.0;
    const int brightnessOffset = qBound(-120, brightness, 120);

    for (int y = 0; y < image.height(); ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < image.width(); ++x) {
            uchar *pixel = line + x * 3;
            int red = clampedColor(int((pixel[0] - 128) * contrastFactor + 128 + brightnessOffset));
            int green = clampedColor(int((pixel[1] - 128) * contrastFactor + 128 + brightnessOffset));
            int blue = clampedColor(int((pixel[2] - 128) * contrastFactor + 128 + brightnessOffset));
            const int luminance = (red * 299 + green * 587 + blue * 114) / 1000;

            red = clampedColor(int(luminance + (red - luminance) * saturationFactor + 0.5));
            green = clampedColor(int(luminance + (green - luminance) * saturationFactor + 0.5));
            blue = clampedColor(int(luminance + (blue - luminance) * saturationFactor + 0.5));

            pixel[0] = uchar(red);
            pixel[1] = uchar(green);
            pixel[2] = uchar(blue);
        }
    }

    return image;
}

QImage invertedImage(const QImage &source)
{
    QImage image = source.convertToFormat(QImage::Format_RGB888);
    for (int y = 0; y < image.height(); ++y) {
        uchar *line = image.scanLine(y);
        for (int x = 0; x < image.width(); ++x) {
            uchar *pixel = line + x * 3;
            pixel[0] = uchar(255 - pixel[0]);
            pixel[1] = uchar(255 - pixel[1]);
            pixel[2] = uchar(255 - pixel[2]);
        }
    }
    return image;
}

QString galleryExportPath()
{
    QString picturesPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (picturesPath.isEmpty())
        picturesPath = QDir::homePath();

    QDir picturesDir(picturesPath);
    picturesDir.mkpath(QStringLiteral("CatEditAiProSixSevenSigmaEditor"));
    picturesDir.cd(QStringLiteral("CatEditAiProSixSevenSigmaEditor"));

    const QString fileName = QStringLiteral("CatEdit_%1.png")
            .arg(QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMdd_hhmmss")));
    return picturesDir.filePath(fileName);
}

} // namespace

void ProcessingWorker::importImage(const QString &filePath)
{
    QImageReader reader(localPath(filePath));
    reader.setAutoTransform(true);

    QImage image = reader.read();
    if (image.isNull()) {
        emitState(tr("Select an image"), tr("Unable to open image"));
        return;
    }

    m_original = image.convertToFormat(QImage::Format_RGB888);
    m_current = m_original;
    m_adjustmentBase = QImage();
    m_adjustmentActive = false;
    m_history.clear();

    emitState(tr("Image loaded. Choose a tool."));
}

void ProcessingWorker::removeBackground()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    qreal backgroundPercent = 0.0;
    qint64 preprocessMs = 0;
    qint64 segmentationMs = 0;
    qint64 postprocessMs = 0;
    QImage result;

    if (SegmentationEngine::instance().isAvailable()) {
        result = SegmentationEngine::instance().replaceBackground(
                m_current, QColor(QStringLiteral("#00ff00")), &backgroundPercent, &preprocessMs,
                &segmentationMs, &postprocessMs);
    } else {
        QElapsedTimer stageTimer;
        stageTimer.start();
        result = ImageFilters::replaceBackground(m_current, QColor(QStringLiteral("#00ff00")),
                                                 &backgroundPercent);
        segmentationMs = stageTimer.elapsed();
    }

    if (result.isNull()) {
        const QString error = SegmentationEngine::instance().isAvailable()
                ? tr("AI segmentation failed")
                : tr("Unable to remove background");
        emitState(error, error);
        return;
    }

    pushHistory();
    m_current = result;
    const QString engineLabel = SegmentationEngine::instance().isAvailable()
            ? tr("AI background removed")
            : tr("Background replaced");
    emitState(QStringLiteral("%1: %2%. Prep: %3 ms, segmentation: %4 ms, post: %5 ms")
                      .arg(engineLabel)
                      .arg(backgroundPercent, 0, 'f', 1)
                      .arg(preprocessMs)
                      .arg(segmentationMs)
                      .arg(postprocessMs));
}

void ProcessingWorker::enhance()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    QElapsedTimer timer;
    timer.start();
    const QImage result = autoEnhancedImage(m_current);

    pushHistory();
    m_current = result;
    emitState(tr("Auto enhancement applied. Time: %1 ms").arg(timer.elapsed()));
}

void ProcessingWorker::blackWhite()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = blackWhiteImage(m_current);
    emitState(tr("Black and white style applied"));
}

void ProcessingWorker::sepia()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = sepiaImage(m_current);
    emitState(tr("Sepia style applied"));
}

void ProcessingWorker::blur()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = ImageFilters::gaussianBlur(m_current, 6);
    emitState(tr("Blur applied"));
}

void ProcessingWorker::sharpen()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = ImageFilters::sharpen(m_current);
    emitState(tr("Sharpen applied"));
}

void ProcessingWorker::edges()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = ImageFilters::edges(m_current);
    emitState(tr("Edges style applied"));
}

void ProcessingWorker::cartoon()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = ImageFilters::cartoon(m_current);
    emitState(tr("Cartoon style applied"));
}

void ProcessingWorker::neuralStyle()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();

    if (!NeuralStyleEngine::instance().isAvailable()) {
        emitState(tr("Neural style unavailable"),
                  tr("Build ncnn and place models/mosaic.bin (see third_party/ncnn/README.md)"));
        return;
    }

    qint64 preprocessMs = 0;
    qint64 inferenceMs = 0;
    qint64 postprocessMs = 0;
    const QImage result = NeuralStyleEngine::instance().applyStyle(
            m_current, &preprocessMs, &inferenceMs, &postprocessMs);
    if (result.isNull()) {
        emitState(tr("Neural style failed"), tr("Neural style failed"));
        return;
    }

    pushHistory();
    m_current = result;
    emitState(tr("Neural style applied. Prep: %1 ms, inference: %2 ms, post: %3 ms")
                      .arg(preprocessMs)
                      .arg(inferenceMs)
                      .arg(postprocessMs));
}

void ProcessingWorker::invert()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = invertedImage(m_current);
    emitState(tr("Colors inverted"));
}

void ProcessingWorker::adjust(int brightness, int contrast, int saturation)
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    pushHistory();
    m_current = adjustedImage(m_current, brightness, contrast, saturation);
    emitState(tr("Manual correction applied"));
}

void ProcessingWorker::adjustLive(int brightness, int contrast, int saturation)
{
    if (!ensureImage())
        return;

    if (!m_adjustmentActive) {
        pushHistory();
        m_adjustmentBase = m_current;
        m_adjustmentActive = true;
    }

    m_current = adjustedImage(m_adjustmentBase, brightness, contrast, saturation);
    emitState(tr("Manual correction preview"));
}

void ProcessingWorker::commitAdjustment()
{
    if (!ensureImage())
        return;

    if (!m_adjustmentActive) {
        emitState(tr("No correction to apply"));
        return;
    }

    finishAdjustmentSession();
    emitState(tr("Manual correction applied"));
}

void ProcessingWorker::undo()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    if (m_history.isEmpty()) {
        emitState(tr("Nothing to undo"));
        return;
    }

    m_current = m_history.takeLast();
    emitState(tr("Last action undone"));
}

void ProcessingWorker::reset()
{
    if (!ensureImage())
        return;

    m_adjustmentBase = QImage();
    m_adjustmentActive = false;
    m_current = m_original;
    m_history.clear();
    emitState(tr("Reset to original"));
}

void ProcessingWorker::exportResult()
{
    if (!ensureImage())
        return;

    finishAdjustmentSession();
    const QString path = galleryExportPath();
    if (!m_current.save(path, "PNG")) {
        emitState(tr("Unable to export image"), tr("Unable to export image"));
        return;
    }

    emitState(tr("Exported to gallery: %1").arg(QFileInfo(path).fileName()));
}

bool ProcessingWorker::ensureImage()
{
    if (!m_current.isNull())
        return true;

    emitState(tr("Select an image"), tr("Select an image first"));
    return false;
}

void ProcessingWorker::pushHistory()
{
    if (m_current.isNull())
        return;

    m_history.append(m_current);
    const int maxHistorySize = 20;
    while (m_history.size() > maxHistorySize)
        m_history.removeFirst();
}

void ProcessingWorker::finishAdjustmentSession()
{
    m_adjustmentBase = QImage();
    m_adjustmentActive = false;
}

void ProcessingWorker::emitState(const QString &statusText, const QString &errorText)
{
    emit stateReady(m_original, m_current, !m_history.isEmpty(), statusText, errorText);
}
