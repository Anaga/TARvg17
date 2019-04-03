#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel
{
        Q_OBJECT
public:
    MyModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

#endif // MYMODEL_H
