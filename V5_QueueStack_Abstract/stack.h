#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class EmptyException {};

template <class T>
class Stack
{
    public:
        virtual ~Stack(){};

        virtual void push(T data) = 0;
        virtual T pop() = 0;

        ///This is a pure virtual function
        ///The " = 0" tells the compiler that any class that inherits this class
        ///must implement the function, otherwise the program will not compile.
        ///If we skip the " = 0" and don't implement the function, either in this
        ///or a derived class and then use the classes in a program, it will cause
        ///a runtime error instead, which is mush harder to deal with.
        virtual void print(ostream& outs) const = 0;

        friend ostream& operator <<(ostream& outs, const Stack<T> &stac) {
            ///We call stac.print, even though it isn't implemented, because
            ///we trust that it will be implemented in the derived class
            stac.print(outs);
            return outs;
        }

};

#endif // STACK_H

