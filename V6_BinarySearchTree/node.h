#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class K, class T>
class Node {
    public:
        Node(K key, T data, Node* left = NULL, Node* right = NULL) 
        : key(key), data(data), left(left), right(right) {};

        virtual ~Node() {};

        K key;
        T data;
        Node* left;
        Node* right;
};

#endif
