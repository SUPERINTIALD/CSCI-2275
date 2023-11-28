#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
    string parens;
    do
    {
        cout << "Enter a string of parentheses (or quit by typing 'q'): ";
        cin >> parens;
        
        Stack s = Stack();
        cout << "Parens balanced?: " << s.isBalanced(parens) << endl;
        
    } while(parens != "q");
}