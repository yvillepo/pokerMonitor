#include "util.h"
#include <QLabel>

QString     convert_unit(int i)
{
    if (i >= 9 && i <= 13)
    {
        switch (i) {
        case 9:
            return "T";
        case 10:
            return "J";
        case 11:
            return "Q";
        case 12:
            return "K";
        case 13:
            return "A";
        }
    }
    return QString::number(i + 1);
}

QString    convert(int i, int j)
{
    return i > j ? convert_unit(i) + convert_unit(j) : convert_unit(j) + convert_unit(i);
}

QString     toStrCard(int i, int j)
{
    i =  13 - i;
    j =  13 - j;
    QString str;
    str = j > i ? convert(i, j) + "o" : convert(i, j) + "s";
    if (i == j) str = convert(i, j);
    return str;
}

QPoint strCardToCoordonate(QString str)
{
    int r1 = Card::convert_char_rang_to_int(str[0]);
    int r2 = Card::convert_char_rang_to_int(str[1]);
    r1 =  14 - r1;
    r2 =  14 - r2;
    if (r1 == r2)
        return QPoint(r1, r2);
    if (str[2] == 'o')
        return QPoint(r2, r1);
    else
        return QPoint(r1, r2);
}

QStringList    str_liste_hands(QString file, int debut)
{
    QFile           fichier(file);
    QString         text;
    QStringList     l_text;

    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    text = fichier.readAll();
    if (debut)
        text = text.mid(debut - 3);
    l_text = text.split("\n\n\n\n");
    return l_text;
}

QString    stringPos(e_position pos)
{
    switch (pos)
    {
    case BT:
        return "BT";
    case SB:
        return "SB";
    case BB:
        return "BB";
    case CO:
        return "CO";
    case MP:
        return "MP";
    case UTG:
        return "UTG";
    case UTG1:
        return "UTG1";
    case UTG2:
        return "UTG2";
    case UTG3:
        return "UTG3";
    case UTG4:
        return "UTG4";
    case UTG5:
        return "UTG5";
    case UTG6:
        return "UTG6";
    case NULLpos:
        return "NULLpos";
    }
}

