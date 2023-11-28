#include <iostream>
#include "QueueLL.hpp"

using namespace std;

int main()
{
    cout << "Test 1: basic enqueue and dequeue" << endl;
    QueueLL q1 = QueueLL();
    q1.enqueue(1);
    q1.dequeue();
    cout << "Expected: NULL" << endl;
    cout << "Got: ";
    q1.printQueue();
    cout << endl;
    
    cout << "Test 2: more extensive operations" << endl;
    QueueLL q2 = QueueLL();
    q2.enqueue(5);
    q2.enqueue(7);
    q2.enqueue(1);
    q2.enqueue(3);
    q2.dequeue();
    q2.enqueue(4);
    q2.enqueue(8);
    q2.enqueue(2);
    q2.dequeue();
    q2.enqueue(6);
    q2.dequeue();
    cout << "Expected: 3 -> 4 -> 8 -> 2 -> 6" << endl;
    cout << "Got: ";
    q2.printQueue();
    cout << endl;
    
    // Test 3: Edge case - dequeue empty queue
    QueueLL q3 = QueueLL();
    cout << "Expected: Dequeue failed, queue already empty\nNULL" << endl;
    cout << "Got: ";
    q3.dequeue();
    q3.printQueue();
    
}