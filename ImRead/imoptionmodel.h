#ifndef IMOPTIONMODEL_H
#define IMOPTIONMODEL_H

#include "imoption.h"
#include <QAbstractTableModel>

class ImOptionModel : public QAbstractTableModel
{
public:
    explicit ImOptionModel(QObject *parent = nullptr);
    explicit ImOptionModel(ImOption *imOpt ,QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant    displayRect(const QRect rect, int column) const;
    void        EditRect(QRect *rect, int column, int value);
private:
    ImOption *imOpt;
};

#endif // IMOPTIONMODEL_H
