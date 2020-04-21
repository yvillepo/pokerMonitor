#ifndef RANGE_H
#define RANGE_H

#include <QMap>
#include <QString>
#include <iostream>
#include "util.h"

using namespace std;

class Range
{

private:
    QMap<QString, bool> range;
    QMap<int, QString> m_seat_player;
public:
    Range();
    Range(QMap<QString, bool>);
    Range(QString str_range);
    QMap<QString, bool> generate_map_range();
    void readRange(QString range);
    void afficher(ostream &flux) const;
    void fct(int i);
    void affiche();
private:
    void readRangeUnit(QString rangeUnit);
    void readOneHand(QString hand);
};

ostream& operator<<( ostream &flux, Range const& range);

#endif // RANGE_H
