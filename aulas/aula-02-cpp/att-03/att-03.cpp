#include <iostream>

using namespace std;

int main() {

    // Declaração de variáveis
    int helicopter, cop, bandit, direction;

    cin >> helicopter >> cop >> bandit >> direction;

    // Repetição quando é anti-horário
    while (helicopter != bandit) {
        bandit += direction;

        if (bandit < 0) {
            bandit = 15;
        }

        if (bandit > 15) {
            bandit = 0;
        }

        if(bandit == cop) {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;
    
    return 0;
}