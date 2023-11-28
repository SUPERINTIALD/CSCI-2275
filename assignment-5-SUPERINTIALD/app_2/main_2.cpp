// #include "WaitlistQueue.hpp"
#include "../code_2/WaitlistQueue.hpp"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
    cout << "*----------------------------------------*" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Resize" << endl;
    cout << "5. Quit" << endl;
    cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    // DO NOT MODIFY THIS.
    if(argc > 2)
    {
        freopen(argv[2],"r",stdin);
    }
    
    /* TODO */
    bool quit = false;
    string s_input;
    int input;

    WaitlistQueue myQueue;


    // loop until the user quits
    while (!quit)
    {
        menu();

        // read in input, assuming a number comes in
        getline(cin, s_input);
        try
        {
            input = stoi(s_input);
        }
        catch (exception& e)
        {
            
            input = 10;
        }

        switch (input)
        {
            case 1: {
                string s1;
                cout << "Enter the value to add into queue:" << endl;
                getline(cin, s1);
                myQueue.enqueue(s1);

                break;
            }

            case 2: {
              
                myQueue.dequeue();

                break;
            }

            case 3: {
                string peekVal = myQueue.peek();
                cout << peekVal << endl;

                break;
            }

            case 4: {
                string s1;
                cout << "Enter the new capacity:" << endl;
                getline(cin, s1);
                int newSize = stoi(s1);
                myQueue.resize(newSize);

                break;
            }

            case 5: {
                // quit
                quit = true;
                cout << "Quitting..." << endl;
                cout << "Contents of the queue:" << endl;
                string* q = myQueue.getQueue();
                int iFront =  myQueue.getQueueFront();
                int iEnd = myQueue.getQueueEnd();

                for (int i=iFront; i< iEnd+1; i++){
                    cout << q[i] << endl;
                }
                


                cout << "Goodbye!" << endl;
                break;

            }

            default:     
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    }

    
    return 0;
}