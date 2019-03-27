#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

   QSqlDatabase *myDB;
   QSqlDatabase db;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   void on_pushButton_Connect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
