#include <QCoreApplication>
#include <stdio.h>
#include <iostream>
void revertBytesInString(char *incmmingString, int start, int stop);
void swapChar(char *str, int a, int b);
void revertString(char *inpStr, int len);

// https://www.interviewzen.com/interview/4z3KcbW

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char myRow[] = "This is test row!";
    int len = sizeof(myRow)/sizeof(char);

    std::cout << myRow << "\n";
    revertString(myRow, len);

    char nextRow[] = "   This is test, row!   ";
    len = sizeof(nextRow)/sizeof(char);

    std::cout << nextRow << "\n";
    revertString(nextRow, len);

    char nextRow2[] = "   !This!    is     test, row!   ";
    len = sizeof(nextRow2)/sizeof(char);

    std::cout << nextRow2 << "\n";
    revertString(nextRow2, len);


    char simplchar[] = "a";
    len = sizeof(simplchar)/sizeof(char);

    std::cout << simplchar << "\n";
    revertString(simplchar, len);

    return a.exec();
}

void swapChar(char *str, int a, int b){
    std::cout << "  swap ";
    char ch = str[a];
    str[a] = str[b];
    str[b] = ch;
    std::cout << ch;
}


void revertString(char *inpStr, int len){
    /*
    std::cout << inpStr << "  len is "<< len << std::endl;
    revertBytesInString(inpStr,0,3);
    std::cout << inpStr<< std::endl;
*/
    bool startWord = true;
    int wordBegin = 0;

    bool stopWord = false;
    int wordEnd = -1;
    int i=0;

    char ch;
    for (i=0;i<len;i++) {
        ch = inpStr[i];
        if (startWord) {
            if (isblank(ch) || ispunct(ch)){
                std::cout << "New word found - ";
                wordEnd=i-1;
                std::cout << "stat is " << wordBegin << " end is "<< wordEnd << std::endl;
                startWord=false;
                stopWord=true;
                //std::cout << inpStr<< std::endl;
                revertBytesInString(inpStr,wordBegin,wordEnd);
                std::cout << inpStr<< std::endl;
            }
        }

        if (stopWord){
            if (isalpha(ch)){
                wordBegin=i;
                startWord=true;
                stopWord=false;
            }
        }
    }
    //End of input line, reverse last word

    if (startWord) {
        std::cout << "Last word found - ";
        wordEnd=i;
        std::cout << "stat is " << wordBegin << " end is "<< wordEnd << std::endl;
        startWord=false;
        stopWord=true;
        //std::cout << inpStr<< std::endl;
        revertBytesInString(inpStr,wordBegin,wordEnd);
        std::cout << inpStr<< std::endl;
    }
}

void revertBytesInString(char *incmmingString, int start, int stop){
    std::cout << "revertBytesInString " << start << " "<< stop << std::endl;
    int worlLen = stop-start+1;
    for (int i = 0; i < worlLen/2; i++) {
        swapChar(incmmingString, start+i, stop-i);
    }
    std::cout <<std::endl;
}

