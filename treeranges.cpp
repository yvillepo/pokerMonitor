#include "treeranges.h"


TreeRanges::TreeRanges(QString action, float frequence, TreeRanges *parent)
{
    this->action = action;
    this->frequence = frequence;
    this->parent = parent;
}

TreeRanges::~TreeRanges()
{
    qDeleteAll(children);
}

void TreeRanges::appendChild(TreeRanges *childParam)
{
    children.append(childParam);
}

TreeRanges *TreeRanges::child(int row)
{
    return children.value(row);
}

int TreeRanges::childCount() const
{
    return children.count();
}

QVariant TreeRanges::data(int column) const
{
    if(column == 0)
        return action;
    if(column == 1)
        return frequence;
    return QVariant();
}

int TreeRanges::row() const
{
    if (parent) {
        parent->children.indexOf(const_cast<TreeRanges*>(this));
    }
    return 0;
}

TreeRanges *TreeRanges::parentRanges()
{
    return parent;
}
