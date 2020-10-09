#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int head, type;
	struct node* next;
}Node;

typedef struct
{
	Node* nodes[65535]; //lista de listas ou vector de lista
}Graph;


Graph* allocateGraph();
void addNode(Graph* graph, int head, int tail, int type);
void printGraph(Graph* graph);

