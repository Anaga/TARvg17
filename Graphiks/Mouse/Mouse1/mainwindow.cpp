#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
class MyGraphicsView : public QGraphicsView
{
   Q_OBJECT

protected:
   void mouseMoveEvent(QMouseEvent *event);
};
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    m_scene = new MyQGraphicsScene();
    m_scene->setSceneRect(0,0,800,600);
    ui->graphicsView->setScene(m_scene);

    m_scene->addRect(0,0, 800, 600, QPen(Qt::SolidLine), QBrush(QColor(Qt::magenta)));

    ellipse =  m_scene->addEllipse(
                0,0, 200, 100,
                QPen(Qt::DashLine), QBrush(QColor(Qt::darkCyan)));

    ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    //ui->graphicsView->setMouseTracking(true);

    //connect(scene, SIGNAL(mouseMoveEvent(QMouseEvent*)),
    //        this, SLOT(GraphicsSceneMouseEvent(QMouseEvent*)));

    //setMouseTracking(true);

}


void MainWindow::mouseMoveEvent(QMouseEvent* event) {
    //qDebug() << "Global pos: " << event->globalPos();
    //qDebug() << "Local pos: " << event->pos();
    QString qsTemp = "Local pos: %1:%2";
    qsTemp = qsTemp.arg(event->x()).arg(event->y());
    ui->label->setText(qsTemp);
    //qDebug() << QString::number(event->pos().x());
    //qDebug() << QString::number(event->pos().y());
}

void MainWindow::GraphicsSceneMouseEvent(QMouseEvent *event)
{
    qDebug() << "Global pos: " << event->globalPos();
    qDebug() << "Local pos: " << event->pos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MyQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "Global pos: " << event->globalPos();
    qDebug() << "Local pos: " << event->pos();
}
