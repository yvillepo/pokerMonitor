#ifndef MESRANGES_H
#define MESRANGES_H

#include "util.h"
#include "range.h"

class MesRanges
{
public:
    MesRanges();
private:
    QMap<e_position, Range*>    open;
};

#endif // MESRANGES_H
