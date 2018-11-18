#include "WordBankUI.h"

void WordBankUI::main(){
    fillWordBank();

    cout << "Word List:" << endl;
    for(int i = 0; i < wordbank.size(); i++){
        cout << wordbank[i] << endl;
    }

    bool validInput = 0;
    bool newWord = 0;
    string userInput = "";
    char select = '\0';
    cout << "Do you want to add a new word? (y/n)" << endl;
    do{
        cout << "input: ";
        cin >> userInput;
        select = tolower(userInput[0]);
        switch(select){
            case 'y':
                newWord = 1;
                validInput = 1;
                break;
            case 'n':
                newWord = 0;
                validInput = 1;
                break;
            default:
                cout << "Input Not recognized. Try agian." << endl;
                validInput = 0;
                break;
        }
    }while(!validInput);

    if(newWord){
        cout << "What is the new Word? (please all lowercase and no spaces)" << endl;
        cout << "input: ";
        cin >> userInput;
        wordbank.push_back(userInput);
        wordBankToFile();
    }
}

void WordBankUI::fillWordBank(){
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

void WordBankUI::wordBankToFile(){
    ofstream fout;
    fout.open("WordBank.txt");
    for(int i = 0; i < (wordbank.size()); i++){
        fout << wordbank[i] << endl;
    }
    fout.close();
}
