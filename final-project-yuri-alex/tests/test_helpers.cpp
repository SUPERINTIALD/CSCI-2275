#include <gtest/gtest.h>
#include "test_helpers.hpp"

#include "../code_1/hash.hpp"
#include "../code_1/miniGit.hpp"


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string readFileIntoString(std::string fileName){
	std::string line, out;
  	ifstream A;
  	A.open(fileName);
  	if(!A){throw std::runtime_error("could not open file: " + fileName);}
	while(getline(A,line)){
		out = out+line+"\n";
	}
	return out;
}

string test_insert(string arr[], int len, int tabSize)
{
    
    testing::internal::CaptureStdout();
    HashTable* ht = new HashTable(tabSize);
    
    for(int i=0;i<len;i++)
    {
        ht->insertItem(arr[i],i);
    }
    
    ht->printTable();
    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_search(string arr[], int len, string search_key, int tabSize){
    testing::internal::CaptureStdout();
    HashTable* ht = new HashTable(tabSize);
    for (int i = 0; i < len; i++) ht->insertItem(arr[i], i);

    HashNode* root = ht->searchItem(search_key);
    if (root != nullptr){
        cout << "Commit IDs with '" << search_key << "':";
        for (int i =0; i < int(root->commitNums.size()); i++) cout << " " << root->commitNums[i] << (i < root->commitNums.size()-1 ? "," : "");
        cout << endl;
    } else cout << "No commits with that keyword!" << endl;

    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_add(string arr[], int len){
    testing::internal::CaptureStdout();
    MiniGit git;
    git.init(5);

    for (int i = 0; i < len; i++){
        string a = git.add(arr[i]);
        cout << "(" << a << ")" << endl;
    }

    git.printLLContents();

    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_rm(string arradd[], int len, string delmsg){
    testing::internal::CaptureStdout();
    MiniGit git;
    git.init(5);
    for(int i = 0; i < len; i++){
        git.add(arradd[i]);
    }
    git.rm(delmsg);
    git.printLLContents();
    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_commit(string arr[], int len, string msg){
    testing::internal::CaptureStdout();
    MiniGit git;
    git.init(5);

    for (int i = 0; i < len; i++) git.add(arr[i]);

    git.commit(msg);

    git.printLLContents();

    string output = testing::internal::GetCapturedStdout();
    return output;
}
