#include "handviewwidget.h"

HandViewWidget::HandViewWidget(QString text, QWidget *parent) :
    QWidget(parent),
    type_hand(text)
{
    brush = Qt::gray;
    pen.setColor(Qt::black);
    penSelect = QPen(Qt::blue, 7);
    select = false;
}

void HandViewWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setBrush(brush);
    p.setPen(select ? penSelect : pen);
    p.drawRect(0,0,this->width() - 1, this->height() - 1);
    p.setPen(pen);
    p.drawText(QRectF(0 ,0, this->width() - 1, this->height() - 1), type_hand, QTextOption(Qt::AlignCenter));
}

void HandViewWidget::color(const QColor color)
{
    this->brush = QBrush(color);
    update();
}

void HandViewWidget::colorContour(const QColor color, int width)
{
    select = true;
    penSelect = QPen(color, width);
    update();
}

void HandViewWidget::toggleSelect()
{
    select = !select;
    update();
}
