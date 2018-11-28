#include <QCoreApplication>
#include <QDebug>

#include "rodent.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Heeelo all Rodent";


    Rodent hamster("Ham");

    qDebug()<< hamster.getName();

    {
        Rodent mouse("Mous");
        qDebug()<< mouse.getName();
    }
    Rodent rat("Rat");

    Rodent *pRodent;

    pRodent = new Rodent("LabRat");
    pRodent = new Rodent("LabRat2");
    for (int i=0; i<3; i++){
        QString qsTemp = "Rat %1";
        Rodent labRat(qsTemp.arg(i));
        qDebug() << "Creare new Rodent, number " << i;
    }
    //qDebug() << qsTemp;
    qDebug() << "Who will die?";
    delete pRodent;



    return a.exec();
}
