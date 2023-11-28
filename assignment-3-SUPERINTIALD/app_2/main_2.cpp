#include "../code_2/CUSatelliteNetwork.hpp"
// #include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

     // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
     // DO NOT MODIFY ABOVE.

    // TODO

    string userInputStr;
    int userInputInt;
    CUSatelliteNetwork li;

    // Now prompt user to choose a letter
    do
    {
        displayMenu();
        cin >> userInputStr;
        userInputInt = std::stoi(userInputStr);
        string name, distanceStr, previousSatelliteName;
        int distance;

        switch (userInputInt)  {
            case 1:
                li.loadDefaultSetup();
                li.printNetwork();

                break;

            case 2:
                li.printNetwork();

                break;
            case 3:
               
                cout << "Enter name of the recipient to receive the message: " << endl;
                cin >> name;                                
                cout << endl;
                li.transmitInfo(name);

                break;

            case 4:
                cout << "Enter a new satellite name: "<< endl;
                cin >> name;                                


                cout << "Enter distance of satellite from earth: " << endl;
                cin >> distanceStr;                                
                distance = std::stoi(distanceStr);

                cout << "Enter the previous satellite name (or First): "<< endl;
                cin >> previousSatelliteName;    
                 
                if (previousSatelliteName == "First"){
                    li.addSatelliteInfo(previousSatelliteName, name, distance);
                    li.printNetwork();
                }
                else{
                    CUSatellite* previousPtr;
                    previousPtr = nullptr;
                    previousPtr =li.searchForSatellite(previousSatelliteName);

                    while (previousPtr == NULL){
                
                        cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" << endl;
                        cin >> previousSatelliteName;
                        previousPtr = li.searchForSatellite(previousSatelliteName);
                    }
                    li.addSatelliteInfo(previousSatelliteName, name, distance);
                    li.printNetwork();  
                }

                break;
            case 5:
                cout << "Quitting..." << endl;
                cout << "Goodbye!" << endl;

                break;           
        }
        
    }
    while(userInputStr != "5");
    return 0;
}




/************************************************
           Definitions for main_2.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option: " << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Info " << endl;
    cout << " 4. Add Satellite " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
