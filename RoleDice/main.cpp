#include <QCoreApplication>
#include <QDateTime>
#include <iostream>

enum DicesSet {
    WrongD,
    D4,
    D6,
    D8
};


static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

int rollDice(DicesSet d)
{
    int max = 1;

    switch (d) {
        case D4 : max = 4; break;
        case D6 : max = 6; break;
        case D8 : max = 8; break;
    default: max = 1; break;
    }
    int value = randomBetween(1,max);
    std::cout << "rollDice D"<<max<<" value "<< value <<"\n";
    return value;
}

int rollNTimes(int n, DicesSet d)
{
    int summ = 0;
    for(int i=0; i<n; i++){
        summ+=rollDice(d);
    }
    return summ;
}

void initRand()
{
    qint64 mSec = QDateTime::currentMSecsSinceEpoch();
    //uint seed = (uint) mSec;
    uint seed = 0x09262018;
    std::cout << "mil sec from epoch() " << mSec << " seed from it " << seed << std::endl;
    qsrand(seed);
}

int userInput()
{
    std::cout << "What dice shall roll?\n";
    std::cout << "We now support D4, D6, D8\n";
    std::cout << "Enter 0 to exit\n";
    int dice = 0;
    std::cin >> dice;

    DicesSet MyDice;
    switch (dice) {
        case 4 : MyDice = D4; break;
        case 6 : MyDice = D6; break;
        case 8 : MyDice = D8; break;
    default: MyDice = WrongD; break;
    }

    if (MyDice==WrongD) {
        std::cout << "Not support dice, exit\n";
        return 0;
    }

    int times;
    std::cout << "How many timese we shall roll D"<<dice<<" dice? \n";
    std::cin >> times;

    int summa = 0;
    summa = rollNTimes(times, MyDice);
    std::cout << "Summa is " << summa << " \n";
    return  summa;
}

int main()
{
    initRand();
    int summa = 0;
    do {
      summa = userInput();
    } while (summa!=0);

    return 0;
}
