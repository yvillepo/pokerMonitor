#include "range_view.h"
#include "ui_range_view.h"
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <SQL.h>
#include "util.h"

range_view::range_view(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::range_view)
{
    ui->setupUi(this);
 //   this->setFrameShape(QFrame::Box);
    init();
}

QPushButton  *range_view::btAt(int i)
{
    return findChild<QPushButton  *>("pushButton_" + QString::number(i));
}

int     range_view::heightForWidth(int w) const
{
    return w;
}

range_view::~range_view()
{
    delete ui;
}

void    range_view::activate(int i)
{
    btAt(i)->setPalette(QPalette(QColor("green")));
}
void    range_view::disable(int i)
{
    btAt(i)->setPalette(QPalette(QColor("grey")));
}

void    range_view::no_data(int i)
{
    btAt(i)->setPalette(QPalette(QColor("red")));
}

void    range_view::read_bd(int pos)
{
    QString str_requete = QString(R"(SELECT id_hand_type, type_hand, id_position, nb_open, nb_possibilite_open
FROM MY_OPEN_RANGE NATURAL JOIN HAND_TYPE
WHERE id_position = %1)").arg(pos);
    qDebug() << str_requete.toStdString().c_str();
    QSqlQuery res = Sql::Requete(str_requete);
    while (res.isValid())
    {
        if (res.value("nb_possibilite_open").toInt() == 0)
        {
            no_data(res.value("id_hand_type").toInt() - 1);
            btAt(res.value("id_hand_type").toInt() - 1)->setToolTip("no data");
        }
        else {
            if (res.value("nb_open").toInt() >
                    res.value("nb_possibilite_open").toInt() / 2)
            {
                    activate(res.value("id_hand_type").toInt() - 1);
            }
            else {
                disable(res.value("id_hand_type").toInt() - 1);
            }
            btAt(res.value("id_hand_type").toInt() - 1)->setToolTip(res.value("nb_open").toString() + " / " + res.value("nb_possibilite_open").toString());
        }
        res.next();
    }
}

void    range_view::init()
{

    for (int i(0); i < 13; i++)
    {
        for (int j(0); j < 13; j++)
        {
            if (j > i)
                btAt(i* 13 + j)->setText(convert(13 - i, 13 - j) + "s");
            else if (j < i)
                btAt(i* 13 + j)->setText(convert(13 - j, 13 - i) + "o");
            else
                btAt(i* 13 + j)->setText(convert(13 - i, 13 - j));
        }
    }
}
