#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>



#include <QDebug>
#include <QUrl>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Get_clicked();
    void replyFinished(QNetworkReply *reply);
    void parseJson(QByteArray inputArray);

    void on_pushButton_Parse_clicked();

private:
    QNetworkAccessManager *netManager;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
