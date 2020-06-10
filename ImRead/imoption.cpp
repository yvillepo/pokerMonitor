#include "imoption.h"


ImOption::ImOption(int nb, QRect screen, QRect c1, QRect c2, QList<QPoint*> pix, QList<QRect*> bet)
{
    nbJoueur = nb;
    screenRect = screen;
    card1Rect = c1;
    card2Rect = c2;
    posPixel = pix;
    betRect = bet;
}

QRect ImOption::getScreenRect() const
{
    return screenRect;
}

int ImOption::getNbJoueur() const
{
    return nbJoueur;
}

void ImOption::setNbJoueur(int nb)
{
    nbJoueur = nb;
}

void ImOption::setScreenRect(QRect screenRect)
{
    this->screenRect = screenRect;
}
