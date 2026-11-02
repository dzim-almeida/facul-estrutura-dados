#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
    ForwardList forwardList;
    forwardList.pushBack(10);
    forwardList.pushBack(9);
    
    forwardList.print();
    
    ForwardList forwardList2 = forwardList;
    forwardList2.print();

    return 0;
}