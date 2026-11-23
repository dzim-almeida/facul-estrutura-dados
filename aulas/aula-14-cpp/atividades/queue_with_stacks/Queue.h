#ifndef QUEUE_STACK
#define QUEUE_STACK
#include <vector>
using namespace std;

class Queue
{
private:
    vector<int> qstart;
    vector<int> qend;

    void enqueue();

public:
    void push(int val);
    void pop();
    int front();
};
#endif