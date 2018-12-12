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
    qsTemp = arraySolution(qsTemp);
    //qsTemp = sort(qsTemp);
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


QString MainWindow::arraySolution(QString qsInput)
{
    // this function not use sort,  but use array, and can handle only [a..z] letters
#define ALPHABET_LENGTH 26
    QChar arr_ch[ALPHABET_LENGTH];
    int arr_i[ALPHABET_LENGTH] = {0};
    
    for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        arr_ch[i]='a'+i;
    }

    qDebug() << "arr content:";
    QString firstRow = "Leter: ";
    QString secondRow= "Count: ";
    for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        firstRow .append(arr_ch[i]).append(" | ");
        secondRow.append(QString::number(arr_i[i])) .append(" | ");
    }
    qDebug() << firstRow;
    qDebug() << secondRow;

    char ch;
    for (int i=0; i<qsInput.length(); i++){
        ch = qsInput.at(i).toLatin1();
        if ((ch>='a') && (ch<='z')) { // we will update count only for [a..z] letters
            // get array position base on delta from 'a' char.
            // so, for char 'c' delta will be 3 ('c'-'a'=3)
            // and for char 'o' delta will be 13 ('o'-'a'=12)
            int delta = ch - 'a';
            arr_i[delta]++;
        }
    }
    qDebug() << "arr content:";
    firstRow = "Leter: ";
    secondRow= "Count: ";
    for (int i = 0; i < ALPHABET_LENGTH; ++i) {
        firstRow .append(arr_ch[i]).append(" | ");
        secondRow.append(QString::number(arr_i[i])) .append(" | ");
    }
    qDebug() << firstRow;
    qDebug() << secondRow;
    QString qsOutput;
    for (int i = 0; i < ALPHABET_LENGTH; ++i) { // for all letters
        for (int j=0; j<arr_i[i]; j++){     // we will insert to qsOutput begin
            qsOutput.prepend(arr_ch[i]);    // this letter from 0 till arr_i[i] count
        }                                   // most time it is zerro
    }
    return qsOutput;
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
























