#include <iostream>

using namespace std;

int main() {
    // Declara as variáveis
    int outPairs[50], animals, animal;

    cin >> animals;

    // Lê os pares de animais
    for (int i = 0; i < animals; i++) {
        cin >> animal;
        outPairs[i] = animal;
    }

    // Declara a variável para contar os pares de animais
    int pairs = 0;

    // Percorre o array de pares de animais
    for (int i = 0; i < animals; i++) {
        if (outPairs[i] == 0) {
            continue;
        }

        for (int j = i + 1; j < animals; j++) {
            if (outPairs[i] + outPairs[j] == 0) {
                outPairs[j] = 0;
                pairs++;
                break;
            }
        }
    }

    cout << pairs << endl;
    return 0;
}