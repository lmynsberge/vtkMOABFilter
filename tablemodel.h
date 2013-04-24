#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "qtuple.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
	
public:
    TableModel(QObject *parent=0);
	TableModel(QList< QTuple<QString,QString, QString > > listofDetails, QObject *parent=0);
	
	int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
    QList< QTuple<QString,QString, QString > > getList();

private:
    QList< QTuple<QString,QString, QString > > listOfDetails;
};

#endif 