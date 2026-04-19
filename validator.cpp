#include <fstream>
#include "validator.h"

using namespace std;

bool fileExists(string name)
{
    ifstream file(name);

    if(file)
        return true;

    return false;
}

bool validTime(int t)
{
    if(t <= 0)
        return false;

    return true;
}