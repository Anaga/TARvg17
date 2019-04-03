#include "mymodel.h"

MyModel::MyModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    int val = row + col;
    QString qsTemp = "Val for row%1 and col%2 = %3";
    qsTemp = qsTemp.arg(row).arg(col).arg(val);
    if (role == Qt::DisplayRole) {
        return qsTemp;
    }
    return QVariant();
}
