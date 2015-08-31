#include <iostream>
#include "unorderarray.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    UnorderArray<int> unAr(4);
    unAr.push(45);
    unAr.pop();

    return 0;
}

