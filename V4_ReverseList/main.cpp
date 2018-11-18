#include <iostream>

using namespace std;

#include "listnode.h"
#include "listoperations.h"

int main() {

    cout << endl << "TESTING REVERSE_LIST" << endl << endl;

    ListNode *head = new ListNode('a', new ListNode('b', new ListNode('c', new ListNode('d', new ListNode('e', NULL)))));
    //ListOperations::printList(cout, head);

    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    ListOperations::deleteList(head);

    cout << endl;

    head = new ListNode('s', new ListNode('k', new ListNode('i', new ListNode('p', new ListNode('a', new ListNode('n', NULL))))));
    ListOperations::printList(cout, head);
    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    ListOperations::deleteList(head);

    cout << endl;

    head = new ListNode('0', NULL);
    ListOperations::printList(cout, head);
    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    head = ListOperations::reverseList(head);
    ListOperations::printList(cout, head);
    ListOperations::deleteList(head);

    head = NULL;
    ListOperations::printList(cout, head);

    return 0;
}
