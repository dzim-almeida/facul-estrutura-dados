#include <iostream>
using namespace std;

/**
 * @brief Função recursiva que resolve o problema das Torres de Hanoi
 * 
 * @param qte
 * @param ini 
 * @param aux 
 * @param end 
 * @return void
 */
void hanoi(int qte, char ini, char aux, char end) {
    if (qte == 1) {
        cout << ini << " -> " << end << endl;
        return;
    }

    hanoi(qte-1, ini, end, aux);
    cout << ini << " -> " << end << endl;
    hanoi(qte-1, aux, ini, end);
}

int main() {
    int qte;
    cin >> qte;

    hanoi(qte, 'A', 'B', 'C');
    return 0;
}