#include "rangeview.h"
#include "util.h"

RangeView::RangeView(QObject *parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 650, 650);
    QRectF  sceneGeometry = sceneRect();
    int sizeX = sceneGeometry.x();
    int sizeY = sceneGeometry.y();
    for (int i = 0; i <= 13; i++)
    {
        addLine(0, i * 50, 50 * 13,  i * 50, QPen(Qt::gray));
        addLine(i * 50, 0, i * 50, 50 * 13, QPen(Qt::gray));
    }
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            HandViewItem *hand_item = new HandViewItem;
            hand_item->setPos(i * 50, j * 50);
            QRectF rect = hand_item->rect();
            l_hand_item.append(hand_item);
            addItem(hand_item);
            if (i == 1 && j == 1)
                hand_item->activate();
        }
    }

}
