#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList driverList;
    driverList = QSqlDatabase::drivers();

    qDebug()<< driverList;
    for (QString line : driverList){
        ui->textBrowser->append(line);
    }

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bookshelf.sql");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Connect_clicked()
{
    if (!db.open()){
        ui->label_status->setText("Can't open connection");
        ui->textBrowser->append( db.lastError().text() );
        return;
    }
    ui->label_status->setText("open connection");
    QStringList dbTablesList = db.tables();
    qDebug() << dbTablesList;
    ui->textBrowser->append("Tables: ");
    for (QString line : dbTablesList){
        ui->textBrowser->append(line);
    }
}

void MainWindow::on_pushButton_Send_clicked()
{
    QSqlQuery query("select * from books");
    ui->textBrowser->append("Books: ");
    while (query.next()) {
        QString book = query.value(1).toString();
        ui->textBrowser->append(book);
    }

}
