#include <iostream>

#include "stack.h"
#include "queue.h"

using namespace std;

void pushOntoStack(Stack &s, string name, double value) {

    cout << "pushing measurement onto stack: name: " << name << ", value: " << value << endl;
    s.push(Measurement(name, value));
    cout << "current stack: " << s << endl;
    cout << "stack size: " << s.size() << endl;
    cout << endl;
}

void popOffStack(Stack &s) {

    cout << "popping measurement off stack" << endl;
    try {
        Measurement m = s.pop();
        cout << "value returned: " << m << endl;
    }
    catch(EmptyException) {
        cout << "caught EmptyException" << endl;
    }
    cout << "current stack: " << s << endl;
    cout << "stack size: " << s.size() << endl;
    cout << endl;
}

void clearStack(Stack &s) {

    cout << "popping every element off of stack" << endl;
    while(!s.isEmpty()) {
        s.pop();
    }
    cout << "current stack: " << s << endl;
    cout << "stack size: " << s.size() << endl;
    cout << endl;
}

void addToQueue(Queue &q, string name, double value) {

    cout << "adding measurement to queue: name: " << name << ", value: " << value << endl;
    q.add(Measurement(name, value));
    cout << "current queue: " << q << endl;
    cout << "queue size: " << q.size() << endl;
    cout << endl;
}

void removeFromQueue(Queue &q) {

    try {
        cout << "removing measurement from queue" << endl;
        Measurement m = q.remove();
        cout << "value returned: " << m << endl;
    }
    catch(EmptyException) {
        cout << "caught EmptyException" << endl;
    }
    cout << "current queue: " << q << endl;
    cout << "queue size: " << q.size() << endl;
    cout << endl;
}

void clearQueue(Queue &q) {

    cout << "removing every element from queue" << endl;
    while(!q.isEmpty()) {
        q.remove();
    }
    cout << "current queue: " << q << endl;
    cout << "queue size: " << q.size() << endl;
    cout << endl;
}

int main() {

    cout << endl << "STACK" << endl << endl;

    Stack s1;
    pushOntoStack(s1, "kari", 79.2);
    pushOntoStack(s1, "beggi", 91.3);
    pushOntoStack(s1, "kalli", 87.6);
    pushOntoStack(s1, "valdi", 117.4);
    pushOntoStack(s1, "anna", 54.2);

    popOffStack(s1);
    popOffStack(s1);
    popOffStack(s1);
    popOffStack(s1);
    popOffStack(s1);
    popOffStack(s1);

    cout << endl << "QUEUE" << endl << endl;

    Queue q1;
    addToQueue(q1, "kari", 79.2);
    addToQueue(q1, "beggi", 91.3);
    addToQueue(q1, "kalli", 87.6);
    addToQueue(q1, "valdi", 117.4);
    addToQueue(q1, "anna", 54.2);

    removeFromQueue(q1);
    removeFromQueue(q1);
    removeFromQueue(q1);
    removeFromQueue(q1);
    removeFromQueue(q1);
    removeFromQueue(q1);


    cout << endl << "EMPTY CHECK" << endl << endl;

    Stack s2;
    pushOntoStack(s2, "aaa", 11.1);
    pushOntoStack(s2, "bbb", 22.2);
    pushOntoStack(s2, "ccc", 33.3);
    pushOntoStack(s2, "ddd", 44.4);
    pushOntoStack(s2, "eee", 55.5);

    clearStack(s2);

    Queue q2;
    addToQueue(q2, "aaa", 11.1);
    addToQueue(q2, "bbb", 22.2);
    addToQueue(q2, "ccc", 33.3);
    addToQueue(q2, "ddd", 44.4);
    addToQueue(q2, "eee", 55.5);

    clearQueue(q2);


    return 0;
}
