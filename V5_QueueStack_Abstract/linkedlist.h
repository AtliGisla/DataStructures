#include "node.h"
#include "stack.h"
#include "queue.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList : public Stack<T>, public Queue<T>
{
    public:
        LinkedList() : head(NULL), tail(NULL) {};
        virtual ~LinkedList() {
            Node<T>* tmp = head;
            while(head != NULL){
                head = head->next;
                delete tmp;
                tmp = head;
            }
            head = NULL;
            tail = NULL;
        };

        void headInsert(T data) {
            Node<T>* node = new Node<T>(data, head);
            head = node;
            if(tail == NULL){
                tail = head;
            }
        };
        void tailInsert(T data) {
            if(head == NULL){
                headInsert(data);
            }
            else {
                Node<T>* node = new Node<T>(data, NULL);
                tail->next = node;
                tail = node;
            }
        };
        T headRemove(){
            if(head == NULL){
                throw EmptyException();
            }
            T output = head->data;
            Node<T>* newHead = head->next;
            delete head;
            head = newHead;
            if(head == NULL){
                tail = head;
            }
            return output;
        };

        void push(T data){
            headInsert(data);
        };
        void add(T data){
            tailInsert(data);
        };
        T pop(){
            return headRemove();
        };
        T remove(){
            return headRemove();
        };
        void print(ostream& outs) const {
            Node<T>* currNode = head;
            while(currNode != NULL){
                outs << currNode->data << " ";
                currNode = currNode->next;
            }
        };
    private:
        Node<T>* head;
        Node<T>* tail;
};

#endif
