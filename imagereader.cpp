#include "imagereader.h"
#include <QFile>
#include <QDir>
#include <QtWidgets>
#include <iostream>

#define POSX 198
#define POSY 23
#define SIZEX 1242
#define SIZEY 877


ImageReader::ImageReader(QString folder, typeReader type):
    init(false)
{
    if (type == Rcard)
        fillListImgCard(folder);
    refrechEcran();
    readHand();
    testInit();
}

Card    ImageReader::readCard(QImage cardIm)
{
    /*****************Pas du tout OPTI********************/
    cardIm.save("/Users/yann/dbpoker/img/tmp/x.png");               //la comparéson a partir d'un image juste
    QImage  ImageFromFile("/Users/yann/dbpoker/img/tmp/x.png");     // scanné ne fonctionne pas IDK Why
    /****************************************************/
    for (int i = 0; i < strIm.size(); i++)
        if (strIm.at(i).first == ImageFromFile)
            return Card(strIm.at(i).second);
    return Card();
}

void    ImageReader::refrechEcran()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    pixEcran = screen->grabWindow(0, POSX, POSY, SIZEX, SIZEY);
    imEcran = pixEcran.toImage();

}

bool    ImageReader::exist(QImage cardIm)
{
    /*****************Pas du tout OPTI********************/
    cardIm.save("/Users/yann/dbpoker/img/tmp/x.png");               //la comparéson a partir d'un image juste
    QImage  ImageFromFile("/Users/yann/dbpoker/img/tmp/x.png");     // scanné ne fonctionne pas IDK Why
    /****************************************************/
    for (int i = 0; i < strIm.size(); i++)
        if (strIm.at(i).first == ImageFromFile)
            return true;
    return false;
}

Hand ImageReader::readHand()
{
    QImage card1 = scan(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    QImage card2  = scan(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    return Hand(readCard(card1), readCard(card2));
}

int ImageReader::readNumber(QImage number)
{
    return -1;
}

void ImageReader::fillListImgCard(QString folder)
{
    QDir d(folder);
    QFileInfoList fi = d.entryInfoList();
    for (int i(0); i < fi.size(); i++)
    {
        if (fi.at(i).filePath().endsWith("/.") || fi.at(i).filePath().endsWith("/.."))
            continue;
          strIm.push_back(
                      (qMakePair ( QImage(fi.at(i).filePath() ) ,
                       fi.at(i).baseName()))
                      );
    }
}

e_position ImageReader::readPosition()
{
    if (!testInit())
        return NULLpos;
    if (pixBoardPosition[UTG] != imEcran.pixel(posPixel[UTG]))
        return UTG;
    if (pixBoardPosition[MP] != imEcran.pixel(posPixel[MP]))
        return MP;
    if (pixBoardPosition[CO] != imEcran.pixel(posPixel[CO]))
        return CO;
    if (pixBoardPosition[BT] != imEcran.pixel(posPixel[BT]))
        return BT;
    if (pixBoardPosition[SB] != imEcran.pixel(posPixel[SB]))
        return SB;
    if (pixBoardPosition[BB] != imEcran.pixel(posPixel[BB]))
        return BB;
    return NULLpos;
}

void    ImageReader::initPixBoardPosition(int nbJoueur)
{
    if (nbJoueur == 6)
    {
        posPixel[UTG] = QPoint(676, 230);
        posPixel[MP] = QPoint(394, 236);
        posPixel[CO] = QPoint(258, 416);
        posPixel[BT] = QPoint(504, 549);
        posPixel[SB] = QPoint(917, 504);
        posPixel[BB] = QPoint(978, 300);

        pixBoardPosition[UTG] = imEcran.pixel(posPixel[UTG]);
        pixBoardPosition[MP] = imEcran.pixel(posPixel[MP]);
        pixBoardPosition[CO] = imEcran.pixel(posPixel[CO]);
        pixBoardPosition[BT] = imEcran.pixel(posPixel[BT]);
        pixBoardPosition[SB] = imEcran.pixel(posPixel[SB]);
        pixBoardPosition[BB] = imEcran.pixel(posPixel[BB]);
    }
}

bool    ImageReader::testInit()
{
    if (!init)
    {
        if (readHand().getStrHand() == "xx")
        {
            initPixBoardPosition();
            std::cout << "initialisation du lecteur de position OK" << std::endl;
            init = true;
            return true;
        }
    }
    else
        return true;
    return false;

}

QImage ImageReader::scan(int x, int y, int width, int height)
{
   return imEcran.copy(x, y, width, height);
//    QPixmap p = pixEcran.copy(x, y, width, height);
//    return p.toImage();
}


