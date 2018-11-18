#ifndef GAMEUI_H
#define GAMEUI_H

#include "GameData.h"

#include <iostream>
#include <vector>
#include <fstream>
#include "time.h"

using namespace std;

class GameUI{
    public:
        GameUI();
        int main();
    private:
        vector<string> wordbank;

        void fillWordBank();
};

#endif //GAMEUI_H
