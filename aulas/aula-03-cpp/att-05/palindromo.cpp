#include <iostream>
using namespace std;

/** 
 * @brief Verifica se uma palavra é um palíndromo.
 * @param word A palavra a ser verificada.
 * @param start O índice do primeiro caractere da substring a ser verificada.
 * @param end O índice do último caractere da substring a ser verificada.
 * @return true se a palavra for um palíndromo, false caso contrário.
 */

bool palindrome(string word, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (word[start] != word[end]) {
        return false;
    }

    return palindrome(word, start + 1, end - 1);
}

int main() {
    string word;
    cout << "Digite uma palavra: ";
    cin >> word;

     int wordLen = word.length();

    if (palindrome(word, 0, wordLen - 1)) {
        cout << "A palavra é um palíndromo." << endl;
    } else {
        cout << "A palavra não é um palíndromo." << endl;
    }

    return 0;
}