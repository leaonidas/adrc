#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef N
#define N 65535
#endif

#ifndef GRAPH_H
#define GRAPH_H
typedef struct node
{
	int head, type;
	struct node* next;
}Node;

typedef struct
{
	Node* nodes[65535]; /*lista de listas ou vector de lista*/
	int n;
}Graph;

Graph* allocateGraph();
void addNode(Graph* graph, int head, int tail, int type, int* visited);
int* allocateVisited();
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
#endif

