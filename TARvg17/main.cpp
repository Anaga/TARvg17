#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <QString>

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
