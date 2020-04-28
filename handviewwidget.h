#ifndef HANDVIEWWIDGET_H
#define HANDVIEWWIDGET_H

#include <QWidget>

class HandViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HandViewWidget(QString test, QWidget *parent = nullptr);
    void    color(const QBrush = Qt::green);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QString type_hand;
    QBrush  brush;

signals:

};

#endif // HANDVIEWWIDGET_H
