#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

#define MAX_X 800
#define MAX_Y 600

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(MAX_X+50,MAX_Y+150);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    qreal half_mx = MAX_X/2.0;
    qreal half_my = MAX_Y/2.0;
    scene->setSceneRect(-half_mx,-half_my,MAX_X+5,MAX_Y+5);
    drowAxis();

    rotateAngel = 0;
    ui->label_Angel->setText("0°");


    R = 150.0;
    ui->label_Length->setText("150 pxt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drowAxis()
{
    qreal half_mx = MAX_X/2.0;
    qreal half_my = MAX_Y/2.0;

    //Borders
    QPen dots(Qt::black,1, Qt::DashLine);
    scene->addRect(-half_mx, -half_my, MAX_X, MAX_Y,dots);


    QPen bold(Qt::black,2, Qt::SolidLine);
    // Center point
    scene->addEllipse(-3,-3,6,6,bold);

    // Axis lines
    scene->addLine(0,0,half_mx,0,bold);
    scene->addLine(0,0,0,half_my,bold);
    scene->addLine(0,0,-half_mx,0,bold);
    scene->addLine(0,0,0,-half_my,bold);

}

QPoint MainWindow::drawLines(QPoint start, qreal length, int maxAngel, QColor lineCol)
{
    QPen normal(lineCol,1, Qt::SolidLine);

    static QPoint lastPoit ;
    // Axis lines in loop

    int i, x,y;
    qreal alpha;
    qreal rad;
    QPoint end;
    QPoint delta;
    QLine line(start,end);
    QString qsTemp = "alpha:%1, rad:%2, r:%3 line:";
    for (i=0;i<maxAngel;i++) {
        alpha = static_cast<double>(i);
        rad = qDegreesToRadians(alpha);
        x= static_cast<int>(qCos(rad)*length);
        y= static_cast<int>(-qSin(rad)*length);
        delta.setX(x);
        delta.setY(y);
        end=start+delta;
        line.setP1(lastPoit);
        line.setP2(end);


        //qDebug()<< qsTemp.arg(alpha).arg(rad).arg(length) << line;

        scene->addLine(line,normal);
    }
    lastPoit = end;
    return end;
}

void MainWindow::drawSpiro(QPoint start, qreal length, int curAngel, qreal k, QColor lineCol)
{
    QPen normal(lineCol,1, Qt::SolidLine);

    static QPointF lastPoit ;

    qreal R = length;
    qreal t = qDegreesToRadians(static_cast<qreal>(curAngel));
    qreal l = 0.25;

    qreal lk = l*k;
    qreal fric = ((1.0-k)*t);


    qreal newX, newY;
    newX = start.x() +  R*( ( (1-k)*qCos(t)) + ( (lk*qCos(fric) ) ) );
    newY = start.y() -  R*( ( (1-k)*qSin(t)) - ( (lk*qSin(fric) ) ) );
    QPointF curPoit(newX,newY);
    QLineF line(static_cast<QPointF>(start),curPoit);
    //QLineF line(lastPoit,curPoit);
    scene->addLine(line,normal);
    lastPoit = curPoit;

}

qreal MainWindow::degrToRad(qreal degrees)
{
    return ((degrees*M_PI)/180.0);
}


void MainWindow::on_horizontalSlider_Length_valueChanged(int value)
{
    R = value;
    ui->label_Length->setText(QString("%1 pxt").arg(R));
    r = R/2.0;

}

void MainWindow::on_horizontalSlider_Angel_valueChanged(int value)
{
    int rotMax = value;
    rotateAngel = 0;
    ui->label_Angel->setText(QString::number(rotMax));
    QPoint O(00,00);

    //scene->clear();
    //drowAxis();

    drawSpiro(O,R,rotMax,0.5,Qt::cyan);
    /*
    QPoint L = drawLines(O,R,rotMax, Qt::magenta);
    drawLines(L,r,rotMax*2,Qt::cyan);
    */
}
