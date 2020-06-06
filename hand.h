#ifndef HAND_H
#define HAND_H

#include <QString>
#include "card.h"
#include "array"
#include <QPoint>

class Hand
{
public:
    QString     str_hand;
    bool        suited;
    QString     str_type_hand;
    Card        card1;
    Card        card2;
    Hand(QString str_line_file_historique);
    Hand(Card c1, Card c2);
    QString             type_hand();
    QString             getStrHand() {return str_hand;}
    QString             getStrTypeHand(){return str_type_hand;}
    Card                getCard1(){return card1;}
    Card                getCard2(){return card2;}
    std::array<Card, 2> getCard();
    bool                isValid();
    QPoint              index();
    static QPoint       index(Hand h);
};

bool operator==(Hand const& a, Hand const& b);

#endif // HAND_H
