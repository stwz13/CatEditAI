#ifndef NEURALSTYLEENGINE_H
#define NEURALSTYLEENGINE_H

#include <QImage>
#include <QString>

class NeuralStyleEngine
{
public:
    static NeuralStyleEngine &instance();

    void setModelPath(const QString &path);
    bool isAvailable() const;
    bool ensureLoaded() const;

    QImage applyStyle(const QImage &source, qint64 *preprocessMs, qint64 *inferenceMs,
                      qint64 *postprocessMs) const;

private:
    NeuralStyleEngine() = default;

    QString m_modelPath;
    mutable bool m_loadAttempted = false;
    mutable bool m_loaded = false;
};

#endif // NEURALSTYLEENGINE_H
