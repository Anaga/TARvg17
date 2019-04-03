#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QTreeView>
#include <QAbstractTableModel>
#include <QSqlTableModel>


//#include "mymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupModel(QSqlTableModel *model);
private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
    //MyModel *myModel;
};

#endif // MAINWINDOW_H
