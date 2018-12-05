#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>

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
    void on_pushButton_Up_clicked();

    void on_pushButton_Down_clicked();

    void on_pushButton_Start_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_Stop_clicked();

private:
    Ui::MainWindow *ui;
    int counter;
    QTimer *p_my_timer;

    void display();


};

#endif // MAINWINDOW_H
