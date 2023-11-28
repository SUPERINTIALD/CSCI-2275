/*******************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*       This class uses a linked-list of CUSatellite nodes to      */
/*       represent communication paths between Satellites           */
/*******************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUSatelliteNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new Satellite to the network
 *   between the Satellite previous and the Satellite that follows it in the network.
 * @param previous - name of the Satellite that comes before the new Satellite
 * @param SatelliteName - name of the new Satellite 
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{     

    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: populates the network with the predetermined CUSatellites
 * @param none
 * @return none
 */
void CUSatelliteNetwork::loadDefaultSetup()
{

    deleteEntireNetwork();
    // TODO: Copy-paste your solution from Assignment 3
    addSatelliteInfo("", "MAVEN", 9);	
	addSatelliteInfo("", "JUNO", 4);	
    addSatelliteInfo("", "PIONEER", 5);	    
    addSatelliteInfo("", "GALILEO", 6);	
    addSatelliteInfo("", "KEPLER", 10);	
    addSatelliteInfo("", "TESS", 2);	
}

/*
 * Purpose: Search the network for the specified Satellite and return a pointer to that node
 * @param SatelliteName - name of the Satellite to look for in the network
 * @return pointer to node of SatelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    // TODO: Copy-paste your solution from Assignment 3
    CUSatellite* temp = head;   
    if (temp == nullptr){
        return nullptr;
    }
    else{
        if (satelliteName == temp->name){
            return temp;
        }
        else{
             while(temp != NULL){
                if (satelliteName == temp->name){
                    return temp;
                }
                temp = temp->next;                
            }

            // while(temp->next != NULL){
            //     if (satelliteName == temp->name){
            //         return temp;
            //     }
            //     temp = temp->next;                
            // }
            // if (satelliteName == temp->name){
            //     return temp;
            // }
        }        
    } 
        return nullptr;
}

/*
 * Purpose: Relay a message through the linked list until the specified Satellite
 * @param string receiver - name of the Satellite 
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver)
{
    // TODO: Copy-paste your solution from Assignment 3
    
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

 * Purpose: prints the current list in an organized manner
 * @param none
 * @return none

 */
void CUSatelliteNetwork::printNetwork() 
{
    /* finished. do not touch. */
    cout << "== CURRENT PATH ==" << endl;

    if (head)
    {
        CUSatellite* temp = head;
        
        while (temp)
        {
            cout << temp->name << "(" << temp->distanceFromEarth << ") -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    else
    {
        cout << "nothing in path";
    }

    cout << endl << "===" << endl;


}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the Satellite in the network with the specified name.
 * @param SatelliteName - name of the Satellite to delete in the network
 * @return none
 */


void CUSatelliteNetwork::deleteCUSatellite(string satelliteName) 
{
    CUSatellite * tmp = head;
    // TODO: Complete this function
    // if(tmp == NULL || tmp -> name != satelliteName){
    if(searchForSatellite(satelliteName) == nullptr ){
        cout << "Satellite does not exist." << endl;
    }else if(head -> name == satelliteName){
        CUSatellite *tmp = head;
        head = head -> next;
        delete tmp;
    }else{
        CUSatellite * prev = NULL;
        while(tmp -> next != NULL){
            if(tmp -> name == satelliteName)
            {
                break;
            }
            prev = tmp;
            tmp = tmp -> next;
        }
        // if(tmp -> name == satelliteName){
        prev -> next = tmp -> next;
        delete tmp;
        
        // } 
    }  
}

/*
 * Purpose: deletes all Satellites in the network starting from the head Satellite.

 * @param: none
 * @return: none
 */
void CUSatelliteNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function
    CUSatellite * tmp = head;
    CUSatellite * prev = NULL;
    if(tmp == NULL){
        return ;
    } else{
        while(tmp->next != NULL){
            prev = tmp;
            tmp = tmp -> next;
            delete prev;
        }
    head = NULL;
    }
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUSatelliteNetwork::detectLoop() 
{
    // TODO: Complete this function
    // Use 1 to transverse the list 
    // Use next-> next to transverse list
    // set equal to each other
    
    if(head == NULL){
        return false;
    }
    CUSatellite * tmpFast = head->next;
    CUSatellite * tmpSlow = head;
    // int i=0;
    while(tmpFast != NULL && tmpFast->next != NULL && tmpSlow != NULL){
        // i++;
        if(tmpFast == tmpSlow){
            return true;
            break;
        }
        tmpFast = tmpFast -> next -> next;
        tmpSlow = tmpSlow->next;
        // if (i > 5){
        //     break;
        // }
    }
    return false;
}

/*
* Purpose: Creates a loop from last node to the Satellite specified.
* @param SatelliteName - name of the Satellite to loop back to
* returns the last node before loop creation (to break the loop)
*/
CUSatellite* CUSatelliteNetwork::createLoop(string satelliteName) 
{
    // TODO: Complete this function
    // CUSatellite * tmp = NULL;
    CUSatellite * tmp = head;
    CUSatellite * prev = NULL;

    CUSatellite* intermediatePtr = searchForSatellite(satelliteName);

    if(intermediatePtr == nullptr)
    {
        // // find E object
        // return prev;
         while(tmp != NULL){
                    
            prev = tmp;
            tmp = tmp -> next;
        }
        return prev;

    }else{
        while(tmp != NULL){
                    
            if(tmp->next == NULL){
                tmp -> next = intermediatePtr;
                break;
            }
            prev = tmp;
            tmp = tmp -> next;
        }
            return tmp;
    }
}
/*
 * Purpose: Take the chunk of nodes from start index to end index and
 *          move that chunk to the end of the List
 * @param: start_index, end_index - indices of start node and the end node
 * @return: none
 */
void CUSatelliteNetwork::readjustNetwork(int start, int end)
{
    /*
    Bascially Get start and end,
    then use that to get start of index.
    Need to get end of linkedList;
    Then from start of index put at end of the Linked list until end count is reached.
    */ 

    // TODO: Complete this function
    
    // CUSatellite * tmpList[10];
    CUSatellite * tmp = head;
    CUSatellite * oldListStart = NULL;
    CUSatellite * oldListReconnect = NULL;
    CUSatellite * oldListEnd = NULL;
    CUSatellite * brokenListStartPoint = NULL;
    CUSatellite * brokenListEndPoint = NULL;

    
    if(tmp == NULL){
        cout << "Linked List is Empty" << endl;

    }else{
        tmp = head;
        int totalNodeCount = 0;
        while(tmp != NULL){
            totalNodeCount++;            
            tmp = tmp -> next;
        }

       if(end > totalNodeCount -2 || end < 0){
            cout << "Invalid end index" << endl;
        }else if(start > totalNodeCount -1 || start < 0){
            cout << "Invalid start index" << endl;
        }else if(start > end){
            cout << "Invalid indices";
        }
        else{
            int count = 0;
            tmp = head;
            while(tmp != NULL){ // Transverse the lists to start finding Start value and then remvoe that to add to end of linked list.
                if(count == start){
                    brokenListStartPoint = tmp; // Once inside this is B
                    
                    //Move part of linkedlist to the end
                    for (int i=start + 1; i < end + 1; i++){
                        tmp = tmp -> next; //Here is point to E
                    }
                    brokenListEndPoint = tmp;   // point to E
                    oldListReconnect = tmp -> next;  
                    break;
                }
                oldListStart = tmp;//A
                count++;
                tmp = tmp -> next;
            }
            //retrive the last node here since we encountered core dump inside the while loop above
            tmp = head;
            while(tmp->next != NULL){ //first tmp still point to E            
                tmp = tmp -> next; //firt tmp point toF
            }
            oldListEnd = tmp; // F
            // Put the broken list back together
            if (start == 0){
                // oldListStart->next = oldListReconnect;
                brokenListEndPoint->next = NULL;
                head = oldListReconnect;
                oldListEnd->next = brokenListStartPoint;
            }else{
                brokenListEndPoint->next = NULL;
                if (oldListReconnect == nullptr){
                    oldListStart -> next = brokenListStartPoint;
                }else{
                    oldListStart->next = oldListReconnect;
                    oldListEnd->next = brokenListStartPoint;
                }
                
            }
            


        }
    }
}



/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUSatelliteNetwork::~CUSatelliteNetwork()
{
    // TODO: Complete this function
    CUSatellite * prev;
    CUSatellite * tmp = head;
    while(tmp != NULL){
        prev = tmp;
        tmp = tmp -> next;
        delete prev;
    }
    head = nullptr;
}