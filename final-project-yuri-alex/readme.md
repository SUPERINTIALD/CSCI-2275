# CSCI 2275 – Data Structures - Final Project

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. **Also, include the names of the team-members/authors**. 

Authors: Alex McDonald & Yuri Fung

### Objectives
This program is a version control ssytem also known as a revision control system in tracks changes in the source code. It will let users manage their documents/projects easiy by using simple commands. This program is used by having a doublly linked list, single linked list, and hashtables. By "committing" changes along with a brief description from the user, it can commit/record changes to the document. 

### Overview

### *Hash* Class Specificitions:
  **HashNode* HashTable::createNode(string key, HashNode* next)**

+ This function creates a node in the HashTable, based off of the key and then implements its next HashNode. 

  **HashTable::HashTable(int bsize)**

+ Creates a HashTable of bsize.

  **unsigned int HashTable::hashFunction(string s)**

+ Calculates the alphanumeric value to a numerical value, which then is assigned to an index in the Hastable. 

  **HashNode* HashTable::searchItem(string key)**

+ Searches the Item based on a key in the Hashtable. 

  **bool HashTable::insertItem(string key, int cNum)**

+ Inserts a value in the Hashtable and sets a value cNum. If there is nothing in the HashTable it will create a new HashNode and insert it into the empty HashTable.

  **void HashTable::printTable()**
  
+ This will print all the values of the HashTable, 
  
### *miniGit* Class Specificitions:

  **MiniGit::MiniGit()**

+ Constuctor of the miniGit. 

  **MiniGit::~MiniGit()**

+ Deconstructor of the miniGit. This will delete all the Files, HashTables, and Branches.

  **void MiniGit::init(int hashtablesize)**

+ This will initialize the Hashtable and create a new BranchNode. 

  **BranchNode* MiniGit::workingCommit()**

+ This will set the user onto the current commited work that is updated. Or that the user wants to be on. 
+ If there is no change, then no commit will be made.

  **void MiniGit::add(string fileName)**

+ This will add the file into the current working commited work for them to commit. 

  **void MiniGit::rm(string fileName)**

+ This will delete individual Files by searching for the FileName.

  **void MiniGit::printSearchTable()**

+ This will print the git's contents: the Commit ID, File, and Branch.

  **void MiniGit::search(string key)**

+ This will search the commit ID and find past commited work.

  **string MiniGit::commit(string msg)**
+ This is the actual working commit in which it saves the files/branch, and updates the working commit. This then adds another commit file.
  **void MiniGit::checkout(string commitID)**
+ This function will get the specfic branch based on the Commit ID by using the search function. Then in the minigit directory it sets it to the working commit directory and update all files. All in all, it lets you navigate between branches.



### Output 
+ Below shows the code that should be printed:

+ This is the actual working commit in which it saves the files/branch, and updates the working commit. This then adds another commit file.

  **void MiniGit::checkout(string commitID)**

+ This function will get the specfic branch based on the Commit ID by using the search function. Then in the minigit directory it sets it to the working commit directory and update all files. The commit ID can either be "-" or a positive or negative number. If it is positive, git will checkout that ID. If it is negative, git will checkout x previous commits. If it is "-", this acts the same as "git checkout -1", where it checks out the most recent commit, like an "undo." (Friendly Commits)


### How to Use this Program 
+ Below shows the code that should be printed:

Select a numerical option:
+=====Main Menu=========+
 1. init 
 2. add 
 3. rm 
 4. commit 
 5. checkout
 6. search
 7. quit 
+-----------------------+
#>


+ #1: The initializes the program, by creating a new BranchNode and HashTable, commitID, and number of commits made to 0.If you already initialized it beforehand, it will give you an error that you initialized it already.


+ #2: The add function is what files you would like to add to commit. You can you add the names of the files after you press "2". Then after you can write the name of the file. If the name of the file you have entered doesn't exist in the file, it will keep repeating until you enter a right one, or write "cancel". Furthermore, if you have not initialized the program, if will return an error message saying to use Option #1.


+ #3: This function will delete the files. You can type in the file name, and it will delete the file, and reattach the remaining files if needed. Furthermore, if it cannot find the file that it needs to delete, it will return an error. Finally, if you have not initialized the program, if will return an error message saying to use Option #1.
+#4: This will commit your current added files, and save the files. Everytime you save it creates a unique Commit ID that you can refer back to when needed.


+ #5: This fucntion will get the specific branch you are on, and you can enter your commitID, in which will return the commits you have made. You can put a positive number then it will checkout that specific commit from the commit ID. If it is a negative number, it will result in a way like an undo.


+ #6: This function will search the commit ID messages, and see if it exists.


+ #7: Quits the program.