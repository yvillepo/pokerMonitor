#include "card.h"
#include <QDebug>

Card::Card(QString s)
{
    if (s.length() != 2)
    {
        qDebug() << s << " : not a card";
        return ;
    }
    str         = s;
    char_rank   = s.at(0);
    rank        = convert_char_rang_to_int(char_rank);
    color       = convert_char_color_to_color(s.at(1));
}

int Card::convert_char_rang_to_int(QChar c)
{
    if (c.isNumber())
        return c.digitValue();
    switch(c.unicode())
    {
    case 'A':
        return 14;
    case 'K':
        return 13;
    case 'Q':
        return 12;
    case 'J':
        return 11;
    case 'T':
        return 10;
    default:
        return -1;
    }
}

QChar Card::convert_int_rang_to_Chart(int rang)
{
    if (rang <= 9 && rang >=2)
        return QString().setNum(rang).at(0);
    switch(rang)
    {
    case 14:
        return 'A';
    case 13:
        return 'K';
    case 12:
        return 'Q';
    case 11:
        return 'J';
    case 10:
        return 'T';
    default:
        return '0';
    }
}

e_color Card::convert_char_color_to_color(QChar c)
{
    switch(c.unicode())
    {
    case 'h':
        return coeur;
    case 'd':
        return carreau;
    case 's':
        return pique;
    case 'c':
        return trefle;
    default:
        return undefined;
    }
}

bool operator==(Card const& a, Card const& b)
{
    return (a.getStrCard() == b.getStrCard());
}
