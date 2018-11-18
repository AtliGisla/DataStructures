#include "GameUI.h"

GameUI::GameUI(){

}

//0: quit
//1: user won, back to main menu
//2: user won, repeat game
//3: computer won, back to main menu
//4: computer won, repeat game

int GameUI::main(){
    //read in wordbank
    fillWordBank();
    
    //start new game
    
        //check if wordbank is empty
    if(wordbank.size() == 0){
        cout << "NO WORDS FOUND" << endl;
        return 0;
    }
    //choose random word and put to dashes
    srand(time(NULL));
    int randomNumber = rand() % wordbank.size();
    string answer = wordbank[randomNumber];
    string hiddenWord = "";
    for(int i = 0; i < answer.length(); i++){
        hiddenWord += "-";
    }

    //initialize guesses
    int guesses = 0;
    bool validInput = 0;
    string userInput = "";
    char select = '\0';
    int difficulty = 0;
    do{
        cout << "Pick Difficulty:" << endl;
        cout << "-(E)asy" << endl;
        cout << "-(M)edium" << endl;
        cout << "-(H)ard" << endl;
        cout << "input: ";
        cin >> userInput;
        select = tolower(userInput[0]);
        switch(select) {
            case 'e':
                guesses = 15;
                difficulty = 1;
                validInput = 1;
                break;
            case 'm':
                guesses = 10;
                difficulty = 2;
                validInput = 1;
                break;
            case 'h':
                guesses = 5;
                difficulty = 3;
                validInput = 1;
                break;
            default:
                cout << "Input not recognized. Try Again" << endl;
                validInput = 0;
                break;
        }
    }while(!validInput);

    cout << "START GAME" << endl << endl;
    int turns = 1;
    bool gameOver = 0;
    char userChar = '\0';
    int inputDescription = 0; //0 if empty, 1 if char, 2 if string
    bool guessInWord = 0;
    bool userWon = 0;
//**
    while(!gameOver){
        //print turn number, guesses left, and current status on word
        cout << "TURN " << turns << endl << endl;
        turns++;
        cout << "NUMBER OF WRONG GUESSES LEFT: " << guesses << endl << endl;
        cout << "Current Word: " << hiddenWord << endl << endl;

        //guess letter or word
        cout << "Guess one character or a whole word" << endl;
        cout << "input: ";
        cin >> userInput;

        if(userInput[0] == '\0'){
            inputDescription = 0;
        } else if(userInput[1] == '\0'){
            userChar = userInput[0];
            inputDescription = 1;
        } else {
            inputDescription = 2;
        }

        //check if letter or word in string
        guessInWord = 0;
        if(inputDescription == 1){//test char
            for(int i = 0; i < answer.length(); i++){
                if(tolower(userChar) == tolower(answer[i])){
                    hiddenWord[i] = answer[i];
                    guessInWord = 1;
                }
            }

            if(guessInWord){
                cout << userChar << " is in the Word" << endl << endl;
            } else{
                cout << userChar << " is not in the Word" << endl << endl;
                guesses--;
            }

        } else if(inputDescription == 2){//test whole word
            for(int i = 0; i < userInput.length(); i++){
                if(userInput[i] >= 'A' && userInput[i] <= 'Z'){
                    userInput[i] = userInput[i] + 32;
                }
            }
            for(int i = 0; i < answer.length(); i++){
                if(answer[i] >= 'A' && answer[i] <= 'Z'){
                    answer[i] = answer[i] + 32;
                }
            }
            if(userInput.compare(answer) == 0){
                //correct guess
                hiddenWord = answer;
            }
            else{
                //incorrect guess
                cout << userInput << " is not the word. sorry" << endl;
                guesses--;
            }
        }

        //check win or loss (word is complete or guesses are 0)
        if(guesses == 0){
            //user lost
            userWon = 0;
            gameOver = 1;
        }
        //checkWin
        bool containsDashes = 0;
        for(int i = 0; i < hiddenWord.length(); i++){
            if(hiddenWord[i] == '-'){
                containsDashes = 1;
            }
        }
        if(!containsDashes){
            userWon = 1;
            gameOver = 1;
        }
    }//close the while loop
//** loop to **
    
    //print result
    cout << endl << "Game is Over" << endl;
    if(userWon){
        cout << "User Won! :)" << endl;
        cout << "The word was: " << answer << endl;
    } else{
        cout << "Computer Won! :(" << endl;
        cout << "The word was: " << answer << endl;
    }

    //ask user to save highscore
    bool saveHighScore = 0;
    do{
        cout << "Save current score? (y/n)" << endl;
        cout << "input: ";
        cin >> userInput;
        select = tolower(userInput[0]);
        switch(select){
            case 'y':
                saveHighScore = 1;
                validInput = 1;
                break;
            case 'n':
                saveHighScore = 0;
                validInput = 1;
                break;
            default:
                cout << "Input Not Recognized. Try Again." << endl;
                validInput = 0;
                break;
        }
    }while(!validInput);

    //write in highscore
    if(saveHighScore){
        cout << "Saving High Score..." << endl << endl;
        cout << "Write your 3 Initials (example: AAA, GKR, XYZ, etc.)" << endl;
        cout << "input: ";
        cin >> userInput;
        char initials[3];
        for(int i = 0; i < 3; i++){
            initials[i] = userInput[i];
        }
        int wrongGuesses = (20 - (5 * difficulty)) - guesses;
        int totalGuesses = turns;
        GameData currentGame(initials, &answer[0], wrongGuesses, totalGuesses, difficulty);
        ofstream fout;
        fout.open("HighScores.txt", ios::app);
        fout.write((char*) &currentGame, sizeof(currentGame));
        fout.close();
    }


    //ask to play again
    bool playAgain = 0;
    do{
        cout << "Do you want to play again?(y/n)" << endl;
        cout << "input: ";
        cin >> userInput;
        select = tolower(userInput[0]);
        switch(select){
            case 'y':
                playAgain = 1;
                validInput = 1;
                break;
            case 'n':
                playAgain = 0;
                validInput = 1;
                break;
            default:
                cout << "Input not Recognized. Try Again" << endl;
                validInput = 0;
                break;
        }
    } while(!validInput);

    //return the code (see codes at top of file)
    if(userWon && !playAgain){
        return 1;
    }
    if(userWon && playAgain){
        return 2;
    }
    if(!userWon && !playAgain){
        return 3;
    }
    if(!userWon && playAgain){
        return 4;
    }
}

void GameUI::fillWordBank(){
    wordbank.clear();
    ifstream fin;
    fin.open("WordBank.txt");
    string word;
    fin >> word;
    while(!fin.eof()){
        wordbank.push_back(word);
        fin >> word;
    }
    fin.close();
}
