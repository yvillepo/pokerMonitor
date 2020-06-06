#include "hand.h"

Hand::Hand(QString str_line_file_historique){
    card1 = Card(str_line_file_historique.mid
                (str_line_file_historique.indexOf('[') + 1, 2));
    card2 = Card(str_line_file_historique.mid
                (str_line_file_historique.indexOf(']') - 2, 2));
    str_hand = card1.getStrCard() + card2.getStrCard();
    str_type_hand = type_hand();
}

Hand::Hand(Card c1, Card c2) {
    card1 = c1;
    card2 = c2;
    str_hand = card1.getStrCard() + card2.getStrCard();
    str_type_hand = type_hand();
}

QString    Hand::type_hand(){
        QString res;
        if (card1.getIntRank() == card2.getIntRank())
            return (QString(card1.getCharRank()) + QString(card2.getCharRank()));

        if (card1.getIntRank() > card2.getIntRank())
            res = QString(card1.getCharRank()) + QString(card2.getCharRank());
        else
            res = QString(card2.getCharRank()) + QString(card1.getCharRank());
        if (card1.getColor() == card2.getColor())
        {
            suited = true;
            res += "s";
        }
        else
        {
            suited = false;
            res += "o";
        }
        return (res);
}
bool        Hand::isValid()
{
    if (card1.isValid() && card2.isValid())
        return true;
    return false;
}

QPoint Hand::index()
{
    int x = card1.getIntRank() % 14;
    int y = card2.getIntRank() % 14;

    if (suited)
        return QPoint(x, y);
    else
        return QPoint(x, y);
}

QPoint Hand::index(Hand h)
{
    return h.index();
}

std::array<Card, 2> Hand::getCard(){
    std::array<Card, 2> res = {card1, card2};
    return res;
}

bool operator==(Hand const& a, Hand const& b)
{
    return (a.card1 == a.card1 && a.card2 == a.card2);
}
