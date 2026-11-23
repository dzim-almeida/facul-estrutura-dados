#ifndef STACK
#define STACK
#include "Node.h"

class Stack {
    private:
        Node* head;
        int length;

    public:
        Stack() {
            head = new Node(0, nullptr);
            length = 0;
        }

        void push(int val) {
            if (empty()) {
                head->next = new Node(val, nullptr);
                length++;
                return;
            }

            Node* current_top = head->next;
            head->next = new Node(val, current_top);
            length++;
        }

        bool empty() {
            return length == 0;
        }
};

#endif