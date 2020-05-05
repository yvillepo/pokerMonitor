#include "SQL.h"
#include "read_history.h"
#include "lecteur.h"
#include "hand_view.h"
#include <QLatin1String>
#include <string>
#include <iostream>
#include "reader.h"

Sql::Sql(QString file)
{
    bd = QSqlDatabase::addDatabase("QSQLITE");
    connection(file);
    init_bd();
    init_my_open_range();
}
void    Sql::connection(QString file)
{
    if (!bd.isValid())
    {
        qDebug() << "erreucrconnection banque de donnée QSQLITE";
        exit (1);
    }
    bd.setDatabaseName(file);
}


QString Sql::hand(int id)
{
    if (bd.open())
    {
        qDebug() << "OK - ouverture de la base de donnée";
        QSqlQuery requete;
        if (requete.exec("SELECT text_game FROM test WHERE id LIKE " + QString::number(id)))
        {
            requete.next();
            QString name = requete.value("text_game").toString();
            qDebug() << bd.tables() << endl;
            return name;
        }
        else {
            qDebug() << "Echec de la requête";
            qDebug() << requete.lastError();

        }
        return nullptr;
    }
    else {
        qDebug() << "Echec d'ouverture de la base de donnée";
        qDebug() << bd.lastError();
    }
    return "";
}


// a revoir
QSqlQuery        *Sql::select_file_history(QString chemin)
{
    QSqlQuery   *requete;
    QString     str_requete;
    if (bd.open())
    {
        str_requete = R"(SELECT chemin, taille FROM HISTORY_FILE WHERE chemin LIKE ")" + chemin.replace(u'€', '%') + "\"";
        str_requete.remove(str_requete.indexOf('%') - 1).remove(str_requete.indexOf('%') - 1);
        requete = new QSqlQuery(str_requete.toStdString().c_str());
        return requete;
    }
    return  new QSqlQuery();
}

void    Sql::insert_file_history(QString chemin, qint64 taille)
{
    QSqlQuery requete;
    if (bd.open())
        requete.exec(QString(R"(INSERT INTO HISTORY_FILE VALUES (NULL, "%1", %2);)").arg(chemin).arg(taille));
}

void    Sql::insert_hand_history(QString chemin, qint64 index_new_end)
{
    QSqlQuery   requete;
    QString     str_requete;
    QStringList partie;
    int         nb_new_hand(0);

    partie = str_liste_hands(chemin, index_new_end);
    if (!bd.open())
    {
        qDebug() << "bd.open() FAIL" << endl;
        return;
    }
    for (int i(0); i < partie.size(); i++)
    {
        if (partie.at(i) != "")
        {
            jeux j = lecteur::Read_summary(partie.at(i));
            str_requete = QString(R"(INSERT INTO HAND_HISTORY (hand, gain, rake, gain_sans_rake, text) VALUES ("%1", %2, %3 , %4 ,"%5"))")
                    .arg(j.my_hand.c[0].str + j.my_hand.c[1].str)
                    .arg(j.gain).arg(j.rake).arg(j.rake + j.gain).arg(partie.at(i));
            requete.exec(str_requete.toStdString().c_str());
            nb_new_hand++;
        }
    }
    if (nb_new_hand > 0)
    {
        qDebug() << chemin.right(chemin.lastIndexOf("/"));
        qDebug() << QString("insertion %1 nouvelle main").arg(nb_new_hand);
    }
}

void    Sql::update_file_history_size(QString chemin, qint64 new_size)
{
    QSqlQuery   requete;
    QString     str_requete;

    str_requete = QString(R"(UPDATE HISTORY_FILE SET taille = '%1' WHERE chemin like "%2")").arg(new_size).arg(chemin.replace(u'€', '%'));
    requete.exec(str_requete);
}

void    Sql::creation_db()
{
    if (QSqlQuery().exec(QString("CREATE DATABASE hand_history_poker2")))
        qDebug() << "creation bd ok ";
    else
        qDebug() << "creation bd pas ok ";
}

void    Sql::init_bd()
{
    if (!bd.open())
        return ;
    QSqlQuery   requete;
    int         id(1);

    QString str_requete;
    requete.exec("SELECT * FROM HAND_TYPE LIMIT 1");
    requete.next();
    if (requete.isValid())
            return;
    for (int i(0); i < 13; i++)
    {
        for (int j(0); j < 13; j++)
        {
            str_requete = QString(R"(INSERT INTO HAND_TYPE VALUES (%1, '%2'))").arg(id);
            if (j > i)
                str_requete = str_requete.arg(convert(13 - i, 13 - j) + "s");
            else if (j < i)
                 str_requete = str_requete.arg(convert(13 - j, 13 - i) + "o");
            else
                 str_requete = str_requete.arg(convert(13 - i, 13 - j));
            str_requete.append(';');
            qDebug() << str_requete.toStdString().c_str();
            if (requete.exec(str_requete.toStdString().c_str()))
                qDebug() << "requete ok" ;
            id++;
        }
    }
}

void    Sql::init_my_open_range()
{
    if (!bd.open())
        return ;
    QSqlQuery requete;

    QString str_requete;
    requete.exec("SELECT * FROM MY_OPEN_RANGE LIMIT 1");
    requete.next();
    if (requete.isValid())
        return ;
    str_requete = R"(INSERT into MY_OPEN_RANGE (type_hand, id_position, nb_open, nb_possibilite_open)
Select type_hand, a.* from HAND_TYPE ,
(SELECT 10 as id_position, 0 as nb_open, 0 as nb_possibilite_open
UNION SELECT 9, 0, 0
UNION SELECT 8, 0, 0
UNION SELECT 7, 0, 0
UNION SELECT 6, 0, 0
UNION SELECT 5, 0, 0) a)";
    qDebug() << str_requete.toStdString().c_str();
    requete.exec(str_requete.toStdString().c_str());
}

QSqlQuery Sql::Requete(QString str_requete)
{
    QSqlQuery requete;

    if (!requete.exec(str_requete.toStdString().c_str()))
    {
        qDebug() << str_requete.toStdString().c_str() << endl <<  "echec requete";
        return (requete);
    }
    requete.next();
    return (requete);
}
