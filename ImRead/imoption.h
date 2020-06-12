#ifndef IMOPTION_H
#define IMOPTION_H

#define POSX 198
#define POSY 23
#define SIZEX 1242
#define SIZEY 877

#include <QRect>
#include <QList>
#include <QVariant>

class ImOption {
public:
    ImOption (int nbJoueur = 6,
              QRect screenRect = QRect(POSX, POSY, SIZEX, SIZEY),
              QRect card1Rect = QRect(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2),
              QRect car2Rect = QRect(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2),
              QList<QPoint*> posPix= {new QPoint(978, 300), new QPoint(917, 504),new QPoint(504, 549),new QPoint(258, 416),new QPoint(394, 236),new QPoint(676, 230)},
              QList<QRect*> betRect = {new QRect(609,654,54,16),new QRect(1,1,1,1),new QRect(2,2,2,2),new QRect(3,3,3,3),new QRect(4,4,4,4),new QRect(5,5,5,5)});

private:
    int                         nbJoueur;
public:
    QRect                       screenRect;
    QRect                       card1Rect;
    QRect                       card2Rect;
    QList<QPoint*>               posPixel;
    QList<QRect*>                betRect;

    void    setNbJoueur(int nb);
    void    setScreenRect(QRect screenRect);
    int     getNbJoueur() const;
    QRect   getScreenRect() const;
};

Q_DECLARE_METATYPE(ImOption);

#endif // IMOPTION_H
