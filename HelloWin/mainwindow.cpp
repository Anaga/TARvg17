#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    counter=0;
    p_my_timer = new QTimer(this);
    connect(p_my_timer, SIGNAL(timeout()), this, SLOT(on_pushButton_Up_clicked()));

    QDateTime dt;
    dt = QDateTime::currentDateTime();
    qDebug() << dt.toString();
    QString qsTemp = dt.toString(" hh:mm:ss.zzz");
    qDebug() << "qsTemp is "<< qsTemp;
    ui->label->setText(qsTemp);
    //qsTemp = "This is test message";
   // timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Up_clicked()
{
    counter++;
    display();
}

void MainWindow::on_pushButton_Down_clicked()
{
    counter--;
    display();
}

void MainWindow::display()
{
    if (counter>10) {
        ui->lcdNumber->setDecMode();
    }
    QString qsTemp = "Counter value is %1";
    qsTemp = qsTemp.arg(counter);
    ui->label->setText(qsTemp);
    ui->lcdNumber->display(counter);
}

void MainWindow::on_pushButton_Start_clicked()
{
    p_my_timer->start(ui->horizontalSlider->value());
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    p_my_timer->setInterval(value);
    QString qsTemp = "Timer repeat value %1 milsec";
    qsTemp = qsTemp.arg(value);
    ui->label_TimerVal->setText(qsTemp);
}

void MainWindow::on_pushButton_Stop_clicked()
{
    p_my_timer->stop();
}
