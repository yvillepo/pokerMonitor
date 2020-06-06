#ifndef TREERANGES_H
#define TREERANGES_H

#include <QString>
#include <QList>
#include <QVariant>
#include <multirange.h>


class TreeRanges
{
public:
    TreeRanges();

    TreeRanges(QString action,float frequence,TreeRanges * parent = nullptr);
    ~TreeRanges();
    void appendChild(TreeRanges * childParam);
    TreeRanges * child(int row);
    int childCount() const;
    QVariant data(int column) const;
    int row () const;
    TreeRanges *parentRanges();



private:

    QList<TreeRanges*>  children;
    QString             action;
    float               frequence;
    TreeRanges          *parent;
};

#endif // TREERANGES_H
