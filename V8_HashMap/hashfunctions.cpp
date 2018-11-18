#include "hashfunctions.h"

int char_hash(char c) {

    return int(c);
}

int int_hash(int i) {

    if(i < 0) {
        return -i;
    }
    return i;
}

int string_hash(string s) {

    int yaBoi = 0;
    for(int i = 0; i < s.length(); i++){
        yaBoi += s[i];
    }
    return yaBoi;
}
