#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#define COUNT 10

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
        printMovieInventoryHelper(node->rightChild);
    }

}

void MovieTree::showMovieCollection()
{//TODO
    if(root == NULL){
        return;
    }
    printMovieInventoryHelper(root);
}

void addLLNode(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating)
{
    LLMovieNode * m = new LLMovieNode;
    m->ranking = _ranking;
    m->title = _title;
    m->year = _year;
    m->rating = _rating;

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
    tmp->titleChar  = _title.at(0);
    tmp->parent = NULL;
    tmp-> leftChild = NULL;
    tmp -> rightChild = NULL;


    addLLNode(tmp, parentpointer, _ranking, _title, _year,_rating);


    return tmp;
}

TreeNode* MovieTree::addHelper(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating)
{
    int inputTitle = int (_title.at(0));
    if(root == NULL || root->titleChar == inputTitle){
        if (root == NULL){
            return createMovieNode(root, parentpointer, _ranking, _title, _year,_rating);
        }else{


            addLLNode(root, parentpointer, _ranking, _title, _year,_rating);
        }
        
        //Linked List application:
    }else if(int (root->titleChar) < inputTitle){
        root->rightChild = addHelper(root->rightChild, parentpointer, _ranking, _title, _year,_rating);
        root->rightChild->parent = root;
    }else if(int(root->titleChar) > inputTitle){
        root->leftChild = addHelper(root->leftChild, parentpointer, _ranking, _title, _year,_rating);
        root->leftChild->parent = root;
    }
return root;
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
    LLMovieNode * prev;
    LLMovieNode * tmp = node->head;
    while(tmp != NULL){
        prev = tmp;
        tmp = tmp -> next;
        delete prev;
    }
    node->head = NULL;
}

TreeNode* MovieTree::getSuccessor(TreeNode* node){
    //TODO
    TreeNode *tmp = node;
    while(tmp && tmp->leftChild != NULL){
        tmp = tmp->leftChild;
    }
    return tmp;
}

TreeNode* MovieTree::removeBSTNodeHelper(TreeNode* node, TreeNode* parent, char titleFirstLetter){
    //TODO
    
    if(node == NULL){
        return node;
    }
    //traverse left and right
    else if(titleFirstLetter < node->titleChar){        
        node->leftChild = removeBSTNodeHelper(node->leftChild, parent, titleFirstLetter);
         
    }else if(titleFirstLetter > node->titleChar){        
        node->rightChild = removeBSTNodeHelper(node->rightChild, parent, titleFirstLetter);
    }else{
        if(node->leftChild == NULL && node->rightChild == NULL){
            removeLLnodes(node);
            delete node;

            return NULL;
        }
        //First right child        
        else if(node->rightChild == NULL){
            TreeNode * tmp = node->leftChild;
            node->leftChild->parent = node->parent;
            removeLLnodes(node);
            delete node;

            return tmp;
        }
        // second for left child
        else if(node->leftChild == NULL){
            TreeNode * tmp = node->rightChild;
            node->rightChild->parent = node->parent; 
            removeLLnodes(node);
            delete node;

            return tmp;        
        }
        else {
            // if node has both children
            TreeNode * tmp = getSuccessor(node->rightChild);
            tmp->parent = node->parent;
            tmp->leftChild = node->leftChild;
            removeLLnodes(node);
            delete node;

            return tmp;
        }
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
    
    TreeNode * L = curr->leftChild;
    TreeNode * R = curr;
    if(R  == NULL || L == NULL){
        return;
    }else{
        R ->leftChild = L->rightChild;
        if(R ->leftChild != NULL){
            R ->leftChild->parent = R ;
        }
        L->parent = R->parent;
        if(R  == root){
            root = L;

        }else if(R  == R ->parent->rightChild){
            R ->parent->rightChild = L;
        }else{
            R ->parent->leftChild = L;
        }
        R ->parent = L;
        L->rightChild = R;
    }
}
