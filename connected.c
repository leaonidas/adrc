#include "connected.h"

void isConnected(Graph* graph){ //returns true if connected

	bool visited[N]; //has the info about the lrdy visited nodes
	int root_index = 0; //0 set as the top root by default
	int created_nodes_counter = 6;

	visit_neighbors_DFS(graph, visited, root_index);
	//AFTER PROCESSING THE DFS and VISITED ALL NODES

	for(int i = 0; i < created_nodes_counter; i++)
	{
		if(visited[i] == false){
			printf("the graph is NOT CONNECTED\n\n");
			return;
		}
	}
	printf("the graph is CONNECTED\n\n");
	return;
}

void visit_neighbors_DFS(Graph* graph, bool visited[], int target_index){

	Node* aux = graph->nodes[target_index]; //gets the first linked

	while(aux != NULL){
		visit_neighbors_DFS(graph,visited,aux->head);//recursive method to be applied in the target_node neighbors
		aux = aux->next;
	}

	visited[target_index] = true;	

	return;
}