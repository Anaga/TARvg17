
#include <QCoreApplication>
#include <QDebug> //F1 for help
#include <QTextStream>
#include <QString>


bool mainFunc(){

    QTextStream cin(stdin);

    qDebug() << "Please enter sex Ff/Mm";
    char sex;
    cin >> sex;
    switch (sex) {
    case 'M':
    case 'm':
        qDebug() << "Male";
        return true;
        break;
    case 'W':
    case 'w':
        qDebug() << "Female";
        return true;
        break;

    default:
        qDebug() << "Alien";
        break;
    }

    return false;

}


