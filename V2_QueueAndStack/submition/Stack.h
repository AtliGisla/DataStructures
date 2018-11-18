#ifndef STACK_H
#define STACK_H

#include <ostream>
#include <string>

#include "measurement.h"
#include "Node.h"

using namespace std;

class Stack
{
    public:
        Stack() : head(NULL), itemCount(0) {};
        virtual ~Stack();
        void push(Measurement data);
        Measurement pop();
        int size();
        bool isEmpty();
        friend ostream& operator <<(ostream& out, Stack& stack);
    protected:

    private:
        Node* head;
        int itemCount;
};

#endif // STACK_H
