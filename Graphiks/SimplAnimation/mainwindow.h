#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <QGraphicsItemGroup>

#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkBox_clicked();
    void updatePos();

    void on_checkBox_clicked(bool checked);

    void on_horizontalSlider_valueChanged(int value);
    //int horiz_bound_check(QGraphicsEllipseItem item);
    //int vetic_bound_check(QGraphicsEllipseItem item);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QTimer *timer;
    int speedX;
    int speedY;

    QGraphicsItemGroup *group;


};

#endif // MAINWINDOW_H
