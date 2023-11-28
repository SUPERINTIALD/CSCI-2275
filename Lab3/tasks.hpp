#include <iostream>

using namespace std;

struct BankAccount 
{
    string accountOwner;
    float balance;
};

void task1(int &a); // TODO: update the parameter

void task2(BankAccount* account, string& name, int initialBalance);

void task3(BankAccount** arr);