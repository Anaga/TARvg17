#include <QCoreApplication>
#include <QDebug> // to print out


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //create a new array of 10 numbers
    int intArr[10] = {2,3,4,5,6,7,8,9,10,11};

    //print out element on position 3
    qDebug() << "Array intArr on position 3 have value " << intArr[3];

    //and print out all array:
    for (int i = 0; i<10; i++){
        qDebug() << "Array intArr on position "<< i <<" have value " << intArr[i];
    }

    // we can repalase any element in array
    intArr[3] = -50;

    //print out element on position 3
    qDebug() << "Array intArr on position 3 have value " << intArr[3];

    //or eaven modify it in plase:
    // we will add 10 to last 4 elements
    for (int i = 6; i<10; i++){
        intArr[i]+=10;
    }
    qDebug() << "print out all array ";
    //and print out all array:
    for (int i = 0; i<10; i++){
        qDebug() << "Array intArr on position "<< i <<" have value " << intArr[i];
    }

    qDebug() << "print out all array in backward direction:";
    //and print out all array in backward direction:
    for (int i = 9; i>0; i--){
        qDebug() << "Array intArr on position "<< i <<" have value " << intArr[i];
    }


    return a.exec();
}
