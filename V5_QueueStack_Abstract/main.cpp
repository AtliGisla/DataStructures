#include <iostream>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "bufferlist.h"

using namespace std;

template <class T>
void pushTest(Stack<T> *stac, T value) {
    cout << "push(" << value << ")" << endl;
    stac->push(value);
    cout << "stack: " << *stac << endl;
    cout << endl;
}

template <class T>
void popTest(Stack<T> *stac) {
    try
    {
        cout << "pop()" << endl;
        T value = stac->pop();
        cout << "value = " << value << endl;
        cout << "stack: " << *stac << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
    cout << endl;
}

template <class T>
void addTest(Queue<T> *que, T value) {
    cout << "add(" << value << ")" << endl;
    que->add(value);
    cout << "queue: " << *que << endl;
    cout << endl;
}

template <class T>
void removeTest(Queue<T> *que) {
    try
    {
        cout << "remove()" << endl;
        T value = que->remove();
        cout << "value = " << value << endl;
        cout << "queue: " << *que << endl;
    }
    catch(EmptyException) {
        cout << "Caught EmptyException" << endl;
    }
    cout << endl;
}


void intStackTest(Stack<int> *stac) {

    pushTest(stac, 53);

    popTest(stac);
    popTest(stac);

    pushTest(stac, 3);
    pushTest(stac, 8);
    pushTest(stac, 43);

    popTest(stac);

    pushTest(stac, 58);
    pushTest(stac, 1003);

    popTest(stac);
    popTest(stac);

    pushTest(stac, 333);
    pushTest(stac, 338);
    pushTest(stac, 3343);
    pushTest(stac, 118);
    pushTest(stac, 1143);
    pushTest(stac, 3000000);

    popTest(stac);
    popTest(stac);
    popTest(stac);
    popTest(stac);

    popTest(stac);
    popTest(stac);
    popTest(stac);
    popTest(stac);

    popTest(stac);
    popTest(stac);
}

void doubleStackTest(Stack<double> *stac) {

    pushTest(stac, 53.8);

    popTest(stac);
    popTest(stac);

    pushTest(stac, 33.35);
    pushTest(stac, 8.7);
    pushTest(stac, 43.56);

    popTest(stac);

    pushTest(stac, 58.6);
    pushTest(stac, 1003.5);

    popTest(stac);
    popTest(stac);
}

void stringStackTest(Stack<string> *stac) {

    pushTest(stac, (string)"ned");


    popTest(stac);


    popTest(stac);

    pushTest(stac, (string)"brandon");

    pushTest(stac, (string)"jamie");

    pushTest(stac, (string)"tywin");


    popTest(stac);

    pushTest(stac, (string)"sandor");

    pushTest(stac, (string)"gregor");


    popTest(stac);
    popTest(stac);
}

void intQueueTest(Queue<int> *que) {

    addTest(que, 53);

    removeTest(que);
    removeTest(que);

    addTest(que, 3);
    addTest(que, 8);
    addTest(que, 43);

    removeTest(que);

    addTest(que, 58);
    addTest(que, 1003);

    removeTest(que);
    removeTest(que);

    addTest(que, 333);
    addTest(que, 338);
    addTest(que, 3343);
    addTest(que, 118);
    addTest(que, 1143);
    addTest(que, 3000000);

    removeTest(que);
    removeTest(que);
    removeTest(que);
    removeTest(que);

    removeTest(que);
    removeTest(que);
    removeTest(que);
    removeTest(que);

    removeTest(que);
    removeTest(que);
}

void doubleQueueTest(Queue<double> *que) {

    addTest(que, 53.7);


    removeTest(que);
    removeTest(que);

    addTest(que, 3.4);

    addTest(que, 8.8);

    addTest(que, 43.3);


    removeTest(que);

    addTest(que, 58.2);

    addTest(que, 1003.7);


    removeTest(que);
    removeTest(que);
}

void stringQueueTest(Queue<string> *que) {

    addTest(que, (string)"cercei");

    removeTest(que);
    removeTest(que);

    addTest(que, (string)"arya");
    addTest(que, (string)"daenerys");
    addTest(que, (string)"margaery");

    removeTest(que);

    addTest(que, (string)"sansa");
    addTest(que, (string)"olenna");

    removeTest(que);
    removeTest(que);
}

void testLinkedListStack() {

    cout << "\n -- new Stack --" << endl;
    Stack<int> *stac1 = new LinkedList<int>();
    intStackTest(stac1);
    delete stac1;

    cout << "\n -- new Stack --" << endl;
    Stack<double> *stac2 = new LinkedList<double>();
    doubleStackTest(stac2);
    delete stac2;

    cout << "\n -- new Stack --" << endl;
    Stack<string> *stac3 = new LinkedList<string>();
    stringStackTest(stac3);
    delete stac3;
}

void testLinkedListQueue() {

    cout << "\n -- new Queue --" << endl;
    Queue<int> *que1 = new LinkedList<int>();
    intQueueTest(que1);
    delete que1;

    cout << "\n -- new Queue --" << endl;
    Queue<double> *que2 = new LinkedList<double>();
    doubleQueueTest(que2);
    delete que2;

    cout << "\n -- new Queue --" << endl;
    Queue<string> *que3 = new LinkedList<string>();
    stringQueueTest(que3);
    delete que3;
}

void testBufferListStack() {

    cout << "\n -- new Stack --" << endl;
    Stack<int> *stac1 = new BufferList<int>();
    intStackTest(stac1);
    delete stac1;

    cout << "\n -- new Stack --" << endl;
    Stack<double> *stac2 = new BufferList<double>();
    doubleStackTest(stac2);
    delete stac2;

    cout << "\n -- new Stack --" << endl;
    Stack<string> *stac3 = new BufferList<string>();
    stringStackTest(stac3);
    delete stac3;
}

void testBufferListQueue() {

    cout << "\n -- new Queue --" << endl;
    Queue<int> *que1 = new BufferList<int>();
    intQueueTest(que1);
    delete que1;

    cout << "\n -- new Queue --" << endl;
    Queue<double> *que2 = new BufferList<double>();
    doubleQueueTest(que2);
    delete que2;

    cout << "\n -- new Queue --" << endl;
    Queue<string> *que3 = new BufferList<string>();
    stringQueueTest(que3);
    delete que3;
}

int main() {

    ///Comment these out one by one for more focused tests

//    testLinkedListStack();
  //  testLinkedListQueue();
    testBufferListStack();
    testBufferListQueue();

    return 0;
}
