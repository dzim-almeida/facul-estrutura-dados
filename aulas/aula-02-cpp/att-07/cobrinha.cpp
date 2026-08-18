#include <iostream>
using namespace std;

int main() {
    // Definir as variaveis
    int q, x, y, aux_x, aux_y;
    string d;

    cin >> q >> d;
    cin >> x >> y;

    aux_x = x;
    aux_y = y;

    if (d == "U") {
        y--;
    } else if (d == "D") {
        y++;
    } else if (d == "L") {
        x--;
    } else if (d == "R") {
        x++;
    }

    for (int i = 1; i <= q; i++) {
        cout << x << " " << y << endl;

        x = aux_x;
        y = aux_y; 

        if (i != q) {
            cin >> aux_x >> aux_y;
        }
    }
    
    return 0;
}