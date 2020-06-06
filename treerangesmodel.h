#ifndef TREERANGESMODEL_H
#define TREERANGESMODEL_H

#include <QWidget>
#include <QAbstractItemModel>
#include "treeranges.h"

class TreeRangesModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TreeRangesModel(QObject *parent = nullptr);
    ~TreeRangesModel() override;

    // QAbstractItemModel interface
    QModelIndex index(int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;


private:
    void readFile();
    QStringList getActionAndFrequence(QString line);

    TreeRanges *rootRanges;

};

#endif // TREERANGESMODEL_H
