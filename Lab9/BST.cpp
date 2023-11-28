#include "MovieTree.hpp"
#include <iostream>
#include <fstream>


using namespace std;
/* ------------------------Starter Code function---------- */
LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

void preorderTraversalHelper(TreeNode * root) {
	if (root == NULL) 
    {
		return;
	}
    cout << root->titleChar << " ";
    preorderTraversalHelper(root->leftChild);
    preorderTraversalHelper(root->rightChild);
}

void MovieTree::preorderTraversal() {
	preorderTraversalHelper(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* --------------------------Constructor---------------------------- */
MovieTree::MovieTree()
{
    root = NULL;
}

/* --------------------------Destructor---------------------------- */

void MovieTree:: rdelete(TreeNode *node)
{
	//TODO
    if(node == NULL){
        return;
    }
    rdelete(node->leftChild);
    //delete the linked list.
    LLMovieNode * tmp = node->head;
    LLMovieNode * prev;
    while(tmp != NULL){
        prev = tmp;
        tmp = tmp->next;
        delete prev;
    }
    rdelete(node->rightChild);
    delete node;
}

MovieTree::~MovieTree()
{
	//TODO
    rdelete(root);
}

/* -------------------------showMovieCollection----------------------------- */
void MovieTree::printMovieInventoryHelper(TreeNode* node)
{
	//TODO
    if(node != NULL){
        printMovieInventoryHelper(node->leftChild);

        if (node->head != NULL){
            cout << "Movies starting with letter: " << node->titleChar << endl;
        }
        
        LLMovieNode * tmp = node->head;
        if(tmp == NULL){
            // cout << "nothing in path" << endl;
        }else {
            while(tmp != NULL){ 
                cout << " >> " << tmp->title << " " << tmp->rating << endl;
                tmp = tmp->next;
            }
        }
      


        //Connects the tmp Node to the Binary Node's Linkedlist head.
        // LLMovieNode * tmp = node->head;
        //Traverse the Linked List And sort them by alphabetical order.
        // while(tmp != NULL){
        //     tmp = tmp-> next;
        //     cout << " >> " << tmp->title << " " << tmp->rating << endl;

        // }
        printMovieInventoryHelper(node->rightChild);
    }

}

void MovieTree::showMovieCollection()
{//TODO
    if(root == NULL){
        // cout << "Inventory NULL" << endl;
        return;
    }
    printMovieInventoryHelper(root);
}


// LLMovieNode * searchLLNode(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating){

//     LLMovieNode * m = root->head;
//     if(m == NULL){
//         return NULL;
//     }else{
//         if((m->title > _title) && (m->title < _title)){
            
//         }
//     }
// }

void addLLNode(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating)
{
    LLMovieNode * m = new LLMovieNode;
    m->ranking = _ranking;
    m->title = _title;
    m->year = _year;
    m->rating = _rating;

 // Add inserting node at a point for alphabetical later.
    if(root->head == NULL || root->head->title >= m->title){
        m->next = root->head;
        root->head = m;
    }else{
        LLMovieNode * tmp = root->head;
        while(tmp->next != NULL && tmp->next->title < m->title){
            tmp = tmp->next;
        }
        m->next = tmp->next;    // LLMovieNode * m = new LLMovieNode;
        tmp->next = m;
    }

}

/* --------------------------insertMovie---------------------------- */
TreeNode * createMovieNode(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating){
    TreeNode * tmp = new TreeNode;
    // Set new Node's title char to first node of the Title character? Binary Big
    tmp->titleChar  = _title.at(0);
    tmp->parent = NULL;
    tmp-> leftChild = NULL;
    tmp -> rightChild = NULL;


    addLLNode(tmp, parentpointer, _ranking, _title, _year,_rating);


    return tmp;
}

TreeNode* MovieTree::addHelper(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating)
{

    // int icreationCounter = 0;
    // cout << "0" << endl;
    int inputTitle = int (_title.at(0));


    // icreationCounter++;
    if(root == NULL || root->titleChar == inputTitle){
        

        // int rootTitle = int(root->head->title.at(0));
        // inputTitle == rootTitle
        // cout << "kelvin counter"  << endl;

        if (root == NULL){
            return createMovieNode(root, parentpointer, _ranking, _title, _year,_rating);
        }else{


            addLLNode(root, parentpointer, _ranking, _title, _year,_rating);
        }
        
        //Linked List application:
    }else if(int (root->titleChar) < inputTitle){
        // root->parent = parentpointer;
        root->rightChild = addHelper(root->rightChild, parentpointer, _ranking, _title, _year,_rating);
        root->rightChild->parent = root;
        // root->rightChild->head = addLLNode
        // addLLNode(root->rightChild, parentpointer, _ranking, _title, _year,_rating);
    }else if(int(root->titleChar) > inputTitle){
        // root->parent = parentpointer;
        // cout << "3" << endl;
        root->leftChild = addHelper(root->leftChild, parentpointer, _ranking, _title, _year,_rating);
        root->leftChild->parent = root;
        // addLLNode(root->leftChild, parentpointer, _ranking, _title, _year,_rating);
    }
return root;


	//TODO
//parentpointer = prev for binary search tree
//Bascially Get root, or currNode, add if letter is < or > than 0 for the first character
// the title. Then add node within left or right. Set Node...
    // LLMovieNode * tmp = root->head;
    // while()
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	//TODO
    root = addHelper(root, NULL, ranking, title, year, rating);
}

/* ------------------------removeMovieRecord------------------------------ */

void MovieTree::removeMovieRecord(std::string title)
{
    TreeNode * binaryNode;
    
    binaryNode = searchCharNode(title.at(0));   
    if(binaryNode == NULL){
        cout << "Movie not found."<<endl;
    }else{
        LLMovieNode * tmp = binaryNode->head;
        if(binaryNode->head == NULL){
            cout << "Movie not found."<< endl;
        }else if(binaryNode->head->title == title){
            LLMovieNode * tmp = binaryNode->head;
            binaryNode->head = binaryNode->head->next;
            delete tmp;
            // cout << "kelvin=" << binaryNode->titleChar << endl;
            // if (binaryNode->head == NULL){
            //     cout << "null" << endl;
            // }else{
            //     cout << "not null" << endl;
            // }


            // binaryNode = NULL;
        }else{
            LLMovieNode * prev;
            while(tmp->next != NULL){
                    if(tmp->title == title){
                        break;
                    }
                    prev = tmp;
                    tmp = tmp->next;
                }
            prev->next = tmp->next;
            delete tmp;
        }
    }
}


/* ------------------------removeBSTNode------------------------------ */
void MovieTree::removeLLnodes(TreeNode* node){
    //TODO
    // TreeNode * binaryNode;
    // binaryNode = searchCharNode(node->titleChar);   
    LLMovieNode * prev;
    LLMovieNode * tmp = node->head;
    while(tmp != NULL){
        prev = tmp;
        tmp = tmp -> next;
        delete prev;
    }
    node->head = NULL;
    // delete tmp;
    
    // node = NULL;
}

TreeNode* MovieTree::getSuccessor(TreeNode* node){
    //TODO
    // return NULL;
    TreeNode *tmp = node;
    while(tmp && tmp->leftChild != NULL){
        tmp = tmp->leftChild;
    }
    return tmp;
}

TreeNode* MovieTree::removeBSTNodeHelper(TreeNode* node, TreeNode* parent, char titleFirstLetter){
    // //TODO

    // // return NULL;

    searchCharNode(node->titleChar);
    if(node == NULL){
        return node;
    }
    //traverse left and right
    if(titleFirstLetter < node->titleChar){
        node->leftChild = removeBSTNodeHelper(node->leftChild, parent, titleFirstLetter);
    }else if(titleFirstLetter > node->titleChar){
        node->rightChild = removeBSTNodeHelper(node->rightChild, parent, titleFirstLetter);

    }else{
        if(node->leftChild == NULL && node->rightChild == NULL){
            removeLLnodes(node);
            delete node;
            return NULL;
        }
        //First child left
        else if(node->leftChild == NULL){
            TreeNode * tmp = node->rightChild;
            removeLLnodes(node);
            delete node;
            return tmp;
        // child right
        }else if(node->rightChild == NULL){
            TreeNode * tmp = node->leftChild;
            removeLLnodes(node);
            delete node;
            return tmp;
        }
        // booth children
        TreeNode * tmp = getSuccessor(node->rightChild);
        node->titleChar = tmp->titleChar;
        node->rightChild = removeBSTNodeHelper(node->rightChild, parent, node->titleChar);
    }
    return node;
}

void MovieTree::removeBSTNode(char titleFirstLetter){
    //TODO
    root = removeBSTNodeHelper(root, NULL, titleFirstLetter);
}


/* --------------------------rightRotation---------------------------- */
void MovieTree::rightRotation(TreeNode* curr)
{
	//TODO
}
