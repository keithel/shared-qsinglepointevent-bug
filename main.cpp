#include <QApplication>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QtAssert>

QString toString(QPointF point)
{
    return QString("(%1, %2)").arg(point.x()).arg(point.y());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPointF mePoint(1,1);
    QPointF mePointGlob(10,10);
    QMouseEvent *me = new QMouseEvent(QEvent::MouseMove, mePoint, mePointGlob, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    Q_ASSERT_X(me->scenePosition() == mePoint, "After first event created", QString("Unexpected scenePosition in first point event (mouse). Expected %1, Actual %2").arg(toString(mePoint)).arg(toString(me->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(me->globalPosition() == mePointGlob, "After first event created", QString("Unexpected globalPosition in first point event (mouse). Expected %1, Actual %2").arg(toString(mePointGlob)).arg(toString(me->globalPosition())).toLocal8Bit());

    QPointF hePoint(2, 2);
    QPointF hePointGlob(20, 20);
    QHoverEvent *he = new QHoverEvent(QEvent::HoverMove, hePoint, hePointGlob, hePoint, Qt::NoModifier);
    Q_ASSERT_X(he->scenePosition() == hePoint, "After second event created", QString("Unexpected scenePosition in second point event (hover). Expected %1, Actual %2").arg(toString(hePoint)).arg(toString(he->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(he->globalPosition() == hePointGlob, "After second event created", QString("Unexpected globalPosition in second point event (hover). Expected %1, Actual %2").arg(toString(hePointGlob)).arg(toString(he->globalPosition())).toLocal8Bit());

    Q_ASSERT_X(me->scenePosition() == mePoint, "After second event created", QString("Unexpected scenePosition in first point event (mouse). Expected %1, Actual %2").arg(toString(mePoint)).arg(toString(me->scenePosition())).toLocal8Bit());
    Q_ASSERT_X(me->globalPosition() == mePointGlob, "After second event created", QString("Unexpected globalPosition in first point event (mouse). Expected %1, Actual %2").arg(toString(mePointGlob)).arg(toString(me->globalPosition())).toLocal8Bit());
    return 0;
}
