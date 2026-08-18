#include <iostream>

using namespace std;

int main() {
    // Declara as variáveis
    string nome;
    int idade;

    // Solicita o nome e a idade do usuário
    cout << "Digite seu nome: ";
    cin >> nome;

    cout << "Digite sua idade: ";
    cin >> idade;

    string classificacao;

    // Valida a idade e classifica o usuário
    if (idade >= 0 && idade < 12) {
        classificacao = "crianca";
    } else if (idade < 18) {
        classificacao = "jovem";
    } else if (idade < 65) {
        classificacao = "adulto";
    } else if (idade < 1000) {
        classificacao = "idoso";
    } else {
        classificacao = "mumia";
    }

    cout << nome << " eh " << classificacao << endl;

    return 0;
}