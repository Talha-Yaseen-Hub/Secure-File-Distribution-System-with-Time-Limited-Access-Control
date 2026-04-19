#include <iostream>
#include <filesystem>
#include "menu.h"
#include "filemanager.h"

using namespace std;

int main()
{
    cout << "[DEBUG] Current working directory:\n"
         << filesystem::current_path() << endl;

    int choice;
    bool running = true;

    while(running)
    {
        showMenu();
        choice = getChoice();

        switch(choice)
        {
            case 1:
                secureFile();
                break;

            case 2:
                openSecureFile();
                break;

            case 3:
                running = false;
                break;

            default:
                cout<<"Invalid choice\n";
        }

        if(running)
        {
            cout<<"\nPress Enter...";
            cin.ignore();
            cin.get();
        }
    }
}
