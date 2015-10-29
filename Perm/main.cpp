#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void permutation(int k, string &s)
{
    for(int j = 1; j < s.size(); ++j)
    {
        std::swap(s[k % (j + 1)], s[j]);
        k = k / (j + 1);
        cout << s << "\n";
    }
}

int main()
{
    int i = 0;
    string s = "123";

    do {
        cout << s << "\n";
        i++;
    }
    while( next_permutation(s.begin(), s.end()) );
    cout << "all perm: " << i << endl;

    string a = "123";
    int d = 0;
//    int size = sizeof(a)/sizeof(int);

    for (int i = a.size()-1; i > 1 ; --i, d++) {
        swap( a[d], a[i] );
        cout << a << "\n";
    }

    cout << std::tgamma(4) << "\n";

//    for (int i = 0; i < tgamma(4); i++)
    permutation( 2, s);

    return 0;
}

