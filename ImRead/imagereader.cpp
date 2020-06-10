#include "imagereader.h"
#include <QFile>
#include <QDir>
#include <QtWidgets>
#include <iostream>
#include <QGridLayout>
#include <thread>
#include <chrono>

ImOption *ImageReader::getOption() const
{
    return option;
}

ImageReader::ImageReader(QString folder, typeReader type, uint timeRefrech):
    init(false),
    refrechTimer(new QTimer(this)),
    lastPos(NULLpos)
{
    option = new ImOption();
    for (int i = 0; i < option->getNbJoueur(); i++) lStack.append(0);
    if (type == Rcard)
        fillListImgCard(folder);
    refrechEcran();
    initPixPosition();
    testInit();
    connect(refrechTimer, SIGNAL(timeout()), this, SLOT(readInfo()));
}

ImageReader::~ImageReader()
{
    qDebug() << "Imagereader supr";
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
    QRect rW = option->getScreenRect();
    pixEcran = screen->grabWindow(0, rW.x(), rW.y(), rW.width(), rW.height());
    imEcran = pixEcran.toImage();
}

void    ImageReader::readInfo()
{
    refrechEcran();
    e_position pos = readPosition();
    if (pos != lastPos)
    {
        lastPos = pos;
        readValidHand();
    }
    readStacks();
    emit refresh();

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
    card1 = scan(option->card1Rect);
    card2  = scan(option->card2Rect);
    return Hand(readCard(card1), readCard(card2));
}

bool ImageReader::readValidHand() // la position
{
    e_position pos = lastPos; //effet du a la recopie dans une nouvelle fonction (enciennement dans  read Info)
    bool handValid = false;
    qDebug() << "nouvelle Position " + stringPos(pos)  << endl;
    if (pos != NULLpos)
    {
        stop();
        int tryReadHand = 5;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        refrechEcran();
        Hand h = readHand();
        qDebug() << " main : " + h.getStrHand() << endl;
        while (!h.isValid() && tryReadHand)
        {
            qDebug() << " main : " + h.getStrHand() << endl;
            if (!h.isValid())
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            tryReadHand--;
            refrechEcran();
            h = readHand();
        }
        if (h.isValid())
        {
            handValid = true;
            emit newHand(h, pos);
        }
        start();
    }
    return handValid;
}

int ImageReader::readNumber(QImage number)
{
    return -1;
}

void ImageReader::readStacks()
{
    lStack.replace(0, readStack(scan(*option->betRect.at(0))));
}

float ImageReader::readStack(QImage const stack)
{
    int etatVirgule = findVirgule(stack);
    qDebug() << "etta virgule : " << etatVirgule;
    return -1;
}

int ImageReader::findVirgule(QImage const stack)
{
    QImage v1 = stack.copy(18, 13, 6, 3);
    QImage v2 = stack.copy(24, 13, 6, 3);
    QImage v3 = stack.copy(30, 13, 6, 3);

    QImage virgule = QImage(":/virgule.png");

    /*****************Pas du tout OPTI********************/
    v1.save("/Users/yann/dbpoker/img/tmp/x.png");               //la comparéson a partir d'un image juste
    QImage  v1FromFile("/Users/yann/dbpoker/img/tmp/x.png");     // scanné ne fonctionne pas IDK Why
    /****************************************************/
    if (v1FromFile == virgule || v1 == virgule)
        return 1;
    /*****************Pas du tout OPTI********************/
    v2.save("/Users/yann/dbpoker/img/tmp/x.png");               //la comparéson a partir d'un image juste
    QImage  v2FromFile("/Users/yann/dbpoker/img/tmp/x.png");     // scanné ne fonctionne pas IDK Why
    /****************************************************/
    if (v2FromFile == virgule || v2 == virgule)
        return 2;
    /*****************Pas du tout OPTI********************/
    v3.save("/Users/yann/dbpoker/img/tmp/x.png");               //la comparéson a partir d'un image juste
    QImage  v3FromFile("/Users/yann/dbpoker/img/tmp/x.png");     // scanné ne fonctionne pas IDK Why
    /****************************************************/
    if (v3FromFile == virgule)
        return 3;
    if (v3 == virgule)
        return 3;
    return 0;

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

bool        ImageReader::isPosition(e_position pos)
{
    return pixPosition[pos] == imEcran.pixel(posPixel[pos]);
}

void        ImageReader::initPixPosition()
{
    pixPosition[BB] = PIXBB;
    pixPosition[SB] = PIXSB;
    pixPosition[BT] = PIXBT;
    pixPosition[CO] = PIXCO;
    pixPosition[MP] = PIXMP;
    pixPosition[UTG] = PIXUTG;
}

e_position ImageReader::readPosition()
{
    if (!testInit())   // a enlevé ?? Obsolette??
        return NULLpos;
    if (isPosition(UTG))
        return UTG;
    if (isPosition(MP))
        return MP;
    if (isPosition(CO))
        return CO;
    if (isPosition(BT))
        return BT;
    if (isPosition(SB))
        return SB;
    if (isPosition(BB))
        return BB;
    return NULLpos;
}

void    ImageReader::initPixBoardPosition(int nbJoueur)
{
    Q_UNUSED(nbJoueur);
    for (int i = 0; i < option->getNbJoueur(); i++)
    {
        posPixel[static_cast<e_position>(i)] = *option->posPixel.at(i);
        pixBoardPosition[static_cast<e_position>(i)] = imEcran.pixel(*option->posPixel.at(i));
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

QImage ImageReader::scan(QRect rect)
{
    return scan(rect.x(), rect.y(), rect.width(), rect.height());
}

void ImageReader::start(int time) // a revoir
{
    if (time)
    {
        refrechTimer->start(time);
    }
    else
    {
        refrechTimer->start();
    }
}

void    ImageReader::stop()
{
    refrechTimer->stop();
}
