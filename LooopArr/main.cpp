#include <QCoreApplication>
#include <QDebug>

#define N 10
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int Arr[N] = {0};

    for (int i=0; i<N; i++){
        Arr[i] = i*3;
    }

    for (int i=0; i<N; i++){
        qDebug() << "i is "<< i << "Arr is" <<Arr[i];
    }

    for (int var:Arr){
        qDebug() << "var is "<< var ;
    }

    for (int var:Arr){
        var = 10;
        qDebug() << "new var is "<< var ;
    }

    for (int i=0; i<N; i++){
        qDebug() << "i is "<< i << "Arr is" <<Arr[i];
    }

    int my_array[5] = {1, 2, 3, 4, 5};
    for (int &x : my_array) {
        x *= 2;
    }

    for (int var:my_array){
        qDebug() << "var is "<< var ;
    }

    qDebug() << "auto try "
                ;
    char m_a[5] = {'a','b','c','d','e'};
    for (auto var:m_a){

        qDebug() << "var is "<< var ;
    }
    return a.exec();
}
