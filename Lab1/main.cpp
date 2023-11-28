/* DO NOT MODIFY */

#include <iostream>
#include "debug.h"
using namespace std;

/* DO NOT MODIFY */
int main() 
{
    // Buggy1: fairWeather()
    cout << "----- Test Cases for fairWeather() -----" << endl;
    cout << "Input: 20          | Expected: 0           | Got: " << fairWeather(20) << endl;
    cout << "Input: 70          | Expected: 1           | Got: " << fairWeather(70) << endl;
    cout << "Input: 100         | Expected: 0           | Got: " << fairWeather(100) << endl;
    cout << "Input: 0           | Expected: 0           | Got: " << fairWeather(0) << endl;
    cout << endl;

    // Buggy2: sumNonNegNums()
    cout << "----- Test Cases for sumNonNegNums() -----" << endl;
    cout << "Input: 5,4         | Expected: 9           | Got: " << sumNonNegNums(5, 4) << endl;
    cout << "Input: -1,3        | Expected: 3           | Got: " << sumNonNegNums(-1, 3) << endl;
    cout << "Input: 7,-1        | Expected: 7           | Got: " << sumNonNegNums(7, -1) << endl;
    cout << "Input: -7,-4       | Expected: 0           | Got: " << sumNonNegNums(-7, -4) << endl;
    cout << endl;

    // Buggy3: addVowel()
    cout << "----- Test Cases for addVowel() -----" << endl;
    cout << "Input: ant         | Expected: anta        | Got: " << addVowel("ant") << endl;
    cout << "Input: elephant    | Expected: elephante   | Got: " << addVowel("elephant") << endl;
    cout << "Input: iguana      | Expected: iguanai     | Got: " << addVowel("iguana") << endl;
    cout << "Input: orca        | Expected: orcao       | Got: " << addVowel("orca") << endl;
    cout << "Input: unicorn     | Expected: unicornu    | Got: " << addVowel("unicorn") << endl;
    cout << "Input: monkey      | Expected: monkey      | Got: " << addVowel("monkey") << endl;
    cout << "Input: bird        | Expected: bird        | Got: " << addVowel("bird") << endl;
    cout << endl;

    return 0;
}

/* DO NOT MODIFY */