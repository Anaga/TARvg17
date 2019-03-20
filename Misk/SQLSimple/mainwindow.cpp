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
    QString qsTemp = ui->lineEdit->text();
    QSqlQuery query(qsTemp);
    //QSqlQuery query("select * from books");
    ui->textBrowser->append("Books: ");
    while (query.next()) {
        QString book = query.value(1).toString();
        ui->textBrowser->append(book);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    QStringList authorsList;
    QSqlQuery query("select name from authors");
    while (query.next()) {
        QString author = query.value(0).toString();
        authorsList.append(author);
    }
    qDebug() << authorsList;

    QStringList genresList;
    query.prepare("select name from genres");
    query.exec();
    while (query.next()) {
        QString gen = query.value(0).toString();
        genresList.append(gen);
    }
    qDebug() << genresList;

    query.exec("select title,author,genre  from books");
    QString title, author, genre;
    int authId, genId;
    while (query.next()) {
        title = query.value(0).toString();
        authId = query.value(1).toInt();
        genId = query.value(2).toInt();

        author = authorsList.at(authId-1);
        genre = genresList.at(genId-1);
        QString qsTemp = title + " | " + author + " | "+genre;
        ui->textBrowser->append(qsTemp);
    }
}

