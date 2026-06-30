#include <iostream>
#include "menu.h"

using namespace std;

void showMenu()
{
    cout<<"\n=============================\n";
    cout<<" Secure File System\n";
    cout<<"=============================\n";
    cout<<"1 Secure File\n";
    cout<<"2 Open Secure File\n";
    cout<<"3 Exit\n";
}

int getChoice()
{
    int c;
    cout<<"Enter choice: ";
    cin>>c;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        return -1;
    }

    return c;
}
