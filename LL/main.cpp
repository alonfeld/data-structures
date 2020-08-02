#include <iostream>
#include "LL.hpp"
using namespace std;

int main()
{
    cout << "LLTest " << endl;

    //Test Linked List
    int data;

    LL LinkedList;
    LinkedList.printList();
    cout << "LLTest: negative test:  remove last." << endl;
    data = LinkedList.removeLast();

    cout << "LLTest: negative test:  remove first." << endl;
    data = LinkedList.removeFirst();

    cout << "LLTest: Add -10" << endl;
    LinkedList.add(-10);
    LinkedList.printList();

    cout << "LLTest: remove last." << endl;
    data = LinkedList.removeLast();
    cout << "LLTest: removed data " << data << endl;
    LinkedList.printList();
    
    cout << "LLTest: negative test:  remove first." << endl;
    data = LinkedList.removeFirst();  

    cout << "LLTest: Add -20" << endl;
    LinkedList.add(-20);
    LinkedList.printList();

    cout << "LLTest: remove first." << endl;
    data = LinkedList.removeFirst();
    cout << "LLTest: removed data " << data << endl;

    cout << "LLTest: negative test:  remove last." << endl;
    data = LinkedList.removeLast();
    LinkedList.printList();

    cout << "LLTest: Add -30 -40" << endl;
    LinkedList.add(-30);
    LinkedList.add(-40);
    LinkedList.printList();

    cout << "LLTest: remove first." << endl;
    data = LinkedList.removeFirst();
    cout << "LLTest: removed data " << data << endl;

    cout << "LLTest: remove last." << endl;
    data = LinkedList.removeLast();
    cout << "LLTest: removed data " << data << endl;
    LinkedList.printList();

    cout << "LLTest: Add -50 -60" << endl;
    LinkedList.add(-50);
    LinkedList.add(-60);
    LinkedList.printList();

    cout << "LLTest: remove last." << endl;
    data = LinkedList.removeLast();
    cout << "LLTest: removed data " << data << endl;

    cout << "LLTest: remove last." << endl;
    data = LinkedList.removeLast();
    cout << "LLTest: removed data " << data << endl;
    LinkedList.printList();

#if 0
    cout << "LLTest: Add 1" << endl;
    LinkedList.add(1);
    LinkedList.printList();

    cout << "LLTest: Add 2" << endl;
    LinkedList.add(2);
    LinkedList.printList();

    cout << "LLTest: Add 3" << endl;
    LinkedList.add(3);
    LinkedList.printList();

    cout << "LLTest: Add 4" << endl;
    LinkedList.add(4);
    LinkedList.printList();

    cout << "LLTest: Add 5 to location 2" << endl;
    LinkedList.addInPlace(5, 2);
    LinkedList.printList();

    cout << "LLTest: negative test: Add 6 to location 7" << endl;
    LinkedList.addInPlace(6, 7);

    cout << "LLTest: Add 6 to location 6" << endl;
    LinkedList.addInPlace(6, 6);
    LinkedList.printList();

    cout << "LLTest: Add 7 to location 6" << endl;
    LinkedList.addInPlace(7, 6);
    LinkedList.printList();

    cout << "LLTest: negative test: Add 8 to location 0" << endl;
    LinkedList.addInPlace(8, 0);

    cout << "LLTest: Add 9 to location 1" << endl;
    LinkedList.addInPlace(9, 1);
    LinkedList.printList();

    cout << "LLTest: remove first." << endl;
    data = LinkedList.removeFirst();
    LinkedList.printList();

    cout << "LLTest: remove last." << endl;
    data = LinkedList.removeLast();
    LinkedList.printList();    
#endif   
}
