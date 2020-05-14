#ifndef PREFLOPHELPERWIDGET_H
#define PREFLOPHELPERWIDGET_H

#include "util.h"
#include "imagereader.h"
#include "myopenrange.h"
#include <QStackedWidget>
#include <QWidget>

class PreflopHelperWidget : public QWidget
{
    Q_OBJECT

private:
    QStackedWidget  *stackRange;
    myOpenRange     *openRange;
    QPushButton     *btStart;
    QLabel          *LabHand;
    QLabel          *labPos;
    QLabel          *labOpen;
    ImageReader     *scanner;
    bool            start;

public:
    PreflopHelperWidget(QWidget *parent = nullptr);
    ~PreflopHelperWidget();
public slots:
    void setPosition(e_position pos);
    void setHandPosition(Hand h, e_position pos);
    void toogleScan();
};

#endif // PREFLOPHELPERWIDGET_H
