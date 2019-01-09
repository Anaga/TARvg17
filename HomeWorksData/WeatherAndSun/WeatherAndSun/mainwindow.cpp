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
    /*
     *
     * reqest:
https://api.openweathermap.org/data/2.5/weather?q=Narva&units=metric&appid=b7920869b08bcdf2c3477cd70a6f27c9

response:
{
  "coord":{"lon":28.19,"lat":59.38},
  "weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04n"}],
  "base":"stations",
  "main":{"temp":-4.79,"pressure":1024.49,"humidity":96,"temp_min":-4.79,"temp_max":-4.79,"sea_level":1028.03,"grnd_level":1024.49},
  "wind":{"speed":2.01,"deg":214.503},
  "clouds":{"all":92},
  "dt":1547070537,
  "sys":{"message":0.0035,"country":"RU","sunrise":1547017034,"sunset":1547040740},
  "id":590031,
  "name":"Narva",
  "cod":200
}


reqest:
https://api.openweathermap.org/data/2.5/weather?q=Tallinn&units=metric&appid=b7920869b08bcdf2c3477cd70a6f27c9

response:
{
  "coord":{"lon":24.75,"lat":59.44},
  "weather":[{"id":804,"main":"Clouds","description":"overcast clouds","icon":"04n"}],
  "base":"stations",
  "main":{"temp":-2,"pressure":1015,"humidity":92,"temp_min":-2,"temp_max":-2},
  "visibility":10000,
  "wind":{"speed":2.6,"deg":360},
  "clouds":{"all":90},
  "dt":1547068800,
  "sys":{"type":1,"id":1330,"message":0.2238,"country":"EE","sunrise":1547017888,"sunset":1547041538},
  "id":588409,
  "name":"Tallinn",
  "cod":200
}
     *
     * */

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
