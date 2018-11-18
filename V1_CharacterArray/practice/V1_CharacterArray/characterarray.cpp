#include "characterarray.h"

CharacterArray::CharacterArray()
{
    size = 0;
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    for(int i = 0; i < capacity; i++){
        array[i] = '\0';
    }
}

CharacterArray::CharacterArray(char* str, int length)
{
    size = length;
    capacity = length + 1;
    array = new char[capacity];
    for(int i = 0; i < length; i++){
        array[i] = str[i];
    }
    array[length] = '\0';
}

CharacterArray::~CharacterArray()
{
    delete[] array;
}

void CharacterArray::append(char c) {

    if(size + 1 >= capacity){
        resize();
    }
    array[size] = c;
    size++;
}

void CharacterArray::insert(char c, int index) {

    if(index < 0 || index > size){
        throw IndexOutOfBoundsException();
    }
    if(size + 1 >= capacity){
        resize();
    }
    for(int i = size; i > index; i--){
        array[i] = array[i - 1];
    }
    array[index] = c;
    size++;
}

void CharacterArray::setAt(char c, int index) {

    if(index < 0 || index >= size){
        throw IndexOutOfBoundsException();
    }
    array[index] = c;
}

char CharacterArray::getAt(int index) {

    if(index < 0 || index >= size){
        throw IndexOutOfBoundsException();
    }
    return array[index];
}

char CharacterArray::pop_back() {

    if(isEmpty()) {
        throw EmptyException();
    }
    char output = array[size - 1];
    array[size - 1] = '\0';
    size--;
    return output; //change or remove this line
}

char CharacterArray::removeAt(int index) {

    if(index < 0 || index >= size){
        throw IndexOutOfBoundsException();
    }
    char output = array[index];
    for(int i = index; i < size; i++){
        array[i] = array[i + 1];
    }
    size--;
    return output; //change or remove this line
}

void CharacterArray::clear() {

    for(int i = 0; i < capacity; i++){
        array[i] = '\0';
    }
    size = 0;
}

int CharacterArray::length() {

    return size;
}

bool CharacterArray::isEmpty() {

    return !(array[0]);
}

char* CharacterArray::substring(int startIndex, int length) {

    if(startIndex < 0 || (startIndex + length > size)){
        throw IndexOutOfBoundsException();
    }
    char* sub = new char[length + 1];
    for(int i = 0; i < length; i++){
        sub[i] = array[startIndex + i];
    }
    sub[length] = '\0';
    return sub;
}

ostream& operator <<(ostream& out, const CharacterArray& ca) {

    out << ca.array;
    return out;
}

void CharacterArray::resize() {
    capacity *= 2;
    char *newarr = new char[capacity];
    for(int i = 0; i < capacity; i++){
        newarr[i] = '\0';
    }
    for(int i = 0; i < size; i++){
        newarr[i] = array[i];
    }
    delete[] array;
    array = newarr;
}
