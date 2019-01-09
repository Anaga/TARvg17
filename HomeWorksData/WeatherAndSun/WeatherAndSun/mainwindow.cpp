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
    //"sunrise":1547017888,
    //"sunset":1547041538

    QDateTime dtSunRise;
    dtSunRise.setSecsSinceEpoch(1547017888);
    QTime tSunRise = dtSunRise.time();
    int iSunRiseInSec = tSunRise.msecsSinceStartOfDay()/1000;
    QString qsTemp = tSunRise.toString("HH:mm:ss");
    qDebug() << "Sun rise:" << qsTemp;
    qDebug() << "iSunRiseInSec "<< iSunRiseInSec;

    ui->lineEdit_SunRise->setText("Sun rise: "+qsTemp);

    QDateTime dtSunSet;
    dtSunSet.setSecsSinceEpoch(1547041538);
    QTime tSunSet = dtSunSet.time();
    int iSunSetInSec = tSunSet.msecsSinceStartOfDay()/1000;
    qsTemp = tSunSet.toString("HH:mm:ss");
    qDebug() << "Sun set:" << qsTemp;
    qDebug() << "iSunSetInSec "<< iSunSetInSec;
    ui->lineEdit_SunSet->setText("Sun set: "+qsTemp);

    ui->progressBar->setRange(iSunRiseInSec,iSunSetInSec);

    QDateTime dt = QDateTime::currentDateTime();
    QTime tNow = dt.time();
    tNow = tNow.addSecs(60*60*11); // shift for 11 hour in future
    int iNowInSec = tNow.msecsSinceStartOfDay()/1000;
    ui->progressBar->setValue(iNowInSec);
    qDebug() << "iNowInSec "<< iNowInSec;
    qsTemp = tNow.toString("HH:mm:ss");
    ui->label_Sun->setText("Now is: "+qsTemp);

    //"main":{"temp":-4.79,
    ui->verticalSlider->setValue(-5);

}
