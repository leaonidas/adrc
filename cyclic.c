#include "cyclic.h"

void commercialyCyclic(Graph* graph){

    int visited[N], recStack[N];
    int i, j;

    for(i=0; i<N; i++){
        visited[i]=0;
        recStack[i]=0;
    }

    for(i=0; i<N; i++){
        if(DFSComm(graph, i, visited, recStack)){
            printf("Graph has a cycle.\n\n");
            for(j=0; j<N; j++){
                if(recStack[j]==1) printf("%d ", j+1);
            }
            printf("\n\n");
            return;
        }
    }
    printf("Graph is acyclic!\n\n");
    return;

}

bool DFSComm(Graph* graph, int n, int visited[], int recStack[]){

    Node* aux;
    aux = graph->nodes[n];

    if(visited[n]==0){
        visited[n] = 1;
        recStack[n] = 1;

        while(aux->next!=NULL){

            if(visited[aux->head]==0 && DFSComm(graph, aux->head, visited, recStack)){
                return true;
            }else if(recStack[aux->head]==1){
                return true;
            }

            if(aux->next!=NULL) aux=aux->next;
        }
    }
    recStack[n]=0;
    return false;
}