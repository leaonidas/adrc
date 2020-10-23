#include "graph.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))


void isConnected(Graph*, int*);
void visit_neighbors_DFS(Graph*, int*, int);