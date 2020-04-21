#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include "card.h"
#include "hand.h"
#include <QImage>
#include <QPair>

typedef enum xfct{
    Rstack,
    Rcard,
} typeReader;

class ImageReader
{
private:
    QList<QPair<QImage,  QString>> strIm;
    QList<QPair<QImage, int>> intIm;
public:
    ImageReader(QString folder = "/Users/yann/dbpoker/img/card/", typeReader = Rcard);
    ImageReader(QString folder1, QString folder2);
    Card    readCard(QImage card);
    Hand    readHand(QImage card){}
    int     readNumber(QImage number);
    float   readStack(QImage stack){}
private:
    void    fillListImgCard(QString folder);
};
#endif // IMAGEREADER_H
