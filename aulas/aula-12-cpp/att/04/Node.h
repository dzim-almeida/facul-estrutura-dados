// file: Node.h
#ifndef NODE_H
#define NODE_H

/**
 * @brief Representa um nó da estrutura de dados.
 * 
 * Armazena um valor e os ponteiros para nós relacionados.
 */
struct Node {
    int value; // Valor do nó
    Node* next; // Nó seguinte
    Node* prev; // Nó anterior

    // Contructor do Node
    Node(int val, Node* prev, Node* next) {
        this->value = val;
        this->next = next;
        this->prev = prev;
    }
};


#endif