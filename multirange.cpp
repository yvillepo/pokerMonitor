#include "multirange.h"



MultiRange::MultiRange()
{

}

void MultiRange::read(QString str)
{

}

HandFrequence::HandFrequence(QList<action> frequence)
{
    this->lFrequence = frequence;
}

void HandFrequence::addAction(HandFrequence::action a)
{
    lFrequence.append(a);
}

void HandFrequence::addAction(QString action, float frequence)
{
    lFrequence.append({action, frequence});
}

void HandFrequence::Normalise()
{
    float sum = 0;
    for (const action a : lFrequence) {
        sum += a.frequence;
    }
    for (action a : lFrequence) {
        a.frequence /= sum;
    }
}


