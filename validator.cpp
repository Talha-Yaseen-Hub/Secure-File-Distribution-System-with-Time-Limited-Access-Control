#include <fstream>
#include "validator.h"

using namespace std;

bool fileExists(string name)
{
    ifstream file(name);
    return file.good();
}

bool validTime(int t)
{
    return (t > 0);
}
