#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

#include "miniGit.hpp"
#include <vector>

MiniGit::MiniGit() {
    fs::remove_all(".minigit");
    fs::create_directory(".minigit");
    commitHead = nullptr;
}

MiniGit::~MiniGit() {   
    BranchNode* c = commitHead;
    while (c != nullptr){
        FileNode* f = c->fileHead;
        while (f != nullptr){
            FileNode* temp = f->next;
            delete f;
            f = temp;
        }
        BranchNode* temp2 = c->next;
        delete c;
        c = temp2;
    }
}

void MiniGit::init(int hashtablesize) {
    if (commitHead != nullptr){
        cout << "Already initialized!" << endl;
        return;
    }
    ht = new HashTable(hashtablesize);
    BranchNode* initial = new BranchNode;
    initial->commitID = 0;
    commitHead = initial; //creates the working commit node to add files
    commits = 0;
    cout << "Successfully initialized." << endl;
}

BranchNode* MiniGit::workingCommit(){
    if (commitHead == nullptr) return nullptr;
    BranchNode* working = commitHead;
    while (working->next != nullptr) working = working->next;
    return working;
}

string minigitName(string name, int version){
    if (name[0] == '.' && name[1] == '.' && name.size() > 3){
        name[0] = 'o'; name[1] = 'o'; //remove .. allowing files outside of build directory. '..' -> 'oo'
    }
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == '/') name[i] = '.';
    }
    return ".minigit/" + to_string(version) + "_" + name;
}

string MiniGit::add(string fileName) {
    BranchNode* working = workingCommit();
    if (working == nullptr){cout << "Error: Git is uninitialized! (Use Option #1)" << endl; return "success";}
    else if (!canCommit) {
        cout << "You are not on the most recent commit! Use checkout HEAD (Option #6)." << endl;
        return "success";
    }

    ifstream file;
    file.open(fileName);
    if (!file.is_open()) return "File '" + fileName + "' does not exist!";
    file.close();


    FileNode* f = new FileNode;
    f->version = 0;
    f->name = fileName; 
    //in .minigit: file name is "f->version + '_' + f->name". Ex: fn = "C:/User/abc.txt" ver = 2, .minigit name = "2_C:/User/abc.txt"
    
    if (working->fileHead == nullptr) working->fileHead = f;
    else{
        FileNode* c = working->fileHead;
        while (c != nullptr){
            if (c->name == fileName){
                if (working->previous != nullptr){
                    FileNode* pc = working->previous->fileHead;
                    while (pc != nullptr && pc->name != fileName) pc = pc->next;
                    if (pc != nullptr){
                        if (isFileIdentical(pc->name, minigitName(pc->name, pc->version))){
                            return "No changes made to file " + fileName + "!";
                        } else {
                            c->version = c->version + 1;
                            modified = true;
                            return "success";
                        }
                        
                    } else {
                        c->version = c->version + 1;
                        modified = true;
                        return "success";
                    }
                } else return "Already added file " + fileName + "!";

                //c->version = c->version + 1;
            }
            else if (c->next == nullptr){ //new file added
                FileNode* f = new FileNode;
                f->version = 0;
                f->name = fileName;
                c->next = f;
                break;
            }
            c = c->next;
        }
        //TODO: save the file in .minigit
    }

    cout << "Added file " << fileName << endl;
    modified = true;
    return "success";
}

void MiniGit::rm(string fileName) {
BranchNode * c = commitHead;
    //gets most recent commit node;
    if(c == nullptr){
       cout << "Error: Git is uninitialized! (Use Option #1)" << endl;
       return;
    }
    while(c->next != nullptr){
        c = c->next;
    }
    //Edge case if Git is uninitialized.
    
    //find the file Node (fileName) 
    FileNode* f = c->fileHead;
    FileNode* tmp = nullptr;
    //As long as file is not null, and keep going until it finds FileName.
   
    while (f != nullptr){   
        if(f->name == fileName){
            break;
        }
        tmp = f;
        f = f->next;   
    }
     if(f == nullptr){
        cout << "File doesn't exist" << endl;
        return;
    }
        //Once Found deletes the fileName and reconstructs the linkedlist, and edge cases when only 1 node is in the linkedList.

        //If fileName doesn't exit it couts, and returns nothing.
    // if the file is the only one, then it deletes and sets 
        if(tmp == NULL){
            c->fileHead = f->next;
        }else{
            tmp->next = f->next;
        }
        delete f;
        cout << "Deleted " + fileName << endl;
}


void MiniGit::printSearchTable()
{
    ht->printTable();
}

void MiniGit::printLLContents(){
    BranchNode* c = commitHead;
    cout << "Printing git contents:" << endl;
    while (c != nullptr){
        FileNode* f = c->fileHead;
        cout << "Commit #" << c->commitID << ": (Message: '" << c->commitMessage << "')" << endl;
        while (f != nullptr){
            cout << "  File: " << f->name << "  Version: " << f->version << endl;
            f = f->next;
        }
        c = c->next;
    }
    cout << "Hash table contents:" << endl;
    ht->printTable();
}


void MiniGit::search(string key)
{
    if (commitHead == nullptr){
        cout << "Error: Git is uninitialized! (Use option #1)" << endl;
        return;
    }
    HashNode* root = ht->searchItem(key);
    if (root != nullptr){
        cout << "Commit IDs with '" << key << "':";
        for (int i =0; i < int(root->commitNums.size()); i++) cout << " " << root->commitNums[i] << (i < root->commitNums.size()-1 ? "," : "");
        cout << endl;
    } else cout << "No commits with that keyword!" << endl;
}



string MiniGit::commit(string msg) {
    BranchNode* working = workingCommit();
    if (working == nullptr) return "_error";
    else if (!modified) {
        cout << "Error: No changes to any files were added, cannot commit. (Use option #2 to add changes)" << endl;
        return "";
    }
    else if (!canCommit){
        cout << "Error: You are not on the most recent commit! Use checkout HEAD (option #6)";
        return "";
    }
    if (msg.size() == 0) {
        cout << "Error: Enter a valid message" << endl;
        return "";
    }
    if (working->fileHead == nullptr){
        cout << "Error: Add files before you commit" << endl;
        return "";
    }

    working->commitMessage = msg;
    BranchNode* nw = new BranchNode;
    nw->commitMessage = "";
    nw->previous = working;
    nw->next = nullptr; 
    nw->commitID = (working->commitID) + 1;

    working->next = nw;
    
    FileNode* file = working->fileHead;
    FileNode* nfile = nullptr; //last node in new commit node's file LL:
    while (file != nullptr){
        FileNode* newfile = new FileNode;
        newfile->name = file->name;
        newfile->version = file->version;
        newfile->next = nullptr;

        //save file in .minigit
        ofstream mgfile;
        mgfile.open(minigitName(file->name, file->version));
        ifstream readfile;
        readfile.open(file->name); //name should already contain directory
        string line;
        while(getline(readfile, line, '\n')) mgfile << line << endl;
        mgfile.close();
        mgfile.close();

        if (nfile == nullptr) {
            nw->fileHead = newfile;
            nfile = newfile;
        }
        else {
            nfile->next = newfile;
            nfile = newfile;
        }

        file = file->next;
    }

    //TODO split message by white space and insert each
    string word;
    stringstream ss = stringstream(msg);
    while(getline(ss, word, ' ')) ht->insertItem(word, working->commitID);

    modified = false;
    return to_string(working->commitID); //should return the commitID of the commited DLL node
}

void MiniGit::checkout(string commitID) {

    if (commitID == "-") commitID = "-1";

    BranchNode* c = workingCommit();
    stringstream msg = stringstream("");
    if (c == nullptr){
        cout << "Error: Git is uninitialized! (Use Option #1)" << endl;
        return;
    }
    if (commitID == "HEAD" || commitID == "head"){
        if (c->previous == nullptr){
            cout << "Error: No commits have been made, already checked out on head commit." << endl;
            return;
        }
        c = c->previous;
        msg = stringstream("Returned to HEAD node.");
    } else {
        c = commitHead;
        try{
            stoi(commitID);
        } catch (...){
            cout << "Please enter a number." << endl;
            return;
        }

        int j = stoi(commitID);

        if (j >= 0){
            c = commitHead;
            while (c != nullptr){
                if (c->commitID == j) break;
                c = c->next;
            }
            if (c == nullptr || c->next == nullptr){ //already checked out on working node
                cout << "Error: No commits with id #" << commitID << endl;
                return;
            }
        } else { //go back j commits
            j *= -1;
            c = workingCommit();
            for (int i = 0; i < j; i++){
                if (c->previous != nullptr)c = c->previous;
                else{
                    cout << "Error: Not enough commits to go back by " << j << endl;
                    return;
                }
            }
        }
        msg << "Checked out Commit #" << (c->commitID);
    }

    canCommit = c->commitID == workingCommit()->previous->commitID;

    FileNode* file= c->fileHead;
    while (file != nullptr){
        ofstream wfile;
        wfile.open(file->name);
        ifstream readfile;
        readfile.open(minigitName(file->name, file->version));
        string line;
        while (getline(readfile, line, '\n')){
            wfile << line << endl;
        }
        wfile.close();
        readfile.close();

        file = file->next;
    }

    cout << msg.str() << endl;


}

bool MiniGit::isFileIdentical(string file1, string file2){
    ifstream stream1;
    stream1.open(file1);
    vector<string> file1_lines;
    if (stream1.is_open()){
        string line;
        while (getline(stream1, line, '\n')) file1_lines.push_back(line);
        stream1.close();
    } else {
        cout << "not identical 1" << endl;
        return false;
    }
    
    ifstream stream2;
    stream2.open(file2);
    vector<string> file2_lines;
    if (stream2.is_open()){
        string line;
        while(getline(stream2, line, '\n')) file2_lines.push_back(line);
        stream2.close();
    } else {
        cout << "not identical 2" << endl;
        return false;
    }

    if (file1_lines.size() != file2_lines.size()) return false;
    for (int i = 0; i < file1_lines.size(); i++){
        if (file1_lines[i] != file2_lines[i]) return false;
    }
    return true;
}
