#include "Queue.h"

void Queue::push(int val) {
    qend.push_back(val);
    enqueue();
}
void Queue::pop() {
    qstart.pop_back();
    enqueue();
}

int Queue::front() {
    return qstart.back();
}

void Queue::enqueue() {
    if (qstart.size() != 0) {
        return;
    }

    while (qend.size() != 0) {
        qstart.push_back(qend.back());
        qend.pop_back();
    }
}
