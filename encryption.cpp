#include <iostream>
#include <fstream>
#include "encryption.h"

using namespace std;

bool encryptFile(string input,string output,int key)
{
    ifstream in(input, ios::binary);
    ofstream out(output, ios::binary | ios::trunc);

    if(!in || !out)
    {
        cout<<"File error\n";
        return false;
    }

    char ch;
    int count = 0;

    while(in.get(ch))
    {
        out.put(ch ^ key);
        count++;
    }

    cout<<"[DEBUG] Bytes encrypted: "<<count<<endl;

    return true;
}

bool decryptFile(string input,int key)
{
    ifstream in(input, ios::binary);

    if(!in)
    {
        cout<<"Encrypted file missing\n";
        return false;
    }

    in.seekg(0, ios::end);
    int size = in.tellg();
    in.seekg(0);

    cout<<"[DEBUG] File size: "<<size<<endl;

    if(size <= 0)
    {
        cout<<"File corrupted\n";
        return false;
    }

    char ch;
    int count = 0;

    cout<<"\nFile Content:\n\n";

    while(in.get(ch))
    {
        cout<<(char)(ch ^ key);
        count++;
    }

    cout<<"\n\n[DEBUG] Bytes decrypted: "<<count<<endl;

    return true;
}
