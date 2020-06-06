#ifndef MULTIRANGE_H
#define MULTIRANGE_H

#include <QList>
#include "hand.h"

class HandFrequence
{
    struct action{
        QString action;
        float   frequence;
    };
    QList<action> lFrequence;
public:
    HandFrequence(QList<action> lFrequence = {});
    void addAction(action a);
    void addAction(QString action, float frequence);
    void Normalise();
};

class MultiRange
{
public:
    MultiRange();
    void read(QString str);
};

#endif // MULTIRANGE_H
