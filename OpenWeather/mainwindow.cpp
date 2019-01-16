#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    netManager = new QNetworkAccessManager(this);

    connect(netManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Get_clicked()
{
    QString qsCityName= ui->comboBox->currentText();
    QString qsTemp = ui->lineEdit_Address->text();
    ui->textBrowser->append(qsCityName + " URL : " + qsTemp);
    QUrl adress;
    //adress.setUrl("https://qt-project.org",);
    //adress.setScheme("https");
    adress.setUrl("https://api.openweathermap.org/data/2.5/weather?q=Narva&units=metric&appid=b7920869b08bcdf2c3477cd70a6f27c9", QUrl::StrictMode);
    //adress.setPort(80);

    if (adress.isValid()) {
        qDebug() << adress.host();
        qDebug() << adress.port();
        qDebug() << adress.query();
        netManager->get(QNetworkRequest(adress));
    }
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    ui->textBrowser->append("We got replay");
    qDebug() << "reply from URL " << reply->url().toString();
    if ( reply->error() != QNetworkReply::NoError){
        qWarning() <<"ErrorNo: "<< reply->error() << "for url: " << reply->url().toString();
        qDebug() << "Request failed, " << reply->errorString();
        qDebug() << "Headers:"<<  reply->rawHeaderList()<< "content:" << reply->readAll();
        return;
    }

    QList<QByteArray> replyHeaders = reply->rawHeaderList();
    QString qsHeadersList;
    QByteArray baContent = reply->readAll();
    QString qsContent = baContent;
    QPair<QByteArray, QByteArray> HeaderPair;
    qDebug() << "Headers list:"<<  reply->rawHeaderList(); //<< "content:";// << reply1->readAll();
    qDebug() << "Replay Headers list: count " << replyHeaders.size();
    for (int i = 0; i < replyHeaders.size(); ++i) {
        HeaderPair = reply->rawHeaderPairs().at(i);
        qsHeadersList.append(HeaderPair.first);
        qsHeadersList.append(": ");
        qsHeadersList.append(HeaderPair.second);
        qsHeadersList.append("\n");
        qDebug() << "i is: "<< i;
    }
    qDebug() << qsHeadersList;
    ui->textBrowser->append("Headers: " + qsHeadersList);
    ui->textBrowser->append("Content: " + qsContent);


    //QString qsTemp = reply->readAll();
    //ui->textBrowser->append(qsTemp);

}

void MainWindow::parseJson(QByteArray inputArray)
{
    qDebug() << "parseJson";
    qDebug() << "inputArray is " << inputArray;

}

void MainWindow::on_pushButton_Parse_clicked()
{
  QString qsTemp = ui->plainTextEdit->toPlainText();
  if (!qsTemp.isEmpty()){
      parseJson(qsTemp.toLatin1());
  }
}
