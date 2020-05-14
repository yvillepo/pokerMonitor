#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include "card.h"
#include "hand.h"
#include "util.h"
#include <QVector>
#include <QImage>
#include <QPixmap>
#include <QPair>
#include <QTimer>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>

using namespace std;

#define  PIXUTG    4291048756
#define  PIXMP     4290983220
#define  PIXCO     4290917428
#define  PIXBT     4290917428
#define  PIXSB     4291048756
#define  PIXBB     4290917428


typedef enum xfct{
    Rstack,
    Rcard,
} typeReader;

class ImageReader : public QObject
{
    Q_OBJECT
private:
    bool init;
    QTimer  *refrechTimer;
    friend class DiagnosticScanner;
    QImage  card1;
    QImage  card2;
    QPixmap pixEcran;
    QImage imEcran;
    QList<QPair<QImage,  QString>> strIm;
    QList<QPair<QImage, int>> intIm;
    e_position                      lastPos;
    QMap<e_position, unsigned int>  pixBoardPosition;
    QMap<e_position, unsigned int>  pixPosition;
    QMap<e_position, QPoint> posPixel;
public:
    ImageReader(QString folder = "/Users/yann/dbpoker/img/card/", typeReader = Rcard, uint timeRefrech = 1000);
   // ImageReader(QString folder1, QString folder2){};
    ~ImageReader();
    Card            readCard(QImage card);
    Hand            readHand();
    e_position      readPosition();
    void            initPixBoardPosition(int nbJoueur = 6);
    bool            exist(QImage card);
    int             readNumber(QImage number);
 //   float           readStack(QImage stack){return 0.0;}
    QImage          scan(int x, int y, int width, int height);
public slots:
    void refrechEcran();
    void start(int time = 1000); // a revoit (t = 0 ? )
    void stop();
    void readInfo();
signals:
    void newHand(Hand newHand, e_position newPosition = NULLpos);

private:
    void            fillListImgCard(QString folder);
    bool            testInit();
    bool            isPosition(e_position pos);
    void            initPixPosition();
//    inline bool     isBB();
//    inline bool     isSB();
//    inline bool     isBT();
//    inline bool     isCO();
//    inline bool     isMP();
//    inline bool     isUTG();

};

class DiagnosticScanner : public QWidget
{
    Q_OBJECT
private:
    ImageReader                 *imRead;
    QTimer                      *refrechTimer;
    bool                        diagnostic;
    bool                        boolShowPixPox;
    int                         nbHandRead;
    QGridLayout                 *mainBoxLayout;
    QLineEdit                   *refreshRateEdit;
    QPushButton                 *BtLancerTest;
    QLabel                      *newValueLabel;
    QVector<QLabel*>            labImC1;
    QVector<QLabel*>            labImC2;
    QVector<QLabel*>            labStrCart;
    QMap<e_position, QLabel*>   labPos;
    QMap<e_position, QLabel*>   labPixPos;
    QPushButton                 *btShowPixPox;
    Hand                        lastHand;
    e_position                  lastPosition;
    int                         nbReRead;
    QLabel                      *labLastHand;
    QLabel                      *labNbReRead;
public:
    DiagnosticScanner(QWidget *parent = nullptr, Qt::WindowFlags f = 0);
    ~DiagnosticScanner();
public slots:
    void    startDiagnostic();
    void    stopDiagnostic();
    void    toogleDiagnostic();
    void    newHand();
    void    updateLastHand(Hand newHand, e_position newPosition);
    void    toogleShowPixPos();
private:
    void    updateHand(Hand newHand);
    void    updatePosition();
    void    updatePixPox();
signals:
    void    deleteSignal();
};

#endif // IMAGEREADER_H
