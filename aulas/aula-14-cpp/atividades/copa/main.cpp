#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<string> teams = {
        "A", "B", "C", "D", "E", "F", "G", "H",
        "I", "J", "K", "L", "M", "N", "O", "P"
    };

    queue<string> queue;

    for (string team : teams) {
        queue.push(team);
    }

    while (queue.size() != 1) {
        string team1 = queue.front();
        queue.pop();
        string team2 = queue.front();
        queue.pop();

        int goals_team1;
        int goals_team2;
        cin >> goals_team1;
        cin >> goals_team2;

        string winner = (goals_team1 > goals_team2) ? team1 : team2;
        queue.push(winner);
    }

    cout << queue.front() << endl;

    return 0;
}