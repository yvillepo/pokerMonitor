#ifndef RANGEVIEW_H
#define RANGEVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include "handviewitem.h"

class RangeView : public QGraphicsScene
{
    Q_OBJECT
public:
    RangeView(QObject *parent = nullptr );
    QList<HandViewItem*> l_hand_item;
private:
};

#endif // RANGEVIEW_H
