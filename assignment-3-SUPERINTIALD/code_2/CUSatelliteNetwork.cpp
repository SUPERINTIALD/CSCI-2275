/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/
// #include "../code_2/CUSatelliteNetwork.hpp"
#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) {
    // TODO

    // convert to upper strings (yuri >> YURI)
    std::transform(previous.begin(), previous.end(),previous.begin(), ::toupper);
    std::transform(satelliteName.begin(), satelliteName.end(),satelliteName.begin(), ::toupper);

    CUSatellite* previousPtr = searchForSatellite(previous);


    if (previous == "" || previous == "FIRST"){
        if(head == NULL){
            cout << "adding: " << satelliteName << " (HEAD)" << endl;
            CUSatellite *tmp = new CUSatellite;
            tmp->name = satelliteName;
            tmp->distanceFromEarth = distance;
            tmp->numberMessages = 0;
            tmp ->next = NULL;
            head = tmp;
        }
        else{
            cout << "adding: " << satelliteName << " (HEAD)" << endl;
            CUSatellite *tmp = new CUSatellite;
            tmp->name = satelliteName;
            tmp->distanceFromEarth = distance;
            tmp->numberMessages = 0;
            // tmp ->next = NULL;
            tmp ->next = head;
            head = tmp;            
        } 
    }
    else if (previousPtr == NULL){

        

         cout << "Cannot add new node; previous node not found\n" << endl;
        
        // while (previousPtr == NULL){
        //     cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" << endl;
        //     cin >> previous;
        //     previousPtr = searchForSatellite(previous);
        // }

        //  cout << "adding: " << satelliteName << " (prev: " << previousPtr->name << ")" << endl;

        // CUSatellite *tmp = new CUSatellite;
        // tmp -> name = satelliteName;
        // tmp->distanceFromEarth = distance;
        // tmp -> next = previousPtr -> next;
        // previousPtr -> next = tmp;

    }
     else{
        cout << "adding: " << satelliteName << " (prev: " << previousPtr->name << ")" << endl;

        CUSatellite *tmp = new CUSatellite;
        tmp -> name = satelliteName;
        tmp->distanceFromEarth = distance;
        tmp->numberMessages = 0;
        tmp -> next = previousPtr -> next;
        previousPtr -> next = tmp;
    }
}

 
/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup(){

  
	addSatelliteInfo("", "MAVEN", 9);	
	addSatelliteInfo("", "JUNO", 4);	
    addSatelliteInfo("", "PIONEER", 5);	    
    addSatelliteInfo("", "GALILEO", 6);	
    addSatelliteInfo("", "KEPLER", 10);	
    addSatelliteInfo("", "TESS", 2);	
}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName){
    // TODO
    CUSatellite* temp = head;   

    if (temp == nullptr){
        // cout << "kelvin 1" << endl;
        return nullptr;
    }
    else{
        // cout << "satelliteName=" << satelliteName << endl;
        // cout << "temp->name=" << temp->name << endl;
        if (satelliteName == temp->name){
            return temp;
        }
        else{
            while(temp->next != NULL){
                // cout << "kelvin x >> temp->name" << temp->name << endl;
                if (satelliteName == temp->name){
                    return temp;
                }
                temp = temp->next;
                if (satelliteName == temp->name){
                    return temp;
                }
            }
            //  while (temp != NULL){
            //     temp = temp->next;
            //     if (satelliteName == temp->name){
            //         return temp;
            //     }
            // }
        }        
    } 
    
    // cout << "kelvin 3" << endl; 
    return nullptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) {
    // TODO

    if (head == nullptr){
        cout << "Empty list" << endl;
    }else{
        // Check the given receiver whether it exist or not
    CUSatellite* receiverPtr = searchForSatellite(receiver);

    // if it doesn't exist, output msg
    if (receiverPtr == nullptr){
        cout << "Satellite not found" << endl;
    }else{
        // if it is exist, output the required msg
         CUSatellite* ptr = head;

        while (ptr != NULL){
                //increment the # of msg
                ptr->numberMessages++;

                //output the receiver msg
                cout << ptr->name << " [# messages received: " << ptr->numberMessages << "] received: distance of " << ptr->name << " from earth is " << ptr->distanceFromEarth <<  endl;

                //if receiver found, stop here
                if (receiver == ptr->name){
                    break;
                }

                //point to the next node
                ptr = ptr->next;
            }
        }
    }    
}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() {
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->distanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
