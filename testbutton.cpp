#include "testbutton.h"
#include <QPushButton>
#include <QDebug>

testButton::testButton(QWidget *parent) : QPushButton(parent)
{
//    qDebug() << hasHeightForWidth();
//    qDebug() << sizePolicy().hasHeightForWidth();
    //if(!hasHeightForWidth())
        sizePolicy().setHeightForWidth(true);
//    qDebug() << hasHeightForWidth();
//    qDebug() << sizePolicy().hasHeightForWidth();
        //setBackgroundRole(QPalette::Light);
}

QSize   testButton::sizeHint() const
{
//    QSize s = QPushButton::sizeHint();
//    s.setHeight(s.width());
//    return s;
    return QSize(41,36);
}

int heightForWidth(int w)
{
    return w;
}
