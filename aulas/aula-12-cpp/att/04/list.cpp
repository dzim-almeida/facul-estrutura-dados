// file: list.cpp
// desc: Implementação das funções de List.h
#include <iostream>
#include "List.h"
#include "Node.h"
#include "stdexcept"
using namespace std;

// =================================================================================================
// Incializador e destrutor
/**
 * @brief Inicializa a List com valores válidos
 * 
 * Construtor padrão
 */
List::List() {
    this->head = new Node(0, nullptr, nullptr);
    this->length = 0;
}

/**
 * @brief Destroi o objeto List
 * 
 * Destrutor padrão
 */
List::~List() {
    clear();
    delete head;
}

// =================================================================================================



// =================================================================================================
// Funções principais

/**
 * @brief Insere um elemento no final da lista.
 * 
 * O elemento inserido é devidamente linkado com um prev e next.
 * casos "empty" ou listas com único elemento são tratados especialmente.
 * 
 * @param key valor a ser inserido na lista
 */
void List::push_back(int key) {

    // CASE 01 - verifica lista vazia, criando node sem prev e next
    if (empty()) { 
        head->next = new Node(key, nullptr, nullptr);
        length++;
        return;
    }

    // CASE 02 - verifica lista com único elemento, linkando prev e next
    if (size() == 1) { 
        Node* next = head->next; // primeiro elemento
        Node* node = new Node(key, next, next); // node a ser inserido
        next->next = node;
        next->prev = node;
        length++;
        return;
    }

    // DEFAULT - conexão de novos node depois de uma estrutura já montada
    Node* next = head->next; // primeiro elemento
    Node* prev = head->next->prev; // último elemento

    Node* node = new Node(key, prev, next); // node a ser inserido
    prev->next = node;
    next->prev = node;
    length++;
}

int List::pop_back() {
    if (empty()) {
        throw invalid_argument("Lista não tem elementos válidos.");
    }

    if (size() == 1) {
        Node* node = head->next;
        int val = node->value;
        delete node;
        length--;
        return val;
    }
    
    if (size() == 2) {
        Node* node = head->next;
        Node* prev = node->prev;
        
        node->next = nullptr;
        node->prev = nullptr;

        int val = prev->value;
        delete prev;
        length--;
        return val;
    } else {
        Node* node = head->next->prev;
        node->prev->next = head->next;
        head->next->prev = node->prev;

        int val = node->value;
        delete node;
        length--;
        return val;
    }   
}

void List::insertAfter(int key, int k) {
    if (empty()) {
        throw invalid_argument("Lista não tem elementos válidos!");
    }

    if (size() < k) {
        throw invalid_argument("Indique um elemento válido! Quantidade de elementos: " + k);
    }

    Node* current = head->next;
    int count = 1;
    while (count != k) {
        current = current->next;
        count++;
    }

    current->next = new Node(key, current, current->next);
    length++;
}

void List::remove(int key) {
    if (empty()) {
        return;
    }
    
    if (size() == 1) {
        if (head->next->value == key){
            Node* deleted = head->next;
            head->next = nullptr;
            delete deleted;
            length--;
        }
        return;
    }

    Node* current = head->next;
    do {
        if (current->value == key) {
            Node* next = current->next;
            Node* prev = current->prev;
            next->prev = current->prev;
            prev->next = current->next;
            delete current;
            length--;
            return;
        }
    } while (current != head->next);
}

// =================================================================================================



// =================================================================================================
// Funções auxiliares

int List::size() {
    return length;
}

bool List::empty() {
    return length == 0;
}


/**
 * @brief Deleta todos os elementos da lista.
 * 
 * Os elementos são deletados tratando vazamentos de memória.
 * casos "empty" ou listas com único elemento são tratados especialmente.
 */
void List::clear() {
    // CASE 01 - Verifica lista vazia, retornando em caso positivo
    if (empty()) {
        return;
    }

    // CASE 02 - Verifica se lista tem apeanas 1 elemento, deletando de forma única
    if (size() == 1) {
        delete head->next; // Deleta o único elemento
        length--;
        return;
    }

    // DEFAULT - Deleta os elementos limpando ponteiros do primeiro e último elemento
    Node* next = head->next; // primeiro elemento
    next->prev->next = nullptr; // limpando ponteiros das pontas da lista
    next->prev = nullptr;

    // Delete de cada elemento a partir do início da lista
    while (head->next != nullptr) {
        Node* deleted = head->next; // elemento deletado
        head->next = deleted->next; // atualiza início da lista
        delete deleted; // deleta elemento
        length--;
    }
}

/**
 * @brief Imprime os valores inscritos na lista em ordem.
 * 
 * Função percorre todos os elementos verificando se voltou para o início.
 */
void List::print() {
    // CASE 01 - verifica se a lista está vazia
    if (empty()) { 
        cout << "[ ]" << endl;
        return;
    }

    // CASE 02 - verifica se a lista tem apenas um elemento
    if (size() == 1) { 
        cout << "[ " << head->next->value << " ]" << endl;
        return;
    }

    // DEFAULT - lista com mais de um elemento
    cout << "[ ";

    Node* current = head->next; // primeiro elemento
    do {
        cout << current->value << " ";
        current = current->next;
    } while(current != head->next); // verifica se current voltou ao início
    
    cout << "]" << endl;
}

/**
 * @brief Imprime os valores inscritos na lista em ordem inversa.
 * 
 * Função percorre todos os elementos verificando se voltou para o final.
 */
void List::printReverse() {
    // CASE 01 - verifica se a lista está vazia
    if (empty()) {
        cout << "[ ]" << endl;
        return;
    }

    // CASE 02 - verifica se a lista tem apenas um elemento
    if (size() == 1) {
        cout << "[ " << head->next << "]" << endl;
        return;
    }

    // DEFAULT - lista com mais de um elemento
    cout << "[ ";

    Node* current = head->next->prev; // último elemento
    do {
        cout << current->value << " ";
        current = current->prev;
    } while(current != head->next->prev); // verifica se current chegou ao último elemento
    
    cout << "]" << endl;
}

// =================================================================================================
