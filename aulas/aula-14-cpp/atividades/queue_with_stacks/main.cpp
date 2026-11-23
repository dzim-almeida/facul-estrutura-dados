#include "queue.cpp"

#include <iostream>
using namespace std;

int main() {
    Queue queue;

    int elem;
    cin >> elem;

    while (elem != 0) {
        int comm;
        cin >> comm;

        if (comm == 1) {
            int val;
            cin >> val;
            queue.push(val);
        } else if (comm == 2) {
            queue.pop();
        } else {
            cout << queue.front() << endl;;
        }

        elem--;
    }

    return 0;
}