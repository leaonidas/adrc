#include "graph.h"


void commercialyCyclic(Graph* graph);
bool DFSComm(Graph* graph, int n, int visited[], int prev);
bool finalNode(Node* node);