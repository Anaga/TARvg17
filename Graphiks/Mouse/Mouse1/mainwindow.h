#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <QGraphicsItemGroup>

#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class MyQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
protected:
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};



namespace Ui {



class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mouseMoveEvent(QMouseEvent* event);
    void GraphicsSceneMouseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MyQGraphicsScene *m_scene;
    QGraphicsEllipseItem *ellipse;
    QTimer *timer;
};




#endif // MAINWINDOW_H
