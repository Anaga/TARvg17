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
    QJsonParseError parError;
    QJsonDocument mainJson = QJsonDocument::fromJson(inputArray,&parError);

    if (parError.error != QJsonParseError::NoError) {
        qDebug() << "Error in parsing" << parError.errorString();
        return;
    }
    qDebug() << "no errors in parseJson";

    if (mainJson.isArray()) { qDebug() << "This is Array";}
    if (mainJson.isObject()) { qDebug() << "This is Object";}
    if (mainJson.isNull()) { qDebug() << "This is Null";}
    if (mainJson.isEmpty()) { qDebug() << "This is Empty";}

    QJsonObject myObj = mainJson.object();
    qDebug() << "All keys ";
    qDebug() << myObj.keys();

    if (!myObj.contains("main")) {
        qDebug() << "no main in parseJson";
        return;
    }
    QJsonValue keyValue = myObj.value("main");
    qDebug() << keyValue;

    QJsonObject item = keyValue.toObject();
    keyValue = item.value("temp");
    qDebug() << keyValue;


    double d_tempCelc = keyValue.toDouble(-200);
    ui->label->setText(QString::number(d_tempCelc));

    keyValue = myObj.value("weather");
    qDebug() << "weather :" << keyValue;
// working with array
    QJsonArray arr = keyValue.toArray();
     qDebug() << "array :" << arr;

     QJsonValue iconId = arr[0].toObject().value("icon");
     qDebug() << iconId;

     /*
      * https://api.openweathermap.org/data/2.5/forecast?id=588335&units=metric&appid=b7920869b08bcdf2c3477cd70a6f27c9
      * id=588335 - Tartu
      */

     // image for icon "04n" can be downloaded there:
     // http://openweathermap.org/img/w/04n.png


     /* iterat over array
     for (int i=0;i<40;i++){
         QJsonValue iconId = arr[i].toObject().value("icon");
         qDebug() << iconId;
         QString qsTemp = iconId.toString();
         ui->plainTextEdit->appendPlainText("18:00:00 -4.18 light snow");
     }
     */

     QString qsTemp = iconId.toString();
     ui->label_iconID->setText(qsTemp);





}

void MainWindow::on_pushButton_Parse_clicked()
{
  QString qsTemp = ui->plainTextEdit->toPlainText();
  if (!qsTemp.isEmpty()){
      parseJson(qsTemp.toLatin1());
  }
}
