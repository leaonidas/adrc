#include "biconnected.h"

int time=0;
int bi=1;
int edge1=-1;
int edge2=-1;
int rootSons=0;

void isBiconnected(Graph* graph){

	int visited[N];
	int d[N];
	int l[N];
	int pred[N];
	int i;

	time=0;

	for(i=0;i<N;i++){
		visited[i]=0;
		d[i]=0;
		l[i]=0;
		pred[i]=-1;
	}

	/*root is node 1*/
	artPoints(graph, 0, visited, d, l, pred);

	if(bi==1){
		printf("Graph is biconnected\n");
	}
	else{
		printf("Graph is not biconnected\n");
		if(edge1!=-1){
			printf("Bridge %d-%d\n\n\n", edge1+1, edge2+1);
		}
		else{
			printf("No bridges\n\n\n");
		}
		
	}

	/*for(i=0;i<N;i++){
	//	printf("%d ", d[i]);
	//	printf("%d\n", l[i]);
	//}*/

	return;
}



void artPoints(Graph* graph, int n, int visited[], int d[], int l[], int pred[]){

	Node* aux;
	aux=graph->nodes[n];

	visited[n]=1;
	time=time+1;
	d[n]=time;
	l[n]=d[n];
	
	/*printf("%d, ", n);*/
	/*printf("%d\n", time);*/
	
	while(aux!=NULL){
		
		if(visited[aux->head]==0){
				/*if is root and second child*/
				if(n==0){
					rootSons++;
					if(rootSons==2){
						/*printf("%d is an articulation point\n",n+1);*/
						bi=0;
					}
				}
				pred[aux->head]=n;
				artPoints(graph, aux->head, visited, d, l, pred);

				/*check if n is an articulation point*/
				if(l[aux->head]>=d[n] && n!=0){
					/*printf("%d is an articulation point\n",n+1);*/
					/*printf("aqui\n");*/
					bi=0;
				}

				l[n]=MIN(l[n], l[aux->head]);

				/*check if edge is bridge*/
				if(l[aux->head]>d[n]){
					/*printf("edge %d-%d is bridge\n", aux->head+1, n+1);*/
					edge1=aux->head;
					edge2=n;
				}
			}
			/*back edge*/
			else if (aux->head!=pred[n]){
				l[n]=MIN(l[n], d[aux->head]);
			}

		aux=aux->next;
	}

}




/*graph, no raiz, vetor visited*/
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

