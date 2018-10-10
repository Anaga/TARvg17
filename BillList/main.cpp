#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

#include <iostream>
using namespace std;

struct item{
    float Amount;
    float Price;
    float Weight;
    QString Description;
    float Summa;
};

item ParseOneRow(QString row);

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

    item AllItems[20];

    QString oneLine = in.readLine();
    QString qsTemp = "%1 : %2 \n";
    int i=0;
    int N=0;
    while (oneLine!= nullptr) {
        i++;
        qsTemp=qsTemp.arg(i,3,10, QChar(' ')).arg(oneLine);
        cout << qUtf8Printable(qsTemp);

        if (oneLine.contains('.')) {
            AllItems[N]= ParseOneRow(oneLine);
            N++;
        }
        oneLine = in.readLine();
        qsTemp = "%1 : %2 \n";
    }
    file.close();

    item CI; // Current item
    for (i=0; i<N; i++){
        CI = AllItems[i];

        cout << "\tA: "<<CI.Amount ;
        cout << "\tP: "<<CI.Price;
        cout << "\tW: "<<CI.Weight;
        cout << "\tSUMMA: "<<CI.Price*CI.Amount;
        cout << "\tDescr: "<<qUtf8Printable(CI.Description);
        cout << endl;
    }
    return 0;
}

item ParseOneRow(QString row){
    //cout << __func__ << endl;
    item one;
    QTextStream in(&row, QIODevice::ReadOnly);
    in >> one.Amount;
    in >> one.Price;
    in >> one.Weight;
    one.Description = in.readLine().trimmed();

    //cout << "One item description is " << qUtf8Printable(one.Description)<< " Summa is " << (one.Amount*one.Price) << endl;
    return one;
}
