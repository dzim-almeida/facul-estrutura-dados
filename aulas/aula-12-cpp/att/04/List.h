// file: List.h
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "Node.h"

/**
 * @brief Representa a lista duplamente encadeada.
 * 
 * A classe lista apenas as implementações de cada funcão.
 * Abaixo uma descrição por sessões.
 */
class List {
    private:
        Node* head; // Nó sentinela
        int length; // tamanho da lista

        // Funções internas

        void removeNode(Node* node); // desliga um nó da lista e libera sua memória

    public:
        // Inicializador e destrutor da classe

        List(); // Construtor padrão
        List(const List& lst); // Construtor de cópia
        ~List(); // Destrutor
        
        // =================================================================================================

        // Funções principais

        void push_back(int key); // inserir ao final
        int pop_back(); // deletar o último elemento
        void insertAfter(int key, int k); // inserir após
        void remove(int key); // remove um elemento
        void removeAll(int key); // remove todas as intâncias de um elemento
        void concat(List& lst); // junta duas listas em uma só

        // =================================================================================================

        // Funções auxiliares

        void print(); // mostrar a lista
        void printReverse(); // mostrar a lista invertida
        bool empty(); // verifica se a lista está vazia
        int size(); // retorna o tamanho da lista
        void clear(); // limpa todos os elementos da lista

        // =================================================================================================
        
        // Sobrecarga de operadores
        List operator=(const List& lst);
        bool operator==(const List& lst);
        bool operator!=(const List& lst);
};

#endif