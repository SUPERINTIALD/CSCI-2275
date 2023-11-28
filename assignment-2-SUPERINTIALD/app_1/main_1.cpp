#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include "../code_1/array_double.hpp"
// #include "array_double.hpp"

using namespace std;
wordRecord* arrayDouble(wordRecord* arrayPtr, int& arraySize){
    int newArraySize = 2 * arraySize;
    wordRecord* newArray = new wordRecord[newArraySize];
    for(int i = 0; i < arraySize; i ++){
        newArray[i].word  = arrayPtr[i].word;
        newArray[i].count = arrayPtr[i].count;
    }
    delete[] arrayPtr;
    arraySize = newArraySize;
    return newArray;
}

bool isWordInRecord(string newWord, wordRecord wordStruct[], int length){
    bool result = false;
    for(int i = 0; i < length; i ++){
        if(newWord.compare(wordStruct[i].word) == 0){
            wordStruct[i].count++;
            result = true;
            break;
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    //arguments
    string startingIndex = argv[1];
    string fileTxt = argv[2];
    string ignoreTxt = argv[3];
    //start program here
    string ignoreArr[100];
    getIgnoreWords(ignoreTxt.c_str(), ignoreArr);
    int arraySize = 100;
    wordRecord* myRecord;
    int arrayDoubleCount = 0;
    myRecord = new wordRecord[arraySize];
    string bookName = fileTxt;
    ifstream inputFile;
    inputFile.open(bookName);
    string fileLine;
    int myRecordSize = 0;
    string fileWord;


    //Once file is opened Read file, ignore words, and double array accordingly
    if(inputFile.is_open()){
        while(getline(inputFile,fileLine,'\n')){
            istringstream ss(fileLine);
            while(getline(ss, fileWord, ' ')){
                bool isIgnoreWordFunction = isIgnoreWord(fileWord, ignoreArr, 100 );
                if(isIgnoreWordFunction == false){
                    bool judgmentMaker = isWordInRecord(fileWord, myRecord, myRecordSize);
                    if(judgmentMaker == false){
                        if(arraySize == myRecordSize){
                            myRecord = arrayDouble(myRecord, arraySize);
                            arrayDoubleCount++;
                        }      
                        myRecord[myRecordSize].word = fileWord;
                        myRecord[myRecordSize].count = 1;
                        myRecordSize++; 
                    }                           
                } 
            }
        }
    }
    else
    {
        cout << "Opening File Failed" << endl;
    }
    // Close the file
    inputFile.close();

    int totalNonCommonWords = getTotalNumberNonIgnoreWords(myRecord, myRecordSize);

    sortArray(myRecord, myRecordSize);

    cout << "Array doubled: " << arrayDoubleCount << endl;
    cout << "Distinct non-common words: " << myRecordSize << endl;
    cout << "Total non-common words: " << totalNonCommonWords << endl;
    // cout << "Probability of next 10 words from rank " << stoi(startingIndex) << '\n' <<"---------------------------------------" << endl;
    cout << "Probability of next 10 words from rank " << stoi(startingIndex) << endl;
    cout <<"---------------------------------------" << endl;

    printTenFromN(myRecord, stoi(startingIndex), totalNonCommonWords);
    return 0;
}