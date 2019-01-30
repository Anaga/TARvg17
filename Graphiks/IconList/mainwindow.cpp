#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_sun->setChecked(true);
    ui->pushButton_sun->setIcon(QIcon(":/small/icons/48x48/sun.png"));
    ui->pushButton_sun->setIconSize(QSize(48,48));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_sun_clicked()
{
    ui->label_sun->setText("<center>Sun rise! <br> <img src=':/big/icons/256x256/sun.png'>");
}

void MainWindow::on_pushButton_snow_clicked(bool checked)
{
    qDebug() << "on_pushButton_snow_clicked(bool checked)" << checked;

    if (checked) {
        ui->label_snow->setText("<center>Snow is falling! <br> <img src=':/big/icons/256x256/snow.png'> ");
    } else {
        ui->label_snow->setText("<center>Snow stop falling!<br> <img src=':/big/icons/256x256/snow1.png' width='256'  height='256'  >");
    }
}

void MainWindow::on_pushButton_rain_toggled(bool checked)
{

    ui->label_rain->setText("<center>It raining day! <br> <img src=':/big/icons/256x256/rain.png'>");

    qDebug() << "on_pushButton_rain_toggled(bool checked)" << checked;
}

