#include "tasks.hpp"
/*
    Task 1: update the value of the taskOne variable _without_ changing the
            function's return type. (hint: try modifying the parameter)
            
    NOTE: be sure to update the hpp file as well!!!
*/
void task1(int &a)
{
    a++;
}

/*
    Task 2: initialize a BankAccount. DO NOT change the function header.
*/

void task2(BankAccount* account, string& name, int initialBalance)
{
    // TODO: set the BankAccount's accountOwner and balance
    account -> accountOwner = name;
    account -> balance = initialBalance;


}

/*
    Task 3: use pointers (i.e. dereferencing addresses) to add 100 to each 
            element of the array.
            
    NOTE: do NOT use arr[i] syntax. Use parentheses and the dereference
          operator * to access the array.
*/
void task3(BankAccount** arr)
{
    // TODO: Add 100 to the first element in arr
    (*arr) -> balance += 100;
    // TODO: Add 100 to the second element in arr
    (*(arr + 1)) -> balance += 100;
    // TODO: Add 100 to the third element in arr
    (*(arr + 2)) -> balance += 100;
}