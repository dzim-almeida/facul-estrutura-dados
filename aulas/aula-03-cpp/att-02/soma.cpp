#include <iostream>
using namespace std;

int soma(int n) {
    if (n == 1){
        return 1;
    } else {
        return n + soma(n - 1);
    }
}

int soma2(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    cout << "digite um numero positivo: ";
    cin >> n;
    cout << "A soma dos numeros de 1 a " << n << " é: " << soma(n) << endl;
    return 0;
}

