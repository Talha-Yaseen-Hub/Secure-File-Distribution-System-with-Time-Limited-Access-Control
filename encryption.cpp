#include <iostream>
#include <fstream>
#include <filesystem>
#include "encryption.h"

using namespace std;

bool encryptFile(string input,string output,int key)
{
    cout << "\n Encrypting file: " << input << endl;
    cout << " Output file: " << output << endl;

    ifstream in(input, ios::binary);
    ofstream out(output, ios::binary | ios::trunc);

    if(!in)
    {
        cout<<"Input file not found\n";
        return false;
    }

    if(!out)
    {
        cout<<"Output file creation failed\n";
        return false;
    }

    char ch;
    int count = 0;

    while(in.get(ch))
    {
        ch = ch ^ key;
        out.put(ch);
        count++;
    }

    cout << "[DEBUG] Bytes written: " << count << endl;

    in.close();
    out.close();

    return true;
}

bool decryptFile(string input,int key)
{
    cout << "\n[DEBUG] Decrypting file: " << input << endl;

    ifstream in(input, ios::binary);

    if(!in)
    {
        cout<<"Encrypted file not found\n";
        return false;
    }

    // file size check
    in.seekg(0, ios::end);
    int size = in.tellg();
    in.seekg(0, ios::beg);

    cout << "[DEBUG] File size: " << size << " bytes\n";

    if(size <= 0)
    {
        cout<<"File is empty or corrupted\n";
        return false;
    }

    char ch;

    cout<<"\nFile Content:\n\n";

    int count = 0;

    while(in.get(ch))
    {
        ch = ch ^ key;
        cout<<ch;
        count++;
    }

    cout<<"\n\n[DEBUG] Bytes read: " << count << endl;

    in.close();

    return true;
}
