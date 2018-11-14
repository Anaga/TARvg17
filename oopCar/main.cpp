#include <QCoreApplication>
#include <QDebug>

// Class car

class Car
{
public:
    QString qsRegNumber;
    float engeneVolume;
public:
    Car() {}

    QString toPrint() {
        QString qsTemp = "Reg Number is %1; engine vol is %2";
        return qsTemp.arg(qsRegNumber).arg(engeneVolume);
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<< "Hello";

    Car my_car;
    my_car.engeneVolume = 1.2;
    my_car.qsRegNumber = "ABC234";

    qDebug() << "My car Reg Number is " << my_car.qsRegNumber << "engen vol is " << my_car.engeneVolume;

    Car my_new_car;
    my_new_car.engeneVolume = 2.2;
    my_new_car.qsRegNumber = "III111";

    qDebug() << "My new car Reg Number is " << my_new_car.qsRegNumber << "engen vol is " << my_new_car.engeneVolume;

    qDebug() << my_car.toPrint();
    qDebug() << my_new_car.toPrint();


    return a.exec();
}
