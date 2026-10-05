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
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < (vec.size() - 1)) {
            cout << " ";
        }
    }
    cout << endl;
}


void refresh(vector<int>& queue, const vector<int>& giveup) {
    for(int i = 0; i < giveup.size(); i++) {
        for(auto it = queue.begin(); it != queue.end(); it++) {
            if(giveup[i] == *it) {
                queue.erase(it);
                break;
            }
        }
    }
}


int main() {
    vector<int> queue;
    vector<int> giveup;
    
    int len;
    cin >> len;
    input(queue, len);
    cin >> len;
    input(giveup, len);

    refresh(queue, giveup);
    print(queue);
}