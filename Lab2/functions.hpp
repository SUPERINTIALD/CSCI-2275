#include <iostream>
using namespace std;

struct LetterNode
{
    char letter;
    int speciesCount;
    string species[100];
};

void initLetterNodeArray(LetterNode array[]);

void insertToLetterNode(LetterNode array[], string speciesName);

void printLetterNodeInfo(LetterNode array[], char choice);
