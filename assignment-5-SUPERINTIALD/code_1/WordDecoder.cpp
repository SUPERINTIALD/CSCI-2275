#include <iostream>
// #include "../code_1/WordDecoder.hpp"
#include "WordDecoder.hpp"


using namespace std;


WordDecoder::WordDecoder()
{
    // TODO. Initialize all variables required
    stackHead = nullptr;
}

WordDecoder::~WordDecoder()
{
    //TODO. Free up to avoid memory leaks
    Letter * prev;
    Letter * tmp = stackHead;
    while(tmp != NULL){
        prev = tmp;
        tmp = tmp -> next;
        delete prev;
    }
    stackHead = nullptr;
}

bool WordDecoder::isEmpty()
{
    // TODO. Checking if stack is empty    
    if(stackHead == nullptr){
        return true;
    } else{
        return false;
    }
}

void WordDecoder::push(string letter)
{    //TODO Perform push operation stack
    if(isEmpty()){
        Letter * tmp = new Letter;
        tmp -> letter = letter;
        stackHead = tmp;
        stackHead-> next = NULL;
 
    } else {
        Letter * tmp = new Letter;
    
        tmp->next = stackHead;
        tmp->letter = letter;
        stackHead = tmp;

    }


}



void WordDecoder::pop()
{
    Letter * tmp = NULL;
    //TODO Perform pop operation stack
    if(stackHead == NULL){
        cout << "Stack empty, cannot pop a letter." << endl;
    } else {
        tmp = stackHead->next;
        
        delete stackHead;
      
        stackHead = tmp ;
       
    }
}

Letter* WordDecoder::peek()
{
    //TODO Perform peek operation stack
    if(!isEmpty()){
     
        return stackHead;
    }else{
        
        cout << "Stack empty, cannot peek." << endl;
        return nullptr;
    }
}

void WordDecoder::evaluate(string * s, int size)
{
    /* TODO:
    1. Push to stack if lette rin string not a ")"
    2. If ")" comes, then pop until "(", store somewhere. Put letters back to the stack in reverse order of pop.
    3. Finally, the elements are stored in reverse, so print in reverse order. */







    string saveStr = "";
    string cs = "";
    string decodedWord = "";
    int leftP = 0;
    string saveAfter = "";

    for(int i = 0; i < size; i++){

        if(s[i] == ")"){
            saveStr = "";
            while(stackHead->letter != "("|| peek()->letter == "("){
                if(stackHead->letter == "("){
                  
                    pop();
                    break;
                }
             
                saveStr += peek()->letter;
             
                pop();
            }
            decodedWord = "";
            for(int i = 0; i < saveStr.length(); i++){
            
                cs = saveStr.at(i);
                if(cs != ")"){
                    push(cs);
                    decodedWord += cs;
                 
                }
            }
            
        }else{
           
            if(s[i] == "("){
                leftP++;
            
            }
            if(leftP == 0){
            push(s[i]);
            saveAfter += s[i];
            }
            push(s[i]);
        }
    }
    cout << "The decoded word: " << saveAfter <<decodedWord  << endl;
}