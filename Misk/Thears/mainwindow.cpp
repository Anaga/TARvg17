#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsT1Status = "The thread T1 is %1,\ncounting %2,\ntimeout %3";
    QString qsTemp = qsT1Status.arg("Stoped").arg("Up").arg("1000");
    ui->label_T1->setText(qsTemp);
    ui->radioButton_T2_Up->setChecked(true);

    worker1 = new MyWorker();
    MyThread1 = new QThread();

    worker1->moveToThread(MyThread1);

    connect(worker1, SIGNAL(valueChange(int)),
            this, SLOT(updateText(int)));

    connect(MyThread1, SIGNAL(started()),
            worker1, SLOT(workHarder()));

    connect(MyThread1, SIGNAL(finished()),
            worker1, SLOT(breakWork()));

//    connect(ui->dial_T1, SIGNAL(valueChanged(int)),
//            worker1, SLOT(setTimeout(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dial_T1_valueChanged(int value)
{
    ui->label_T1->setText(someMagic());
    worker1->setTimeout(value);
}


void MainWindow::on_radioButton_T1_Down_toggled(bool checked)
{
    ui->label_T1->setText(someMagic());

}

void MainWindow::on_pushButton_T1_clicked(bool checked)
{
    ui->label_T1->setText(someMagic());
    if (checked) {
        MyThread1->start();
    }
    else {
        MyThread1->quit();
    }

}

void MainWindow::updateText(int value)
{
    QString qsTemp = "Proc T1 value %1";
    ui->textBrowser->append(qsTemp.arg(value));
}

QString MainWindow::someMagic()
{
    bool status = ui->pushButton_T1->isChecked();
    int timeout = ui->dial_T1->value();
    bool direction = ui->radioButton_T1_Up->isChecked();
    QString qsStatus;
    qsStatus =  !status ? "Stoped": "Started";

    QString qsDir;
    qsDir = direction ? "Up" : "Down";


    return qsT1Status.arg(qsStatus).arg(qsDir).arg(timeout);
}
