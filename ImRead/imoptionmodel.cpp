#include "imoptionmodel.h"

ImOptionModel::ImOptionModel(ImageReader *imRead, QObject *parent) : QAbstractTableModel(parent)
{
    this->imRead = imRead;
    this->imOpt = imRead->getOption();
}

int ImOptionModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4 + 2 * imOpt->getNbJoueur();
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
    if (role == Qt::DecorationRole)
    {
        qDebug() << "here";
        if (index.row() == 0 && index.column() == 1)
        {
             qDebug() << "here2";
            return QPixmap::fromImage(imRead->card1);
        }

    }
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch (index.row()) {
        case 0:
            if (index.column() == 0)
            {
                return imOpt->getNbJoueur();
            }
            return QString("");
        case 1:
            return displayRect(imOpt->getScreenRect(), index.column());
        case 2:
            return displayRect(imOpt->card1Rect, index.column());
        case 3:
            return displayRect(imOpt->card2Rect, index.column());
        }
        if (index.row() > 3 && index.row() <= 3 + imOpt->getNbJoueur())
        {
            if (index.column() == 0)
                return imOpt->posPixel.at(index.row() - 4)->x();
            if (index.column() == 1)
                return imOpt->posPixel.at(index.row() - 4)->y();
        }
        if (index.row() > 3 + imOpt->getNbJoueur() &&  index.row() <= 3 + imOpt->getNbJoueur() * 2)
        {
            return displayRect(*(imOpt->betRect.at(
                                   index.row() - (4 + imOpt->getNbJoueur()))),
                               index.column());
        }
    }
    return  QVariant();
}

bool ImOptionModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        switch (index.row()) {

        case 0:
        {
            if (index.column() == 0)
            {
                imOpt->setNbJoueur(value.toInt());
                return true;
            }
            return false;
        }
        case 1:
            EditRect(&(imOpt->screenRect), index.column(), value.toInt());
            return true;
        case 2:
            EditRect(&(imOpt->card1Rect), index.column(), value.toInt());
            return true;
        case 3:
            EditRect(&(imOpt->card2Rect), index.column(), value.toInt());
            return true;
        }
        if (index.row() > 3 && index.row() <= 3 + imOpt->getNbJoueur())
        {
            if (index.column() == 0)
                imOpt->posPixel.at(index.row() - 4)->setX(value.toInt());
            else if (index.column() == 1)
               imOpt->posPixel.at(index.row() - 4)->setY(value.toInt());
            else {
                return false;
            }
            return true;
        }
        if (index.row() > 3 + imOpt->getNbJoueur() &&  index.row() <= 3 + imOpt->getNbJoueur() * 2)
        {
            EditRect(imOpt->betRect.at(
                                   index.row() - (4 + imOpt->getNbJoueur())),
                               index.column(), value.toInt());
            return true;
        }
    }
    return false;
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
        if (section > 3 && section <= 3 + imOpt->getNbJoueur())
        return QString("PosPixel") + QString::number(section - 4);
        if (section > 3 + imOpt->getNbJoueur() &&  section <= 3 + imOpt->getNbJoueur() * 2)
            return QString("betRect") + QString::number(section - (4 + imOpt->getNbJoueur()));
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

void ImOptionModel::EditRect(QRect *rect, int column, int value)
{
    switch (column) {
    case 0 :
        rect->moveLeft(value);
        break;
    case 1 :
        rect->moveTop(value);
        break;
    case 2:
        rect->setWidth(value);
        break;
    case 3:
        rect->setHeight(value);
        break;
    }
}
