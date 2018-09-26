#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <QString>



#include "iostream"   // 19.09 Programmeerimine: kodutöö - Write console application to classify types of triangles, base on 3 length of triangle sizes.
#include "math.h"     // Application shall ask user to enter 3 side length. then if triangle is possible, print out class of triangle: ("Acute triangle\n");//остроугольный
#define PI 3.14159265 // ("Equilateral triangle\n");//равносторонний ("Isosceles triangle\n");//равнобедренный ("Obtuse triangle\n");//тупоугольный ("Rigth triangle\n");//прямоугольный
using namespace std;  // ("Scalene triangle\n");// разносторонний and then calculate the area of this triangle. use Heron's Formula for Triangular Area at
                      // http://www.math.ubc.ca/~cass/courses/m309-01a/goon/proof.html in case, if Triangular can't exist with this sides, notify user about it.
int main() {
    cout << "Enter three dimensions of a triangle: ";
    double a, b, c;
    cin >> a >> b >> c;
    cout << "Triangle's sides are: a = " << a << ", b = " << b << ", c = " << c << endl;
    double par =(b*b + c*c - a*a) / (2 * b * c);
    cout << " angA par is " << par << endl;
    double angA = acos((b*b + c*c - a*a) / (2 * b * c)) * 180.0 / PI;

    par =(a*a + c*c - b*b) / (2 * a * c);
    cout << " angB par is " << par << endl;
    double angB = acos((a*a + c*c - b*b) / (2 * a * c)) * 180.0 / PI;

    par =(b*b + a*a - c*c) / (2 * b * a);
    cout << " angC par is " << par << endl;
    double angC = acos((b*b + a*a - c*c) / (2 * b * a)) * 180.0 / PI;

    while ((a >= (b + c)) || (b >= (a + c)) || (c >= (a + b))) {
        cout << "This triangle is impossible in Euclidean space!" << endl << "Enter adequate values: ";
        cin >> a >> b >> c; cout << endl;
        cout << "Triangle's sides are: a = " << a << ", b = " << b << ", c = " << c << endl; cout << endl;
    }
    cout << "Angle A = " << angA << endl;
    cout << "Angle B = " << angB << endl;
    cout << "Angle C = " << angC << endl;
    if ((angA < 90) && (angB < 90)  && (angC < 90)) cout << "Your triangle is an acute triangle" << endl;
    if ((angA > 90) || (angB > 90)  || (angC > 90)) cout << "Your triangle is an obtuse triangle" << endl;
    if ((a == b) && (b == c) && (a == c)) cout << "Your triangle is equilateral" << endl;
    if ((a == b) || (a == c) || (b == c)) cout << "Your triangle is isosceles" << endl;
    if ((a == sqrt(b*b + c*c)) || (b == sqrt(a*a + c*c)) || (c == sqrt(a*a + b*b))) cout << "Your triangle is rectangular (Right triangle)" << endl;
    if ((a != b) && (b != c) && (a != c)) cout << "Your triangle is scalene" << endl; cout << endl;
    double semiperimeter = (a + b + c)/2;
    double area = sqrt(semiperimeter*(semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
    cout << "Area of the triangle is " << area << endl;
}



/*
int main(int argc, char *argv[])
{
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    QCoreApplication a(argc, argv);

    QString message = "Привет мир !";

#ifndef QT_NO_TEXTCODEC
    cout.setCodec("csIBM866");
#endif
    //записываем в консоль
    cout << message << endl;

    float A,B,C,hypot,sumKat,hypot2,P,S;

    A = 0.15 + 0.15;
    B = 0.1 + 0.2;

    if (A==B) {qDebug() << "A==B" << A << B;}
    if (A>B) {qDebug() << "A>B" << A << B;}


    QString string = "Привет мир !";
    QTextCodec *codec = QTextCodec::codecForName("CP866");
    QByteArray encodedString = codec->fromUnicode(string);
    qDebug() << encodedString.data();
    cout << string << endl;

    cout.setCodec("CP866");
    cout << string << endl;


    cout.setCodec("UTF8");
    cout << string << endl;

    cout.setCodec("CP1251");
    cout << string << endl;

   cout << string.toLocal8Bit().data();

    QList<QByteArray> codecList;

    codecList = codec->availableCodecs();
    cout << "codecList size is " << codecList.size() << endl;
    QString qsExample = "codec nr %1 have value ";
    QString qsTemp;
    QByteArray codecName;
    for (int i=0; i<codecList.size() ; i++ ){
        codecName = codecList[i];
        QString qsTemp = qsExample.arg(i) ;
        cout << qsTemp << codecName << endl;
    }



    if ( ((round((pow(A,2)+pow(B,2))*10))/10)==(round(pow(hypot,2)*10)/10)){
        qDebug() << "See on täisnurkne kolmnurk!";
        }

    codec->codecForName("KOI8-RU");
    encodedString = codec->fromUnicode(string);
    qDebug() << encodedString.data();

    codec->codecForName("UTF8");
    encodedString = codec->fromUnicode(string);
    qDebug() << encodedString.data();

    codec->codecForName("UTF16");
    encodedString = codec->fromUnicode(string);
    qDebug() << encodedString.data();

    return a.exec();
}
*/
