#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    const char* nn = "nn string";
    cout << nn << endl;

    const char* m = NULL;
    if ( m )
        cout << string(m) << endl;
//    char* mm = const_cast<char*>(nn);
//    strcpy(const_cast<char*>(nn), "Hi");
//    nn = mm;

    return 0;
}

