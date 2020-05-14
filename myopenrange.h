#ifndef MYOPENRANGE_H
#define MYOPENRANGE_H

#include <QMap>
#include "util.h"
#include "range.h"

class myOpenRange
{
public:
    myOpenRange(QString File);
    Range   *getRange(e_position p){return openRange[p];}
private:
    QMap<e_position, Range*> openRange;
};

#endif // MYOPENRANGE_H
