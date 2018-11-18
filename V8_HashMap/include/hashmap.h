#ifndef HASHMAP_H
#define HASHMAP_H

#define INITIAL_CAPACITY 4

#include "bucket.h"
#include "..\map.h"
using namespace std;

template <class K, class T>
class HashMap : public Map<K, T>
{
    public:
        HashMap(int (*func)) {
            hash_func = func;
            capacity = INITIAL_CAPACITY;
            count = 0;
            array = new Bucket<K, T>[capacity];
        };

        virtual ~HashMap() {
            for(int i = 0; i < capacity; i++){
                delete array[i];
            }
            delete[] array;
        };

        void insert(K key, T data) {
            int index = hash_func(key) % capacity;
            if(array[index]->insert(key, data) == false){
                throw ItemExistsException();
            }
            else {
                count++;
            }
        };

        void update(K key, T data) {
            int index = hash_func(key) % capacity;
            if(array[index]->update(key, data) == false){
                throw NotFoundException();
            }
        };

        T get(K key) {
            int index = hash_func(key) % capacity;
            return array[index]->get(key);///Get funcion throws Exception
        };

        void remove(K key) {
            int index = hash_func(key) % capacity;
            if(array[index]->remove(key) == false){
                throw NotFoundException();
            }
            else {
                count--;
            }
        };

        bool contains(K key) {
            int index = hash_func(key) % capacity;
            return array[index]->contains(key);
        };

        int size() const {
            return count;
        };

        bool empty() const {
            return (count == 0);
        };

        void clear() {
            for(int i = 0; i < capacity; i++){
                delete array[i];
            }
        };

        void print(ostream& out) const {
            for(int i = 0; i < capacity; i++){
                array[i].print();
            }
        };

    private:
        Bucket<K,T>* array; ///sentinel buckets
        int capacity;
        int count;

        int (*hash_func)(K);

        void resize() {

        };
};

#endif // HASHMAP_H
