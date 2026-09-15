#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &vector, int n) {
    cout << "[";
    for (int x = 0; x < n; x++) {
        cout << vector[x];
        if (x != n-1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief Calcula a soma do triângulo de Pascal a partir de uma base
 * @param base o vetor que representa a base do triângulo
 * @param n o tamanho da base
 */
void sumTriangle(vector<int> &base, int n) {
    if (n <= 1) {
        printVector(base, n);
        return;
    } else {
        vector<int> newBase(n - 1);
        for (int i = 0; i < n - 1; i++) {
            newBase[i] = base[i] + base[i + 1];
        }
        sumTriangle(newBase, n - 1);
        printVector(base, n);
    }
}

int main() {
    int n; // Número de elementos do vetor
    cin >> n;

    vector<int> base(n); // Vetor de tamanho n
    
    
    for (int i = 0; i < n; i++) {
        cin >> base[i]; // Preenchendo o vetor com os valores fornecidos pelo usuário
    }

    sumTriangle(base, n);

    return 0;
}