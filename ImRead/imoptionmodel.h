#ifndef IMOPTIONMODEL_H
#define IMOPTIONMODEL_H

#include <QAbstractTableModel>
#include "imagereader.h"

class ImOptionModel : public QAbstractTableModel
{
public:
    ImOptionModel(ImageReader *imRead ,QObject *parent = nullptr);
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
    ImOption        *imOpt;
    ImageReader     *imRead;
    ExistClass            test;
};

#endif // IMOPTIONMODEL_H
