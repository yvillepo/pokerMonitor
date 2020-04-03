#ifndef RANGE_H
#define RANGE_H

#include <QMap>
#include <QString>
#include <iostream>
#include "util.h"

using namespace std;

class range
{

private:
    QMap<QString, bool> r;
    QMap<QString, bool> generate_map_range();
    QMap<int, QString> m_seat_player;
public:
    range();
    range(QMap<QString, bool>);
    range(QString str_range);
    void afficher(ostream &flux) const;
    void fct(int i);
    bool test();
};

ostream& operator<<( ostream &flux, range const& range);

#endif // RANGE_H
