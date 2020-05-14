#include "myopenrange.h"
#include <QFile>

myOpenRange::myOpenRange(QString nameFile)
{
    QFile fichier(nameFile);
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "imposible de lire le contenue du fichier : " << nameFile;
    QTextStream flux(&fichier);
    QString line;
    int i = 1;
    while (!flux.atEnd())
    {
        line = flux.readLine();
        openRange[static_cast<e_position>(i++)] = new Range(line);
    }
}
