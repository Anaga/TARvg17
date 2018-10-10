#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

#include <iostream>
using namespace std;

int main()
{
    QString message;
    QString qsFileName = "Bills ListUTF8BOM.txt";

    QFile file(qsFileName);
    if (!file.exists()){
        message = "Can't find file %1 to read\n";
        message = message.arg(qsFileName);
        qDebug() << message;
        return -1;
    }

    if(!file.open(QFile::ReadOnly | QFile::Text))  {
        message = "Can't open the file %1 for reading\n";
        message = message.arg(qsFileName);
        qDebug() << message;
        return -1;
    }

    QTextStream in(&file);
    in.setAutoDetectUnicode(true);
    in.setCodec("UTF-8");

    system("chcp 65001");

    QString oneLine = in.readLine();
    QString qsTemp = "%1 : %2 \n";
    int i=0;
    while (oneLine!= nullptr) {
        i++;
        qsTemp=qsTemp.arg(i,3,10, QChar(' ')).arg(oneLine);
        cout << qUtf8Printable(qsTemp);
        oneLine = in.readLine();
        qsTemp = "%1 : %2 \n";
    }
    file.close();
    return 0;
}
