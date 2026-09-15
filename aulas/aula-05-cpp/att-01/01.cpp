#include <iostream>
using namespace std;

/**
 * @brief Calcula o número de maneiras de subir uma escada com n degraus
 * @param n o número de degraus da escada
 * @return o número de maneiras de subir a escada
 */
int stairs(int n) {
    if (n < 3) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }

    return stairs(n - 1) + stairs(n - 3);
}

int main() {
    int n; // Quantidade de degraus da escada
    cin >> n; 

    cout << stairs(n) << endl; // Imprime o número de maneiras de subir a escada com n degraus
    
    return 0;
}