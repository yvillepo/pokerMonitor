#include "imoption.h"


ImOption::ImOption(int nb, QRect screen, QRect c1, QRect c2, QList<QPoint> pix, QList<QRect> bet)
{
    nb_joueur = nb;
    screenRect = screen;
    card1Rect = c1;
    card2Rect = c2;
    posPixel = pix;
    betRect = bet;
}
