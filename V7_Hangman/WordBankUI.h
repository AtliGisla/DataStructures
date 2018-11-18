#ifndef WORDBANKUI_H
#define WORDBANKUI_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class WordBankUI{
    public:
        void main();

    private:
        vector<string> wordbank;

        void fillWordBank();
        void wordBankToFile();
};

#endif
