#pragma once

#include<iostream>
#include<vector>
#include "hash.hpp"

using namespace std;


enum GITOP {init, add, rm, commit, checkout, status};

struct FileNode {
    string name;
    int version;
    FileNode* next = nullptr;
};

struct BranchNode {
    int commitID;
    string commitMessage = "";
    BranchNode* next = nullptr;
    BranchNode* previous = nullptr;
    FileNode* fileHead = nullptr;
};

//*** You can add helper functions if you desire ***//
class MiniGit {
private:    
    BranchNode* commitHead;
    int commits;
    HashTable* ht;

    bool modified = false;
    bool canCommit = true;

    BranchNode* workingCommit();
    
   

public:
    MiniGit();
    ~MiniGit();

    void init(int hashtablesize);
    string add(string fileName); //altered so that git add can return a string error message where if received, main_1 can ask for another file name
    void rm(string fileName);
    void search(string key);
    string commit(string msg);
    void checkout(string commitID);
    void printSearchTable();
    void printLLContents(); //TODO: Remove (this is for debug)
    bool isFileIdentical(string file1, string file2);
    
    
};