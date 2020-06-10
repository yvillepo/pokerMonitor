#include "imoptionmodel.h"

ImOptionModel::ImOptionModel(QObject *parent) : QAbstractTableModel(parent)
{
    imOpt = new ImOption();
}

ImOptionModel::ImOptionModel(ImOption *imOpt, QObject *parent) : QAbstractTableModel(parent)
{
    this->imOpt = imOpt;
}

int ImOptionModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4 + 2 * imOpt->nb_joueur;
}

int ImOptionModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

QVariant ImOptionModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0)
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch (index.row()) {
        case 0:
            if (index.column() == 0)
            {
                return imOpt->nb_joueur;
            }
            return QString("");
        case 1:
            return displayRect(imOpt->screenRect, index.column());
        case 2:
            return displayRect(imOpt->card1Rect, index.column());
        case 3:
            return displayRect(imOpt->card2Rect, index.column());
        }
        if (index.row() > 3 && index.row() <= 3 + imOpt->nb_joueur)
        {
            if (index.column() == 0)
                return imOpt->posPixel.at(index.row() - 4).x();
            if (index.column() == 1)
                return imOpt->posPixel.at(index.row() - 4).y();
        }
        if (index.row() > 3 + imOpt->nb_joueur &&  index.row() <= 3 + imOpt->nb_joueur * 2)
        {
            return displayRect(imOpt->betRect.at(
                                   index.row() - (4 + imOpt->nb_joueur)),
                               index.column());
        }
    }
    return  QVariant();
}

bool ImOptionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return true;
}

QVariant ImOptionModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0:
            return QString("x");
        case 1:
            return QString("y");
        case 2:
            return QString("width");
        case 3:
            return QString("height");

        }
    }
    else {

        switch (section) {
        case 0:
            return QString("nb_joueur");
        case 1:
            return QString("screenRect");
        case 2:
            return QString("Card1Rect");
        case 3:
            return QString("Card2Rect");
        }
        if (section > 3 && section <= 3 + imOpt->nb_joueur)
        return QString("PosPixel") + QString::number(section - 4);
        if (section > 3 + imOpt->nb_joueur &&  section <= 3 + imOpt->nb_joueur * 2)
            return QString("betRect") + QString::number(section - (4 + imOpt->nb_joueur));
    }
    return QVariant();
}

Qt::ItemFlags ImOptionModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QAbstractItemModel::flags(index);
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

QVariant ImOptionModel::displayRect(const QRect rect, int column) const
{
    switch(column)
    {
    case 0:
        return rect.x();
    case 1:
        return rect.y();
    case 2:
        return rect.width();
    case 3:
        return rect.height();
    }
    return QVariant();
}
