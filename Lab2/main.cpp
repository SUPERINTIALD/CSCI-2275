#include <iostream>
#include <fstream>
#include "functions.hpp"
using namespace std;

int main(int argc, char* argv[]) 
{
    // cout << "You have " << argc << " arg number" <<  endl;

    // for (int i= 0; i < argc; i++){
    //     cout << argv[i] << endl;
    // }

    
    string fileName = argv[1];
    

    // Open the file with given filename
    ifstream inputFile;
    /*
            TODO: open the file given via command line arguments!
    */
    //opens bears.txt and then reads
    inputFile.open(fileName);
    string fileLine;
    // LetterNode Array
    LetterNode allSpecies[26];
    
    if(inputFile.is_open())
    {
        // Initialize the LetterNode array
        initLetterNodeArray(allSpecies);
        
        /*
            TODO: read each line of the file and call insertToLetterNode()
                  on each line!
        */

       while(getline(inputFile,fileLine,'\n')){
        insertToLetterNode(allSpecies, fileLine);
        cout << fileLine <<endl;
       }
    }
    else
    {
        cout << "Opening file failed" << endl;
        
        return -1;
    }
    
    inputFile.close();
    
    // Now prompt user to choose a letter
    char choice;
    do
    {
        cout << "Choose a capital letter (type 0 to exit): ";
        cin >> choice;
        printLetterNodeInfo(allSpecies, choice);
    }
    while(choice != '0');
}