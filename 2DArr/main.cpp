#include <QCoreApplication>
#include <QDebug>
#include <iostream>
using namespace std;

void printOneDemArr(int A[], int A_Len);
int main()
{
#define A_SIZE 25
#define B_SIZE 15
    int OneDArray[A_SIZE];
    for (int i=0;i<A_SIZE;i++){
        OneDArray[i] = (i+1)*3;
    }
    printOneDemArr(OneDArray, A_SIZE);

    int OneDArrayB[B_SIZE];
    for (int i=0;i<B_SIZE;i++){
        OneDArrayB[i] = (i-127)*20;
    }
    printOneDemArr(OneDArrayB, B_SIZE);
    return 0;
}

void printOneDemArr(int A[], int A_Len)
{
    for (int i=0;i<A_Len-1;i++){
        cout << A[i] << ", ";
    }
    cout << A[A_Len-1] << " ; ";
    //cout << "\b\b" << ";" ;
    cout << endl;
}
