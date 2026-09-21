#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

// The matrix is stored in a 1d array, the representation of the matrix is as follows:
// 0 1 2 3
// 4 5 6 7
// 8 9 10 11
// is represented as a 1d array as follows:
// 0 1 2 3 4 5 6 7 8
// where the value at position [i][j] is stored in the array at position j + i*columns
// example: the value at position [1][2] is stored in the array at position 2 + 1*4 = 6

// The constructor allocates memory for the matrix and initializes the rows and columns attributes. The destructor frees the allocated memory. The get_value and set_value methods access and modify the values in the matrix, respectively. The print method displays the matrix in a formatted way.
Matrix::Matrix(int m, int n) : rows(m), columns(n), array(new int[m*n]) {};

// The destructor frees the memory allocated for the matrix.
Matrix::~Matrix() {
    delete[] array;
};

// set_value method assigns a new value to the cell at position [i][j] in the matrix. The value is stored in the 1D array at the calculated index.
void Matrix::set_value(int i, int j, int value) {array[j + i*columns] = value;}; // array[j + i*columns] is equal to *(array + (j + i*columns));

// get_rows method returns the number of rows in the matrix.
int Matrix::get_rows() {return rows;};

// get_columns method returns the number of columns in the matrix.
int Matrix::get_columns() {return columns;};

// get_value method returns the value stored in the cell at position [i][j] in the matrix. The value is retrieved from the 1D array at the calculated index.
int Matrix::get_value(int i, int j) {return array[j + i*columns];};

// print method displays the matrix in a formatted way. It iterates through the rows and columns, retrieves the values from the 1D array, and prints them with a width of 5 characters for alignment.
void Matrix::print() {
    int val;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            val = array[j + i*columns];
            cout << setw(5) << val;
        }
        cout << "\n";
    }
};

// Completar a implementação

// The matrix_sum function takes references to three Matrix objects: a, b, and c. It sums the values of matrices a and b and stores the result in matrix c. The function assumes that the dimensions of matrices a, b, and c are compatible for addition (i.e., they have the same number of rows and columns). The implementation iterates through each cell of the matrices, retrieves the values from a and b, adds them together, and sets the corresponding value in c.
void matrix_sum(Matrix& a, Matrix& b, Matrix& c) {
    for (int i = 0; i < a.get_rows(); ++i) {
        for (int j = 0; j < a.get_columns(); ++j) { 
            int sum = a.get_value(i, j) + b.get_value(i, j);
            c.set_value(i, j, sum);
        }
    }
}

// The matrix_multiply function takes references to three Matrix objects: a, b, and c. It multiplies matrices a and b and stores the result in matrix c. The function assumes that the number of columns in matrix a is equal to the number of rows in matrix b, which is a requirement for matrix multiplication. The implementation iterates through each cell of the resulting matrix c, calculates the dot product of the corresponding row from a and column from b, and sets the value in c.
void matrix_multiply(Matrix& a, Matrix& b, Matrix& c) {
    for (int i = 0; i < a.get_rows(); ++i) {
        for (int j = 0; j < b.get_columns(); ++j) {
            int sum = 0;
            for (int k =0; k < a.get_columns(); k++) {
                int product = a.get_value(i, k) * b.get_value(k, j);
                sum += product;
            }
            c.set_value(i, j, sum);
        }
    }
}