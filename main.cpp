#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <QtGlobal>

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
#include <QHoverEvent>
#endif

QString toString(QPointF point)
{
    return QString("(%1, %2)").arg(point.x()).arg(point.y());
}

void validatePointEvent(const QPointF& beforePoint, const QPointF& afterPoint, const QString& where, const QString& formatErrMsg)
{
    if (beforePoint != afterPoint) {
        qDebug().noquote().nospace() << "Failure " << where << ": " << formatErrMsg.arg(toString(beforePoint), toString(afterPoint));
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPointF mePoint1(1,1);
    QPointF mePoint1Glob(10,10);
    QMouseEvent *me1 = new QMouseEvent(QEvent::MouseMove, mePoint1, mePoint1Glob, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    validatePointEvent(mePoint1, me1->scenePosition(), "After first event created", "Unexpected scenePosition in first point event. Expected %1, Actual %2");
    validatePointEvent(mePoint1Glob, me1->globalPosition(), "After first event created", "Unexpected globalPosition in first point event. Expected %1, Actual %2");

    QPointF mePoint2(2, 2);
    QPointF mePoint2Glob(20, 20);
    QMouseEvent *me2 = new QMouseEvent(QEvent::MouseMove, mePoint2, mePoint2Glob, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    validatePointEvent(mePoint2, me2->scenePosition(), "After second event created", "Unexpected scenePosition in second point event. Expected %1, Actual %2");
    validatePointEvent(mePoint2Glob, me2->globalPosition(), "After second event created", "Unexpected globalPosition in second point event. Expected %1, Actual %2");

    validatePointEvent(mePoint1, me1->scenePosition(), "After second event created", "Unexpected scenePosition in first point event. Expected %1, Actual %2");
    validatePointEvent(mePoint1Glob, me1->globalPosition(), "After second event created", "Unexpected globalPosition in first point event. Expected %1, Actual %2");

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
    QPointF hePoint(3, 3);
    QPointF hePointGlob(30, 30);
    QHoverEvent *he = new QHoverEvent(QEvent::HoverMove, hePoint, hePointGlob, hePoint, Qt::NoModifier);
    validatePointEvent(hePoint, he->scenePosition(), "After third (hover) event created", "Unexpected scenePosition in third (hover) point event. Expected %1, Actual %2");
    validatePointEvent(hePointGlob, he->globalPosition(), "After third (hover) event created", "Unexpected globalPosition in third (hover) point event. Expected %1, Actual %2");

    validatePointEvent(mePoint1, me1->scenePosition(), "After third (hover) event created", "Unexpected scenePosition in first point event. Expected %1, Actual %2");
    validatePointEvent(mePoint1Glob, me1->globalPosition(), "After third (hover) event created", "Unexpected globalPosition in first point event. Expected %1, Actual %2");
#endif

    return 0;
}
