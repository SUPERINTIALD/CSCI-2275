#ifndef READFILE_H__
#define READFILE_H__

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct wordRecord {
	string word;
	int count;
	float probabilityOfOccurance;
};

// TODO add detailed explanation on what the function should do
/*
By using all of these functions, we are able to use this program to read the file from Tom_Sawyer, ignore the words from another text file, 
then output the probability and word accordingly from the next ten words. However, since the Tom_Sawyer is a very large file, we need to dynamically allocate the array size, and keep doubling it. 
*/

//First the getIgnoreWords function reads the ignoreWords.txt file and then puts it into an array.
void getIgnoreWords(const char* ignoreWordFileName, string ignoreWords[]);
//Seoond the isIgnoreWord function uses the ignoreWords array, then determines if the incoming string is a ignoreWord or not.
bool isIgnoreWord(string word, string ignoreWords[], int length);
//Third the getTotalNumberNonIgnoreWords function gets the total number of the file from Tom_Sawyer while excluding the IgnoreWords.
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);
//Fourth, the sortArray function sorts the array through bubbleSort methods. Though first it sorts through the counts of the wordRecord in decending order.
//If the counts equal each other then, it sorts through the word from the wordRecord and determines which one to put first.
void sortArray(wordRecord distinctWords[], int length);
//Fifth, the printTenFromN prints the next 10 frequent words starting from the index "N" from userinput. Then it prints the next 10 words of probability and word accordingly.
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);

#endif // READFILE_H__