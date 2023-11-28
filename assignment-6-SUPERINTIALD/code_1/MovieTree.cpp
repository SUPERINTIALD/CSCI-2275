#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}
MovieTree::MovieTree() {
    root = nullptr;
}
void destroyNode(MovieNode * currNode){
    if(currNode ==nullptr){
        return;
    }
    destroyNode(currNode->left);
    destroyNode(currNode->right);
    delete currNode;
}
MovieTree::~MovieTree() {
    destroyNode(root);
}
void printMovieInventoryHelper(MovieNode * currNode){
    if(currNode != nullptr){
        printMovieInventoryHelper(currNode->left);
        cout << "Movie: " << currNode->title << " (" << currNode->rating << ")" << endl;
        printMovieInventoryHelper(currNode->right);
    }
}
void MovieTree::printMovieInventory() {
    if(root == nullptr){
        cout << "Tree is Empty. Cannot print." << endl;
        return;
    }
    printMovieInventoryHelper(root);
}
MovieNode * createMovieNode(int ranking, string title, int year, float rating){
    MovieNode * tmp = new MovieNode;
    tmp->title = title;
    tmp->ranking = ranking;
    tmp->year = year;
    tmp->rating = rating;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}
MovieNode * addMovieNodeHelper(MovieNode * currNode, int ranking, string title, int year, float rating){
    if(currNode == nullptr){
        return createMovieNode(ranking, title, year, rating);
        //Compares string titles
    } else if(currNode -> title.compare(title) < 0){
        currNode->right = addMovieNodeHelper(currNode->right, ranking, title, year, rating);
    } else if(currNode -> title.compare(title) > 0){
        currNode->left = addMovieNodeHelper(currNode->left, ranking, title, year, rating);
    }
    return currNode;
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
    root = addMovieNodeHelper(root, ranking, title, year, rating);
}
MovieNode * findMovieHelper(MovieNode * currNode, string title){
    if(currNode == nullptr){
        return nullptr;
    }
    if(currNode->title == title){
        return currNode;
    }
    if(currNode->title > title){
        return findMovieHelper(currNode->left, title);
    }
    return findMovieHelper(currNode->right, title);
}
void MovieTree::findMovie(string title) {
    MovieNode * tmp = findMovieHelper(root, title);
    if(tmp == nullptr){
        cout << "Movie not found." << endl;
    }else{
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << tmp->ranking << endl;
        cout << "Title  :" << tmp->title << endl;
        cout << "Year   :" << tmp->year << endl;
        cout << "Rating :" << tmp->rating << endl;
    }
}
void queryMoviesHelper(MovieNode * currNode, float rating, int year){
    if(currNode != nullptr){
        if(currNode->rating >= rating && currNode->year > year){
            cout << currNode->title << " (" << currNode->year << ") " << currNode->rating << endl;
        }
        queryMoviesHelper(currNode->left, rating, year);     
        queryMoviesHelper(currNode->right, rating, year);
    }
}
void MovieTree::queryMovies(float rating, int year) {
    if(root == nullptr){
        cout << "Tree is Empty. Cannot query Movies." << endl;
        return ;
    } 
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryMoviesHelper(root, rating, year);

}
void averageRatingHelper(MovieNode* currNode, int &numMovies, float &totalRating){
    if(currNode == nullptr){
        return;
    }
    averageRatingHelper(currNode->left, numMovies, totalRating);
    numMovies++;
    totalRating += currNode->rating;
    averageRatingHelper(currNode->right, numMovies, totalRating);

}
void MovieTree::averageRating() {
    if(root == nullptr){
        cout << "Average rating:0.0" << endl;
        return;
    }else{
       int numMovies = 0;
        float totalRating = 0;
        averageRatingHelper(root, numMovies, totalRating);
        float average = (totalRating/numMovies);
        cout << "Average rating:"<< average << endl; 
    }
    
}
void printLevelNodesHelper(MovieNode * currNode, int level){
    if(currNode == nullptr){
        return;
    }
    if(level == 0){
        cout << "Movie: " << currNode->title << " (" << currNode->rating << ")" << endl;
    }else if(level > 0){
        printLevelNodesHelper(currNode -> left, level - 1);
        printLevelNodesHelper(currNode -> right, level - 1);
    }
}
void MovieTree::printLevelNodes(int level) {
    printLevelNodesHelper(root, level);
}