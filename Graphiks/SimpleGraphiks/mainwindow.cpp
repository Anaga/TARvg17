#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    x = y =0;
    QPen outlinePen(Qt::blue );
    QBrush greenBrush(QColor(50,250,50,100));


    line = scene->addLine(20,20, 200, 20, QPen(Qt::DotLine));
    text = scene->addText("Hello Scene", QFont("Times", 10, QFont::Bold) );
    rec = scene->addRect(x, y, 50, 50, outlinePen, greenBrush);
    rec->setFlag(QGraphicsItem::ItemIsMovable);

    draw10Rects();

    qDebug() << __PRETTY_FUNCTION__;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_Red_clicked()
{
    qDebug() << __PRETTY_FUNCTION__;
    x+=10;
    y+=20;
    qDebug() << "x= " << x << "  y= " << y;
    QPen outlinePen(Qt::blue );
    outlinePen.setWidth(3);
    QBrush redBrush("#FF0000");
    qDebug() << "x= " << x << "  y= " << y ;
    qDebug() << "s val " << ui->horizontalSlider->value();
    rec->setBrush(redBrush);

    //scene->addRect(x, y, 50, 50, outlinePen, redBrush);
}

void MainWindow::on_radioButton_Gren_clicked()
{
    qDebug() << __PRETTY_FUNCTION__;
    x+=30;
    y+=50;
    QPen outlinePen(Qt::blue );
    QBrush greenBrush(Qt::green);

    qDebug() << "x= " << x << "  y= " << y;
    rec->setBrush(greenBrush);

    QBrush brFromRec;
    brFromRec = rec->brush();

    QColor colFromBrush;
    colFromBrush = brFromRec.color();
    colFromBrush.setAlpha(42);

    qDebug() << "Cololr" << colFromBrush;
    //scene->addRect(x, y, 50, 50, outlinePen, greenBrush);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << __PRETTY_FUNCTION__ << " value " << value;

}

void MainWindow::draw10Rects()
{
    x=0;
    y=0;
    int width = 50;
    int heigth = 100;
    int green = 250;

    QBrush brush;
    QColor color(50,green,50);
    brush.setColor(color);
    brush.setStyle(Qt::Dense1Pattern);
    brush.setStyle(Qt::SolidPattern);
    qDebug() << brush;

    for(int i=0; i<10; i++){
      scene->addRect(x, y, width, heigth,
                     QPen(Qt::DashDotLine), brush);
      x+=10;
      y+=-10;
      width+=7;
      heigth+=20;
      green+=-10;
      color.setGreen(green);
      brush.setColor(color);

    }

}
