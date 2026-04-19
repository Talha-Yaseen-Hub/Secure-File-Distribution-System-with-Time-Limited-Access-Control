#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include "accesscontrol.h"

using namespace std;

bool createMeta(string file,string password,int minutes)
{
    ofstream meta(file + ".meta");

    if(!meta)
    {
        cout<<"Meta file creation failed\n";
        return false;
    }

    time_t now = time(0);
    time_t expiry = now + (minutes * 60);

    meta<<password<<endl;
    meta<<expiry;

    meta.close();

    return true;
}

bool verifyAccess(string file,string password)
{
    ifstream meta(file + ".meta");

    if(!meta)
    {
        cout<<"Meta file missing\n";
        return false;
    }

    string savedPass;
    time_t expiry;

    getline(meta, savedPass);
    meta >> expiry;

    meta.close();

    if(password != savedPass)
    {
        cout<<"Wrong password\n";
        return false;
    }

    time_t now = time(0);

    if(now > expiry)
    {
        cout<<"File expired\n";

        remove((file + ".enc").c_str());
        remove((file + ".meta").c_str());

        return false;
    }

    return true;
}
