#include <iostream>
#include <fstream>
#include "../code_1/fundamentals_1.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    float sortedArray[99];
    int numElements = 0;
    
    // add 10 item first
    string fileName = argv[1];

    ifstream inputFile;
    inputFile.open(fileName);
    string fileLine;
    float newValue;

    if(inputFile.is_open()){
        while(getline(inputFile,fileLine,'\n')){
            newValue = std::stof(fileLine);
            numElements = addToArrayDesc(sortedArray,  numElements, newValue);
            for (int i = 0; i < numElements; i++){
                if(i == numElements - 1){
                    cout << sortedArray[i]<<endl;
                } else{
                    cout << sortedArray[i]<< ",";
                }
                       
            }
        }
    } else{
        cout << "Failed to open the file." << endl;
        return -1;
    }

   

    inputFile.close();
    return 0;
}