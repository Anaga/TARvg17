#include <QCoreApplication>
#include <QDebug>

// Class car

class Car
{
    float engeneVolume= 1.0 ; // liters
    int   doorsCount  = 4;    // units
    float tankMax = 50.0;   // liters
    float gasVolume = 0.0;  // liters
    float odometer = 0.0;   // km
    float gasConsumption = static_cast<float>(14.6); // km per liter

public:
    QString qsRegNumber = "      ";

    Car() {
        qDebug() << "defaule cons() 18";
        setCons();
    }

    Car(float vol) {
        qDebug() << "Car(float vol) 23";
        engeneVolume = vol;
        setCons();
    }

    Car(QString reg) {
        qDebug() << "Car(QString reg) 29";
        qsRegNumber = reg;
        setCons();
    }

    Car(float vol, QString reg) {
        qDebug() << "Car(float vol, QString reg) 35";
        engeneVolume = vol;
        qsRegNumber = reg;
    }
    // End of constructions


    void setDoorsCount(int newCount) {
        if ((newCount >1) && (newCount < 10)) {
            doorsCount = newCount;
        }
    }

    void setCons(){
        if (engeneVolume > static_cast<float>(0.0)) {
            gasConsumption = engeneVolume*static_cast<float>(14.6);
            qDebug() << "gasConsumption now = " <<gasConsumption ;
        }
    }


    QString toPrint() {
        QString qsTemp = "Reg Number is %1; engine vol is %2; doors count %3\n"
                         "Gas current vol: %4, max vol: %5";
        return qsTemp.arg(qsRegNumber).arg( static_cast<double>(engeneVolume), 2 , 'f', 3).arg(doorsCount)
                .arg( static_cast<double>(gasVolume)).arg( static_cast<double>(tankMax));
    }
    QString shortPrint() {
        QString qsTemp = "Reg Number is %1; gas volume %2; odomentr %3";
        return qsTemp.arg(qsRegNumber).arg(static_cast<double>(gasVolume)).arg(static_cast<double>(odometer), 2 , 'f', 3);
    }

    float fill( float volume){
        gasVolume = volume;
        return volume;
    }

    float drive ( float km) {
        float litersSpend = km/gasConsumption;
        qDebug() << "litersSpend = " <<litersSpend ;
        if (gasVolume >= litersSpend) {
            gasVolume-= litersSpend;
            odometer+=km;
            return km;
        }
        return 0;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<< "Hello";

    Car my_car(static_cast<float>(1.2));
    //my_car.engeneVolume = 1.2;
    my_car.qsRegNumber = "ABC234";

    //qDebug() << "My car Reg Number is " << my_car.qsRegNumber << "engen vol is " << my_car.engeneVolume;

    Car my_new_car(static_cast<float>(2.2));
    //my_new_car.engeneVolume = 2.2;
    my_new_car.qsRegNumber = "III111";

    //qDebug() << "My new car Reg Number is " << my_new_car.qsRegNumber << "engen vol is " << my_new_car.engeneVolume;

    qDebug().noquote() << my_car.toPrint();
    qDebug().noquote() << my_new_car.toPrint();

    Car car2(static_cast<float>(13.0/12.0));
    //car2.engeneVolume = 13.0/12;
    qDebug().noquote()  << car2.toPrint();

    Car car3("324REF");
    // car3.dorsCount = 12;
    car3.setDoorsCount(12);
    qDebug().noquote()  << car3.toPrint();

    car3.setDoorsCount(8);
    qDebug().noquote()  << car3.toPrint();

    Car car4(12,"AZX322");
    qDebug().noquote()  << car4.toPrint();
    qDebug() << car4.shortPrint();

    qDebug() << car4.fill(150);
    qDebug() << car4.shortPrint();

    qDebug() << car4.drive(1);
    qDebug() << car4.shortPrint();

    qDebug() << car4.drive(10);
    qDebug() << car4.shortPrint();

    qDebug() << car4.drive(static_cast<float>(14.6));
    qDebug() << car4.shortPrint();
    qDebug() << car4.drive(40);
    qDebug() << car4.shortPrint();

    for (int i=0; i<10; i++){
        qDebug() << car4.drive(250);
        qDebug() << car4.shortPrint();
    }

    return a.exec();
}
