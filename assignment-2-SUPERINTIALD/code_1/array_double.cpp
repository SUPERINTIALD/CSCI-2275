#include "array_double.hpp"
#include <string>

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]){
    ifstream inputFile;
    inputFile.open(ignoreWordFileName);
    string fileLine;
    int x = 0;
    if(inputFile.is_open()){
        while(getline(inputFile,fileLine,'\n')){
            ignoreWords[x] = fileLine;
            // cout<<ignoreWords[x]<<endl;
            x++;
        }
    }
    else
    {
        cout << "Opening File Failed" << endl;
    }
    // Close the file
    inputFile.close();
}


bool isIgnoreWord(string word, string ignoreWords[], int length){
    bool result;

    for (int i = 0; i < length; i++)
    {
        result = false;
        if(word.compare(ignoreWords[i]) == 0){
            result = true;
            break;
        } 
    }
    return result;
}


int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length){
    int total = 0;
    for(int i = 0; i < length; i++){
        total += distinctWords[i].count;
    }
    return total;
}


void sortArray(wordRecord distinctWords[], int length){
     int i, j;
    for (i = 0; i < length - 1; i++){
        for (j = 0; j < length - i - 1; j++){
            if (distinctWords[j].count < distinctWords[j + 1].count){
                swap(distinctWords[j], distinctWords[j + 1]);    
            }else if (distinctWords[j].count == distinctWords[j + 1].count){
                if (distinctWords[j].word.compare(distinctWords[j + 1].word) > 0){
                    swap(distinctWords[j], distinctWords[j + 1]);
                }
            }
        }
    } 
}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){
    int numRange = 10;
    int precision = 5;

    float probabilityOfOccurrence;

    //add equation here;
    for(int i = N; i < N + numRange; i++){
        probabilityOfOccurrence = (float)distinctWords[i].count / totalNumWords;
        // cout << distinctWords[i].count << endl;
        cout << fixed << setprecision(precision) << probabilityOfOccurrence <<" - "<< distinctWords[i].word<< endl;
    }
}

