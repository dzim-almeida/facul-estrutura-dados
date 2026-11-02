#include "list.cpp"
#include <iostream>

int main() {

    List lst;
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(8);
    lst.print();
    lst.insertAfter(20, 2);
    lst.insertAfter(10, 5);
    lst.print();
    lst.remove(2);
    lst.print();
    lst.clear();
    lst.printReverse();

    return 0;
}