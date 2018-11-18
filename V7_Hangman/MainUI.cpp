#include "MainUI.h"

MainUI::MainUI(){
    userScore = 0;
    computerScore = 0;
}

void MainUI::main(){
    bool playAgainDirectly = 0;
    bool validInput = 0;
    bool continueGame = 1;
    char select = '\0';
    string userInput = "";
    do{
        cout << "CURRENT SCORES: user: " << userScore << ", computer: " << computerScore << endl;
        cout << "*-------------------------------*" << endl;
        cout << "|          *Play Game*          |" << endl;
        cout << "|           Press (P)           |" << endl;
        cout << "*-------------------------------*" << endl;
        cout << "|   View High   |   View/Edit   |" << endl;
        cout << "|   Scores (H)  |  Word Bank(W) |" << endl;
        cout << "*-------------------------------*" << endl;
        cout << "|             QUIT              |" << endl;
        cout << "|           Press (Q)           |" << endl;
        cout << "*-------------------------------*" << endl;
        
        do{
            cout << "input: ";
            cin >> userInput;

            select = tolower(userInput[0]);
            switch(select){
                case 'p':
                        do{
                            int gameOutput = gameui.main();
                            playAgainDirectly = resolveGame(gameOutput);
                            //0: quit
                            //1: user won, back to main menu
                            //2: user won, repeat game
                            //3: computer won, back to main menu
                            //4: computer won, repeat game
                        } while(playAgainDirectly);
                        validInput = 1;
                    break;
                case 'h':
                        highscoreui.main();
                        validInput = 1;
                    break;
                case 'w':
                        wordbankui.main();
                        validInput = 1;
                    break;
                case 'q':
                    validInput = 1;
                    continueGame = 0;
                    break;
                default:
                    cout << "Input is not valid. Try again." << endl;
                    validInput = 0;
                    break;
            }
        }while(!validInput);
    }while(continueGame);
}

bool MainUI::resolveGame(int code){
    switch(code){
        case 1:
            userScore++;
            return 0;
        case 2:
            userScore++;
            return 1;
        case 3:
            computerScore++;
            return 0;
        case 4:
            computerScore++;
            return 1;
        default:
            return 0;
    }
}
