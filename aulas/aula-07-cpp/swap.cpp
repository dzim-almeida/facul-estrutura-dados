#include <iostream>
using namespace std;

/**
 * @brief Swaps the values of two integers using pointers.
 * 
 * @param a 
 * @param b
 *  
 */
void swap(int *a, int *b) {
    int temp = *a; // store the value pointed to by a in temp
    *a = *b; // assign the value pointed to by b to the location pointed to by a
    *b = temp; // assign the value stored in temp to the location pointed to by b
}

int main() {
    int x {10};
    int y {20};

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swap(&x, &y); // passing addresses of x and y

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}