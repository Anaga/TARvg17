#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

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
    void on_radioButton_Red_clicked();
    void on_radioButton_Gren_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void draw10Rects();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rec;
    QGraphicsLineItem *line;
    QGraphicsTextItem *text;

    int x;
    int y;

};

#endif // MAINWINDOW_H
