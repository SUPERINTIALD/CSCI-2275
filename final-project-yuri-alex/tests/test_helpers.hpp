#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include "../code_1/hash.hpp"
#include "../code_1/miniGit.hpp"

using namespace std;

// TODO add detailed explanation on what the function should do
std::string exec(const char* cmd);
std::string readFileIntoString(std::string fileName);
string test_insert(string arr[], int len, int tabSize);
string test_search(string arr[], int len, string search_key, int tabSize);
string test_add(string arr[], int len);
string test_rm(string arr[], int len, string rm);
string test_commit(string arr[], int len, string msg);
string test_rm(string arradd[], int len, string delmsg);
#endif // TEST_H__