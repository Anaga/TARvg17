#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Event pos" << event->pos();
    qDebug() << "Global pos" << event->globalPos();


}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("<img src = ':/img/img/chees.png' width='84'  height='60'>");
    ui->label_2->setText("<img src = ':/img/img/lay.png' width='115'  height='30'>");
    ui->label_3->setText("<img src = ':/img/img/sad.png' width='91'  height='46'>");
    ui->label_4->setText("<img src = ':/img/img/stand.png' width='94'  height='58'>");
}

MainWindow::~MainWindow()
{
    delete ui;
}
