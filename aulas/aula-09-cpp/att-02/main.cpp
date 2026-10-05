#include <iostream>
#include <vector>
using namespace std;

void input(vector<string>& in, unsigned int len) {
    for(int i = 0; i < len; i++) {
        string elem;
        cin >> elem;
        in.push_back(elem);
    }
}

void matchingStrings(const vector<string>& inputs, const vector<string>& querys) {
    for(int i = 0; i < querys.size(); i++) {
        int queryCount = 0;
        for(int j = 0; j < inputs.size(); j++) {
            if(querys[i] == inputs[j]) {
                queryCount++;
            }
        }
        cout << queryCount;
        if(i < (querys.size() - 1)) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<string> inputs;
    vector<string> querys;
    
    int len;
    cin >> len;
    input(inputs, len);
    cin >> len;
    input(querys, len);

    matchingStrings(inputs, querys);

    return 0;
}