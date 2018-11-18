#include "Queue.h"

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    itemCount = 0;
}

Queue::~Queue()
{
    Node* nextNode = head;
    while(!isEmpty()){
        nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

void Queue::add(Measurement data){
    if(isEmpty()){
        Node* node = new Node(data);
        head = node;
        tail = node;
        itemCount++;
    }
    else{
        Node* node = new Node(data);
        tail->next = node;
        tail = node;
        itemCount++;
    }
}

Measurement Queue::remove(){
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

int Queue::size(){
    return itemCount;
}

bool Queue::isEmpty(){
    return (head == NULL);
}

ostream& operator << (ostream& out, Queue& queue){
    Node* currNode = queue.head;
    while(currNode != NULL){
        out << currNode->measurement << " ";
        currNode = currNode->next;
    }
    return out;
}
