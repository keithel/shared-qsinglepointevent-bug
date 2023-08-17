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
    QMouseEvent *me = new QMouseEvent(QEvent::MouseMove, mePoint, mePoint, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    Q_ASSERT_X(me->position() == mePoint, "After first event created", QString("Unexpected position in first point event (mouse). Expected %1, Actual %2").arg(toString(mePoint)).arg(toString(me->position())).toLocal8Bit());

    QPointF hePoint(2, 2);
    QHoverEvent *he = new QHoverEvent(QEvent::HoverMove, hePoint, hePoint, hePoint, Qt::NoModifier);
    Q_ASSERT_X(he->position() == hePoint, "After second event created", QString("Unexpected position in second point event (hover). Expected %1, Actual %2").arg(toString(hePoint)).arg(toString(he->position())).toLocal8Bit());

    Q_ASSERT_X(me->position() == mePoint, "After second event created", QString("Unexpected position in first point event (mouse). Expected %1, Actual %2").arg(toString(mePoint)).arg(toString(me->position())).toLocal8Bit());
    return 0;
}
