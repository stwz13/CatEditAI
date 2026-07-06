#ifndef SEGMENTATIONENGINE_H
#define SEGMENTATIONENGINE_H

#include <QColor>
#include <QImage>
#include <QString>

class SegmentationEngine
{
public:
    static SegmentationEngine &instance();

    void setModelPaths(const QString &paramPath, const QString &binPath);
    bool isAvailable() const;
    bool ensureLoaded() const;

    QImage replaceBackground(const QImage &source, const QColor &color, qreal *backgroundPercent,
                             qint64 *preprocessMs, qint64 *inferenceMs,
                             qint64 *postprocessMs) const;

private:
    SegmentationEngine() = default;

    QString m_paramPath;
    QString m_binPath;
    mutable bool m_loadAttempted = false;
    mutable bool m_loaded = false;
};

#endif // SEGMENTATIONENGINE_H
