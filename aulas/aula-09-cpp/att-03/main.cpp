#include <iostream>
#include <vector>
using namespace std;

void input(vector<int>& in, unsigned int len) {
    for(int i = 0; i < len; i++) {
        int elem;
        cin >> elem;
        in.push_back(elem);
    }
}

void print(const vector<int>& vec) {
    cout << "[ ";
    for(int elem : vec) {
        cout << elem << " ";
    }
    cout << "]" << endl;
}


void rotate(vector<int>& vec, unsigned int rot) {
    auto it = vec.begin();
    for(int c = 1; c <= rot; c++) {
        int last_elem = vec.back();
        vec.pop_back();
        vec.insert(it, last_elem);
    }
}


int main() {
    vector<int> vec;
    
    int len, rot;
    
    cin >> len >> rot;

    input(vec, len);
    
    rotate(vec, rot);
    print(vec);
}