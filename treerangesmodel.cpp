#include "treerangesmodel.h"
#include <QDebug>
#include <QFile>

TreeRangesModel::TreeRangesModel(QObject *parent) : QAbstractItemModel(parent)
{
    rootRanges = new TreeRanges("bb", 0);
    readFile();
}

TreeRangesModel::~TreeRangesModel()
{
    delete  rootRanges;
}

QModelIndex TreeRangesModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();
    TreeRanges * parentRanges;

    if(!parent.isValid()){
        parentRanges = rootRanges;
    }else{
        parentRanges = static_cast<TreeRanges*>(parent.internalPointer());
    }

    TreeRanges * chilRange = parentRanges->child(row);
    if(chilRange)
        return createIndex(row,column,chilRange);
    return QModelIndex();
}

QModelIndex TreeRangesModel::parent(const QModelIndex &child) const
{
    if (!child.isValid())
        return QModelIndex();

    TreeRanges * childRange = static_cast<TreeRanges*>(child.internalPointer());
    TreeRanges * parentPerson = childRange->parentRanges();
    if(parentPerson== rootRanges)
        return QModelIndex();
    return createIndex(parentPerson->row(),0,parentPerson);
}

int TreeRangesModel::rowCount(const QModelIndex &parent) const
{
    TreeRanges * parentRanges;
    /*
         * Only the first columns can have children
         * */
    if(parent.column() > 0)
        return 0;

    if(!parent.isValid()){
        parentRanges = rootRanges;
    }else{
        parentRanges = static_cast<TreeRanges*>(parent.internalPointer());
    }

    return  parentRanges->childCount();
}

int TreeRangesModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return  2;
}

QVariant TreeRangesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    //No need to handle edit role here, the model is not editable anyway.
    if (role != Qt::DisplayRole)
        return QVariant();

    TreeRanges *range = static_cast<TreeRanges*>(index.internalPointer());

    return range->data(index.column());
}

QVariant TreeRangesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && (role == Qt::DisplayRole)){
        return  rootRanges->data(section);
    }
    return QVariant();
}

Qt::ItemFlags TreeRangesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return nullptr;
    return QAbstractItemModel::flags(index);
}

void TreeRangesModel::readFile()
{
    QString filename = ":/Tree3WayCash.txt";
    QFile inputFile(filename);
    if(inputFile.open(QIODevice::ReadOnly)){
        int lastIndentation = 0;
        TreeRanges * lastParent = rootRanges;
        TreeRanges * lastRange = nullptr;

        QTextStream in(&inputFile);

        while (!in.atEnd()) {

            QString line = in.readLine();

            int currentIndentation = line.count("\t");

            qDebug() << "Read line : " << line << " tab count : " << QString::number(currentIndentation);

            QStringList infoList = getActionAndFrequence(line);


            int diffIndent = currentIndentation - lastIndentation;

            if(diffIndent == 0){
                //First Level Person
                TreeRanges * range = new TreeRanges(infoList[0],infoList[1].toFloat(),lastParent);
                lastParent->appendChild(range);
                lastRange = range;

            }else if(diffIndent > 0){
                //Move the parent down
                lastParent = lastRange;
                TreeRanges * range = new TreeRanges(infoList[0],infoList[1].toFloat(),lastParent);
                lastParent->appendChild(range);
                lastRange = range;
            }else{
                //Move up the parent chain looking the  correct parent
                int iterations = - diffIndent;
                for(int i = 0; i < iterations ; i++){
                    lastParent = lastParent->parentRanges();
                }
                if (lastParent == 0)
                    lastParent = rootRanges;
                TreeRanges * range = new TreeRanges(infoList[0],infoList[1].toFloat(),lastParent);
                lastParent->appendChild(range);
                lastRange = range;
            }
            lastIndentation = currentIndentation;
        }
        inputFile.close();
    }
}

QStringList TreeRangesModel::getActionAndFrequence(QString line)
{
    QString cleanedUpStr = line.trimmed();
    QStringList split = cleanedUpStr.split("(");
    split[1].chop(2);
    return split;
}
