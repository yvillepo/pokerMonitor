#ifndef RANGEVIEWWIDGET_H
#define RANGEVIEWWIDGET_H

#include <QWidget>
#include <QLayout>
#include "handviewwidget.h"
#include "range.h"

class RangeViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RangeViewWidget(Range r = Range(), QWidget *parent = nullptr);
private:
    QGridLayout *main_layout;
    QList<HandViewWidget *> l_hands_widget;
    Range                   range;

signals:

};

#endif // RANGEVIEWWIDGET_H
