#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAX_X 800
#define MAX_Y 600

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   // qDebug() << "Event pos" << event->pos();
   // qDebug() << "Global pos" << event->globalPos();
    QTransform transform;
    if (event->x() > MAX_X/2) {
        ui->label_2->setText("<img src = ':/img/img/layToRigth.png' width='115'  height='30'>");
        transform.scale(0.9, 0.9);
        transform.translate(-100,0);
    }else {
        ui->label_2->setText("<img src = ':/img/img/lay.png' width='115'  height='30'>");
        transform.scale(-0.9, 0.9);
        transform.translate(100,0);
    }
    pixmap->setTransform(transform);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Event pos" << event->pos();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->
            setStyleSheet("background-color: white;");

    this->setFixedSize(MAX_X,MAX_Y);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
   // ui->graphicsView->setMouseTracking(true);

    pixmap = new QGraphicsPixmapItem(
                QPixmap(":/img/img/stand.png"));

   // QGraphicsPixmapItem *newItem=new QGraphicsPixmapItem(QPixmap(":/img/img/stand.png"));

    //mouse = new QPixmap(":/img/img/stand.png");
    scene->addItem(pixmap);
    pixmap->setScale(0.33);

    QTransform transform;
        //transform.translate(50, 0);
        //transform.rotate(45);
        transform.scale(-0.5, 1.0);
    pixmap->setTransform(transform);
    //pixmap->setRotation(33);



    /*
    ui->label->setText("<img src = ':/img/img/chees.png' width='84'  height='60'>");
    ui->label_2->setText("<img src = ':/img/img/lay.png' width='115'  height='30'>");
    ui->label_3->setText("<img src = ':/img/img/sad.png' width='91'  height='46'>");
    ui->label_4->setText("<img src = ':/img/img/stand.png' width='94'  height='58'>");
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
