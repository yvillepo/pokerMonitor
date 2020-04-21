#ifndef CARD_H
#define CARD_H

#include <QString>

enum    e_color {coeur, carreau, trefle, pique, undefined = -1};

class Card
{
private:
    QString str;
    QChar   char_rank;
    int     rank;
    e_color color;
public:
    Card(QString s);
    Card(){}
    static int      convert_char_rang_to_int(QChar c);
    static QChar    convert_int_rang_to_Chart(int c);
    static e_color  convert_char_color_to_color(QChar c);
    QChar           getCharRank()const {return char_rank;}
    int             getIntRank() const {return rank;}
    QString         getStrCard() const {return str;}
    e_color         getColor() const {return color;}
};

bool operator==(Card const& a, Card const& b);

#endif // CARD_H
