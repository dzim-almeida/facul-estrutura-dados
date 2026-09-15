#include <iostream>
using namespace std;

int maximum(int vet[], int init, int end) {
    if (init >= end) {
        return vet[init];
    }

    int max1 = (vet[init] >= vet[end]) ? vet[init] : vet[end];
    int max2 = maximum(vet, init + 1, end - 1);
    
    if (max1 >= max2) {
        return max1;
    } else {
        return max2;
    }
}

int main() {
    int vet[7] = {1, 2, 3, 23, 4, 5, 6};
    
    cout << "Maximum value in the array: " << maximum(vet, 0, 5) << endl;
    
    return 0;
}