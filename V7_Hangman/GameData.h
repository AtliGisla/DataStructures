#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <iostream>

using namespace std;

class GameData{
    public:
        GameData(){
            initials[0] = '\0';
            word[0] = '\0';
            wrongGuesses = 0;
            totalGuesses = 0;
            difficulty = 1;
        };
        
        GameData(char* a, char* w, int b, int c, int d){
            for(int i = 0; i < 3; i++){
                initials[i] = a[i];
            }
            for(int i = 0; i < 47; i++){
                word[i] = w[i];
            }
            initials[3] = '\0';
            word[47] = '\0';
            wrongGuesses = b;
            totalGuesses = c;
            difficulty = d;

        };

        friend ostream& operator << (ostream& out, GameData& game){
            out << "Game Data" << endl;
            out << "Name: " << game.initials << endl;
            out << "Word: " << game.word << endl;
            out << "Difficulty: ";
            if(game.difficulty == 1) {
                out << "Easy" << endl;
            }else if(game.difficulty == 2){
                out << "Medium" << endl;
            }else if(game.difficulty == 3){
                out << "Hard" << endl;
            } else {
                out << "Unknown" << endl;
            }           
            out << "Total Guesses: " << game.totalGuesses << endl;
            out << "Wrong Guesses: " << game.wrongGuesses << endl;
            return out;
        };

        char initials[4];
        char word[48];
        int wrongGuesses;
        int totalGuesses;
        int difficulty;//1 easy, 2 medium, 3 hard
};

#endif //GAMEDATA_H
