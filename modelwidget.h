#ifndef MODELWIDGET_H
#define MODELWIDGET_H

#include <QTabWidget>
#include <QItemSelection>
#include "tablemodel.h"

class QSortFilterProxyModel;
class QItemSelectionModel;

class ModelWidget : public QTabWidget
{
    Q_OBJECT

public:
    ModelWidget(QWidget *parent=0);
    void readFromFile(QString fileName);
    void writeToFile(QString fileName);

public slots:
    void addEntry();
    void addEntry(QString volume, QString material, QString density);
    void editEntry();
    void removeEntry();

signals:
    void selectionChanged (const QItemSelection &selected);

private:
    void setupTabs();
    TableModel *table;
    QSortFilterProxyModel *proxyModel;
};

#endif