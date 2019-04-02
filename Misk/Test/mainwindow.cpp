#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Currency SomeEuro(10);
    ui->plainTextEdit->appendPlainText("10 Euro");
    Currency SomeSents(0.34);
    Currency total(0);
    total = SomeEuro+SomeSents;
    ui->plainTextEdit->appendPlainText("+ 0.34 sents will be:");
    qDebug() << total.toPrint();
    qDebug() << SomeEuro;
    ui->plainTextEdit->appendPlainText(total.toPrint());

}
