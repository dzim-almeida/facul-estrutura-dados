#include <iostream>
using namespace std;

/** 
 * @brief Imprime uma linha de asteriscos
 * @param n o número de asteriscos a serem impressos
 * @return void
 */

void asteristico(int n) {
    if (n == 0) {
        cout << endl;
        return;
    }
    
    cout << "*";
    asteristico(n - 1);
}

int main() {
    
    int n;
    cout << "digite um numero: ";
    cin >> n;

    asteristico(n);

    return 0;
}

