#include "hand_view.h"
#include <QBrush>

QString     convert_unit_2(int i)
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
        return QString::number(i + 1);
    }
}

QString    convert_2(int i, int j)
{
    return (convert_unit_2(i) + convert_unit_2(j));
}

void    Hand_view::init(int pos)
{
    setRowCount(13);
    setColumnCount(13);
    for (int i(0); i < 13; i++)
    {
        for (int j(0); j < 13; j++)
        {
            if (j > i)
                setItem(i ,j , new QTableWidgetItem(convert_2(13 - i, 13 - j) + "s"));
            else if (j < i)
                setItem(i ,j , new QTableWidgetItem(convert_2(13 - j, 13 - i) + "o"));
            else
                setItem(i ,j , new QTableWidgetItem(convert_2(13 - i, 13 - j)));
        }
    }
    read_bd(pos);
}

Hand_view::Hand_view(QWidget *parent) : QTableWidget(parent)
{
}

Hand_view::Hand_view(int pos, int rows, int columns, QWidget *parent) :QTableWidget (rows, columns, parent)
{
    setWindowTitle("range");
    setWindowFlag(Qt::Window);
    setShowGrid(false);
    for (int i(0); i < 13; i++)
    {
        for (int j(0); j < 13; j++)
        {
            if (j > i)
                setItem(i ,j , new QTableWidgetItem(convert_2(13 - i, 13 - j) + "s"));
            else if (j < i)
                setItem(i ,j , new QTableWidgetItem(convert_2(13 - j, 13 - i) + "o"));
            else
                setItem(i ,j , new QTableWidgetItem(convert_2(13 - i, 13 - j)));
        }
    }
    read_bd(pos);
}

void    Hand_view::activate(int i, int j)
{
    item(i,j)->setBackground(QBrush(QColor("grey")));
}
void    Hand_view::disable(int i, int j)
{
    item(i,j)->setBackground(QBrush(QColor("red")));
}
void    Hand_view::read_bd(int pos)
{
    QString str_requete = QString(R"(SELECT id_hand_type, type_hand, id_position, nb_open, nb_possibilite_open
FROM MY_OPEN_RANGE NATURAL JOIN HAND_TYPE
WHERE id_position = %1)").arg(pos);
    qDebug() << str_requete.toStdString().c_str();
    QSqlQuery res = Sql::Requete(str_requete);
    while (res.isValid())
    {
        if (res.value("nb_open").toInt() ==
                res.value("nb_possibilite_open").toInt())
        {
            if (res.value("nb_possibilite_open").toInt() == 0)
                disable((res.value("id_hand_type").toInt() - 1) / 13, (res.value("id_hand_type").toInt() - 1) % 13);
            else
                activate((res.value("id_hand_type").toInt() - 1) / 13, (res.value("id_hand_type").toInt() - 1) % 13);
        }
        res.next();
    }
}
