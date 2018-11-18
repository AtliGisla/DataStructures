#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main() {

    cout << endl << "STRING_LIST" << endl << endl;

    DoublyLinkedList<string> stringList;

    stringList.append("trjvgm");
    cout << stringList << endl;
    stringList.clear();
    stringList.insert("meukh");
    cout << stringList << endl;
    try {
    stringList.remove();
    }catch(InvalidPositionException) {
        cout << "caught!" << endl;
    }
    stringList.move_to_pos(0);
    cout << stringList.get_value() << endl;
    stringList.move_to_pos(1);
    try{
    stringList.remove();
    } catch(InvalidPositionException) {
        cout << "caught!" << endl;
    }
    try{
        cout << stringList.get_value() << endl;
    } catch(InvalidPositionException) {
        cout << "caught!" << endl;
    }
    cout << stringList.curr_pos() << endl;
    stringList.next();
    stringList.move_to_pos(0);
    cout << stringList.curr_pos() << endl;
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.append("bob");
    stringList.move_to_end();
    cout << stringList.curr_pos() << endl;
    stringList.move_to_start();
    cout << stringList.curr_pos() << endl;
    cout << stringList << endl;


    stringList.append("fic");
    stringList.append("sdf");
    stringList.append("wet");
    stringList.append("fgh");
    stringList.move_to_pos(2);
    cout << stringList << endl;
    stringList.clear();
    stringList.insert("pod");
    cout << stringList << endl;
    stringList.prev();
    stringList.append("bxph");
    cout << stringList << endl;
    stringList.next();
    cout << stringList << endl;
    try{
        stringList.remove();
        cout << stringList << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }

    try{
        stringList.remove();
        cout << stringList << endl;
    }catch(InvalidPositionException) {
        cout << "Caught InvalidPositionException" << endl;
    }
    cout << stringList << endl;
    stringList.prev();

    cout << stringList << endl;
    stringList.insert("ah");

    cout << stringList << endl;

    stringList.next();
    cout << stringList << endl;
    stringList.next();

    cout << stringList << endl;
    stringList.prev();

    cout << stringList << endl;
    stringList.append("z");
    cout << stringList << endl;

    cout << endl << "INT_LIST" << endl << endl;

    DoublyLinkedList<int> intList;

    intList.append(4);
    intList.move_to_start();
    intList.insert(7);
    cout << intList << endl;

}

