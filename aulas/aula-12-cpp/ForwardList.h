#ifndef FORWARD_LIST
/** 
    @brief Estrutura que define um Nó
*/
#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}

    // ~Node() {
    //     std::cout << "nó " << value << " deletado" << std::endl;
    // }
};

/**
    @brief Classe que define uma Lista Encadeada
*/
class ForwardList {
    private:
        Node* head;
        unsigned int size = 0;

    public:
        ForwardList() : head(new Node(0)) {}

        void print() {
            Node* current = head;

            while (current->next != nullptr) {
                std::cout << current->next->value << " ";
                current = current->next;
            }

            std::cout << "\n";
        }

        void pushFront(int value) {
            Node* newNode = new Node(value);
            newNode->next = head->next;
            head->next = newNode;
            size++;
        }

        void popFront() {
            if (head->next == nullptr) {
                return;
            }

            Node* removed = head->next;
            head->next = head->next->next;
            delete removed;
            size--;
        }

        void pushBack(int value) {
            if (head->next == nullptr) {
                head->next = new Node(value);
                size++;
                return;
            }
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = new Node(value);
            size++;
        }

        void popBack() {
            Node* current = head;

            if (current->next == nullptr) {
                return;
            }
            
            while (current->next->next != nullptr) {
                current = current->next;
            }
            Node* deleted = current->next;
            current->next = nullptr;
            delete deleted;
            size--;
        }

        int& value() {
            return head->next->value;
        }

        const int& value() const {
            return head->next->value;
        }

        bool empty() const {
            return head->next == nullptr;
        }

        int getSize() const {
            return size;
        }

        void deleteNodes() {
            while (head->next != nullptr) {
                Node* next = head->next->next;
                delete head->next;
                head->next = next;
            }
            size = 0;
        }

        ForwardList& operator=(ForwardList& lst) {
            deleteNodes();

            if (lst.head->next == nullptr) {
                return *this;
            }

            Node* lstHead = lst.head->next;
            while (lstHead->next != nullptr) {
                this->head->next = lstHead;
                lstHead = lstHead->next;
                head = head->next;
                size++;
            }
            return *this;
        }

        ~ForwardList() {
            deleteNodes();
        }

        class Interator {
            private:
                Node* ptr;

            public:
                Interator(Node* ptr) : ptr(ptr) {}

                bool operator==(const Interator& it) const {
                    return this->ptr==it.ptr;
                }

                bool operator!=(const Interator& it) const {
                    return this->ptr!=it.ptr;
                }
                
                void operator++() const {

                }
        };

        Interator begin() {
            return Interator(this->head);
        }

        Interator end() {
            return Interator(nullptr);
        }
};

#endif