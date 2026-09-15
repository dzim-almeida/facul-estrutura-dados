#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Conta quantas vezes um caractere aparece em uma string
 * @param str a string na qual contar o caractere
 * @param n o tamanho da string
 * @param c o caractere a ser contado
 * @return o número de vezes que o caractere aparece na string
 */
int contaCaracteres(string str, int n, char c) {
    if (n == 0) {
        return 0;
    }
    
    if (str[n - 1] == c) {
        return 1 + contaCaracteres(str, n - 1, c);
    } else {
        return contaCaracteres(str, n - 1, c);
    }
}

int main() {
    string phrase; // A frase na qual contar o caractere
    char character; // O caractere a ser contado

    getline(cin, phrase); // Lê a frase
    cin >> character; // Lê o caractere

    cout << contaCaracteres(phrase, phrase.length(), character) << endl; // Imprime o número de vezes que o caractere aparece na frase
    return 0;
}