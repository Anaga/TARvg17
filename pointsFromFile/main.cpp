#include <QCoreApplication>
#include <QFile>
#include <QDebug>

#include <iostream>
using namespace std;

struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B); // return distance between point A and B (use Pifagor's Theorem)
float perimeter(Point Array[4]); // return distance perimeter usind function distance 4 times
float area(Point Array[4]);  // return area using Gauss's area formula or use Geron formaula for two triangles ABC + ACD

QString printQuad(Point Arr[4]); // and also to QString
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

int main()
{
    QString message;
    QString qsFileName = "61550R4.txt";
    qsFileName = "61550R4.txt";
    qsFileName = "points.txt";
    qsFileName = "squad.txt";
    QFile file(qsFileName);
    if (!file.exists()){
        message = "Can't find file %1 to read\n";
        message = message.arg(qsFileName);
        qDebug() << message;
        return -1;
    }

    if(!file.open(QFile::ReadOnly | QFile::Text))  {
        message = "Can't open the file %1 for reading\n";
        message = message.arg(qsFileName);
        qDebug() << message;
        return -1;
    }

    Point quadOne[4];

    char buf[1024];
    int readCount;
    QString qsBuf;
    QStringList qslPoint;
    float X,Y;
    int i=0;
    while (!file.atEnd()){
        readCount = file.readLine(buf, sizeof(buf));
        buf[readCount-1] = 0;
        qsBuf = buf;
        qslPoint = qsBuf.split(';');
        cout << buf << " readCount is " << readCount << endl;
        cout << " Y: " << qPrintable(qslPoint[1]) ;
        cout << " X: " << qPrintable(qslPoint[0])<< endl;
        X=qslPoint.at(0).toFloat();
        Y=qslPoint.at(1).toFloat();
        cout << " distance from Ziro: " << sqrt(X*X+Y*Y) << endl;
        quadOne[i].x=X;
        quadOne[i].y=Y;
        quadOne[i].Name = 'a'+i;
        i++;
    }
    qDebug() << printQuad(quadOne);

    return 0;
}

float distance(Point A, Point B){ return 4.0; }
float perimeter(Point Array[4]){ return 16.0; }
float area(Point Array[4]){ return 16.0; }



