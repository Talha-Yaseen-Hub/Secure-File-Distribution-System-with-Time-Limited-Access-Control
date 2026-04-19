#include <iostream>
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
    cin>>password;

    cout<<"Enter expiry time (minutes): ";
    cin>>minutes;

    if(!validTime(minutes))
    {
        cout<<"Invalid time value\n";
        return;
    }

    bool status;

    status = encryptFile(file,file + ".enc",7);

    if(!status)
        return;

    status = createMeta(file,password,minutes);

    if(!status)
        return;

    cout<<"File secured successfully\n";
    cout<<"Send these files to receiver:\n";
    cout<<file<<".enc\n";
    cout<<file<<".meta\n";
}

void openSecureFile()
{
    string file;
    string password;

    cout<<"Enter file name : ";
    cin>>file;

    if(!fileExists(file + ".enc"))
    {
        cout<<"Encrypted file missing\n";
        return;
    }

    cout<<"Enter password: ";
    cin>>password;

    bool access;

    access = verifyAccess(file,password);

    if(access)
    {
        decryptFile(file + ".enc",7);
    }
    else
    {
        cout<<"Access denied\n";
    }
}