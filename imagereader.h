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
#include <QAbstractTableModel>

using namespace std;

#define POSX 198
#define POSY 23
#define SIZEX 1242
#define SIZEY 877


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

class ImOption {
public:
    ImOption (int nbJoueur = 6,
              QRect screenRect = QRect(POSX, POSY, SIZEX, SIZEY),
              QRect card1Rect = QRect(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2),
              QRect car2Rect = QRect(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2),
              QList<QPoint> posPix= {QPoint(978, 300), QPoint(917, 504), QPoint(504, 549), QPoint(258, 416), QPoint(394, 236), QPoint(676, 230)},
              QList<QRect> betRect = {QRect(0,0,0,0), QRect(1,1,1,1), QRect(2,2,2,2), QRect(3,3,3,3), QRect(4,4,4,4), QRect(5,5,5,5)});
public:
    int                         nb_joueur;
    QRect                       screenRect;
    QRect                       card1Rect;
    QRect                       card2Rect;
    QList<QPoint>               posPixel;
    QList<QRect>                betRect;
};

class ImOptionModel : public QAbstractTableModel
{
public:
    explicit ImOptionModel(QObject *parent = nullptr);
    explicit ImOptionModel(ImOption *imOpt ,QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant    displayRect(const QRect rect, int column) const;
private:
    ImOption *imOpt;
};

class ImageReader : public QObject
{
    Q_OBJECT

    struct option {
        QRect                       screenRect;
        QRect                       card1Rect;
        QRect                       car2Rect;
        QMap<e_position, QPoint>    posPixel;
        QMap<e_position, QRect>     betRect;
    } opt;

private:
    bool init;
    QTimer  *refrechTimer;
    friend class DiagnosticScanner;
    friend class DiagReadBet;
    QImage  card1;
    QImage  card2;
    QPixmap pixEcran;
    QImage imEcran;
    QList<QPair<QImage,  QString>> strIm;
    QList<QPair<QImage, int>> intIm;
    e_position                      lastPos;
    QMap<e_position, QImage>        imBet;
    QMap<e_position, unsigned int>  pixBoardPosition;
    QMap<e_position, unsigned int>  pixPosition;
    QMap<e_position, QPoint> posPixel;
public:
    ImageReader(QString folder = "/Users/yann/dbpoker/img/card/", typeReader = Rcard, uint timeRefrech = 1000);
   // ImageReader(QString folder1, QString folder2){};
    ~ImageReader();
    Card            readCard(QImage card);
    Hand            readHand();
    bool            readValidHand();
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
    void refresh();

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

class    DiagnosticScanner : public QWidget
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
    int                         nbRead;
    QLabel                      *labLastHand;
    QLabel                      *labNbRead;
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
