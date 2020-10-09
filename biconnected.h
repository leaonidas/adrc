#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define N 11


void isBiconnected(Graph* graph);
void artPoints(Graph* graph, int n, int visited[], int d[], int l[], int time);
void DFS(Graph* graph, int n, int visited[]);
