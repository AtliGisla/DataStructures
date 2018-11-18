#ifndef NODE_H
#define NODE_H

#include "measurement.h"
#include <iostream>
using namespace std;

class EmptyException {};

class Node
{
    public:
        Node() : measurement("", 0.0), next(NULL) {};
        Node(Measurement param_measurement) : measurement(param_measurement), next(NULL) {};
        virtual ~Node() {};

        Measurement measurement;
        Node* next;

    protected:

    private:

};

#endif // NODE_H
