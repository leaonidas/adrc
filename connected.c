#include "connected.h"

void isConnected(Graph* graph, int* visited){ //returns true if connected

	int root_index = 0; //0 set as the top root by default

	visit_neighbors_DFS(graph, visited, root_index);
	//AFTER PROCESSING THE DFS and VISITED ALL NODES

	for(int i = 0; i < N; i++)
	{
		if(visited[i] == -1){
			printf("the graph is NOT CONNECTED\n\n");
			return;
		}
	}
	printf("the graph is CONNECTED\n\n");
	return;
}

void visit_neighbors_DFS(Graph* graph, int* visited, int target_index){

	Node* aux = graph->nodes[target_index]; //gets the first linked
	visited[target_index] = 1; //visit this node

	while(aux != NULL){
		if(visited[aux->head] == -1)
			visit_neighbors_DFS(graph,visited,aux->head);//recursive method to be applied in the target_node neighbors
		aux = aux->next;
	}

	return;
}