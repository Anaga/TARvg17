#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bookshelf.db");
    db.open();
    QStringList dbTablesList = db.tables();
    qDebug() << dbTablesList;

    model = new QSqlTableModel(this,db);
    setupModel(model);
    ui->tableView->setModel(model);
    //QSqlQuery const query("SELECT name FROM author");
    //model->setQuery(query);

    //myModel = new MyModel(this);
    //ui->tableView->setModel(myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupModel(QSqlTableModel *model)
{
    model->setTable("books");
    model->select();
    model->removeColumn(0);

    /*
    model->setHeaderData(0,Qt::Horizontal,"Id");
    model->setHeaderData(1,Qt::Horizontal,"title");
    model->setHeaderData(2,Qt::Horizontal,"author");
    model->setHeaderData(3,Qt::Horizontal,"genre");*/

}
