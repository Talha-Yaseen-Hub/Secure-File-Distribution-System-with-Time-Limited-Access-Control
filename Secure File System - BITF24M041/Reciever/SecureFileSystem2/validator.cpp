#include <fstream>
#include "validator.h"

using namespace std;

bool fileExists(string name)
{
    ifstream f(name);
    return f.good();
}

bool validTime(int t)
{
    return t > 0;
}

