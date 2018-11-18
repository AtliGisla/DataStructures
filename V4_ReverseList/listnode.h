#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>

using namespace std;

class ListNode
{
    public:
        ListNode(char data, ListNode *next) {this->data = data; this->next = next; };
        virtual ~ListNode(){};

        char data;
        ListNode *next;

};

#endif // LISTNODE_H
