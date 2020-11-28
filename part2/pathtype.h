#include "graph.h"
#include <math.h>
#include <stdbool.h>

void pathType(Graph* graph, int src, int dest);
int nextVisit(int* dist, bool* visited, int* typePrev, int size);
bool verifyComm(int prevConn, int nextConn);
void printSolution(int* dist, int* prev, int* typePrev, int src, int dest);
void shortestPath(Graph* graph, int src, int dest);