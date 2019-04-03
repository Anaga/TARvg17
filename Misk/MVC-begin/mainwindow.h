#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void generateTable(int col, int row);
private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
