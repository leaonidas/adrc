#include "graph.h"

#define N 11
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


void isConnected(Graph*);
void visit_neighbors_DFS(Graph*, bool[N], int);

