#include "fundamentals_1.hpp"

int addToArrayDesc(float sortedArray[], int numElements, float newValue){
 
    float newSortedArray[99];
    bool newValueInserted = false;

    // Copy the sorted array
    for(int i = 0; i < numElements; i++){
         newSortedArray[i] = sortedArray[i];
    }

    // loop through the copied sorted array and modify the orignal sort array
    for(int i = 0; i <numElements; i++){        
        if(newValue > newSortedArray[i]){
            sortedArray[i] = newValue;
            newValueInserted = true;

            // Once found the new value position for the array, retrieve the rest of them
            for (int j = i + 1; j < numElements + 1; j++ )
            {
                sortedArray[j] = newSortedArray[j-1];
            }
            break;
        }
    }

    // if newValue hasn't inserted to the array yet, it means 
    // it is smaller than the lowest value in the array and we need to add it in the end of the array!!
    if (newValueInserted == false){
        // ***important here, the numElements is 1 based. 
        // It is already increment by 1 if you use it as index for the array!!
        sortedArray[numElements] = newValue;
    }


   return ++numElements;
}
    
