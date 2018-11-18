#ifndef BUCKET_H
#define BUCKET_H

using namespace std;
#include <stdlib.h>

class NotFoundException {};

template <class K, class T>
class Bucket
{
    public:
        Bucket(K key, T data, Bucket* next = NULL) : key(key), data(data), next(next) {};

        virtual ~Bucket() {
            if(next == NULL){
                return;
            }
            else {
                delete *next;
            }
        };

        bool insert(K key, T data) { ///true if inserted, false if duplicate
            if(this->key == key){
                return false;
            }
            if(next == NULL){
                next = new Bucket(key, data, NULL);
                return true;
            }
            else {
                return (*next)->insert(key, data);
            }
        };

        bool update(K key, T data) { ///true if updated, false if not found
            if(this->key == key){
                this->data = data;
                return true;
            }
            if(next == NULL){
                return false;
            }
            else{
                return (*next)->update(key, data);
            }
        };

        T get(K key) { ///returns value or throws exception;
            if(this->key == key){
                return data;
            }
            if(next == NULL){
                throw NotFoundException();
            }
            else {
                return (*next)->get(key);
            }
        };

        bool remove(K key) { ///true if deleted, false if not found
            if(next == NULL){
                return false;
            }
            if(next->key == key){
                Bucket* temp = next;
                next = next->next;
                delete temp;
                return true;
            }
            return (*next).remove(key);
        };

        bool contains(K key) { ///true if contains, false if doesnt contain

        };

        void print() {
            cout << "[" << key << ", " << data << "] ";
            if(next == NULL){
                return;
            }
            else {
                (*next).print();
            }
        };

    private:
        K key;
        T data;
        Bucket* next;
};

#endif // BUCKET_H
