#include <iostream>

using namespace std;

int main() {
    // Declara as variáveis
    int bookFigures, baruelFigs[100], baruelFigures, fig;
    bool figsInBook[50];

    cin >> bookFigures >> baruelFigures;

    // Inicializa o array de figurinhas do livro
    for (int i = 0; i < bookFigures; i++) {
        figsInBook[i] = false;
    }

    // Percorre a quantidade de figurinhas que o usuário tem
    for (int i = 0; i < baruelFigures; i++) {
        cin >> fig;

        baruelFigs[i] = fig;
    }

    // Inicializa a variável que indica se há figurinhas repetidas
    bool haveRepeatedFigs = false;

    // Percorre o array de figurinhas do Baruel
    for (int i = 0; i < baruelFigures; i++) {
        // Verifica se a figurinha do Baruel está no livro
        bool alreadyInBook = figsInBook[baruelFigs[i] - 1];

        if (!alreadyInBook) {
            // Marca a figurinha como presente no livro
            figsInBook[baruelFigs[i] - 1] = true;

            // Marca a figurinha como já presente no livro
            baruelFigs[i] = 0;

            continue;
        }

        haveRepeatedFigs = true;
    }

    // Imprime as figurinhas que o Baruel tem que não estão no livro
    if (!haveRepeatedFigs) {
        cout << "N" << endl;
    } else {
        bool first = true;

        for (int i = 0; i < baruelFigures; i++) {
            if (baruelFigs[i] != 0) {
                if (!first) {
                    cout << " ";
                }

                cout << baruelFigs[i];
                first = false;
            }
        }

        cout << endl;
    }

    // Inicializa a variável que indica se o livro está completo
    bool bookNotCompleted = false;

    // Imprime as figurinhas que faltam no livro
    bool first = true;

    for (int i = 0; i < bookFigures; i++) {
        if (!figsInBook[i]) {
            bookNotCompleted = true;

            if (!first) {
                cout << " ";
            }

            cout << i + 1;
            first = false;
        }
    }

    if (!bookNotCompleted) {
        cout << "N" << endl;
    } else {
        cout << endl;
    }

    return 0;
}