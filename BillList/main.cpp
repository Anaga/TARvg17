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
    QString qsFileName = "61550R4.txt";
    qsFileName = "61550R4.txt";
    qsFileName = "61548R2.txt";

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

    QTextStream inputConsole(&file);
    inputConsole.setAutoDetectUnicode(true);
    inputConsole.setCodec("UTF-8");

    system("chcp 65001");

    item AllItems[20];

    QString oneLine = inputConsole.readLine();
    QString qsTemp = "A:%1 P:%2 W:%3 SUMMA%4 \n";
    int i=0;
    int N=0;
    float amount, price, weight, summa, total=0;
    QString qsDesc;
    while (!inputConsole.atEnd()) {
        i++;
        if (i<2) {
            cout << qUtf8Printable(oneLine) << endl;
            oneLine = inputConsole.readLine();
        } else {
        inputConsole >> amount;
        inputConsole >> price;
        inputConsole >> weight;
        qsDesc = inputConsole.readLine();
        summa = price*amount;
        total = total + summa;

        qsTemp = "A:%1 P:%2 W:%3 SUMMA:%4 D:%5 \n";
        qsTemp=qsTemp.arg(amount).arg(price).arg(weight).arg(summa).arg(qsDesc);
        //cout <<"A: " <<amount  << "  P: "<< price << weight << qUtf8Printable(qsDesc);
        cout << qUtf8Printable(qsTemp);
        }


        /*if (i>3) break;
        if (oneLine.contains('.')) {
            AllItems[N]= ParseOneRow(oneLine);
            N++;
        }
        qsTemp = "%1 : %2 \n";*/
    }
    file.close();
    cout <<"Total summa is : " <<total << endl;

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
