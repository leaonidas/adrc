#include "graph.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))


void isBiconnected(Graph* graph);
void artPoints(Graph* graph, int n, int visited[], int d[], int l[], int pred[]);
void DFS(Graph* graph, int n, int visited[]);
