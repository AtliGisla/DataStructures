#ifndef QUEUE_H
#define QUEUE_H

#include "measurement.h"
#include "Node.h"

using namespace std;

class Queue
{
    public:
        Queue();
        virtual ~Queue();

        void add(Measurement data);
        Measurement remove();
        int size();
        bool isEmpty();
        friend ostream& operator << (ostream& out, Queue& queue);

        Node* head;
        Node* tail;
        int itemCount;
    protected:

    private:
};

#endif // QUEUE_H
