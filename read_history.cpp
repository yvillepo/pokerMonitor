#include "read_history.h"
#include "SQL.h"
#include <QFile>


void    read_history(QString path, Sql *bd)
{
    QDir d(path);
    QFileInfoList fi = d.entryInfoList();
    QSqlQuery *query;
    int         nb_KO(0);
    int         nb_OK(0);
    for (int i(0); i < fi.size(); i++)
    {
        if (fi.at(i).filePath().endsWith("/.") || fi.at(i).filePath().endsWith("/.."))
            continue;
        query = bd->select_file_history(fi.at(i).filePath());                                       //
        query->next();
        if (!query->isValid())
        {
            bd->insert_file_history(fi.at(i).filePath(), fi.at(i).size());
            bd->insert_hand_history(fi.at(i).filePath(), 0);
            nb_KO++;
        }
        else {
            if (query->value("taille").toInt() < fi.at(i).size())
            {
                bd->insert_hand_history(fi.at(i).filePath(), query->value("taille").toInt());
                bd->update_file_history_size(fi.at(i).filePath(), fi.at(i).size());
            }
            nb_OK++;
        }
    }
    qDebug() << "OK : " << nb_OK << "KO : " << nb_KO;
}
