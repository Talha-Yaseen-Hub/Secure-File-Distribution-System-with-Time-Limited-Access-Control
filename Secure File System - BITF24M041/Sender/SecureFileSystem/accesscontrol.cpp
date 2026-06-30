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
        return false;

    time_t expiry = time(0) + minutes*60;

    meta<<password<<endl;
    meta<<expiry;

    return true;
}

bool verifyAccess(string file,string password)
{
    ifstream meta(file + ".meta");

    if(!meta)
    {
        cout<<"Meta missing\n";
        return false;
    }

    string saved;
    time_t expiry;

    getline(meta, saved);
    meta>>expiry;

    if(password != saved)
    {
        cout<<"Wrong password\n";
        return false;
    }

    if(time(0) > expiry)
    {
        cout<<"Expired\n";
        remove((file+".enc").c_str());
        remove((file+".meta").c_str());
        return false;
    }

    return true;
}
