#include "Matrix.h"

/**
 * @brief Inicializa uma matriz com as dimensões informadas.
 *
 * Aloca dinamicamente memória para as linhas e colunas da matriz.
 *
 * @param r Quantidade de linhas.
 * @param c Quantidade de colunas.
 */
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }
}

/**
 * @brief Libera toda a memória alocada para a matriz.
 *
 * Primeiro libera cada linha e, em seguida, libera o vetor
 * responsável por armazenar os ponteiros das linhas.
 */
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }

    delete[] data;
}

/**
 * @brief Consulta o valor armazenado em uma posição da matriz.
 *
 * @param i Índice da linha.
 * @param j Índice da coluna.
 * @return Valor armazenado na posição informada.
 */
int Matrix::getPos(int i, int j) {
    return data[i][j];
}

/**
 * @brief Altera o valor armazenado em uma posição da matriz.
 *
 * @param i Índice da linha.
 * @param j Índice da coluna.
 * @param value Novo valor da posição.
 */
void Matrix::setPos(int i, int j, int value) {
    data[i][j] = value;
}

/**
 * @brief Retorna a quantidade de linhas da matriz.
 *
 * @return Número de linhas.
 */
int Matrix::getRows() {
    return rows;
}

/**
 * @brief Retorna a quantidade de colunas da matriz.
 *
 * @return Número de colunas.
 */
int Matrix::getCols() {
    return cols;
}