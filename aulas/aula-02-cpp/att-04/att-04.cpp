#include <iostream>

using namespace std;

// Função para calcular a diferença absoluta entre dois números
int calDiff(int a, int b) {
    int diff = a - b;

    if (diff < 0) {
        diff *= -1;
    }

    return diff;
}

int main() {
    // Declara as variáveis
    int players, a, b, winner, bestDiff = 1000;

    // Solicita o número de jogadores
    cin >> players;

    // Loop para ler os valores de cada jogador e determinar o vencedor
    for (int i = 0; i < players; i++) {
        cin >> a >> b;

        // Verifica se a pedra tem ao menos 10 metros
        if (a < 10 || b < 10) {
            continue;
        }
        
        // Calcula a diferença entre os valores de a e b
        int diff = calDiff(a, b);

        // Atualiza o vencedor se a diferença for menor que a melhor diferença encontrada até agora
        if (diff < bestDiff) {
            bestDiff = diff;
            winner = i;
        }
    }

    if (bestDiff == 1000) {
        cout << "sem ganhador" << endl;
    } else {
        cout << winner << endl;
    }
    
    return 0;
}