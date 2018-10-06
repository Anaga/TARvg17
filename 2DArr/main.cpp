#include <QCoreApplication>
#include <QDebug>
#include <iostream>
using namespace std;

void printOneDemArr(int A[], int A_Len);
void printTwoDemArr(int **A, int A_C, int A_R){
    cout << __func__ << endl;
     for (int i = 0; i < A_R; ++i)  {
         cout << i << ": ";
         for (int j = 0; j < A_C; ++j)
             cout << A[i][j] << '\t';
         cout << endl;
     }
}

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


    int TwoDArrayA[2][3] = { {1,2,3},
                             {6,7,8} };

    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << TwoDArrayA[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "---------------------" <<endl;

              //rows (25)  col (15)
    int TwoDArrayB[A_SIZE][B_SIZE] = {0};
    //print out array context
    for (int i=0; i<A_SIZE; i++){
        for (int j=0; j<B_SIZE; j++){
            cout << TwoDArrayB[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "---------------------" <<endl;

    // modify TwoDArrayB and set up "1" on main diagonal
    for (int i=0; i<B_SIZE; i++){
        TwoDArrayB[i][i] = 1;
    }

    //print out array context
    for (int i=0; i<A_SIZE; i++){ // Rows
        for (int j=0; j<B_SIZE; j++){ // Colums
            cout << TwoDArrayB[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "---------------------" <<endl;

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


