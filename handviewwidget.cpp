#include "handviewwidget.h"
#include <QPainter>

HandViewWidget::HandViewWidget(QString text, QWidget *parent) :
    QWidget(parent),
    type_hand(text)
{
    brush = Qt::gray;
}

void HandViewWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(Qt::black);
    p.setBrush(brush);
    p.drawRect(0,0,this->width(), this->height());
    p.drawText(QRectF(0,0, this->width(), this->height()), type_hand, QTextOption(Qt::AlignCenter));
}

void HandViewWidget::color(const QBrush brush)
{
    this->brush = brush;
    repaint();
}
