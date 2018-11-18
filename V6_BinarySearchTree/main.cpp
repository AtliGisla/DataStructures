#include <iostream>
#include <string>

#include "bstmap.h"

using namespace std;

template <class K, class T>
void testInsert(Map<K, T> *map, K key, T data) {

    try {
        cout << "inserting: [" << key << ", " << data << "]" << endl;
        map->insert(key, data);
    }
    catch(ItemExistsException e) {
        cout << "caught ItemExistsException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testUpdate(Map<K, T> *map, K key, T data) {

    try {
        cout << "updating: [" << key << ", " << data << "]" << endl;
        map->update(key, data);
    }
    catch(NotFoundException e) {
        cout << "caught NotFoundException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testGet(Map<K, T> *map, K key) {

    try {
        cout << "getting: " << key << endl;
        T data = map->get(key);
        cout << "item: " << data << endl;
    }
    catch(NotFoundException e) {
        cout << "caught NotFoundException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testRemove(Map<K, T> *map, K key) {

    try {
        cout << "removing: " << key << endl;
        map->remove(key);
    }
    catch(NotFoundException e) {
        cout << "caught NotFoundException" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testContains(Map<K, T> *map, K key) {

    if(map->contains(key)) {
        cout << "map does contain " << key << endl;
    }
    else {
        cout << "map does NOT contain " << key << endl;
    }
    cout << endl;
}

template <class K, class T>
void testSize(Map<K, T> *map) {

    cout << "size of map: " << map->size() << endl;
    cout << endl;
}

template <class K, class T>
void testEmpty(Map<K, T> *map) {

    if(map->empty()) {
        cout << "map is empty" << endl;
    }
    else {
        cout << "map is NOT empty" << endl;
    }
    cout << endl;
}

template <class K, class T>
void testClear(Map<K, T> *map) {

    cout << "clearing contents of map" << endl;
    map->clear();
    cout << endl;
}

template <class K, class T>
void printMap(Map<K, T> *map) {

    cout << "contents: " << *map << endl;
    cout << endl;
}


int main() {

    Map<char, string> *bstMap = new BSTMap<char, string>();
    
    testInsert(bstMap, 'f', (string)"item-f");
    testInsert(bstMap, 'g', (string)"item-g");
    testInsert(bstMap, 'e', (string)"item-e");
    testInsert(bstMap, 'c', (string)"item-c");

    printMap(bstMap);
    testSize(bstMap);

    testContains(bstMap, 'a');
    testContains(bstMap, 'b');

    testRemove(bstMap, 'b');
    testContains(bstMap, 'b');

    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testGet(bstMap, 'c');
    testGet(bstMap, 'f');
    testGet(bstMap, 'e');

    testUpdate(bstMap, 'f', (string)"item-f-updated");

    testGet(bstMap, 'c');
    testGet(bstMap, 'f');
    testGet(bstMap, 'e');

    printMap(bstMap);
    testSize(bstMap);

    testRemove(bstMap, 'c');
    testRemove(bstMap, 'a');
    testRemove(bstMap, 'f');

    testUpdate(bstMap, 'f', (string)"item-f-updated");

    testGet(bstMap, 'c');
    testGet(bstMap, 'f');
    testGet(bstMap, 'e');

    testRemove(bstMap, 'e');
    testRemove(bstMap, 'g');

    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testRemove(bstMap, 'd');
    testEmpty(bstMap);

    printMap(bstMap);
    testSize(bstMap);

    testInsert(bstMap, 'd', (string)"item-d");
    testInsert(bstMap, 'b', (string)"item-b");
    testInsert(bstMap, 'f', (string)"item-f");
    testInsert(bstMap, 'g', (string)"item-g");
    testInsert(bstMap, 'e', (string)"item-e");
    testInsert(bstMap, 'c', (string)"item-c");

    testEmpty(bstMap);
    printMap(bstMap);
    testSize(bstMap);

    testClear(bstMap);
    testEmpty(bstMap);
    printMap(bstMap);
    testSize(bstMap);
    
    delete bstMap;
    bstMap = NULL;
}
