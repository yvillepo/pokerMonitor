#ifndef IMOPTION_H
#define IMOPTION_H

#define POSX 198
#define POSY 23
#define SIZEX 1242
#define SIZEY 877

#include <QRect>
#include <QList>

class ImOption {
public:
    ImOption (int nbJoueur = 6,
              QRect screenRect = QRect(POSX, POSY, SIZEX, SIZEY),
              QRect card1Rect = QRect(543 + 8,555 + 10, 77 - (77 - 28) - 2,45 - (45 - 28) - 2),
              QRect car2Rect = QRect(623 + 8,555 + 10,77 - (77 - 28) - 2,45 - (45 - 28) - 2),
              QList<QPoint> posPix= {QPoint(978, 300), QPoint(917, 504), QPoint(504, 549), QPoint(258, 416), QPoint(394, 236), QPoint(676, 230)},
              QList<QRect> betRect = {QRect(609,654,54,16), QRect(1,1,1,1), QRect(2,2,2,2), QRect(3,3,3,3), QRect(4,4,4,4), QRect(5,5,5,5)});
public:
    int                         nb_joueur;
    QRect                       screenRect;
    QRect                       card1Rect;
    QRect                       card2Rect;
    QList<QPoint>               posPixel;
    QList<QRect>                betRect;
};

#endif // IMOPTION_H
