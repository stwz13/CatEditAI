#ifndef PROCESSINGWORKER_H
#define PROCESSINGWORKER_H

#include <QImage>
#include <QObject>
#include <QString>
#include <QVector>

class ProcessingWorker : public QObject
{
    Q_OBJECT

public slots:
    void importImage(const QString &filePath);
    void removeBackground();
    void enhance();
    void blackWhite();
    void sepia();
    void blur();
    void sharpen();
    void edges();
    void cartoon();
    void neuralStyle();
    void invert();
    void adjust(int brightness, int contrast, int saturation);
    void adjustLive(int brightness, int contrast, int saturation);
    void commitAdjustment();
    void undo();
    void reset();
    void exportResult();

signals:
    void stateReady(const QImage &original, const QImage &current, bool canUndo,
                    const QString &statusText, const QString &errorText);

private:
    bool ensureImage();
    void pushHistory();
    void finishAdjustmentSession();
    void emitState(const QString &statusText, const QString &errorText = QString());

    QImage m_original;
    QImage m_current;
    QImage m_adjustmentBase;
    QVector<QImage> m_history;
    bool m_adjustmentActive = false;
};

#endif // PROCESSINGWORKER_H
