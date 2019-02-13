#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    ui->graphicsView->setScene(scene);

    scene->addRect(0,0, 800, 600, QPen(Qt::SolidLine), QBrush(QColor(Qt::magenta)));

    ellipse =  scene->addEllipse(
                0,0, 200, 100,
                QPen(Qt::DashLine), QBrush(QColor(Qt::darkCyan)));

    ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    timer = new QTimer(this);
    connect(timer, SIGNAL( timeout() ), this, SLOT(updatePos() ));
    timer->start(10);
    speedX=2;
    speedY=1;

    //group = scene->createItemGroup(ellipse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePos()
{
    qreal x, y;
    x = ellipse->x();
    y = ellipse->y();
    qDebug() << "Ellips old pos: " << x << y;

    QRectF boundRec = ellipse->boundingRect(); //get borders of ellips
    qreal wid = boundRec.width();
    qreal heg = boundRec.height();

    if (x+wid >= 800) speedX=-2; // Check rigth border
    if (x <= 0) speedX=+2;       // Check left border

    x+=speedX;

    if (y+heg >= 600) speedY=-1;
    if (y <= 0) speedY=+1;

    y+=speedY;

    qDebug() << "Ellips new pos: " << x << y;
    ellipse->setX(x);
    ellipse->setY(y);

}

void MainWindow::on_checkBox_clicked()
{
    //updatePos();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if (checked) timer->start();
    else timer->stop();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    QString qsTemp = "Cur val %1";
    qsTemp = qsTemp.arg(value);
    ui->label_Slider_Valie->setText(qsTemp);
    qsTemp = QString::number(value,16);
    qDebug() << "value in hex " << qsTemp;
}

#if 0
int MainWindow::vetic_bound_check(QGraphicsEllipseItem item)
{
    QRectF boundRec = item.boundingRect();
    qreal y = boundRec.y();
    qreal heg = boundRec.height();

    if (y+heg >= 600) return -1;
    return 1;
}

int MainWindow::horiz_bound_check(QGraphicsEllipseItem item)
{
    QRectF boundRec = item.boundingRect();
    qreal x = boundRec.x();
    qreal wid = boundRec.width();

    if (x+wid >= 800) return -1;
    return 1;

}

#endif
