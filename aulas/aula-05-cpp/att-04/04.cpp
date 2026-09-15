#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void _printVector(const vector<int> &arr, int n, int order) {
    cout << "[ ";
    if (order == -1) {
        for (int x = n - 1; x >= 0; x--) {
            cout << arr[x] << " ";
        }
    } else {
        for (int x = 0; x < n; x++) {
            cout << arr[x] << " ";
        }
    }
    cout << "]" << endl;
}

int sum(const vector<int> &arr, int n) {
    if (n == 0) {
        return 0;
    }
    
    return arr[n-1] + sum(arr, n-1);
}

int mult(const vector<int> &arr, int n) {
    if (n == 0) {
        return 1;
    }
    
    return arr[n-1] * mult(arr, n-1);
}

int min(const vector<int> &arr, int n) {
    if (n == 1) {
        return arr[0];
    }

    int min_n = min(arr, n-1);

    return (arr[n-1] <= min_n) ? arr[n-1] : min_n;
}

void inv(vector<int> &arr, int init, int end) {
    if (init >= end) {
        return;
    }

    int pivot = arr[init];
    arr[init] = arr[end];
    arr[end] = pivot;

    inv(arr, init+1, end-1);
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> numbers; // Vetor com elementos de tamanho n
    int value;
    
    while (ss >> value)
        numbers.push_back(value);
    
    int n = numbers.size();

    cout << "vet : ";
    _printVector(numbers, n, 1);
    cout << "rvet: ";
    _printVector(numbers, n, -1);
    cout << "sum : " << sum(numbers, n) << endl;
    cout << "mult: " << mult(numbers, n) << endl;
    cout << "min : " << min(numbers, n) << endl;
    cout << "inv : ";
    inv(numbers, 0, n-1);
    _printVector(numbers, n, 1);

    return 0;
}