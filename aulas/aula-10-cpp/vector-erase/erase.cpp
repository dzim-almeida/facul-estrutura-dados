#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int>& v) {
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it;
    }
    cout << endl;
}

void removeAll(vector<int>&v, int value) {
    auto it = v.begin();
    while (it != v.end()) {
        if (value == *it) {
            v.erase(it);
        } else {
            it++;
        }
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 3, 4, 3, 3, 5, 3, 6};

    printVec(vec);
    removeAll(vec, 3);
    printVec(vec);
}