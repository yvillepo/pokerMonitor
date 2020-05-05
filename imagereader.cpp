#include "imagereader.h"
#include <QFile>
#include <QDir>
#include <QtWidgets>
#include <iostream>
#include <QGridLayout>
#include <thread>
#include <chrono>

#define POSX 198
#define POSY 23
#define SIZEX 1242
#define SIZEY 877


ImageReader::ImageReader(QString folder, typeReader type, uint timeRefrech):
    init(false),
    refrechTimer(new QTimer(this)),
    lastPos(NULLpos)
{
    if (type == Rcard)
        fillListImgCard(folder);
    refrechEcran();
    initPixPosition();
    testInit();
    connect(refrechTimer, SIGNAL(timeout()), this, SLOT(readInfo()));
}

ImageReader::~ImageReader()
{
    qDebug() << "Imagereader supr" << endl;
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

void    ImageReader::readInfo()
{
    refrechEcran();
    e_position pos = readPosition();
    if (pos != lastPos)
    {
        lastPos = pos;
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
                emit newHand(h, pos);
            start();
        }
    }
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
    card1 = scan(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2);
    card2  = scan(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2);
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
    if (!testInit())
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

void ImageReader::start(int time)
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

DiagnosticScanner::DiagnosticScanner(QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent, f),
    imRead(new ImageReader()),
    mainBoxLayout(new QGridLayout(this)),
    nbHandRead(0),
    diagnostic(false),
    boolShowPixPox(false),
    labImC1(4, nullptr), labImC2(4, nullptr), labStrCart(4, nullptr),
    nbReRead(0),
    lastHand(Card(), Card()), lastPosition(NULLpos),
    refrechTimer(new QTimer(this))
{
    QGroupBox *hand = new QGroupBox(tr("Hand"), this);
    QGroupBox *position = new QGroupBox(tr("position"), this);
    QGroupBox *gbLastHand = new QGroupBox(tr("Last Hand"), this);

    //*********************HAND**************************/
    QVBoxLayout *handsLay = new QVBoxLayout(hand);
    for (int i = 0; i < 4; i++)
    {
        labImC1[i] = new QLabel(this);
        labImC2[i] = new QLabel(this);
        labStrCart[i] = new QLabel(this);
    }
    for (int i = 0; i < 4; i++)
    {
        QHBoxLayout *handLay = new QHBoxLayout();
        handsLay->addLayout(handLay);
        handLay->addWidget(labImC1[i]);
        handLay->addWidget(labImC2[i]);
        handLay->addWidget(labStrCart[i]);
    }
    /**********************************************************/
    /*********************FOOTER*******************************/
    QHBoxLayout *footer = new QHBoxLayout();
    refreshRateEdit = new QLineEdit("1000", this);
    BtLancerTest = new QPushButton(tr("Start Diag"),this);
    newValueLabel = new QLabel(this);
    newValueLabel->setNum(nbHandRead);
    footer->addWidget(BtLancerTest);
    footer->addWidget(refreshRateEdit);
    footer->addWidget(newValueLabel);
    /**************************************************************/
    /************************POSITION******************************/
    QGridLayout *posLay = new QGridLayout(position);
    for (int i = 0; i < 6; i++)
    {
        e_position pos = static_cast<e_position>(i);
        labPos[pos] = new QLabel("KO", this);
        posLay->addWidget(new QLabel(stringPos(pos), this), i, 0);
        posLay->addWidget(labPos[pos], i, 1);
        labPixPos[pos] = new QLabel("pixEcran", this);
        posLay->addWidget(labPixPos[pos], i, 2);
        labPixPos[pos]->hide();
    }
    btShowPixPox = new QPushButton("Show PixPos", this);
    connect(btShowPixPox, &QPushButton::clicked, this, &DiagnosticScanner::toogleShowPixPos);
    posLay->addWidget(btShowPixPox, 6, 0, 1, 2);
    /****************************************************************/
    /**************************LastHand******************************/
    QHBoxLayout *layLastHand = new QHBoxLayout(gbLastHand);
    labLastHand = new QLabel("Last Hand", this);
    labNbReRead = new QLabel("nbReRead", this);
    layLastHand->addWidget(labLastHand);
    layLastHand->addWidget(labNbReRead);
    /****************************************************************/
    mainBoxLayout->addWidget(hand, 0 , 0, 1, 1);
    mainBoxLayout->addWidget(position, 0, 1, 1, 1);
    mainBoxLayout->addWidget(gbLastHand, 1, 0, 1, 2);
    mainBoxLayout->addLayout(footer, 2, 0, 1, 2);

    setLayout(mainBoxLayout);

    connect(BtLancerTest, SIGNAL(clicked()), this, SLOT(toogleDiagnostic()));
    connect(imRead, SIGNAL(newHand(Hand, e_position)) , this, SLOT(updateLastHand(Hand, e_position)));
    connect(refrechTimer, &QTimer::timeout, this, &DiagnosticScanner::newHand);
}

void    DiagnosticScanner::startDiagnostic()
{
    imRead->start(QString(refreshRateEdit->text()).toInt());
    refrechTimer->start(QString(refreshRateEdit->text()).toInt() + 300);
    BtLancerTest->setText("Stop Diag");
    refreshRateEdit->setDisabled(true);
    diagnostic = true;
}

void    DiagnosticScanner::stopDiagnostic()
{
    imRead->stop();
    refrechTimer->stop();
    BtLancerTest->setText("Start Diag");
    refreshRateEdit->setDisabled(false);
    diagnostic = false;
}

void    DiagnosticScanner::toogleDiagnostic()
{
    if (diagnostic)
        stopDiagnostic();
    else
        startDiagnostic();
}

void    DiagnosticScanner::newHand()
{
    Hand newHand = imRead->readHand();
    updateHand(newHand);
    updatePosition();
    if (boolShowPixPox)
        updatePixPox();
    newValueLabel->setNum(++nbHandRead);
}

void    DiagnosticScanner::updateLastHand(Hand newHand, e_position newPosition)
{
    if (lastHand == newHand && lastPosition == newPosition)
    {
        labNbReRead->setNum(++nbReRead);
        return ;
    }
    nbReRead = 0;
    labLastHand->setText(newHand.str_hand + " " + stringPos(newPosition));
    labNbReRead->setNum(nbReRead);
}

void    DiagnosticScanner::updatePosition()
{
    for (int i = 0; i < 6; i++)
    {
        e_position pos = static_cast<e_position>(i);
        if (imRead->isPosition(pos))
            labPos[pos]->setText("OK");
        else
            labPos[pos]->setText("KO");
    }
}

void    DiagnosticScanner::updateHand(Hand newHand)
{
    int nb = nbHandRead > 3 ? 3 : nbHandRead;
    for (int i = nb; i > 0; i--)
    {
        labImC1[i]->setPixmap(*(labImC1[i - 1]->pixmap()));
        labImC2[i]->setPixmap(*(labImC2[i - 1]->pixmap()));
        labStrCart[i]->setText(labStrCart[i - 1]->text());
    }
    labImC1[0]->setPixmap(QPixmap::fromImage(imRead->card1));
    labImC2[0]->setPixmap(QPixmap::fromImage(imRead->card2));
    labStrCart[0]->setText(newHand.getStrHand());
}

void    DiagnosticScanner::toogleShowPixPos()
{
    boolShowPixPox = !boolShowPixPox;
    for (int i = 0; i < 6; i++)
    {
        e_position pos = static_cast<e_position>(i);
        if (boolShowPixPox)
            labPixPos[pos]->show();
        else
            labPixPos[pos]->hide();
    }
}

void    DiagnosticScanner::updatePixPox()
{
    for (int i = 0; i < 6; i++)
    {
        e_position pos = static_cast<e_position>(i);
        labPixPos[pos]->setText(QString::number(imRead->imEcran.pixel(imRead->posPixel[pos])));
    }
}

DiagnosticScanner::~DiagnosticScanner()
{
    emit deleteSignal();
    delete imRead;
}
