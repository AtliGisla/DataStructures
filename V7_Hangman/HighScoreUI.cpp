#include "HighScoreUI.h"

void HighScoreUI::main(){
    cout << "HIGH SCORES:" << endl << endl;

    ifstream fin;
    fin.open("HighScores.txt");
    if(fin.is_open()){
        fin.seekg(0, fin.end);
        int numberOfScores = fin.tellg() / sizeof(GameData);
        fin.seekg(0, fin.beg);
        //char character = '\0';
        //int integer = 0;
        //char littleArray[4];
        //int userscore = 0;
        GameData readGame;
        for(int i = 0; i < numberOfScores; i++){
            /*fin.read((char*)(&character), sizeof(char));
            littleArray[0] = character;
            fin.read((char*)(&character), sizeof(char));
            littleArray[1] = character;
            fin.read((char*)(&character), sizeof(char));
            littleArray[2] = character;
            fin.read((char*)(&character), sizeof(char));
                        
            fin.read((char*)(&integer), sizeof(int));
            userscore = integer;
            fin.read((char*)(&integer), sizeof(int));
            
            GameData readGame(littleArray, userscore, integer);*/

            fin.read((char*)(&readGame), sizeof(GameData));

            cout << readGame << endl;
        }
    }
    cout << endl;
}
