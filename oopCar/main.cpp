#include <QCoreApplication>
#include <QDebug>

// Class car

class Car
{
    float engeneVolume= 1.0 ;
    int   doorsCount  = 4;
    float tankMax = 50.0;
    float gasVolume = 0.0;
    float odometer = 0.0;

public:
    QString qsRegNumber = "      ";

    Car() {}
    Car(float vol) {engeneVolume = vol;}
    Car(QString reg) {qsRegNumber = reg;}

    Car(float vol, QString reg) {
        engeneVolume = vol;
        qsRegNumber = reg;
    }
    void setDoorsCount(int newCount) {
        if ((newCount >1) && (newCount < 10)) {
            doorsCount = newCount;
        }

    }

    QString toPrint() {
        QString qsTemp = "Reg Number is %1; engine vol is %2; doors count %3";
        return qsTemp.arg(qsRegNumber).arg( (double)engeneVolume, 2 , 'f', 3).arg(doorsCount);
    }
    QString shortPrint() {
        QString qsTemp = "Reg Number is %1; gas volume %2; odomentr %3";
        return qsTemp.arg(qsRegNumber).arg( (double)gasVolume).arg((double) odometer, 2 , 'f', 3);
    }

    float fill( float volume){
        gasVolume = volume;
        return volume;
    }


};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<< "Hello";

    Car my_car(1.2);
    //my_car.engeneVolume = 1.2;
    my_car.qsRegNumber = "ABC234";

    //qDebug() << "My car Reg Number is " << my_car.qsRegNumber << "engen vol is " << my_car.engeneVolume;

    Car my_new_car(2.2);
    //my_new_car.engeneVolume = 2.2;
    my_new_car.qsRegNumber = "III111";

    //qDebug() << "My new car Reg Number is " << my_new_car.qsRegNumber << "engen vol is " << my_new_car.engeneVolume;

    qDebug() << my_car.toPrint();
    qDebug() << my_new_car.toPrint();

    Car car2(13.0/12);
    //car2.engeneVolume = 13.0/12;
    qDebug() << car2.toPrint();

    Car car3("324REF");
   // car3.dorsCount = 12;
    car3.setDoorsCount(12);
    qDebug() << car3.toPrint();

    car3.setDoorsCount(8);
    qDebug() << car3.toPrint();

    Car car4(12,"AZX322");
    qDebug() << car4.toPrint();
    qDebug() << car4.shortPrint();

    qDebug() << car4.fill(150);
    qDebug() << car4.shortPrint();





    return a.exec();
}
