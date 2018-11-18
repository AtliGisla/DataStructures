#ifndef BUFFERLIST_H
#define BUFFERLIST_H

#include <iostream>

#include "queue.h"
#include "stack.h"

///You MUST use this value of initial capacity when you return you final version
///but feel free to change it while testing (to first test regular functionality)
#define INITIAL_CAPACITY 4

///TODO: Inherit both Queue and Stack

template <class T>
class BufferList : public Stack<T>, public Queue<T>
{
public:
    BufferList()
    {
        size = 0;
        capacity = INITIAL_CAPACITY;
        arr = new T[capacity];
        head = 0;
        tail = 0;
    }

    virtual ~BufferList()
    {
        delete[] arr;
    }

    ///TODO: Override functions from Stack ADT
    virtual void push(T data)
    {
        if(capacity == size)
        {
            resize();
        }
        for(int i = size; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = data;
        size++;
    }

    virtual T pop()
    {
        if(size == 0){
            throw EmptyException();
        }

        T data = arr[0];
        for(int i = 0; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return data;
    }

    ///TODO: Override functions from Queue ADT
    virtual void add(T data)
    {
        if(size == 0){
            arr[head] = data;
            size++;
            return;
        }
        else if(size + 1 > capacity){
            resize();
        }
        tail = (tail + 1) % capacity;
        arr[tail] = data;
        size++;
    }

    virtual T remove()
    {
        if(size == 0)
        {
            throw EmptyException();
        }
        if(size == 1){
            T value = arr[head];
            tail = head;
            size--;
            return value;
        }
        else{
            T value = arr[head];
            head = (head + 1) % capacity;
            size--;
            return value;
        }
    }
    ///print override:
    void print(ostream &outs) const
    {

        ///TODO: Implement print for your own testing
        ///This is not tested on Mooshak, so it doesn't
        ///matter exactly how you print the list
        /*for(int i = 0; i < capacity; i++){
            if(i == head){
                outs << "h:";
            }
            if(i == tail){
                outs << "t:";
            }
            outs << arr[i] << " ";
        }
        outs << endl << "size:" << size << endl;*/
    }

    friend ostream& operator <<(ostream& outs, const BufferList<T> &lis)
    {
        lis.print(outs);
        return outs;
    }

private:
    int capacity;
    int size;
    T *arr;
    void resize()
    {
        capacity *= 2;
        T* newArr = new T[capacity];
        int counter = head;
        for(int i = 0; i < size; i++){
            newArr[i] = arr[counter];
            counter++;
            counter %= (capacity / 2);
        }
        head = 0;
        tail = size - 1;
        if(!size){
            tail = 0;
        }
        delete[] arr;
        arr = newArr;
    }
    int tail;
    int head;
};

#endif // BUFFERLIST_H

