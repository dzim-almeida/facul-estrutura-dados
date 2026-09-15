#include <iostream>
using namespace std;

int main() {
    int x {10};
    int *p = &x; // p points to x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p (address of x): " << p << endl;
    cout << "Value pointed to by p: " << *p << endl; // dereferencing p

    *p = 20; // changing the value of x through pointer p
    cout << "New value of x after changing through pointer p: " << x << endl;
    
    return 0;
}