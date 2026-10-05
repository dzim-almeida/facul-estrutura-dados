#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include "stdexcept"

class Vector {
    private:
        int* m_list;
        int m_size;
        int m_capacity;

    public:
        Vector() {
            m_size = 0;
            m_capacity = 16;
            m_list = new int[m_capacity];
        }; // Cria uma lista sequencial com 16 espaços

        Vector(const Vector& other) {
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_list = new int[m_capacity];

            for (int i = 0; i < m_size; i++) {
                m_list[i] = other.m_list[i];
            }
        }; // Construtor de cópia

        int size() const {return m_size;}; // Retorna o tamanho da lista

        int capacity() const {return m_capacity;}; // Retorna o conteiner reservado na memória
        
        bool empty() const {return m_size == 0;}; // Retorna true se size = 0, ou falso caso contrário

        int& at(int idx) {
            if (idx >= 0 && idx < m_size) {
                return m_list[0];
            }
            throw std::out_of_range("index inválido");
        }; // Retorna uma referência na posição da lista verificando se um index é válido

        const int& at (int idx) const {
            if (idx >= 0 && idx < m_size) {
                return m_list[0];
            }
            throw std::out_of_range("index inválido");
        }; // Retorna uma referência na posição da lista verificando se um index é válido. (const function)

        void reserve(int n) {
            if (n >= m_capacity) {
                int* aux = new int[n];
                for (int i = 0; i < m_size; i++) {
                    aux[i] = m_list[i];
                }
                delete[] m_list;
                m_list = aux;
                m_capacity = n;
            }
        }; // Reserva um conteiner na memória com capacidade >= n

        void push_back(const int& value) {
            if (m_size == m_capacity) {
                reserve(2*m_capacity);
            }

            m_list[m_size] = value;
            m_size++;
        }; // Adiciona um elemento ao final da lista, se estourar o tamanho do conteiner dobra a capacidade
        
        void pop_back() {
            if (m_size < 1) {
                return;
            }

            m_size--;
        }; // Diminui o tamanho do vetor

        

        void insert(int idx, int value) {
            if (idx >= 0 || idx < m_size) {
                push_back(m_list[m_size - 1]); // Adiciona o ultimo valor em size + 1, abrindo espaço para o novo elemento
                for (int k = (m_size - 1); k > idx; k--) {
                    m_list[k] = m_list[k-1];
                }
                m_list[idx] = value;
            }
        }; // adiciona um elemento no vetor, abrindo o espaço para o novo elemento

        void replaceAt(int idx, int value)  {
            at(idx) = value;
        }; // Reposiciona um valor no index

        void removeAt(int idx) {
            if (idx >= 0 || idx < m_size) {
                for (int k = idx; k < (m_size - 1); k++) {
                    m_list[k] = m_list[k+1];
                }
                pop_back();
            }
        }; // Remove um valor no index

        void removeAll(int value) {
            int idx = 0;
            while (idx < m_size) {
                if (m_list[idx] == value) {
                    removeAt(idx);
                } else {
                    idx++;
                }
            }
        }; // remove todas as ocorrências de um elemento na lista

        int& operator[](int index) {
            return m_list[index];
        }; // Retorna a referência de uma posição sobrecarregando o acesso com '[]'

        const int& operator[](int index) const {
            return m_list[index];
        }; // Retorna a referência de uma posição sobrecarregando o acesso com '[]' (const function)

        bool operator==(const Vector& v) {
            if (m_size != v.m_size) {
                return false;
            }

            for (int i = 0; i < m_size; i++) {
                if (m_list[i] != v.m_list[i]) {
                    return false;
                }
            }

            return true;
        }; // Verifica se 2 vetores são iguais

        bool operator<(const Vector& v) {
            if (m_size >= v.m_size) {
                return false;
            }

            for (int i = 0; i < m_size; i++) {
                if (m_list[i] >= v.m_list[i]) {
                    return false;
                }
            }

            return true;
        }; // Verifica a Vector é menor que v

        bool operator>(const Vector& v) {
            if (m_list < v.m_list) {
                return false;
            }

            return true;
        }; // Verifica se Vector é maior que v

        bool operator<=(const Vector& v) {
            if (m_list < v.m_list) {
                return true;
            }
            if (m_list == v.m_list) {
                return true;
            }

            return false;
        }; // Verifica se Vector é menor ou igual

        bool operator>=(const Vector& v) {
            if (m_list > v.m_list) {
                return true;
            }
            if (m_list == v.m_list) {
                return true;
            }

            return false;
        }; // Verifica se Vector é maior ou igual
 
         ~Vector() {
            delete[] m_list;
        }; // Destrutor
};

#endif