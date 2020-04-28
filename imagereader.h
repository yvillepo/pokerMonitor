#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include "card.h"
#include "hand.h"
#include "util.h"
#include <QImage>
#include <QPixmap>
#include <QPair>

typedef enum xfct{
    Rstack,
    Rcard,
} typeReader;

class ImageReader : public QObject
{
    Q_OBJECT
private:
    bool init;
    QPixmap pixEcran;
    QImage imEcran;
    QList<QPair<QImage,  QString>> strIm;
    QList<QPair<QImage, int>> intIm;
    QMap<e_position, unsigned int> pixBoardPosition;
    QMap<e_position, QPoint> posPixel;
public:
    ImageReader(QString folder = "/Users/yann/dbpoker/img/card/", typeReader = Rcard);
    ImageReader(QString folder1, QString folder2){};
    Card            readCard(QImage card);
    Hand            readHand();
    e_position      readPosition();
    void            initPixBoardPosition(int nbJoueur = 6);
    bool            exist(QImage card);
    int             readNumber(QImage number);
    float           readStack(QImage stack){return 0.0;}
    QImage          scan(int x, int y, int width, int height);
public slots:
    void refrechEcran();

private:
    void    fillListImgCard(QString folder);
    bool    testInit();
};
#endif // IMAGEREADER_H
