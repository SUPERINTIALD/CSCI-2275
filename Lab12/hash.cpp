// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //TODO: Search the list at that specific index and return the node if found
    // node * tmp = table
//     while(table[index] != NULL) {
	
//       if(table[index]->key == key)
//          return table[index];
			
//       //go to next cell
//       ++index;
		
//    }
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it at the head of this slot's list
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }

}

// TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if (table[i]) {
            cout << i << table[i]->key << " ";
        }
        // TODO: print all keys in slot i
        // for(auto x: table [i])
        //     cout << "-->"
        // cout << endl;
    }
    cout << endl;

 }
