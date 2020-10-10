#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define N 11
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


void isBiconnected(Graph* graph);
void artPoints(Graph* graph, int n, int visited[], int d[], int l[], int pred[], int time);
void DFS(Graph* graph, int n, int visited[]);
