#ifndef QUEUELL_HPP
#define QUEUELL_HPP
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

class QueueLL
{
    private:
        LinkedList data;
        int head;
        int tail;
        int queueSize;
    public:
        QueueLL();
        void enqueue(int value);
        int dequeue();
        bool isEmpty();
        void printQueue();
};
#endif