#include "ncar.h"

NCar::NCar(double engVol, QString regNum)
{
    qDebug() << "NCar(double engVol, QString regNum) 5";
    engineVolume = engVol;
    qsRegNumber = regNum;
    gasConsumption = engineVolume*(14.6);
    qDebug() << "gasConsumption now = " <<gasConsumption ;
}

double NCar::fill(double liters)
{
    gasVolume = liters;
    return gasVolume;
}

double NCar::drive(double kmToRide)
{
    double litersSpend = kmToRide/gasConsumption;
    qDebug() << "litersSpend = " <<litersSpend ;
    if (gasVolume >= litersSpend) {
        gasVolume-= litersSpend;
        odometer+=kmToRide;
        return kmToRide;
    }
    return 0;
}

QString NCar::toPrint()
{
    QString qsTemp = "{%1}: engine: %2 l; consumption:%3 km per liter; max vol: %4\n"
                     "Gas current vol: %5 l; odometr: %6 km";
     qsTemp = qsTemp.arg(qsRegNumber).arg(engineVolume).arg(gasConsumption).arg(tankMax)
             .arg(gasVolume).arg(odometer);
    return qsTemp;

}

Plane::Plane()
{
    qDebug() << "Plane :42";
    location = "Tallinn";
}

void Plane::fly(QString destination)
{
    QString qsTemp = "Fly from %1 to %2";
    qsTemp = qsTemp.arg(location).arg(destination);
    qDebug().noquote() << qsTemp;
    location = destination;
}


