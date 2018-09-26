#include <QCoreApplication>
#include <QDateTime>
#include <iostream>

#define N_MAX 10

enum DicesSet {  // new data type - DicesSet
    WrongD,
    D4,
    D6,
    D8,
    D10,
    D12,
    D20,
    D100
};

DicesSet intToDice(int val)
{
    switch (val) {
        case 4: return D4;
        case 6: return D6;
        case 8: return D8;
    default: return WrongD;
    }
    return WrongD;
}

int diceToInt(DicesSet ds)
{
    switch (ds) {
        case D4: return 4;
        case D6: return 6;
        case D8: return 8;
    default: return 0;
    }
    return 0;
}

static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

int rollDice(DicesSet d)
{
    int max = diceToInt(d);
    if (max==0){
        std::cout << "Can't roll D zerro dice, exit\n";
        return 0;
    }
    int value = randomBetween(1,max);
    std::cout << "roll dice D"<<max<<" value "<< value <<"\n";
    return value;
}

int rollNTimes(int n, DicesSet d)
{
    int summ = 0;
    int val = 0;
    for(int i=0; i<n; i++){
        val = rollDice(d);
        summ+= val;
    }
    float aver = summ/(static_cast<float>(n));
    std::cout << "Average value is "<<aver<<" \n";
    return summ;
}

int rollNTimesSaveToArr(int n, DicesSet d, int rollsArray[])
{
    int summ = 0;
    int val = 0;

    for(int i=0; i<n; i++){
        val = rollDice(d);
        summ+= val;
        rollsArray[i] = val;
    }
    float aver = summ/(static_cast<float>(n));
    std::cout << " Rolls array is : ";
    for (int i=0; i<n; i++){
        std::cout << rollsArray[i] << " ";
    }
    std::cout << " \n";

    std::cout << "Average value is "<<aver<<" \n";
    return summ;
}
void initRand()
{
    qint64 mSec = QDateTime::currentMSecsSinceEpoch();
    //uint seed = (uint) mSec;
    //uint seed = static_cast<uint>(mSec);
    uint seed = 0x09262018;
    std::cout << "mil sec from epoch() " << mSec << " seed from it " << seed << std::endl;
    qsrand(seed);
} int userInput();


int rand8_13();
int main()
{
    //initRand();
    int N =6;
    int summ = 0;
    int rollArray[6];

    for (int i=0; i<N; i++){
        int val = rand8_13();
        summ+=  val;
        rollArray[i] = val;
    }
    float aver = (float)summ /N;
    std::cout << "aver is "<< aver << " summ" << summ << "\n";

    for (int i=0; i<N; i++){
        std::cout << "  " << rollArray[i] ;
    }
    std::cout << "\n backward \n";
    for (int j=5; j>=0; j--){
        std::cout << " " << rollArray[j];
    }
    std::cout << "\n end \n";

    return 0;
}

int rand8_13(){ // functin shal return random number berween 8 and 13
    int val = qrand();
    int div = ((val % 5)) +8;
  std::cout << "divided value " <<div << "\n";
  return div;
}


int userInput()
{
    std::cout << "What dice shall roll?\n";
    std::cout << "We now support D4, D6, D8\n";
    std::cout << "Enter 0 to exit\n";
    int dice = 0;
    std::cin >> dice;

    DicesSet MyDice = intToDice(dice);

    if (MyDice==WrongD) {
        std::cout << "Not supported dice, exit\n";
        return 0;
    }

    int times;
    std::cout << "How many timese we shall roll D"<<dice<<" dice? \n";
    std::cin >> times;


    int summa = 0;
    summa = rollNTimes(times, MyDice);
    std::cout << "Summa is " << summa << " \n";

    int oneRollsArray[N_MAX];
    summa = rollNTimesSaveToArr(times, MyDice, oneRollsArray);
    std::cout << "Summa is " << summa << " \n";
    std::cout << " Rolls array is : ";
    for (int i=times; i>0; i--){
        std::cout << oneRollsArray[i-1] << " ";
    }

    std::cout << " \n";
    return  summa;
}














