/*
Recitation Lab 1
Material: learncpp.com, Chapter 1.1 - 1.10, 7.1 - 7.3
Fall 2022
About You: {Yuri Fung} - {Your Section 802}
*/

#include "debug.h"

/*
Returns the weather status. true if the temperature is moderate (between 50 & 80 degrees F), and false otherwise
@param: None
@return: integer, 0 = good, -1 = error
*/
bool fairWeather(int temperature) 
{
    // TODO: fix this function so it meets the function description.
    if(temperature >= 50 && temperature <= 80){
            return true;
    }else{

        return false;
    }
}
/*
Finds the sum of all non-negative parameters. (You can have 2, 1, or 0 non-negative parameters)
@param: param1 - first number (int)
@param: param2 - second number (int)
@return: total non-negative sum (int)
*/
int sumNonNegNums(int param1, int param2) 
{
    // TODO: fix this function so it meets the function description.
    int total = 0;
    if(param1 > 0){
        total += param1;
    }
    if(param2 > 0){
        total += param2;
    }
    return total;
}

/*
Adds first character of a word to the end of it if the first letter is a vowel.
@param: word - original value (string)
@return: word with its first letter appended if the first letter is a vowel (string)
*/
string addVowel(string word)
{
    // TODO: fix this function so it meets the function description.
    char firstLetter = word[0];
    if(firstLetter == 'a')
    { 
        return word + firstLetter; 
    }
    else if(firstLetter == 'e') 
    { 
        return word + firstLetter; 
    }
    else if(firstLetter == 'i') 
    { 
        return word + firstLetter; 
    }
    else if(firstLetter == 'o') 
    { 
        return word + firstLetter; 
    }
    else if(firstLetter == 'u') 
    { 
        return word + firstLetter; 
    }
    else
    { 
        return word; 
    }
}