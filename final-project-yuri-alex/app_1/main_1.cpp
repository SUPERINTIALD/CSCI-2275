#include <iostream>
#include <fstream>
#include "../code_1/miniGit.hpp"
#include <filesystem>
using namespace std;

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. init " << endl;
    cout << " 2. add " << endl;
    cout << " 3. rm " << endl;
    cout << " 4. commit " << endl;
    cout << " 5. checkout" << endl;
    cout << " 6. search" << endl;
    cout << " 7. quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
int main(int argc, char* argv[]) {

    if(argc>1) 
     {
         freopen(argv[1],"r",stdin);  
     }

    bool running = true;
    MiniGit git;
    while (running){
        displayMenu();
        string s_choice;
        int choice;
        cin >> s_choice;
        try {choice = stoi(s_choice);}
        catch(exception& ex) {choice = 0;}

        switch(choice){
            /*cout << "Enter a size for the hash table: (Recommended: 30)" << endl; //not sure if we are supposed to define this ourselves
            string sizestr = "";
            cin >> sizestr;
            int size = 30;
            if (sizestr.size() > 0) size = stoi(sizestr);*/
            case 1: {
                git.init(5);
                break;
            }
            case 2: {
                string fname;
                cout << "Enter the file name to add:" << endl;
                //TODO: check if file exists
                while (true){
                    cin >> fname;
                    if (fname == "cancel" || fname == "") break;
                    string result = git.add(fname);
                    if (result == "success") break;
                    else cout << "Error: " << result << " Enter another name or write 'cancel':" << endl;
                }
                break;
            }
            case 3: {
                // cout << "rm" << endl;
                string fname;
                cout << "Enter the file name to remove: "<< endl;
                cin >> fname;
                git.rm(fname);
                
                
                break;
            }
            case 4: {
                cout << "Enter the commit message:" << endl;
                string msg;
                getline(cin >> ws, msg);
                string f = git.commit(msg);
                if (f != "") cout << "Created commit with ID " << f << endl;
                break;
            }
            case 5: {
                cout << "Warning: You will lose changes if the files are uncommitted." << endl << "Enter the commit number to checkout: " << endl;
                string o;
                cin >> o;
                git.checkout(o);
                break;
            }
            case 6: {
                cout << "Enter the string to search for:" << endl;
                string msg;
                cin >> msg;
                git.search(msg);
                break;
            }
            case 7: {
                cout << "Quitting..." << endl;
                running = false;
                break;
            }
            case 8: {
                cout <<"Dev option #8: Print" << endl; //Remove for final submission
                git.printLLContents();
                break;
            }
            default: {
                cout << "Invalid choice." << endl;
                break;
            }
        }
        cout << endl;
    }
   
    return 0;
}