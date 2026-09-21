#ifndef MATRIX_H
#define MATRIX_H

/**
 * @brief Representa uma matriz de valores inteiros.
 *
 * A matriz possui quantidade definida de linhas e colunas,
 * armazenando seus elementos em uma estrutura dinâmica.
 */
class Matrix {
    private:
        int rows;
        int cols;
        int **data;

    public:
        /**
         * @brief Cria uma matriz com dimensões especificadas.
         *
         * @param r Quantidade de linhas.
         * @param c Quantidade de colunas.
         */
        Matrix(int r, int c);

        /**
         * @brief Libera a memória utilizada pela matriz.
         */
        ~Matrix();

        /**
         * @brief Retorna o valor armazenado em uma posição.
         *
         * @param i Índice da linha.
         * @param j Índice da coluna.
         * @return Valor armazenado na posição informada.
         */
        int getPos(int i, int j);

        /**
         * @brief Define o valor de uma posição da matriz.
         *
         * @param i Índice da linha.
         * @param j Índice da coluna.
         * @param value Valor a ser armazenado.
         */
        void setPos(int i, int j, int value);

        /**
         * @brief Retorna a quantidade de linhas da matriz.
         *
         * @return Número de linhas.
         */
        int getRows();

        /**
         * @brief Retorna a quantidade de colunas da matriz.
         *
         * @return Número de colunas.
         */
        int getCols();
};

#endif