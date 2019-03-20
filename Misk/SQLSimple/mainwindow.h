#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSqlDatabase db;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Connect_clicked();

    void on_pushButton_Send_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
