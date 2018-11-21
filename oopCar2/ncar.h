#ifndef NCAR_H
#define NCAR_H

#include <QDebug>
#include <QString>

class NCar
{
    //class varaibles
    double engineVolume; // liters
    int   doorsCount  = 4;    // units
    double tankMax = 50.0;   // liters
    double gasVolume = 0.0;  // liters
    double odometer = 0.0;   // km
    double gasConsumption = 14.6; // km per liter
public:
    QString qsRegNumber;

    //class fuctions
public:
    NCar(double engVol=1.3, QString regNum="------");
    double fill(double liters);
    double drive(double kmToRide);
    QString toPrint();
};

#endif // NCAR_H
