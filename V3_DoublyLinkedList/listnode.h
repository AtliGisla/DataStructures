#ifndef STRINGNODE_H
#define STRINGNODE_H

template <class T>

struct ListNode
{
    T data;
    ListNode *prev;
    ListNode *next;

    ListNode() : prev(NULL), next(NULL) { }
    ListNode(T value, ListNode *prev = NULL, ListNode *next = NULL)
    : data(value), prev(prev), next(next) { }

};

#endif // INTNODE_H
