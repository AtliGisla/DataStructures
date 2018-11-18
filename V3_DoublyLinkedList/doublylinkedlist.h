#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

#include "listnode.h"

using namespace std;

class InvalidPositionException { };

template <class T>

class DoublyLinkedList {
    public:
        DoublyLinkedList() { ///CONFIRMED WORKS
            head = new ListNode<T>();
            tail = new ListNode<T>();
            head->next = tail;
            tail->prev = head;
            size = 0;
            currentPosition = 0;
            currNode = tail;
        }

        ~DoublyLinkedList() { ///CONFIRMED WORKS

            ListNode<T>* nextNode = head;
            while(head != NULL){
                nextNode = head->next;
                delete head;
                head = nextNode;
            }
        }

        // Clear contents from the list, to make it empty.
        // Worst-case time complexity: Linear
        void clear() { ///CONFIRMED WORKS
            ListNode<T>* nextNode = NULL;
            while(head->next != tail){
                nextNode = head->next->next;
                delete head->next;
                head->next = nextNode;
            }
            tail->prev = head;
            size = 0;
            currentPosition = 0;
            currNode = tail;
        }

        // Insert an element at the current location.
        // item: The element to be inserted
        // Worst-case time complexity: Constant
        void insert(const T& item) { ///CONFIRMED WORKS
            ListNode<T>* newNode = new ListNode<T>(item, currNode->prev, currNode);
            currNode->prev->next = newNode;
            currNode->prev = newNode;
            size++;
            currentPosition++;
        }

        // Append an element at the end of the list.
        // item: The element to be appended.
        // Worst-case time complexity: Constant
        void append(const T& item) { ///CONFIRMED WORKS

            ListNode<T>* newNode = new ListNode<T>(item, tail->prev, tail);
            tail->prev->next = newNode;
            tail->prev = newNode;
            size++;
            if(currNode == tail){
                currentPosition++;
            }
        }

        // Remove and return the current element.
        // Return: the element that was removed.
        // Worst-case time complexity: Constant
        // Throws InvalidPositionException if current position is
        // behind the last element
        T remove() { ///CONFIRMED WORKS

            if(currNode == tail){
                throw InvalidPositionException();
            }
            ListNode<T>* deletedNode = currNode;
            T output = currNode->data;
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;
            currNode = currNode->next;
            delete deletedNode;
            size--;

            return output;
        }

        // Set the current position to the start of the list
        // Worst-case time complexity: Constant
        void move_to_start() { ///CONFIRMED WORKS

            currentPosition = 0;
            currNode = head->next;
        }

        // Set the current position to the end of the list
        // Worst-case time complexity: Constant
        void move_to_end() { ///CONFIRMED WORKS

            currentPosition = size;
            currNode = tail;
        }

        // Move the current position one step left. No change
        // if already at beginning.
        // Worst-case time complexity: Constant
        void prev() { ///CONFIRMED WORKS

            if(currNode == head->next){
                return;
            }
            else{
                currNode = currNode->prev;
                currentPosition--;
            }
        }

        // Move the current position one step right. No change
        // if already at end.
        // Worst-case time complexity: Constant
        void next() { ///CONFIRMED WORKS

            if(currNode == tail){
                return;
            }
            else{
                currNode = currNode->next;
                currentPosition++;
            }
        }

        // Return: The number of elements in the list.
        // Worst-case time complexity: Constant
        int length() const { ///CONFIRMED WORKS

            return size;
        }

        // Return: The position of the current element.
        // Worst-case time complexity: Constant
        int curr_pos() const { ///CONFIRMED WORKS

            return currentPosition;
        }

        // Set current position.
        // pos: The position to make current.
        // Worst-case time complexity: Linear
        // Throws InvalidPositionException if 'pos' is not a valid position
        void move_to_pos(int pos) {
            if(pos < 0 || pos > size){
                throw InvalidPositionException(); ///CONFIRMED WORKS
            }
            currNode = head->next;
            currentPosition = 0;
            for(int i = 0; i < pos; i++){
                currNode = currNode->next;
                currentPosition++;
            }
        }

        // Return: The current element.
        // Worst-case time complexity: Constant
        // Throws InvalidPositionException if current position is
        // behind the last element
        const T& get_value() const {

            if(currNode == tail) {
                throw InvalidPositionException();
            }
            else{
                return currNode->data;
            }
        }


        // Outputs the elements of 'lis' to the stream 'outs', separated
        // by a single space.
        friend ostream& operator <<(ostream& outs, const DoublyLinkedList& lis) {
            ListNode<T>* currentNode = lis.head->next;
            while(currentNode != lis.tail){
                outs << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            return outs;
        }

    private:

        // head is our preceding node
        // not a data node itself
        ListNode<T> *head;

        // tail is our trailing node
        // not a data node itself
        ListNode<T> *tail;

        //currNode is the node at the current position
        ListNode<T> *currNode;

        int size;
        int currentPosition;
};


#endif // DOUBLY_LINKED_LIST_H
