#include <QCoreApplication>
#include <QDateTime>
#include <iostream>


static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int k=0;k<10;k++){
    qint64 mSec = QDateTime::currentMSecsSinceEpoch();
    uint seed = (uint) mSec;
    std::cout << "mil sec from epoch() " << mSec << " seed from it " << seed << std::endl;

    qsrand(seed);

    std::cout << "Random Qt 1 - ";
    for (int i = 0; i < 15; ++i)    {
        std::cout << randomBetween(10, 20) << " ";
    }
    std::cout << std::endl;

    std::cout << "Random Qt 2 - ";
    for (int i = 0; i < 15; ++i)    {
        std::cout << randomBetween(20, 30) << " ";
    }
    std::cout << std::endl << std::endl;
    }
    return a.exec();
}
