#ifndef SCAN_HAND_H
#define SCAN_HAND_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>


class scanHand
{
public:
    scanHand(QString pathCard = "/Users/yann/dbpoker/img/card");
    QString convertCardImageToStr(QImage image);
    QString convertHandStr(QImage im1, QImage im2);
    void    test();
    void    init();
private:
    QList<QPair<QImage, QString>> listPairImage;
    QWidget *w;
    QHBoxLayout *lay;
    QLabel *lc1;
    QLabel *ln1;
    QLabel *lc2;
    QLabel *ln2;
};

#endif // SCAN_HAND_H
