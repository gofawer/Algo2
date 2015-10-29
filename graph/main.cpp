#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct {
    int n;
    int** adj;
}  Graph;

void init(Graph* g, int n);
void addEdge(Graph* g, int n, int m);
void display(Graph const* g);


int main()
{
    Graph *g = (Graph*) malloc(sizeof(Graph));
    //struct Vector *y = malloc(sizeof *y);
    init(g, 7);
    display(g);

    return 0;
}

void init(Graph* g, int n) {
    g->n = n;
    g->adj = (int**) calloc(n, sizeof(int*));

    for (int k = 0; k < n; k++) {
        g->adj[k] = (int*) calloc(n, sizeof(int));
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void display(const Graph *g) {
    for (int i = 0; i < g->n; ++i) {
        for (int j = 0; j < g->n; ++j) {
            if (g->adj[i][j]) {
                printf("%c%c", (char)('A' + i), '-');
                printf("%c%s", (char)('A' + i), "  ");
            }
            printf("|\n");
        }
    }
}
