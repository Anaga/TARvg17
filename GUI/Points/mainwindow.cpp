#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

    // addEllipse(x,y,w,h,pen,brush)
    ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

    text = scene->addText("www.tthk.ee", QFont("Arial", 20) );
    // movable text
    text->setFlag(QGraphicsItem::ItemIsMovable);

    myColorList.append(Qt::red);
    myColorList.append("#22AAEE");
    myColorList.append(Qt::green);
    myColorList.append("#AA44EE");
    myColorList.append(Qt::blue);
    myColorList.append("#AABB55");

}

void MainWindow::on_pushButton_Rec_change_clicked()
{
    QBrush curBrush;
    QColor curCollor;
    curBrush = rectangle->brush();
    curCollor = curBrush.color();
    int pos = myColorList.indexOf(curCollor);
    qDebug() << "Rec color " << curCollor.name() << "pos in list " << pos ;

    if (pos+1 >= myColorList.size()){
        curCollor = myColorList.at(0);
    } else {
        curCollor = myColorList.at(pos+1);
    }


    qDebug() << "Next color will be " << curCollor.name();


    curBrush.setColor(curCollor);
    rectangle->setBrush(curBrush);


}

void MainWindow::on_pushButton_Elips_change_clicked()
{
    QBrush curBrush;
    QColor curCollor;
    curBrush = ellipse->brush();
    curCollor = curBrush.color();
    int pos = myColorList.indexOf(curCollor);
    qDebug() << "ellipse color " << curCollor.name() << "pos in list " << pos ;

    if (pos+1 >= myColorList.size()){
        curCollor = myColorList.at(0);
    } else {
        curCollor = myColorList.at(pos+1);
    }


    qDebug() << "Next color will be " << curCollor.name();


    curBrush.setColor(curCollor);
    ellipse->setBrush(curBrush);

}
