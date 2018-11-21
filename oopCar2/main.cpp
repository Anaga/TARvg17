#include <QCoreApplication>
#include <QDebug>
#include <QString>

#include "ncar.h"

QDebug operator<<(QDebug dbg, NCar &c){
    QDebugStateSaver saver(dbg);
    dbg.noquote() << c.toPrint();
    return dbg;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NCar car1;
    qDebug().noquote() << car1.toPrint();
    qDebug().nospace().noquote() << 12 << 34 << "abc"<<car1.toPrint();

    NCar car2(2.3, "ABC123");
    qDebug().noquote() << car2.toPrint();
    NCar new_car1;
    qDebug() << new_car1;
    new_car1.drive(20);
    qDebug() << new_car1;
    new_car1.fill(20);
    qDebug() << new_car1;
    new_car1.drive(20);
    qDebug() << new_car1;
    new_car1.qsRegNumber = "AAA111";
    qDebug() << new_car1;
    new_car1.drive(20);
    qDebug() << new_car1;

    NCar aa = new_car1;
    Plane myPlane;

    myPlane.fly("Riga");

    myPlane.fly("Helsenki");




    return a.exec();
}
