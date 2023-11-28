#include "LinkedList.hpp"

using namespace std;


// Search for a specified key and return a pointer to that node
//MANDETORY_TODO: complete this function
// Given the key this function will find the node where the key is present
// If found it will return the node, else NULL
Node* LinkedList::searchList(int key) {

    Node* ptr = NULL;
    ptr = head;
    while (ptr->key != key ){
        ptr = ptr-> next;
    }
    return ptr;
}


// Add a new node to the list
//MANDETORY_TODO: complete this function
// This function will add a node with newKey after the prev node in the linked list
// if prev is null insertion is to be made at head
void LinkedList::insert(Node* prev, int newKey){
    // Node *head, * newPtr;
    //Check if head is Null i.e list is empty
    if(head == NULL){
        Node *tmp = new Node;
        tmp -> key = newKey;
        tmp ->next = NULL;
        head = tmp;
    }

    // if list is not empty, look for prev and append our node there
    else if(prev == NULL)
    {
        Node *tmp = new Node;
        tmp -> key = newKey;
        prev = head;
        prev -> next = NULL;
        head = tmp;
        tmp-> next = prev;
    }
    //general insertion
    else
    {
        
        Node *tmp = new Node;
        tmp -> key = newKey;
        tmp -> next = prev -> next;
        prev -> next = tmp;
    }
}


// OPTIONAL_TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values). Swap the Nodes
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false; 
   

    if (head == nullptr || head->next ==NULL){
        isSwapped = false;
    }
    else{
        Node *tmp = new Node;
        Node* tailPtr = head;
        Node* prevPtr;
        int count = 0;
        // retrieve the lastNode object
        while(tailPtr->next != NULL){
            prevPtr = tailPtr;
            tailPtr = tailPtr->next;
            count++;
        }

        //Get the Note
        if(count == 1){
            tmp = head;
            head = tailPtr;
            tailPtr = tmp;
            tailPtr -> next = NULL;
            head -> next = tailPtr;
            isSwapped = true;
        } else{
            tmp = head;
            head = tailPtr;
            head-> next = tmp -> next;
            tmp -> next = NULL;
            tailPtr = tmp;
            prevPtr -> next = tailPtr;
            isSwapped = true;
        }
    }
  
    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
    Node* temp = head;

    while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
    }

    cout<<temp->key<<endl;
}

