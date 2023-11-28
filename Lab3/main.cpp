#include <iostream>
#include "tasks.hpp"

using namespace std;

int main()
{
    cout << "Task 1: Increment a Reference" << endl;
    int a = 5;
    task1(a);
    cout << "Expected: 6                       | Got: " << a << endl;
    int b = 1010101;
    task1(b);
    cout << "Expected: 1010102                 | Got: " << b << endl;
    cout << endl;
    
    cout << "Task 2: Create a Bank Account" << endl;
    string name1 = "Elmo";
    string name2 = "Cookie Monster";
    string name3 = "Elmo's Goldfish Dorothy";
    BankAccount acct1;
    task2(&acct1, name1, 500);
    cout << "Expected: Elmo                    | Got: " << acct1.accountOwner << endl;
    cout << "Expected: 500                     | Got: " << acct1.balance << endl;
    BankAccount acct2;
    task2(&acct2, name2, 5000);
    cout << "Expected: Cookie Monster          | Got: " << acct2.accountOwner << endl;
    cout << "Expected: 5000                    | Got: " << acct2.balance << endl;
    BankAccount acct3;
    task2(&acct3, name3, 50000000);
    cout << "Expected: Elmo's Goldfish Dorothy | Got: " << acct3.accountOwner << endl;
    cout << "Expected: 50000000                | Got: " << acct3.balance << endl;
    cout << endl;
    
    cout << "Task 3: Sign-on bonus for our bank accounts!" << endl;
    BankAccount* arr[3];
    arr[0] = &acct1;
    arr[1] = &acct2;
    arr[2] = &acct3;
    
    task3(arr);
    
    cout << "Expected Balance: 600             | Got: " << acct1.balance << endl;
    cout << "Expected Balance: 5100            | Got: " << acct2.balance << endl;
    cout << "Expected Balance: 50000100        | Got: " << acct3.balance << endl;
    
}