#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtAlgorithms>

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
    void on_pushButton_Sort_clicked();
    void on_lineEdit_Input_returnPressed();

    void on_pushButton_ReadFile_clicked();

private:
    QString sort(QString qsInput);
    bool writeToFile(QString qsWord);
    bool readFromFile(QString fileName);

private:
    Ui::MainWindow *ui;
    QString qsFileName;

};





















#endif // MAINWINDOW_H
