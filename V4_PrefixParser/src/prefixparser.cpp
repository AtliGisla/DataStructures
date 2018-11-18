#include <iostream>
#include "prefixparser.h"

using namespace std;

int parseExpression(istream& ins){

    if(ins.eof()){
        return 0;
    }

    string word = "";
    ins >> word;

    if(word == "+"){
        return parseExpression(ins) + parseExpression(ins);
    } else if(word == "-"){
        return parseExpression(ins) - parseExpression(ins);
    } else if(word == "*") {
        return parseExpression(ins) * parseExpression(ins);
    } else if(word == "/") {
        int dividend = parseExpression(ins);
        int divider = parseExpression(ins);
        if(divider == 0){
            throw DivideByZeroException();
        }
        return dividend / divider;
    }
    else {
        int value = 0;
        int multOfTen = 1;
        char letter = '\0';
        int temp = 0;
        for(int i = (word.length() - 1); i >= 0; i--){
            letter = word[i];
            temp = letter - 48;
            value += temp * multOfTen;
            multOfTen *= 10;
        }

        return value;
    }
    return 0;
}
