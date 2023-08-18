#include <QApplication>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QtGlobal>

QString toString(QPointF point)
{
    return QString("(%1, %2)").arg(point.x()).arg(point.y());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPointF mePoint1(1,1);
    QPointF mePoint1Glob(10,10);
    QMouseEvent *me1 = new QMouseEvent(QEvent::MouseMove, mePoint1, mePoint1Glob, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    Q_ASSERT_X(me1->scenePosition() == mePoint1, "After first event created", QString("Unexpected scenePosition in first point event. Expected %1, Actual %2").arg(toString(mePoint1), toString(me1->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(me1->globalPosition() == mePoint1Glob, "After first event created", QString("Unexpected globalPosition in first point event. Expected %1, Actual %2").arg(toString(mePoint1Glob), toString(me1->globalPosition())).toLocal8Bit());

    QPointF mePoint2(2, 2);
    QPointF mePoint2Glob(20, 20);
    QMouseEvent *me2 = new QMouseEvent(QEvent::HoverMove, mePoint2, mePoint2Glob, mePoint2, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    Q_ASSERT_X(me2->scenePosition() == mePoint2, "After second event created", QString("Unexpected scenePosition in second point event. Expected %1, Actual %2").arg(toString(mePoint2), toString(me2->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(me2->globalPosition() == mePoint2Glob, "After second event created", QString("Unexpected globalPosition in second point event. Expected %1, Actual %2").arg(toString(mePoint2Glob), toString(me2->globalPosition())).toLocal8Bit());

    Q_ASSERT_X(me1->scenePosition() == mePoint1, "After second event created", QString("Unexpected scenePosition in first point event. Expected %1, Actual %2").arg(toString(mePoint1), toString(me1->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(me1->globalPosition() == mePoint1Glob, "After second event created", QString("Unexpected globalPosition in first point event. Expected %1, Actual %2").arg(toString(mePoint1Glob), toString(me1->globalPosition())).toLocal8Bit());

    QPointF hePoint(3, 3);
    QPointF hePointGlob(30, 30);
    QHoverEvent *he = new QHoverEvent(QEvent::HoverMove, hePoint, hePointGlob, hePoint, Qt::NoModifier);
    Q_ASSERT_X(he->scenePosition() == hePoint, "After third (hover) event created", QString("Unexpected scenePosition in third (hover) point event. Expected %1, Actual %2").arg(toString(hePoint), toString(he->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(he->globalPosition() == hePointGlob, "After third (hover) event created", QString("Unexpected globalPosition in third (hover) point event. Expected %1, Actual %2").arg(toString(hePointGlob), toString(he->globalPosition())).toLocal8Bit());

    Q_ASSERT_X(me1->scenePosition() == mePoint1, "After third (hover) event created", QString("Unexpected scenePosition in first point event. Expected %1, Actual %2").arg(toString(mePoint1), toString(me1->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(me1->globalPosition() == mePoint1Glob, "After third (hover) event created", QString("Unexpected globalPosition in first point event. Expected %1, Actual %2").arg(toString(mePoint1Glob), toString(me1->globalPosition())).toLocal8Bit());

    return 0;
}
