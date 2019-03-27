#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textBrowser->append(" Hello");

    QStringList qsl = QSqlDatabase::drivers();
    for (QString line : qsl) {
       ui->textBrowser->append("SQL driver: " + line);
}

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bookshelf.sql");



    /*
    myDB = new QSqlDatabase;
    myDB->setDatabaseName("")
    ::addDatabase("QPSQL");
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Connect_clicked()
{
    if (!db.open()){
        ui->label->setText("Can't open");
        ui->textBrowser->append( db.lastError().text());
        return;
    }
    ui->label->setText("CDB open");
}
