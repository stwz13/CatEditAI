#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <QColor>
#include <QImage>

namespace ImageFilters {

QImage gaussianBlur(const QImage &source, int radius);
QImage sharpen(const QImage &source);
QImage edges(const QImage &source);
QImage cartoon(const QImage &source);
QImage replaceBackground(const QImage &source, const QColor &color, qreal *backgroundPercent = nullptr);

} // namespace ImageFilters

#endif // IMAGEFILTERS_H
