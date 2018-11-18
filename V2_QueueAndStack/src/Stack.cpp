#include "Stack.h"

Stack::~Stack(){
    Node* nextNode = head;
    while(!isEmpty()){
        nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

void Stack::push(Measurement data){
    Node* node = new Node(data);
    node->next = head;
    head = node;
    itemCount++;
}

Measurement Stack::pop(){
    if(isEmpty()){
        throw EmptyException();
    }
    Measurement temp = head->measurement;
    Node* nextNode = head->next;
    delete head;
    head = nextNode;
    itemCount--;
    return temp;
}

int Stack::size(){
    return itemCount;
}

bool Stack::isEmpty(){
    return (head == NULL);
}

ostream& operator <<(ostream& out, Stack& stack){
    Node* currNode = stack.head;
    while(currNode != NULL){
        out << currNode->measurement << " ";
        currNode = currNode->next;
    }
    return out;
}
