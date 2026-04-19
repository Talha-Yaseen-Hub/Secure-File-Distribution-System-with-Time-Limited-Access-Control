#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <string>
using namespace std;

bool createMeta(string file,string password,int minutes);
bool verifyAccess(string file,string password);

#endif
