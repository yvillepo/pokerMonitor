#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include "card.h"
#include "hand.h"
#include "util.h"
#include "imoption.h"
#include "imoptionmodel.h"
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

class ExistClass {
    ExistClass();
};

class ImageReader : public QObject
{
    Q_OBJECT
private:
    bool init;
    ImOption *option;
    QTimer  *refrechTimer;
    friend class DiagnosticScanner;
    friend class DiagReadBet;
    friend class ImOptionModel;
    QImage  card1;
    QImage  card2;
    QPixmap pixEcran;
    QImage imEcran;
    QList<QPair<QImage,  QString>> strIm;
    QList<QPair<QImage, int>> intIm;
    QList<float>              lStack;
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
    void            readStacks();
    float           readStack(QImage stack);
    QImage          scan(int x, int y, int width, int height);
    QImage          scan(QRect rect);
    ImOption *getOption() const;

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
    int             findVirgule(QImage const stack);
//    inline bool     isBB();
//    inline bool     isSB();
//    inline bool     isBT();
//    inline bool     isCO();
//    inline bool     isMP();
//    inline bool     isUTG();

};

#endif // IMAGEREADER_H
