#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>

using namespace std;

#define CAPACITY 10

class Stack
{
    private:
        int data[CAPACITY];
        int top;
    public:
        Stack();
        void push(int value);
        char pop();
        bool isFull();
        bool isEmpty();
        string isBalanced(string toCheck);
};
#endif