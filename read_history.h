#ifndef READ_HISTORY_H
#define READ_HISTORY_H

#include <QWidget>
#include <QDir>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QtWidgets>
#include "SQL.h"

void            read_history(QString path, Sql *bd);
QStringList     str_liste_hands(QString file, int debut);
#endif // READ_HISTORY_H
