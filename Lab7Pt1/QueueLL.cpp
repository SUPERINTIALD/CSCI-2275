#include "QueueLL.hpp"

QueueLL::QueueLL()
{
    data = LinkedList();
    head = 0;
    tail = 0;
    queueSize = 0;
}

// TODO: Silver Problem!
// Insert new values at the end of the queue
void QueueLL::enqueue(int value)
{
    Node * tmp = new Node;
    Node * lastPtr = NULL;

    // tmp -> key = value;
    // data.insert(lastPtr, tmp -> key);
    if(isEmpty()){
        tmp -> key = value;
        data.insert(lastPtr, tmp->key);
        lastPtr = tmp;
        tail++;
        // cout<<"kelvin 1" << endl;
    }else{
        lastPtr = data.searchByIndex(tail-1);
        tail++;
        // compare the pre's key value
        tmp -> key = value;
        data.insert(lastPtr, tmp->key);
        // cout<<"kelvin 2" << endl;
    }
    // lastPtr = tmp;
    // if(tmp->next == NULL){
    //     cout << "tmp is NULL"<< tmp->key <<endl;
    // } else {
    //     cout << "tmp is NONNULL"<< tmp->key << endl;
    // // }
    // if(lastPtr != NULL){
    //     cout << "LastPtr is NOtNULL"<< lastPtr->key <<endl;
    //     cout << lastPtr->next <<endl;
    // }
}

// TODO: Silver Problem!
// Delete values at the front of the queue
// Return the dequeued value
int QueueLL::dequeue()
{
    // TODO
    data.deleteAtIndex(head);
    // head++;
    tail--;
    return -1;
}

bool QueueLL::isEmpty()
{
    return head == tail;
}

void QueueLL::printQueue()
{
    data.printList();
}