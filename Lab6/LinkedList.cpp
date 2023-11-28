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


// TODO: SILVER PROBLEM (mandatory)
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }
  if (n == 0) {
       //todo
      Node* temp = new Node;
      temp = head;
      head= head -> next;
      delete temp;
      isDeleted = true;
    } 
     // Special case to delete the head
   
  
    //TODO
    if(n != 0 && n < 7){
      Node *pres = head;
      Node *prev = NULL;
      int i = 0;
      while(pres != NULL){
        if(i == n){
          break;
          }
        prev = pres;
        pres = pres -> next;
        i++;
      }
      prev-> next = pres-> next;
      delete pres;
      isDeleted = true;
    }else{
      isDeleted = false;
    }
    
	return isDeleted;
}

//TODO:GOLD PROBLEM (optional)
LinkedList::~LinkedList()
{
    cout<<"deleting network..."<<endl;
    
    // TODO 
    Node *pres = head;
    Node *prev = NULL;
    while(pres != NULL){
      prev = pres;
      pres = pres -> next;
      delete prev;
    }
    head = nullptr;
    cout << "final network:" << endl;
    printList();
}