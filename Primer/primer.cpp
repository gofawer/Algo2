#include <iostream>
#include "fun.h"
using namespace std;

void ex2()
{
    const int j = 43;
    cout << "buffSize: " << buffSize << ", " << getBuff() << "\n";
}

int main()
{
    cout << "Hello World!" << endl;

    {
        ex2();
    }

    return 0;
}

