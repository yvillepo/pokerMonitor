#ifndef HAND_VIEW_H
#define HAND_VIEW_H

#include <QWidget>
#include <QTableWidget>
#include <SQL.h>

class Hand_view : public QTableWidget
{
public:
    Hand_view(int pos, int rows = 13, int columns = 13, QWidget *parent = nullptr);
    Hand_view(QWidget *parent = nullptr);
    void    init(int pos);
    void    read_bd(int pos);
    void    activate(int i, int j);
    void    disable(int i, int j);
};

QString    convert(int i, int j);
#endif // HAND_VIEW_H
