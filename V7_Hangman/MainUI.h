#ifndef MAINUI_H
#define MAINUI_H

#include <string>
#include <iostream>

#include "GameUI.h"
#include "HighScoreUI.h"
#include "WordBankUI.h"
#include "GameData.h"
using namespace std;

class MainUI{
    public:
        MainUI();
        void main();
    private:
        GameUI gameui;
        HighScoreUI highscoreui;
        WordBankUI wordbankui;

        int userScore;
        int computerScore;

        bool resolveGame(int code);
};

#endif
