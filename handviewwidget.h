#ifndef HANDVIEWWIDGET_H
#define HANDVIEWWIDGET_H

#include <QWidget>
#include <QPainter>

class HandViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HandViewWidget(QString test, QWidget *parent = nullptr);
    void    color(QColor color = Qt::green);
    void    colorContour(const QColor = Qt::darkGreen, int width = 6);
    void    toggleSelect();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QString type_hand;
    QPen    pen;
    QBrush  brush;
    bool    select;
    QPen    penSelect;

signals:

};

#endif // HANDVIEWWIDGET_H
