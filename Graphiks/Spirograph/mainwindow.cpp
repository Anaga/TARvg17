#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MAX_X 700
#define MAX_Y 450

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(MAX_X+50,MAX_Y+150);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    int half_X = MAX_X/2;
    int half_Y = MAX_Y/2;
    scene->setSceneRect(-half_X,-half_Y, MAX_X, MAX_Y);
    drawAxes();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawAxes()
{
    int half_X = MAX_X/2;
    int half_Y = MAX_Y/2;

    //scene->addLine(0,0,half_X,half_Y);
    scene->addLine(0,0,half_X,0);
    scene->addLine(0,0,0,half_Y);

    scene->addLine(0,0,-half_X,0);
    scene->addLine(0,0,0,-half_Y);

    QPen redBoldPen(Qt::red);
    redBoldPen.setStyle(Qt::SolidLine);
    redBoldPen.setWidth(2);

    scene->addEllipse(-3,-3,6,6,redBoldPen);
    scene->addRect(-half_X, -half_Y, MAX_X, MAX_Y,
                   QPen(Qt::DotLine));


}

QPoint MainWindow::drawCircle(QPoint center, qreal radius, qreal angle, QColor color)
{
    int i;
    qreal x,y;
    qreal alpha;
    QPen pen(color);
    QPoint end;
    for(i=0; i < static_cast<int>(angle); i++) {
        alpha = qDegreesToRadians(static_cast<qreal>(i));
        x = radius * qCos(alpha) + center.x();
        y = -radius * qSin(alpha) + center.y();
        end.setX(static_cast<int>(x));
        end.setY(static_cast<int>(y));
        QLine line(center,end);

        scene->addLine(line,pen);
    }
    return end;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    QString qsTemp = "Angle is %1";
    ui->label->setText(qsTemp.arg(arg1,5,'g',5));
    QPoint O(00,00);
    int radius = ui->spinBox->value();
    scene->clear();
    drawAxes();
    QPoint newStart = drawCircle(O,radius,arg1, Qt::magenta);
    drawCircle(newStart,radius/2,arg1, Qt::cyan);
    //drawCircle(newStart,radius/3,arg1, Qt::darkYellow);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    QString qsTemp = "Radius is %1";
    ui->label_radius->setText(qsTemp.arg(arg1));
}
