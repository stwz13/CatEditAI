#include "imagefilters.h"

#include <QtGlobal>
#include <cmath>

namespace {

int clampColor(int value)
{
    return qBound(0, value, 255);
}

QImage toRgb888(const QImage &source)
{
    return source.convertToFormat(QImage::Format_RGB888);
}

QVector<float> gaussianKernel(int radius)
{
    const int size = radius * 2 + 1;
    QVector<float> kernel(size);
    const float sigma = qMax(1.0f, radius / 2.0f);
    const float denom = 2.0f * sigma * sigma;
    float sum = 0.0f;

    for (int i = 0; i < size; ++i) {
        const float x = float(i - radius);
        kernel[i] = std::exp(-(x * x) / denom);
        sum += kernel[i];
    }

    for (float &weight : kernel)
        weight /= sum;

    return kernel;
}

QImage convolveHorizontal(const QImage &source, const QVector<float> &kernel)
{
    const QImage image = toRgb888(source);
    const int width = image.width();
    const int height = image.height();
    const int radius = kernel.size() / 2;
    QImage result(width, height, QImage::Format_RGB888);

    for (int y = 0; y < height; ++y) {
        const uchar *srcLine = image.constScanLine(y);
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < width; ++x) {
            float red = 0.0f;
            float green = 0.0f;
            float blue = 0.0f;
            for (int k = -radius; k <= radius; ++k) {
                const int sampleX = qBound(0, x + k, width - 1);
                const uchar *pixel = srcLine + sampleX * 3;
                const float weight = kernel[k + radius];
                red += pixel[0] * weight;
                green += pixel[1] * weight;
                blue += pixel[2] * weight;
            }
            dstLine[x * 3 + 0] = uchar(clampColor(int(red + 0.5f)));
            dstLine[x * 3 + 1] = uchar(clampColor(int(green + 0.5f)));
            dstLine[x * 3 + 2] = uchar(clampColor(int(blue + 0.5f)));
        }
    }

    return result;
}

QImage convolveVertical(const QImage &source, const QVector<float> &kernel)
{
    const QImage image = toRgb888(source);
    const int width = image.width();
    const int height = image.height();
    const int radius = kernel.size() / 2;
    QImage result(width, height, QImage::Format_RGB888);

    for (int y = 0; y < height; ++y) {
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < width; ++x) {
            float red = 0.0f;
            float green = 0.0f;
            float blue = 0.0f;
            for (int k = -radius; k <= radius; ++k) {
                const int sampleY = qBound(0, y + k, height - 1);
                const uchar *pixel = image.constScanLine(sampleY) + x * 3;
                const float weight = kernel[k + radius];
                red += pixel[0] * weight;
                green += pixel[1] * weight;
                blue += pixel[2] * weight;
            }
            dstLine[x * 3 + 0] = uchar(clampColor(int(red + 0.5f)));
            dstLine[x * 3 + 1] = uchar(clampColor(int(green + 0.5f)));
            dstLine[x * 3 + 2] = uchar(clampColor(int(blue + 0.5f)));
        }
    }

    return result;
}

QImage convolveRgb(const QImage &source, const QVector<QVector<float>> &kernel)
{
    const QImage image = toRgb888(source);
    const int width = image.width();
    const int height = image.height();
    const int radius = kernel.size() / 2;
    QImage result(width, height, QImage::Format_RGB888);

    for (int y = 0; y < height; ++y) {
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < width; ++x) {
            float red = 0.0f;
            float green = 0.0f;
            float blue = 0.0f;
            for (int ky = -radius; ky <= radius; ++ky) {
                const int sampleY = qBound(0, y + ky, height - 1);
                const uchar *srcLine = image.constScanLine(sampleY);
                for (int kx = -radius; kx <= radius; ++kx) {
                    const int sampleX = qBound(0, x + kx, width - 1);
                    const uchar *pixel = srcLine + sampleX * 3;
                    const float weight = kernel[ky + radius][kx + radius];
                    red += pixel[0] * weight;
                    green += pixel[1] * weight;
                    blue += pixel[2] * weight;
                }
            }
            dstLine[x * 3 + 0] = uchar(clampColor(int(red + 0.5f)));
            dstLine[x * 3 + 1] = uchar(clampColor(int(green + 0.5f)));
            dstLine[x * 3 + 2] = uchar(clampColor(int(blue + 0.5f)));
        }
    }

    return result;
}

QImage grayscale(const QImage &source)
{
    const QImage image = toRgb888(source);
    QImage result(image.size(), QImage::Format_Grayscale8);
    for (int y = 0; y < image.height(); ++y) {
        const uchar *srcLine = image.constScanLine(y);
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < image.width(); ++x) {
            const uchar *pixel = srcLine + x * 3;
            dstLine[x] = uchar((pixel[0] * 299 + pixel[1] * 587 + pixel[2] * 114) / 1000);
        }
    }
    return result;
}

QImage graySobelMagnitude(const QImage &gray)
{
    QImage result(gray.size(), QImage::Format_Grayscale8);
    const int width = gray.width();
    const int height = gray.height();

    for (int y = 0; y < height; ++y) {
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < width; ++x) {
            auto sample = [&](int sx, int sy) {
                return gray.pixelColor(qBound(0, sx, width - 1), qBound(0, sy, height - 1)).red();
            };
            const int gx = -sample(x - 1, y - 1) - 2 * sample(x - 1, y) - sample(x - 1, y + 1)
                    + sample(x + 1, y - 1) + 2 * sample(x + 1, y) + sample(x + 1, y + 1);
            const int gy = -sample(x - 1, y - 1) - 2 * sample(x, y - 1) - sample(x + 1, y - 1)
                    + sample(x - 1, y + 1) + 2 * sample(x, y + 1) + sample(x + 1, y + 1);
            dstLine[x] = uchar(qMin(255, int(std::sqrt(float(gx * gx + gy * gy)))));
        }
    }

    return result;
}

struct ColorStats {
    float red = 0.0f;
    float green = 0.0f;
    float blue = 0.0f;
    int count = 0;

    void add(uchar r, uchar g, uchar b)
    {
        red += r;
        green += g;
        blue += b;
        ++count;
    }

    float distance(uchar r, uchar g, uchar b) const
    {
        if (count <= 0)
            return 1e9f;
        const float meanR = red / count;
        const float meanG = green / count;
        const float meanB = blue / count;
        const float dr = r - meanR;
        const float dg = g - meanG;
        const float db = b - meanB;
        return dr * dr + dg * dg + db * db;
    }
};

} // namespace

namespace ImageFilters {

QImage gaussianBlur(const QImage &source, int radius)
{
    const QVector<float> kernel = gaussianKernel(radius);
    return convolveVertical(convolveHorizontal(source, kernel), kernel);
}

QImage sharpen(const QImage &source)
{
    const QVector<QVector<float>> kernel = {
        {0.f, -1.f, 0.f},
        {-1.f, 5.f, -1.f},
        {0.f, -1.f, 0.f},
    };
    return convolveRgb(source, kernel);
}

QImage edges(const QImage &source)
{
    QImage blurred = gaussianBlur(source, 2);
    QImage gray = grayscale(blurred);
    QImage magnitude = graySobelMagnitude(gray);

    QImage result(magnitude.size(), QImage::Format_RGB888);
    for (int y = 0; y < magnitude.height(); ++y) {
        const uchar *edgeLine = magnitude.constScanLine(y);
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < magnitude.width(); ++x) {
            const uchar value = edgeLine[x] >= 70 ? 0 : 255;
            dstLine[x * 3 + 0] = value;
            dstLine[x * 3 + 1] = value;
            dstLine[x * 3 + 2] = value;
        }
    }
    return result;
}

QImage cartoon(const QImage &source)
{
    QImage smoothed = gaussianBlur(source, 4);
    QImage gray = grayscale(smoothed);
    QImage edges = graySobelMagnitude(gray);
    QImage result = toRgb888(source);

    for (int y = 0; y < result.height(); ++y) {
        const uchar *edgeLine = edges.constScanLine(y);
        const uchar *smoothLine = smoothed.constScanLine(y);
        uchar *dstLine = result.scanLine(y);
        for (int x = 0; x < result.width(); ++x) {
            if (edgeLine[x] > 65) {
                dstLine[x * 3 + 0] = 20;
                dstLine[x * 3 + 1] = 20;
                dstLine[x * 3 + 2] = 24;
            } else {
                const uchar *pixel = smoothLine + x * 3;
                dstLine[x * 3 + 0] = uchar((pixel[0] / 32) * 32 + 16);
                dstLine[x * 3 + 1] = uchar((pixel[1] / 32) * 32 + 16);
                dstLine[x * 3 + 2] = uchar((pixel[2] / 32) * 32 + 16);
            }
        }
    }

    return result;
}

QImage replaceBackground(const QImage &source, const QColor &color, qreal *backgroundPercent)
{
    QImage rgbImage = toRgb888(source);
    const int width = rgbImage.width();
    const int height = rgbImage.height();
    const int total = width * height;
    if (total <= 0) {
        if (backgroundPercent)
            *backgroundPercent = 0.0;
        return rgbImage;
    }

    const int smallWidth = qMax(1, width / 10);
    const int smallHeight = qMax(1, height / 10);
    const QImage small = rgbImage.scaled(smallWidth, smallHeight, Qt::IgnoreAspectRatio,
                                         Qt::SmoothTransformation);

    ColorStats backgroundStats;
    ColorStats foregroundStats;
    const int border = qMax(1, qMin(smallWidth, smallHeight) / 20);
    const int insetX = qMax(2, smallWidth / 20);
    const int insetY = qMax(2, smallHeight / 20);
    const int rectWidth = qMax(1, smallWidth - 2 * insetX);
    const int rectHeight = qMax(1, smallHeight - 2 * insetY);

    for (int y = 0; y < smallHeight; ++y) {
        const uchar *line = small.constScanLine(y);
        for (int x = 0; x < smallWidth; ++x) {
            const uchar *pixel = line + x * 3;
            const bool onBorder = x < border || y < border || x >= smallWidth - border
                    || y >= smallHeight - border;
            const bool inCenter = x >= insetX && x < insetX + rectWidth && y >= insetY
                    && y < insetY + rectHeight;
            if (onBorder)
                backgroundStats.add(pixel[0], pixel[1], pixel[2]);
            if (inCenter)
                foregroundStats.add(pixel[0], pixel[1], pixel[2]);
        }
    }

    QVector<uchar> smallMask(smallWidth * smallHeight);
    for (int y = 0; y < smallHeight; ++y) {
        const uchar *line = small.constScanLine(y);
        for (int x = 0; x < smallWidth; ++x) {
            const uchar *pixel = line + x * 3;
            const float bgDistance = backgroundStats.distance(pixel[0], pixel[1], pixel[2]);
            const float fgDistance = foregroundStats.distance(pixel[0], pixel[1], pixel[2]);
            smallMask[y * smallWidth + x] = bgDistance + 250.0f < fgDistance ? 1 : 0;
        }
    }

    int backgroundPixels = 0;
    const uchar replacement[3] = {uchar(color.red()), uchar(color.green()), uchar(color.blue())};
    for (int y = 0; y < height; ++y) {
        uchar *line = rgbImage.scanLine(y);
        for (int x = 0; x < width; ++x) {
            const int sx = x * smallWidth / width;
            const int sy = y * smallHeight / height;
            if (smallMask[sy * smallWidth + sx]) {
                line[x * 3 + 0] = replacement[0];
                line[x * 3 + 1] = replacement[1];
                line[x * 3 + 2] = replacement[2];
                ++backgroundPixels;
            }
        }
    }

    if (backgroundPercent)
        *backgroundPercent = qreal(backgroundPixels) * 100.0 / qreal(total);

    return rgbImage;
}

} // namespace ImageFilters
