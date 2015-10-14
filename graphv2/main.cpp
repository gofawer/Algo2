#include <iostream>
#include <vector>
using namespace std;

struct Vertices {
    vector<int> connect;
    bool visited;
};

int numVer = 7;
int numEdge;
Vertices *w = new Vertices[numVer+1];


void addEdge(int a, int b) {
    w[a].connect.push_back(b);
    w[b].connect.push_back(a);
    numEdge++;
}

void displayEdge() {
    for ( int i = 0; i < numVer+1; ++i ) {
        if ( w[i].connect.size() ) {
            for ( auto &elem : w[i].connect )
                cout << i << " <--> " << elem << endl;
        }
    }
}

int main()
{
    addEdge(1, 2);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(1, 3);
    addEdge(3, 6);
    addEdge(3, 7);

    displayEdge();


    return 0;
}

