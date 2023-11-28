#include<iostream>
#include<cmath>
#include<iomanip>
// #include "WordDecoder.hpp"
#include "../code_1/WordDecoder.hpp"

using namespace std;




int main(int argc, char* argv[])
{
 

    // DO NOT MODIFY THIS.
    if(argc>1)
    {
         freopen(argv[1],"r",stdin);
    }

    /* TODO- 
              1. cout #>
              2. get the user input
              3. store them in an array
              4. If the array is empty then print "Nothing to evaluate"
                 else call the evaluate function
    */

    cout << "Enter the encoded word separated by '(' and ')'"<<endl;
    cout << "#>";
    string userStrInput;
    cin >> userStrInput;
    int size = userStrInput.length();
    string strArr[size];
    WordDecoder * li = new WordDecoder;
    string * s = &userStrInput;

    if(userStrInput.empty()){
        cout << "Nothing to evaluate" ;
        exit(1);
    }

    for(int i = 0; i < size; i++){
      
        strArr[i] = s->at(i);

    }
       
    

    
    li->evaluate(strArr, size);
    return 0;
}