#include "graph.h"
#include <math.h>
#include <stdbool.h>

void pathType(Graph* graph, int src, int dest);
int nextVisit(int* dist, bool* visited, int size);
bool verifyComm(int prevConn, int nextConn);
void printSolution(int* dist, int* prev, int src, int dest);