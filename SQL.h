#ifndef BD_ACCESS_H
#define BD_ACCESS_H

#include <QString>
#include <QtSql>
#include <QtWidgets>
#include "mainwindow.h"

class Sql{
private:
    QSqlDatabase    bd;
public:
    Sql(QString bd = "/Users/yann/dbpoker/testpoker.db");
    void                    connection(QString bd = "/Users/yann/dbpoker/testpoker.db");
    QSqlQuery               *select_file_history(QString chemin);
    void                    insert_file_history(QString chemin, qint64 taille);
    void                    insert_hand_history(QString chemin, qint64 taille);
    void                    update_file_history_size(QString chemin, qint64 new_size);
    QString                 hand(int id);
    void                    creation_db();
    void                    init_bd();
    void                    init_my_open_range();
    static  QSqlQuery       Requete(QString requete);
};
#endif // BD_ACCESS_H
