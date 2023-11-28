#include "Stack.hpp"

Stack::Stack()
{
    top = 0;
}

void Stack::push(int value)
{
    if(!isFull())
    {
        data[top] = value;
        top++;
    }
    else
    {
        // push() failed, stack is full
    }
}

char Stack::pop()
{
    if(!isEmpty())
    {
        top--;
        return data[top];
    }
    else
    {
        // pop() failed, stack is empty
        return ' ';
    }
}

bool Stack::isFull()
{
    return top == CAPACITY;
}

bool Stack::isEmpty()
{
    return top == 0;
}

// TODO: GOLD Problem! 
// Use a stack to identify if a string of parentheses is balanced
// @param: paren string to check (string)
// @return: strings "yes", "no", "N/A" (for input 'q')
string Stack::isBalanced(string toCheck)
{
    int leftP = 0;
    int rightP = 0;
    if(toCheck == "q")
    {
        return "N/A";
    }
    
    // TODO - add balance checking logic
    for(char &c : toCheck){  
        // if(c != '(' || c !=  ')'){
        //     return "no";
        // }
        if(c == '('){
            leftP++;
        }else if(c == ')'){
            if(leftP == 0){
                return "no";
            }
            leftP--;
        }
    }
    if(leftP > 0){
            return "no";
        }else{
            return "yes";
    }
}

