#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <string>


QString getMounth (uint number){
    if (number==0) return "Error";
    if (number>12) return "Error";
    const QString mList[13] = {"Nulvar",
                               "Jan", "Veb", "Mart",
                               "Apr", "Mai", "Jun",
                               "Jul", "Ags", "Sen",
                               "Oct", "Nov", "Dec",
                              };
    return mList[number];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString idCode = "38112025710";

    QString masha = "Masha";
    QString petja = "Petja";
    QString lyda = "Lydmila";
    QString qsTemp;

    qsTemp = "In name %1 %2 letters";
    qDebug() << qsTemp;
    qsTemp = qsTemp.arg(masha).arg(masha.size());
    qDebug() << qsTemp;

    qsTemp = "In name %1 %2 letters";
    qsTemp = qsTemp.arg(lyda).arg(lyda.size());
    qDebug() << qsTemp;

    QString leftPetja = petja.left(3);
    qsTemp = "In name %1 %2 letters";
    qsTemp = qsTemp.arg(leftPetja).arg(leftPetja.size());
    qDebug() << qsTemp;

    QString rigthLyda  = lyda.right(4);
    qsTemp = "In name %1 %2 letters";
    qDebug() << qsTemp.arg(rigthLyda).arg(rigthLyda.size());
    rigthLyda  = lyda.right(9);
    qDebug() << qsTemp.arg(rigthLyda).arg(rigthLyda.size());
    /*
    qDebug() <<  rigthLyda[3];
    std::string inp;
    std::cin >> inp;
    rigthLyda = inp.c_str();
    qDebug() << qsTemp.arg(rigthLyda).arg(rigthLyda.size());
    qDebug() << inp.c_str();

    */
    for (int i = idCode.size()-1; i>=0; i--){
        qDebug() <<  idCode[i];
    }

    qDebug() << "Some text";

    qDebug() << "Some text"+idCode;
    qDebug() << qPrintable(idCode.toLocal8Bit());

    qDebug() << getMounth(02);


    QString mFromIdCode = idCode.mid(3,2);
    qDebug() << mFromIdCode;
    bool bOk = false;

    int m;
    m = mFromIdCode.toInt(&bOk);
    if (bOk) {
        qDebug() << getMounth(m);
    }

    idCode = "38112025710";
    mFromIdCode = idCode.mid(3,2);
    qDebug() << mFromIdCode;
    bOk = false;
    m = mFromIdCode.toInt(&bOk);
    if (bOk) {
        qDebug() << "M is " << m;
        qDebug() << getMounth(m);
    }



    return a.exec();
}










