#include "range.h"
#include "card.h"
#include <QtDebug>

QMap<QString, bool> Range::init_range()
{
    QMap<QString, bool> range =  QMap<QString, bool>();
    QString str;
    for (int i(1); i <= 13; i++)
        for (int j(1); j <= 13; j++)
        {
            str = j > i ? convert(i, j) + "s" : convert(i, j) + "o";
            if (i == j) str = convert(i, j);
            range[str] = false;
            tab_range[i - 1][j - 1] = false;
        }
    return range;
}

Range::Range()
{
    range = init_range();
}

Range::Range(QMap<QString, bool> map)
{
    this->range= map;
}

Range::Range(QString str_range) : Range()
{
    this->range = QMap<QString, bool>();
    QStringList lstr = str_range.split(',');

    for (int i = 0; i < lstr.size() ;i++){
        readRangeUnit(lstr.at(i));
    }

}

void Range::fillRange(QString str)
{
    range[str] = true;
    QPoint pt = strCardToCoordonate(str);
    tab_range[pt.x()][pt.y()] = true;
}

void    Range::readRangeUnit(QString strRangeUnit) // dont realy clean but Work perfectly
{
    if (strRangeUnit.size() == 3 &&
            (strRangeUnit[2] == 'o'  || strRangeUnit[2] == 's')) // type KTo
        fillRange(strRangeUnit);

    else if(strRangeUnit.size() == 4 && strRangeUnit[3] == '+') // type Q7+
    {
        int upperCard = Card::convert_char_rang_to_int(strRangeUnit.at(0));
        int lowerCard = Card::convert_char_rang_to_int(strRangeUnit.at(1));
        QString strUpperCard = QString(strRangeUnit.at(0));
        QString typeCard = QString(strRangeUnit.at(2)); // s | o for suited | offsuit
        for (int i = lowerCard; i < upperCard; i++)
        {
            fillRange(strUpperCard +
                    QString(Card::convert_int_rang_to_Chart(i)) +
                    typeCard);
        }
    }

    else if (strRangeUnit.size() == 7 && strRangeUnit.at(3) == '-') // type ,Q6s-Q2s | KTo-K7o
    {
        QString strFirtCard = QString(strRangeUnit.at(0));
        int intUpperCard =
                Card::convert_char_rang_to_int(strRangeUnit.at(1));
        int intLowerCard =
                Card::convert_char_rang_to_int(strRangeUnit.at(5));
        QString typeCard = QString(strRangeUnit.at(2));
        for (int i = intLowerCard; i <= intUpperCard; i++)
        {
            QString strCurrentCard =
                    QString(Card::convert_int_rang_to_Chart(i));
            fillRange(strFirtCard + strCurrentCard + typeCard);
        }
    }

    else if (strRangeUnit.size() == 2 &&
             strRangeUnit.at(0) == strRangeUnit.at(1)) // type 22 or QQ
    {
        fillRange(strRangeUnit);
    }

    else if (strRangeUnit.size() == 5 &&
             strRangeUnit.at(0) == strRangeUnit.at(1)
             && strRangeUnit.at(2) == '-') // type QQ-22
    {
        int intUpperCard = Card::convert_char_rang_to_int(strRangeUnit.at(0));
        int intLowerCard = Card::convert_char_rang_to_int(strRangeUnit.at(3));
        for (int i = intLowerCard; i <= intUpperCard; i++)
        {
            QString curentCard = Card::convert_int_rang_to_Chart(i);
            fillRange(curentCard + curentCard);
        }
    }
    else if (strRangeUnit.size() == 3 &&
             strRangeUnit.at(0) == strRangeUnit.at(1)
             && strRangeUnit.at(2) == '+') // type 22+
    {
        int intLowerCard = Card::convert_char_rang_to_int(strRangeUnit.at(0));
        for (int i = intLowerCard; i <= 14; i++) // 14 = 'A' (As)
        {
            QString curentCard = Card::convert_int_rang_to_Chart(i);
            fillRange(curentCard + curentCard);
        }
    }
}

void Range::afficher(ostream &flux) const
{
    QString str;
    for (int i(13); i >= 1; i--)
    {
        for (int j(13); j >= 1; j--)
        {
            str = j < i ? convert(i, j) + "s" : convert(i, j) + "o";
            if (i == j) str = convert(i, j);
            flux << (range[str] ? "\033[1;32mv\033[0m " : "\033[0;37mx\033[0m " );
        }
        flux << endl;
    }
    flux << endl;
}

bool Range::isTrue(QString type_hand)
{
    if (!range.contains(type_hand))
        return false;
    return range[type_hand];
}

ostream& operator<<( ostream &flux, Range const& ra)
{
    ra.afficher(flux);
    return flux;
}

void Range::affiche()
{
    cout << *this;
}
