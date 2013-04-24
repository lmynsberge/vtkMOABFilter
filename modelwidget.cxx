#include <QtGui>
#include "modelwidget.h"
#include "adddialog.h"
#include <QString>
#include <QStringList>

ModelWidget::ModelWidget(QWidget *parent)
    : QTabWidget(parent)
{
    table = new TableModel(this);

    setupTabs();
}

void ModelWidget::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString volume = aDialog.volumeText->text();
        QString material = aDialog.materialText->toPlainText();
        QString density = aDialog.densityText->text();
		
        addEntry(volume, material, density);
    }
}

void ModelWidget::addEntry(QString volume, QString material, QString density)
{
    QList< QTuple<QString,QString, QString > >list = table->getList();
    QTuple<QString,QString, QString > tuple(volume, material, density);

    if (!list.contains(tuple)) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, volume, Qt::EditRole);
        index = table->index(0, 1, QModelIndex());
        table->setData(index, material, Qt::EditRole);
        index = table->index(0, 2, QModelIndex());
        table->setData(index, density, Qt::EditRole);
		
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The entity \"%1\" already exists.").arg(volume));
    }
}

void ModelWidget::editEntry()
{
    // not implemented -- shouldn't need to, but would allow manual editing via the list
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    QModelIndex index, i;
    QString volume;
    QString material;
	QString density;
    int row;

    foreach (index, indexes) {
        row = proxy->mapToSource(index).row();
        i = table->index(row, 0, QModelIndex());
        QVariant varVolume = table->data(i, Qt::DisplayRole);
        volume = varVolume.toString();

        i = table->index(row, 1, QModelIndex());
        QVariant varMaterial = table->data(i, Qt::DisplayRole);
        material = varMaterial.toString();
		
		i = table->index(row, 2, QModelIndex());
        QVariant varDensity = table->data(i, Qt::DisplayRole);
        density = varDensity.toString();
    }

    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Volume"));

    aDialog.volumeText->setReadOnly(true);
    aDialog.volumeText->setText(volume);
    aDialog.materialText->setText(material);
	aDialog.densityText->setText(density);
	

    if (aDialog.exec()) {
        QString newMaterial = aDialog.materialText->toPlainText();
		QString newDensity = aDialog.densityText->text();
        if (newMaterial != material) {
            i = table->index(row, 1, QModelIndex());
            table->setData(i, newMaterial, Qt::EditRole);
        }
		if (newDensity != density) {
            i = table->index(row, 2, QModelIndex());
            table->setData(i, newDensity, Qt::EditRole);
        }
    }
}

void ModelWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    QModelIndex index;

    foreach (index, indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
    }


}

void ModelWidget::setupTabs()
{
    QStringList groups;
    groups << "Volumes" << "Surfaces";

    for (int i = 0; i < groups.size(); ++i) {
        QString str = groups.at(i);

        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(table);
        proxyModel->setDynamicSortFilter(true);

        QTableView *tableView = new QTableView;
        tableView->setModel(proxyModel);
        tableView->setSortingEnabled(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->hide();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);

        QString newStr = QString("^[%1].*").arg(str);

        proxyModel->setFilterRegExp(QRegExp(newStr, Qt::CaseInsensitive));
        proxyModel->setFilterKeyColumn(0);
        proxyModel->sort(0, Qt::AscendingOrder);

        connect(tableView->selectionModel(),
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SIGNAL(selectionChanged(const QItemSelection &)));

        addTab(tableView, str);
    }
}

void ModelWidget::readFromFile(QString fileName)
{

    //*
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QList< QTuple<QString,QString, QString > > tuple = table->getList();
    QDataStream in(&file);
    in >> tuple;

    if (tuple.isEmpty()) {
        QMessageBox::information(this, tr("No entities in file."),
            tr("The file you are attempting to open contains no recognizeable entities."));
    } else {
        for (int i=0; i<tuple.size(); ++i) {
            QTuple<QString,QString, QString > t = tuple.at(i);
            addEntry(t.first,t.second,t.third);
        }
    }
    //*/
}

void ModelWidget::writeToFile(QString fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QList< QTuple<QString,QString, QString > > tuple = table->getList();
    QDataStream out(&file);
    out << tuple;
}
