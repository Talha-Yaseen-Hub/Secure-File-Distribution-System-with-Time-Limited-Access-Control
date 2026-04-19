#include <iostream>
#include <cstdio>
#include "filemanager.h"
#include "encryption.h"
#include "accesscontrol.h"
#include "validator.h"

using namespace std;

void secureFile()
{
    string file;
    string password;
    int minutes;

    cout<<"Enter file name: ";
    cin>>file;

    if(!fileExists(file))
    {
        cout<<"File does not exist\n";
        return;
    }

    cout<<"Set password: ";
    cin.ignore();
    getline(cin, password);

    cout<<"Enter expiry time (minutes): ";
    cin>>minutes;

    if(!validTime(minutes))
    {
        cout<<"Invalid time value\n";
        return;
    }

    remove((file + ".enc").c_str());
    remove((file + ".meta").c_str());

    if(!encryptFile(file,file + ".enc",7))
        return;

    if(!createMeta(file,password,minutes))
        return;

    cout<<"File secured successfully\n";
    cout<<"Send these files:\n";
    cout<<file<<".enc\n";
    cout<<file<<".meta\n";
}

void openSecureFile()
{
    string file;
    string password;

    cout<<"Enter file name: ";
    cin>>file;

    string encFile = file + ".enc";

    cout << "[DEBUG] Trying to open: " << encFile << endl;

    if(!fileExists(encFile))
    {
        cout<<"Encrypted file missing\n";
        return;
    }

    cout<<"Enter password: ";
    cin.ignore();
    getline(cin, password);

    if(verifyAccess(file,password))
    {
        decryptFile(encFile,7);
    }
    else
    {
        cout<<"Access denied\n";
    }
}
