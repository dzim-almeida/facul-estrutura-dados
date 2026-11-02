// file: list.cpp
// desc: Implementação das funções de List.h
#include <iostream>
#include <stdexcept>
#include <string>
#include "List.h"
#include "Node.h"
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
 * @brief Inicializa a List como cópia de outra lista.
 *
 * Construtor de cópia. Necessário para que a lista possa ser copiada
 * (ex.: dentro de um vector) sem que duas listas dividam os mesmos nós.
 * Cada elemento de lst é inserido em ordem em um novo nó.
 *
 * @param lst lista a ser copiada
 */
List::List(const List& lst) {
    this->head = new Node(0, nullptr, nullptr);
    this->length = 0;

    Node* current = lst.head->next; // primeiro elemento de lst
    for (int i = 0; i < lst.length; i++) {
        push_back(current->value);
        current = current->next;
    }
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
// Funções internas

/**
 * @brief Desliga um nó da lista e libera sua memória.
 *
 * Centraliza a remoção de um nó para ser reaproveitada por pop_back, remove e removeAll.
 * casos com um ou dois elementos são tratados especialmente, pois nessa lista
 * um nó sozinho não possui prev e next.
 *
 * @param node nó que será removido (precisa pertencer à lista)
 */
void List::removeNode(Node* node) {

    // CASE 01 - lista com único elemento, a lista fica vazia
    if (size() == 1) {
        head->next = nullptr;
    }

    // CASE 02 - lista com dois elementos, o que sobra fica sem prev e next
    else if (size() == 2) {
        Node* other = node->next; // elemento que permanece na lista
        other->next = nullptr;
        other->prev = nullptr;
        head->next = other;
    }

    // DEFAULT - religa o anterior com o próximo, "pulando" o nó removido
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // se o removido era o primeiro, o head passa a apontar para o seguinte
        if (head->next == node) {
            head->next = node->next;
        }
    }

    delete node;
    length--;
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

/**
 * @brief Remove o último elemento da lista e retorna seu valor.
 *
 * O último elemento é o prev do primeiro (ou o próprio primeiro, se estiver sozinho).
 *
 * @return int valor do elemento removido
 * @throws invalid_argument caso a lista esteja vazia
 */
int List::pop_back() {
    // CASE 01 - verifica lista vazia, não há o que remover
    if (empty()) {
        throw invalid_argument("Lista não tem elementos válidos.");
    }

    // CASE 02 - lista com único elemento, ele mesmo é o último
    Node* last = head->next;

    // DEFAULT - o último elemento é o anterior ao primeiro
    if (size() > 1) {
        last = head->next->prev;
    }

    int val = last->value; // guarda o valor antes de liberar o nó
    removeNode(last);
    return val;
}

/**
 * @brief Insere um novo nó com valor key após o k-ésimo nó da lista.
 *
 * Os nós são contados a partir de 1. O nó cabeça é considerado a posição 0,
 * então k = 0 insere o elemento no início da lista.
 *
 * @param key valor a ser inserido na lista
 * @param k posição do nó após o qual o novo nó será inserido (0 até size())
 * @throws invalid_argument caso k não seja uma posição válida
 */
void List::insertAfter(int key, int k) {
    // CASE 01 - verifica se a posição k existe na lista
    if (k < 0 || k > size()) {
        throw invalid_argument("Indique um elemento válido! Quantidade de elementos: " + to_string(size()));
    }

    // CASE 02 - inserir após o último é o mesmo que inserir no final (cobre também a lista vazia)
    if (k == size()) {
        push_back(key);
        return;
    }

    // CASE 03 - inserir após o nó cabeça, o novo elemento vira o primeiro da lista
    // insere no final e "gira" o head: como a lista é circular, o último passa a ser o primeiro
    if (k == 0) {
        push_back(key);
        head->next = head->next->prev;
        return;
    }

    // DEFAULT - percorre até o k-ésimo nó e encaixa o novo nó entre ele e o seguinte
    Node* current = head->next; // primeiro elemento
    int count = 1;
    while (count != k) {
        current = current->next;
        count++;
    }

    Node* node = new Node(key, current, current->next); // node a ser inserido
    current->next->prev = node;
    current->next = node;
    length++;
}

/**
 * @brief Remove da lista a primeira ocorrência de key.
 *
 * A lista é percorrida uma única vez a partir do primeiro elemento.
 * Caso key não exista, a lista não é alterada.
 *
 * @param key valor a ser removido
 */
void List::remove(int key) {
    Node* current = head->next; // primeiro elemento

    // percorre exatamente length nós, evitando dar voltas na lista circular
    for (int i = 0; i < length; i++) {
        if (current->value == key) {
            removeNode(current);
            return;
        }
        current = current->next;
    }
}

/**
 * @brief Remove da lista todas as ocorrências de key.
 *
 * O próximo nó é guardado antes de cada remoção, pois o nó atual pode ser liberado.
 *
 * @param key valor a ser removido
 */
void List::removeAll(int key) {
    int total = length; // quantidade de nós a visitar (length muda durante as remoções)
    Node* current = head->next; // primeiro elemento

    for (int i = 0; i < total; i++) {
        Node* next = current->next; // guarda o próximo antes de um possível delete
        if (current->value == key) {
            removeNode(current);
        }
        current = next;
    }
}

/**
 * @brief Concatena a lista lst ao final da lista atual.
 *
 * Os nós de lst não são copiados, eles são religados ao final desta lista.
 * Ao final, lst fica apenas com o seu nó cabeça (vazia).
 *
 * @param lst lista que será adicionada ao final
 */
void List::concat(List& lst) {
    // CASE 01 - concatenar com ela mesma ou com lista vazia não altera nada
    if (this == &lst || lst.empty()) {
        return;
    }

    // CASE 02 - lista atual vazia, basta "pegar" os nós de lst
    if (empty()) {
        head->next = lst.head->next;
        length = lst.length;
    }

    // DEFAULT - liga o último desta lista ao primeiro de lst e o último de lst ao primeiro desta
    else {
        Node* first = head->next; // primeiro elemento desta lista
        Node* last = size() == 1 ? first : first->prev; // último elemento desta lista
        Node* lstFirst = lst.head->next; // primeiro elemento de lst
        Node* lstLast = lst.size() == 1 ? lstFirst : lstFirst->prev; // último elemento de lst

        last->next = lstFirst;
        lstFirst->prev = last;
        lstLast->next = first;
        first->prev = lstLast;
        length += lst.length;
    }

    // lst deixa de ter elementos, restando apenas o nó cabeça
    lst.head->next = nullptr;
    lst.length = 0;
}

// =================================================================================================



// =================================================================================================
// Funções auxiliares

/**
 * @brief Retorna o número de elementos da lista.
 *
 * O nó cabeça não é contado.
 *
 * @return int quantidade de elementos
 */
int List::size() {
    return length;
}

/**
 * @brief Verifica se a lista está vazia.
 *
 * @return true se a lista não tiver elementos
 * @return false caso contrário
 */
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
        head->next = nullptr; // head volta a não apontar para ninguém
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
        cout << "[ " << head->next->value << " ]" << endl;
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



// =================================================================================================
// Sobrecarga de operadores

/**
 * @brief Faz a lista atual receber uma cópia de lst.
 *
 * Os elementos antigos são liberados e os de lst são copiados em novos nós.
 * A auto-atribuição (a = a) é ignorada para não apagar a própria lista.
 *
 * @param lst lista a ser copiada
 * @return List cópia da lista resultante
 */
List List::operator=(const List& lst) {
    // CASE 01 - auto-atribuição, nada a fazer
    if (this == &lst) {
        return *this;
    }

    // DEFAULT - limpa a lista atual e copia cada elemento de lst em ordem
    clear();

    Node* current = lst.head->next; // primeiro elemento de lst
    for (int i = 0; i < lst.length; i++) {
        push_back(current->value);
        current = current->next;
    }

    return *this;
}

/**
 * @brief Verifica se duas listas são iguais.
 *
 * São iguais quando têm o mesmo tamanho e o k-ésimo elemento de uma
 * é igual ao k-ésimo elemento da outra.
 *
 * @param lst lista a ser comparada
 * @return true se as listas forem iguais
 * @return false caso contrário
 */
bool List::operator==(const List& lst) {
    // CASE 01 - tamanhos diferentes já tornam as listas diferentes
    if (length != lst.length) {
        return false;
    }

    // DEFAULT - compara elemento a elemento, andando nas duas listas ao mesmo tempo
    Node* current = head->next; // primeiro elemento desta lista
    Node* other = lst.head->next; // primeiro elemento de lst
    for (int i = 0; i < length; i++) {
        if (current->value != other->value) {
            return false;
        }
        current = current->next;
        other = other->next;
    }

    return true;
}

/**
 * @brief Verifica se duas listas são diferentes.
 *
 * Reaproveita o operador == e nega o resultado.
 *
 * @param lst lista a ser comparada
 * @return true se as listas forem diferentes
 * @return false caso contrário
 */
bool List::operator!=(const List& lst) {
    return !(*this == lst);
}

// =================================================================================================
