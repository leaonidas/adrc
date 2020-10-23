#include "graph.h"


void commercialyCyclic(Graph* graph);
bool DFSComm(Graph* graph, int n, int visited[], int prev);
void debugMsg(char *msg);