#ifndef BSTMAP_H
#define BSTMAP_H

#include "map.h"
#include "node.h"

using namespace std;

template <class K, class T>
class BSTMap : public Map<K, T>{
    public:
        BSTMap<K, T>() {
            root = NULL;
            numberOfNodes = 0;
        };

        ~BSTMap<K, T>() {
            clear();
        };

        void insert(K key, T data) {
            Node<K, T>* &node = find(key, root);

            if(node == NULL){
                node = new Node<K, T>(key, data);
                numberOfNodes++;
            }else {
                throw ItemExistsException();
            }
        };

        void update(K key, T data) {
            Node<K, T>* &node = find(key, root);

            if(node == NULL){
                throw NotFoundException();
            }
            else {
                node->data = data;
            }
        };

        T get(K key) {
            Node<K, T>* &node = find(key, root);

            if(node == NULL){
                throw NotFoundException();
            }
            else {
                return node->data;
            }
        };

        void remove(K key) {
            Node<K, T>* &node = find(key, root);

            if(node == NULL){
                throw NotFoundException();
            }
            else {
                removeNode(node);
                numberOfNodes--;
            }
        };

        bool contains(K key) {
            return (find(key, root));
        };
        
        int size() const {
            return numberOfNodes;
            //return sizeRecursive(root);
        };

        bool empty() const {
            return (root == NULL);
        };

        void clear() {
            removeSubTree(root);
            numberOfNodes = 0;
        };

        void print(ostream& out) const {
            printRecursive(root);
        };

    private:
        Node<K, T>* root;
        int numberOfNodes;

        Node<K, T>* &find(K key, Node<K, T>* &node) {
            if(node == NULL){
                return node;
            }
            if(key < node->key){
                return find(key, node->left);
            }
            if(node->key < key){
                return find(key, node->right);
            }
            return node;
        };

        void removeSubTree(Node<K, T>* &node){
            if(node != NULL){
                removeSubTree(node->left);
                removeSubTree(node->right);
                delete node;
                node = NULL;
            }
        };

        void printRecursive(Node<K, T>* node) const{
            if(node != NULL){
                cout << "NODE [" << node->key << "," << node->data << "]" << endl;
                printRecursive(node->left);
                printRecursive(node->right);
            }
        };
/*
        int sizeRecursive(Node<K, T>* node) const{
            if(node == NULL){
                return 0;
            }
            else{
                return 1 + sizeRecursive(node->left) + sizeRecursive(node->right);
            }
        }
*/
        void removeNode(Node<K, T>* &node){
            if(node->left == NULL && node->right == NULL){
                delete node;
                node = NULL;
            }else if(node->right == NULL){
                Node<K, T>* tmp = node;
                node = node->left;
                delete tmp;
            }else if(node->left == NULL){
                Node<K, T>* tmp = node;
                node = node->right;
                delete tmp;
            }else{
                Node<K, T>* &nodeForDeletion = findRightMostNode(node->left);
                node->data = nodeForDeletion->data;
                node->key = nodeForDeletion->key;
                removeNode(nodeForDeletion);
            }
        }

        Node<K, T>* &findRightMostNode(Node<K, T>* &node){
            if(node->right == NULL){
                return node;
            }
            return findRightMostNode(node->right);
        }
};

#endif
