#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& people, int sword_idx) {
    cout << "[ ";
    for(int i = 0; i < people.size(); i++) {
        cout << people[i];
        if(i == sword_idx) {
            cout << ">";
        }
        cout << " ";   
    }
    cout << "]" << endl;
}

vector<int> populate(int len) {
    vector<int> people;
    for(int i = 1; i <= len; i++) {
       people.push_back(i); 
    }
    return people;
}

void kill_queue(vector<int>& people, int sword_idx) {
    print(people, sword_idx);

    if (people.size() == 1) {
        return;
    }

    int kill_idx = (sword_idx + 1) % people.size();

    people.erase(people.begin() + kill_idx);
    sword_idx = kill_idx % people.size();

    kill_queue(people, sword_idx);
}

int main() {
    int len, sword_idx;
    cin >> len >> sword_idx;
    vector<int> people = populate(len);

    kill_queue(people, sword_idx-1);
    return 0;
}