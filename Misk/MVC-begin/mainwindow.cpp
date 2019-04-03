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

void MainWindow::generateTable(int col, int row)
{
    // Val =  x*x + y*y
    // x - Col, y - Row
    ui->tableWidget->setColumnCount(col);
    ui->tableWidget->setRowCount(row);
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            int green = i*i;
            int blue = j*j;
            int red = static_cast<int> ((green + blue)/1.40);
            QString qsTemp = "R%1, G%2, B%3";
            qsTemp = qsTemp.arg(red).arg(green).arg(blue);
            QTableWidgetItem *item = new QTableWidgetItem(qsTemp);
            item->setBackgroundColor(QColor(red, green, blue));
            ui->tableWidget->setItem(i,j,item);
            qDebug() << "red" << red
                     << "green" << green
                     << "blue" << blue;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    int col = ui->spinBox_Col->value();
    int row = ui->spinBox_Row->value();
    generateTable(col, row);
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{

}
