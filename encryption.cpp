#include <iostream>
#include <fstream>
#include "encryption.h"

using namespace std;

bool encryptFile(string input,string output,int key)
{
     ifstream in(input, ios::binary);
     ofstream out(output, ios::binary);


    if(!in)
    {
        cout<<"Input file not found\n";
        return false;
    }

    char ch;

    while(in.get(ch))
    {
        ch = ch ^ key;
        out.put(ch);
    }

    in.close();
    out.close();

    return true;
}

bool decryptFile(string input,int key)
{
    ifstream in(input);

    if(!in)
    {
        cout<<"Encrypted file not found\n";
        return false;
    }

    char ch;

    cout<<"\nFile Content:\n";

    while(in.get(ch))
    {
        ch = ch ^ key;
        cout<<ch;
    }

    cout<<endl;

    in.close();

    return true;
}