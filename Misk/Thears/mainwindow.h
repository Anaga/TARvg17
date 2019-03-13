#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "myworker.h"

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
    void on_dial_T1_valueChanged(int value);
    void on_radioButton_T1_Down_toggled(bool checked);

    void on_pushButton_T1_clicked(bool checked);
    void updateText(int value);

    QString someMagic();

private:
    Ui::MainWindow *ui;
    MyWorker *worker1;
    QThread *MyThread1;
    QString qsT1Status;
};

#endif // MAINWINDOW_H
