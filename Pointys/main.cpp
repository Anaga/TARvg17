#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
using namespace std;

enum Color{ Red, Green, Blue };

struct Points{
    int x;
    int y;
    Color col;
};

// function header to print out one point to cout
QString printPoint(Points a); // and also to QString

int main()
{
    Points p1; // define 2 ponts
    Points p2;

    // give some value to P1
    p1.x = 10;
    p1.y = 0;
    p1.col = Red;

    // and to P2
    p2.x = 3;
    p2.y = 8;
    p2.col = Green;

    Points PArr[4];

    PArr[0].x=0;
    PArr[0].y=0;

    PArr[1].x=5;
    PArr[1].y=0;

    PArr[2].x=5;
    PArr[2].y=5;

    PArr[3].x=0;
    PArr[3].y=5;

    // Total

    QFile qf("PointList.txt");
    if (qf.open(QFile::WriteOnly | QFile::Truncate)) {
          QTextStream out(&qf);
          out << "Hello \n" ;

          for (int i=0; i<4; i++) {
              out << printPoint(PArr[i]);
              out << endl;
          }
      }


    printPoint(p1);
    printPoint(p2);

    return 0;
}
QString printPoint(Points a){
    QString qsTemp = "Point [%1;%2] \n";
    cout << "Point ["<< a.x << ";"<< a.y<< "] " ;
    qsTemp = qsTemp.arg(a.x).arg(a.y);
    Color c = a.col;
    switch (c) {
    case Red: cout << "Red"; break;
    case Green: cout << "Green"; break;
    case Blue: cout << "Blue"; break;
    default:cout << "Error"; break;
    }
    cout << endl;
    return qsTemp;
}
