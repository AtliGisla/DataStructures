#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue
{
    public:
        virtual ~Queue(){};

        virtual void add(T data) = 0;
        virtual T remove() = 0;

        ///This is a pure virtual function
        ///The " = 0" tells the compiler that any class that inherits this class
        ///must implement the function, otherwise the program will not compile.
        ///If we skip the " = 0" and don't implement the function, either in this
        ///or a derived class and then use the classes in a program, it will cause
        ///a runtime error instead, which is mush harder to deal with.
        virtual void print(ostream& outs) const = 0;

        friend ostream& operator <<(ostream& outs, const Queue<T> &que) {
            ///We call que.print, even though it isn't implemented, because
            ///we trust that it will be implemented in the derived class
            que.print(outs);
            return outs;
        }

};

#endif // QUEUE_H

