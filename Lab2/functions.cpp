#include "functions.hpp"

/*
    TODO: implement the function below!
    
    @param: array to hold LetterNodes for each letter in the alphabet
    @return: None
    
    Desired behavior: creates a new LetterNode for each letter of the alphabet
                      and puts it in the array passed in as a parameter. Initialize
                      the speciesCount for each new node to be 0.
*/
void initLetterNodeArray(LetterNode array[])
{
    // 'A' has the ASCII value of 65 -- use this as a reference point for iterating!
    //write code here
    int asciiA = 65;
    //loops through all 26 letters and assigns it to array of corresponding values.
    for(int i = 0; i < 26; i++)
    {
        
         array[i].letter = char(i + asciiA); 
        
         array[i].speciesCount = 0;
        
       cout << array << endl;
    }
}

/*
    TODO: implement the function below!
    
    @param: array holding LetterNodes for each letter in the alphabet (LetterNode)
    @param: name of the species to insert into the array (string)
    @return: None
    
    Desired behavior: finds the LetterNode corresponding to the first letter of the
                      given speciesName. Once found, add the new speciesName to the 
                      LetterNode's species list and increment the node's speciesCount.
*/
void insertToLetterNode(LetterNode array[], string speciesName)
{

   
    
    //finds first character of speciesName list
    char firstCharacter = speciesName[0];
    //finds Character in letternode array??
    for(int i = 0; i < 26; i++){
        //Sees if firstCharacter equals value of user-input.
        if(firstCharacter == char(array[i].letter)){
        //loops through? until list is done? then add to array.

        //adds count to speciesCount
            
            array[i].species[array[i].speciesCount] = speciesName;
            array[i].speciesCount++;
    
        }
    }


    
}

void printLetterNodeInfo(LetterNode array[], char choice)
{
    if(choice == '0')
    {
        return;
    }
    
    // Otherwise print count of species & names
    int asciiA = 65;
    LetterNode chosen = array[int(choice) - asciiA];
    cout << "There are "  
        << chosen.speciesCount 
        << " species that start with the letter " 
        << choice << "." << endl;
    for(int i = 0; i < chosen.speciesCount; i++)
    {
        cout << chosen.species[i] << endl;
    }
    cout << endl;
}