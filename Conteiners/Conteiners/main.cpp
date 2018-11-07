#include <QCoreApplication>
#include <QList>
#include <QDebug>


// http://doc.crossplatform.ru/qt/4.3.2/containers.html

// function to print all qString  elements in one line from List
QString toPrint(QList<QString> listToPrint)
{
    QString qsResult;
    qDebug() << "Print qString" ;
    QString str;
    foreach (str, listToPrint){ //go ower all elements
        qsResult.append(str);   // and save it it str
        qsResult.append(' ');
    }
    return qsResult;
}
// function to print all qString elements in one line from List
QString toPrint(QList<int> listToPrint)
{
    QString qsTemp;
    QString qsResult;
    qDebug() << "Print int" ;
    QList<int>::const_iterator i;
    for ( i = listToPrint.begin(); i != listToPrint.end(); i++){
        qsTemp.setNum(*i,10);
        qsResult.append(qsTemp);
        qsResult.append(' ');
    }
    return qsResult;
}





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Hello";
    QList<int> MyList;
    MyList << 1 << 2 << 3 << 4;
    qDebug() <<  toPrint(MyList);
    qDebug() << "MyList at 2 is" << MyList.at(2); //fast
    qDebug() << "MyList at 2 is" << MyList[2]; //slow
    MyList[2] = 77;

    qDebug() << "MyList at 2 is" << MyList.at(2); //fast

    MyList.append(21);
    qDebug() << "MyList size is " << MyList.size();
    MyList.insert(2,62);

    qDebug() << "MyList size is " << MyList.size();
    // Task: print out all MyList elemens using 'at' function


    qDebug() << toPrint(MyList);

    QList<QString> MySList;
    MySList.append("ABC");
    MySList.append("DEF");
    MySList.append("some test string");
    MySList << "ehh";
    MySList.append("32") ;
    //MySList.append(QString::setNum(42)) ;
    qDebug() << toPrint(MySList);





    return a.exec();
}
