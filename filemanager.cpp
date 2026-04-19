#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include "filemanager.h"
#include "encryption.h"
#include "accesscontrol.h"
#include "validator.h"

using namespace std;

void logAccess(string file,string status)
{
    ofstream log("access_log.txt", ios::app);

    time_t now = time(0);

    log<<"File: "<<file
       <<" | Status: "<<status
       <<" | Time: "<<ctime(&now);
}

void secureFile()
{
    string file, pass;
    int timeLimit;

    cout<<"Enter file: ";
    cin>>file;

    if(!fileExists(file))
    {
        cout<<"File not found\n";
        return;
    }

    cout<<"Set password: ";
    cin.ignore();
    getline(cin, pass);

    cout<<"Expiry (minutes): ";
    cin>>timeLimit;

    if(!validTime(timeLimit))
    {
        cout<<"Invalid time\n";
        return;
    }

    remove((file+".enc").c_str());
    remove((file+".meta").c_str());

    encryptFile(file, file+".enc", 7);
    createMeta(file, pass, timeLimit);

    cout<<"File secured\n";
}

void openSecureFile()
{
    string file, pass;

    cout<<"Enter file: ";
    cin>>file;

    if(!fileExists(file+".enc"))
    {
        cout<<"Encrypted file missing\n";
        return;
    }

    int attempts = 3;
    bool success = false;

    while(attempts--)
    {
        cout<<"Enter password: ";
        cin.ignore();
        getline(cin, pass);

        if(verifyAccess(file, pass))
        {
            success = true;
            break;
        }

        cout<<"Attempts left: "<<attempts<<endl;
    }

    if(success)
    {
        decryptFile(file+".enc",7);
        logAccess(file, "SUCCESS");
    }
    else
    {
        cout<<"Access blocked\n";
        logAccess(file, "FAILED");
    }
}
