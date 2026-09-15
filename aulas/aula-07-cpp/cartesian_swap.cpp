#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

void swap(Point *p1, Point *p2) {
    Point temp = *p1; // store the value pointed to by p1 in temp
    *p1 = *p2; // assign the value pointed to by p2 to the location pointed to by p1
    *p2 = temp; // assign the value stored in temp to the location pointed to by p2
}

void duplicatePointValue(Point *p1) {
    (*p1).x *= 2;
    (*p1).y *= 2;
}

int main() {
    Point p1 {10, 20};
    Point p2 {30, 40};

    cout << "Before swap: p1 = (" << p1.x << ", " << p1.y << "), p2 = (" << p2.x << ", " << p2.y << ")" << endl;
    swap(&p1, &p2); // passing addresses of p1 and p2
    cout << "After swap: p1 = (" << p1.x << ", " << p1.y << "), p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    cout << "Before duplicate: p1 = (" << p1.x << ", " << p1.y << ")" << endl;
    duplicatePointValue(&p1); // passing address of p1
    cout << "After duplicate: p1 = (" << p1.x << ", " << p1.y << ")" << endl;

    return 0;
}