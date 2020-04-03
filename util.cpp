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

