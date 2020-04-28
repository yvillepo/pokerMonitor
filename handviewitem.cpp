#include "handviewitem.h"
#include <QPen>
#include <QPainter>

HandViewItem::HandViewItem()
{
    setRect(0, 0, 50, 50);
    setPen((QPen(Qt::black)));
    setBrush(QBrush(Qt::gray));
    setFlag(QGraphicsItem::ItemIsSelectable);
}

void HandViewItem::activate()
{

}
