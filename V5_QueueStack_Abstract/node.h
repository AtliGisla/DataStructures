using namespace std;

template <class T>
class Node {
    public:
        Node() : next(NULL) {};
        Node(T data, Node* next) : data(data), next(next) {};

        T data;
        Node* next;
};
