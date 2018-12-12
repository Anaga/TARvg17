#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsFileName = "output.log";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Sort_clicked()
{
    QString qsTemp = ui->lineEdit_Input->text();
    qsTemp = sort(qsTemp);
    ui->plainTextEdit_Output->appendPlainText(qsTemp);
    ui->lineEdit_Input->clear();
    ui->lineEdit_Input->setFocus();
    if (writeToFile(qsTemp)){
        qDebug() << "writeToFile was Ok " << qsTemp;
    }else {
        qDebug() << "writeToFile was not ok " << qsTemp;
    }

}
void MainWindow::on_lineEdit_Input_returnPressed()
{
    ui->pushButton_Sort->click();
}

QString MainWindow::sort(QString qsInput){
    QList<QChar> myList;
    QChar ch;
    for (int i=0; i<qsInput.length(); i++){
        ch = qsInput.at(i);
        myList.append(ch);
    }
    qDebug() << "My list before sorting " << myList;
    std::sort(myList.begin(), myList.end());

    qDebug() << "My list after sorting " << myList;
    QString qsOutput;
    for (int i = 0; i < myList.size(); ++i) {
        qsOutput.prepend(myList.at(i));
    }
    return (qsOutput);
}

bool MainWindow::writeToFile(QString qsWord)
{
    QFile outFile(qsFileName);
    if (!outFile.open(QIODevice::Append | QIODevice::Text)){
        return false;
    }
    outFile.write(qPrintable(qsWord));
    outFile.write("\n");
    outFile.close();
    return true;
}

bool MainWindow::readFromFile(QString fileName)
{
    qDebug() << "readFromFile, File name is" << fileName;
    char buf[1024];
    QFile inputFile(fileName);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Can't open file" ;
        return false;
    }
    qDebug() << buf;
    while (!inputFile.atEnd()) {
        inputFile.readLine(buf, 1024);
        qDebug() << buf;
        QString qsOneLine(buf);
        qsOneLine = qsOneLine.trimmed();
        qDebug() << "One line from file " << fileName << "is :" << qsOneLine;
        ui->lineEdit_Input->setText(qsOneLine);
        ui->pushButton_Sort->click();
            }
    return true;
}

void MainWindow::on_pushButton_ReadFile_clicked()
{
    QString qsTemp = ui->lineEdit_InpFileName->text();
    qDebug() << "on_pushButton_ReadFile_clicked" ;
    qDebug() << "File name is" << qsTemp;
    bool isReadOK = false;
    isReadOK = readFromFile(qsTemp);
    qDebug() << "isReadOK is " << isReadOK;
}
























