#include "diagnosticscanner.h"
#include <QGroupBox>

DiagnosticScanner::DiagnosticScanner(QWidget *parent, Qt::WindowFlags f) :
    QWidget(parent, f),
    imRead(new ImageReader()),
    mainBoxLayout(new QGridLayout(this)),
    nbHandRead(0),
    diagnostic(false),
    boolShowPixPox(false),
    labImC1(4, nullptr), labImC2(4, nullptr), labStrCart(4, nullptr),
    nbRead(0),
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
    labNbRead = new QLabel("nbReRead", this);
    layLastHand->addWidget(labLastHand);
    layLastHand->addWidget(labNbRead);
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

    labNbRead->setNum(++nbRead);

    labLastHand->setText(newHand.str_hand + " " + stringPos(newPosition));
    labNbRead->setNum(nbRead);
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

