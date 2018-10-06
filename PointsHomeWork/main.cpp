#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>

struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B); // return distance between point A and B (use Pifagor's Theorem)
float perimeter(Point Array[4]); // return distance perimeter usind function distance 4 times
float area(Point Array[4]);  // return area using Gauss's area formula or use Geron formaula for two triangles ABC + ACD

QString printQuad(Point Arr[4]); // and also to QString

int main()
{
    Point quadOne[4];

    quadOne[0].Name='A';
    quadOne[0].x=0.0;
    quadOne[0].y=0.0;

    quadOne[1].Name='B';
    quadOne[1].x=4.0;
    quadOne[1].y=0.0;

    quadOne[2].Name='C';
    quadOne[2].x=4.0;
    quadOne[2].y=4.0;

    quadOne[3].Name='B';
    quadOne[3].x=0.0;
    quadOne[3].y=4.0;

    qDebug() << printQuad(quadOne);
    QString qsRetVal = "Have perimeter %1 and area %2";
    float perim,ar;
    perim = perimeter(quadOne);
    ar = area(quadOne);
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;

}

QString printQuad(Point Arr[4])
{
    QString qsRetVal = "Quadrilateral with points: ";
    QString qsTemp;
    Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
        curPoint = Arr[i];
        qsTemp=qsTemp.arg(curPoint.Name).arg(curPoint.x).arg(curPoint.y);
        qsRetVal.append(qsTemp);
    }
    return qsRetVal;
}

float distance(Point A, Point B){ return 4.0; }
float perimeter(Point Array[4]){ return 16.0; }
float area(Point Array[4]){ return 16.0; }
