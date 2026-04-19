#include <iostream>
#include "menu.h"
#include "filemanager.h"

using namespace std;

int main()
{
    int choice;
    bool running = true;

    cout<<"========================================\n";
    cout<<"  Secure File Distribution Application\n";
    cout<<"========================================\n";
    cout<<"This program allows users to secure files\n";
    cout<<"with password protection and expiry time.\n";
    cout<<"Only authorized users can open the file.\n";
    cout<<"----------------------------------------\n";

    while(running)
    {
        showMenu();

        choice = getChoice();

        switch(choice)
        {
            case 1:
            {
                cout<<"\n--- Secure File Selected ---\n";
                secureFile();
                break;
            }

            case 2:
            {
                cout<<"\n--- Open Secure File Selected ---\n";
                openSecureFile();
                break;
            }

            case 3:
            {
                cout<<"\nExiting program...\n";
                running = false;
                break;
            }

            case -1:
            {
                cout<<"Invalid input type. Please enter a number.\n";
                break;
            }

            default:
            {
                cout<<"Invalid option. Please try again.\n";
            }
        }

        if(running)
        {
            cout<<"\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    cout<<"\nProgram terminated successfully.\n";

    return 0;
}