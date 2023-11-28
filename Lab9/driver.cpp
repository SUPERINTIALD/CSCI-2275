#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10



int main()
{
    int arr[]= {50,12,21,10,60,30,5,100,22,55};
    int len = 10;
    

    BST tree;
    for(int i=0;i<len;i++)
    {
        tree.addNode(arr[i]);
    }
    cout<< "Starting Tree:"<<endl;
    tree.print2DUtil(1);
    
    // Delete Node Test Cases
    
    // Leaf node -- 22
    tree.deleteNode(22);
    cout<< "deleting 22:"<<endl;
    tree.print2DUtil(1);
    
    // Subtree node, 1 child -- 10
    tree.deleteNode(10);
    cout<< "deleting 10:"<<endl;
    tree.print2DUtil(1);
    
    // Subtree node, 2 children -- 60
    tree.deleteNode(60);
    cout<< "deleting 60:"<<endl;
    tree.print2DUtil(1);
    
    // Root node -- 50
    tree.deleteNode(50);
    cout<< "deleting 50:"<<endl;
    tree.print2DUtil(1);
}
