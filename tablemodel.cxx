#include "tablemodel.h"


	
TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

TableModel::TableModel(QList< QTuple<QString,QString, QString > > details, QObject *parent)
    : QAbstractTableModel(parent)
{
    listOfDetails=details;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfDetails.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= listOfDetails.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        QTuple<QString,QString, QString > tuple = listOfDetails.at(index.row());

        if (index.column() == 0)
            return tuple.first;
        else if (index.column() == 1)
            return tuple.second;
		else if (index.column() == 2)
            return tuple.third;
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Entity");

            case 1:
                return tr("Material/Tally");
				
            case 2:
                return tr("Density/Multiplier");
				
            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; row++) {
        QTuple<QString,QString, QString > tuple(" ", " ", " ");
        listOfDetails.insert(position, tuple);
    }

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; ++row) {
        listOfDetails.removeAt(position);
    }

    endRemoveRows();
    return true;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
        if (index.isValid() && role == Qt::EditRole) {
                int row = index.row();

                QTuple<QString,QString, QString > t = listOfDetails.value(row);

                if (index.column() == 0)
                        t.first = value.toString();
                else if (index.column() == 1)
                        t.second = value.toString();
				else if (index.column() == 2)
                        t.third = value.toString();
        else
            return false;

        listOfDetails.replace(row, t);
                emit(dataChanged(index, index));

        return true;
        }

        return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

QList< QTuple<QString,QString, QString > > TableModel::getList()
{
    return listOfDetails;
}
