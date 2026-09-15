#include <iostream>
using namespace std;

// Verifica se é possível subir escadas de 1 em 1 degrau
// Retorna quantas vezes isso é possível fazer
int upStairsWithOneStep(int n) {
    if (n < 1) {
        return 0;
    }

    return upStairsWithOneStep(n - 1) + 1;
}

// Verifica se é possível subir escadas de 3 em 3 degraus
// Retorna quantas vezes isso é possível fazer
int upStairsWithThreeSteps(int n) {
    if (n < 3) {
        return 0;
    }

    return upStairsWithThreeSteps(n - 3) + 1;
}

// Verifica se é possível subir escadas de 1 em 1 degrau ou de 3 em 3 degraus
// Retorna quantas vezes isso é possível fazer
int upStairs(int n) {
    return upStairsWithOneStep(n) + upStairsWithThreeSteps(n);
}

int main() {
    // Recebe o número de degraus da escada
    int n;
    cin >> n;

    // Calcula quantas vezes é possível subir a escada
    int result = upStairs(n);

    cout << result << endl;

    return 0;
}