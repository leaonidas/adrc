#include "biconnected.h"

void isBiconnected(Graph* graph){

	int visited[N];
	int d[N];
	int l[N];
	int time=0;
	int i;

	for(i=0;i<N;i++){
		visited[i]=0;
		d[i]=0;
		l[i]=0;
	}

	//start algorithm in node 1
	//DFS(graph, 0, visited);

	/*for(i=0;i<N;i++){
		printf("%d ", visited[i]);
	}*/

	return;
}

void artPoints(Graph* graph, int n, int visited[], int d[], int l[], int time){

	Node* aux;
	aux=graph->nodes[n];

	visited[n]=1;
	time=time+1;
	d[n]=time;
	l[n]=d[n];
	
	printf("%d\n", n);
	
	if(graph->nodes[n]!=NULL){
		
		if(visited[aux->head]==0)
			artPoints(graph, aux->head, visited, d, l);

        while(aux->next!=NULL){
            aux=aux->next;

			if(visited[aux->head]==0)
				artPoints(graph, aux->head, visited, d, l);
        }
    }
}




void DFS(Graph* graph, int n, int visited[]){

	Node* aux;
	aux=graph->nodes[n];

	visited[n]=1;
	printf("%d\n", n);
	
	if(graph->nodes[n]!=NULL){
		
		if(visited[aux->head]==0)
			DFS(graph, aux->head, visited);

        while(aux->next!=NULL){
            aux=aux->next;

			if(visited[aux->head]==0)
				DFS(graph, aux->head, visited);
        }
    }
}

