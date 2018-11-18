#include "characterarray.h"

CharacterArray::CharacterArray()
{
    arr = new char[INITIAL_CAPACITY];
    arr[0] = '\0';
    capacity = INITIAL_CAPACITY;
    size = 1;
}

CharacterArray::CharacterArray(char* str, int length)
{
    size = 0;
    capacity = INITIAL_CAPACITY;
    arr = new char[capacity];
    while(capacity < (length + 1)){
        resize();
    }
    for(int i = 0; i < length; i++) {
        arr[i] = str[i];
        size++;
    }
    size++;
    arr[size-1] = '\0';
}

CharacterArray::~CharacterArray()
{
    delete[] arr;
}

void CharacterArray::append(char c) {
    if(size >= capacity){
        resize();
    }
    arr[size-1] = c;
    size++;
    arr[size-1] = '\0';
}

void CharacterArray::insert(char c, int index) {
    if(index < 0 || index >= size){
        throw IndexOutOfBoundsException();
    }

    if(size+1 > capacity){
        resize();
    }
    for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = c;
    size++;
}

void CharacterArray::setAt(char c, int index) {
    if(index < 0 || index >= (size-1)){
        throw IndexOutOfBoundsException();
    }
    arr[index] = c;
}

char CharacterArray::getAt(int index) {
    if(index < 0 || index >= (size-1)){
        throw IndexOutOfBoundsException();
    }
    return arr[index]; //change or remove this line
}

char CharacterArray::pop_back() {

    //Example of throwing an exception
    if(isEmpty()) {
        throw EmptyException();
    }
    char removed = arr[size-2];
    arr[size-2] = '\0';
    size--;
    return removed; //change or remove this line
}

char CharacterArray::removeAt(int index) {
    if(index < 0 || index >= (size-1)){
        throw IndexOutOfBoundsException();
    }
    char removed = arr[index];
    for(int i = index; i < (size-1); i++){
        arr[i] = arr[i + 1];
    }
    size--;
    return removed;
}

void CharacterArray::clear() {
    size = 1;
    arr[0] = '\0';
}

int CharacterArray::length() {
    return size-1;
}

bool CharacterArray::isEmpty() {
    if(size == 1){
        return true;
    }
    return false;
}

char* CharacterArray::substring(int startIndex, int length) {
    if((startIndex > size || startIndex < 0) || ((startIndex + length) >= size || (startIndex + length) < 0)){
        throw IndexOutOfBoundsException();
    }
    char* tempStr = new char[length + 1];
    for(int i = 0; i < length; i++){
        tempStr[i] = arr[i + startIndex];
    }
    tempStr[length] = '\0';
    return tempStr;
}

ostream& operator <<(ostream& out, const CharacterArray& ca) {
    out << ca.arr;
    return out; //change or remove this line
}

void CharacterArray::resize(){
    capacity *= 2;
    char* tempArr = new char[capacity];
    for(int i = 0; i < size; i++){
        tempArr[i] = arr[i];
    }
    delete[] arr;
    arr = tempArr;
}
