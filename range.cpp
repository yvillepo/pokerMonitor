#include "range.h"
#include <QtDebug>

QMap<QString, bool> range::generate_map_range()
{
    QMap<QString, bool> r =  QMap<QString, bool>();
    QString str;
    for (int i(1); i <= 13; i++)
        for (int j(1); j <= 13; j++)
        {
            str = j > i ? convert(i, j) + "s" : convert(i, j) + "o";
            if (i == j) str = convert(i, j);
            r[str] = false;
        }
    return r;
}

range::range()
{
    r = generate_map_range();
}

range::range(QMap<QString, bool> map)
{
    this->r = map;
}

range::range(QString str_range) : range()
{
    this->r = QMap<QString, bool>();
    QStringList lstr = str_range.split(',');

    for (int i = 0; i < lstr.size() ;i++){}

}

void range::afficher(ostream &flux) const
{
    QString str;
    for (int i(13); i >= 1; i--)
    {
        for (int j(13); j >= 1; j--)
        {
            str = j < i ? convert(i, j) + "s" : convert(i, j) + "o";
            if (i == j) str = convert(i, j);
            flux << (r[str] ? "\033[1;32mv\033[0m " : "\033[0;37mx\033[0m " );
        }
        flux << endl;
    }
    flux << endl;
}

ostream& operator<<( ostream &flux, range const& ra)
{
    ra.afficher(flux);
    return flux;
}

bool range::test()
{
    cout << *this;
    return true;
}
