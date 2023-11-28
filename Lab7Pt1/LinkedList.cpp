#include "LinkedList.hpp"

using namespace std;

// Search for a specified key and return a pointer to that node
// Given the key this function will find the node where the key is present
// If found it will return the node, else NULL
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}

Node* LinkedList::searchByIndex(int idx) {

    Node* ptr = head;
    int count = 0;
    while (ptr != NULL && count != idx)
    {
        ptr = ptr->next;
        count++;
    }
    return ptr;
}

void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
}



// Print the keys in your list
void LinkedList::printList(){

  if(head == NULL)
  {
      cout << "NULL" << endl;
      return;
  }
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}


// TODO: SILVER PROBLEM (mandetory)
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

     // Special case to delete the head
    if (n == 0) {
       //todo
        Node* temp = head->next;
        delete head;
        head = temp;
        return true;
    }

    Node *pres = head;
	Node *prev = NULL;
    int counter = 0;
    while(pres != NULL && counter != n)
    {
        prev = pres;
        pres = pres->next;
        counter++;
    }
    
    // If pres is null, then out of bounds
    if(pres == NULL)
    {
        cout << "Index out of bounds. Deletion failed." << endl;
    }
    else
    {
        prev->next = pres->next;
        delete pres;
        pres = nullptr;
        isDeleted = true;
    }

    //TODO
	return isDeleted;
}

//TODO:GOLD PROBLEM (optional)
LinkedList::~LinkedList()
{
    // Go through every node and delete it
    Node* prev;
    Node* pres = head;
    while(pres != NULL)
    {
        prev = pres;
        pres = pres->next;
        delete prev;
    }
    head = nullptr;
}