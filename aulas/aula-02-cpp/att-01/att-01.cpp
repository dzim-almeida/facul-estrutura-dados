#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // declarar variáveis
    double a, b, c, p, area;

    // ler os lados do triângulo
    cout << "Digite o valor do lado a: ";
    cin >> a;

    cout << "Digite o valor do lado b: ";
    cin >> b;

    cout << "Digite o valor do lado c: ";
    cin >> c;

    // calcular o semi-perímetro
    p = (a + b + c) / 2;

    // calcular a área usando a fórmula de Heron
    area = sqrt(p * (p-a) * (p-b) * (p-c));
    cout << fixed << setprecision(2) << area << endl;
    
    return 0;
}