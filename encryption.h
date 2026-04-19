#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

bool encryptFile(string input,string output,int key);
bool decryptFile(string input,int key);

#endif
