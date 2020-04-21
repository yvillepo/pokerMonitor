#include "scan_hand.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QScrollArea>
#include <QGridLayout>
#include <QPixmap>
#include <QApplication>

scanHand::scanHand(QString pathCard)
{
    init();
    QDir d(pathCard);
    QFileInfoList fi = d.entryInfoList();
    for (int i(0); i < fi.size(); i++)
    {
        if (fi.at(i).filePath().endsWith("/.") || fi.at(i).filePath().endsWith("/.."))
            continue;
        listPairImage.push_back(qMakePair(QImage(fi.at(i).filePath()),fi.at(i).baseName()));
    }
//    QApplication::beep();
    test();
}

QString scanHand::convertCardImageToStr(QImage image)
{
    for (int i = 0; i < listPairImage.size(); i++)
    {
        if (listPairImage.at(i).first == image)
        {
            qDebug() << "corespondance trouver" << endl;
//            QApplication::beep();
            return listPairImage.at(i).second;
        }
    }
    qDebug() << "corespondance non trouver" << endl;
    return "carte non identifié";
}

QString scanHand::convertHandStr(QImage im1, QImage im2)
{
    QString str1 = convertCardImageToStr(im1);
    QString str2 = convertCardImageToStr(im2);
    lc1->setPixmap(QPixmap::fromImage(im1));
    lc2->setPixmap(QPixmap::fromImage(im2));
    ln1->setText(str1);
    ln2->setText(str2);
    return str1 + str2;
}

void scanHand::test()
{
      qDebug() << "ok ?" << convertCardImageToStr(QImage("/Users/yann/dbpoker/img/card2/2h.png")) << endl;
}

void scanHand::init()
{
    w = new QWidget();
    lay = new QHBoxLayout();
    lc1 = new QLabel();
    lc2 = new QLabel();
    ln1 = new QLabel();
    ln2 = new QLabel();
    lay->addWidget(lc1);
    lay->addWidget(ln1);
    lay->addWidget(lc2);
    lay->addWidget(ln2);
    w->setLayout(lay);
    w->show();
}


