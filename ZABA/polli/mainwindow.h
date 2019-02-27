#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMouseEvent>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QtMath>
#include <QTimer>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void drowAxis();
    QPoint drawLines(QPoint start, qreal length, int maxAngel, QColor lineCol);
    void drawSpiro(QPoint start, qreal length, int curAngel, qreal k, QColor lineCol);
    qreal radToGrad(qreal radian);
    qreal degrToRad(qreal degrees);


private slots:
    void on_horizontalSlider_Length_valueChanged(int value);

    void on_horizontalSlider_Angel_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmap;
    QPixmap *mouse;

    int rotateAngel;
    qreal R;
    qreal r;
};

#endif // MAINWINDOW_H
