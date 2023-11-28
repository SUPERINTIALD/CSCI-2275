#include "generateSeries.hpp"
#include<iostream>
#include <math.h>
using namespace std;

void generateSeries(int* &arr, int &n, int &m, int &arraySize){
    arr = new int[arraySize];
    for(int i = 0; i < arraySize; i++){
        arr[i] = n *pow(m,i);
        cout << arr[i] << endl;    
    }


}