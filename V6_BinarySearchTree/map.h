#ifndef MAP_H
#define MAP_H

#include <ostream>

using namespace std;

class NotFoundException{};
class ItemExistsException{};

template <class K, class T>
class Map
{
    public:
        virtual ~Map() {};

        ///All these functions must be overloaded and implemented in a child class
        virtual void insert(K key, T data) = 0;
        virtual void update(K key, T data) = 0;
        virtual T get(K key) = 0;
        virtual void remove(K key) = 0;
        virtual bool contains(K key) = 0;
        virtual int size() const = 0;
        virtual bool empty() const = 0;
        virtual void clear() = 0;
        virtual void print(ostream& out) const = 0;

        ///No need to overload this function in child classes
        friend ostream& operator <<(ostream& out, const Map<K, T>& bm) {
            bm.print(out);
            return out;
        }
};

#endif // MAP_H
