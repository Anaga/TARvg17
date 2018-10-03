#include <QCoreApplication>
#include <QDebug>
#include <iostream>
using namespace std;

enum Color{ Red, Green, Blue };

struct Points{
    int x;
    int y;
    Color col;
};

void printPoint(Points a);
int main(int argc, char *argv[])
{
    Points p1;
    Points p2;

    p1.x = 10;
    p1.y = 0;
    p1.col = Red;

    p2.x = 3;
    p2.y = 8;
    p2.col = Green;

    printPoint(p1);
    printPoint(p2);

    QCoreApplication a(argc, argv);

    return a.exec();
}
void printPoint(Points a){
    cout << "Point ["<< a.x << ";"<< a.y<< "] " ;
    Color c = a.col;
    switch (c) {
    case Red: cout << "Red"; break;
    case Green: cout << "Green"; break;
    case Blue: cout << "Blue"; break;
    default:cout << "Error"; break;
    }
    cout << endl;
}
