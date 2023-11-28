// CPP program to implement hashing with chaining
#include<iostream>
#include <vector>
#include "hash.hpp"


using namespace std;

HashNode* HashTable::createNode(string key, HashNode* next)
{
    HashNode* n = new HashNode;
    n->key = key;
    n->next = next;
    return n;
}

HashTable::HashTable(int bsize)
{
    table = new HashNode*[bsize];
    tableSize = bsize;
    for (int i = 0; i < tableSize; i++) table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++) sum += int(s[i]);
    return sum % tableSize;
}

// TODO Complete this function
//function to search
HashNode* HashTable::searchItem(string key)
{
    int index = hashFunction(key);
    HashNode* root = table[index];
    if (root == nullptr) return nullptr;
    while (root != nullptr){
        if (root->key == key) break;
        else root = root->next;
    }

    return root;
    
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(string key, int cNum)
{
    HashNode* search = searchItem(key);
    if (search == nullptr){
        int index = hashFunction(key);
        HashNode* node = createNode(key, table[index]);
        node->commitNums.push_back(cNum);
        table[index] = node;
    } else {
        search->commitNums.push_back(cNum);
        return true;
    }

    return false;
}


// function to display hash table //
/* assume the table size is 5. For each bucket it will show the 
** the string key and the commit number (separated by comma) within parenthesis
** e.g. the key is science and commit numbers are 1 and 4. The key science
** is hashed to position 0. So the print format will be-

0|| science(1,4,)
1|| 
2|| 
3|| 
4|| difficult(3,)-->fun(2,)-->computer(0,)

*/
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++){
        cout << i << "|| ";
        if (table[i] != nullptr){
            HashNode* c = table[i];
            while (c != nullptr){
                cout << c->key << "(";
                for (int j = 0; j < c->commitNums.size(); j++) 
                    cout << c->commitNums[j] << ((j < c->commitNums.size() - 1) ? "," : ""); //ternary operator: returns first expression if true
                c = c->next;
                cout << ")" << (c == nullptr ? "" : "-->");
            }
        }
        cout << endl;
    }
}
