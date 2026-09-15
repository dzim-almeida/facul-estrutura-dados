#include <iostream>
using namespace std;

/** 
 * @brief Calcula o fatorial de um número
 * @param n o número do qual calcular o fatorial
 * @return o fatorial de n
 */

int fatorial(int n) {
    if (n == 0 || n ==1) {
        return 1;
    }

    return n * fatorial(n-1);
}

int main() {
    int n;
    cout << "digite um numero: ";
    cin >> n;

    cout << "O fatorial de " << n << " é: " << fatorial(n) << endl;

    return 0;
}