#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int N, T;
int skymap[25][25];

int neighbors(int i, int j) {
    int one = 0;
    if (skymap[i][j+1] == 1) one++;
    if (skymap[i+1][j] == 1) one++;
    if (skymap[i][j-1] == 1) one++;
    if (skymap[i-1][j] == 1) one++;

    return one;
}

void fill() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> skymap[i][j];
        }
    }
}

void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << skymap[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> N;
        memset(skymap, 0, sizeof(skymap)/sizeof(int));

        fill();
        print();
        cout << neighbors(1,1) << "\n";
    }



    return 0;
}
