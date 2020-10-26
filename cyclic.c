#include "cyclic.h"

void commercialyCyclic(Graph* graph){
    int visited[N];
    int i;

    /*Establish all nodes as not visited*/
    for(i=0; i<N; i++){
        visited[i]=0;
    }

    /*Run DFS in nodes not yet visited*/
    for(i=0; i<N; i++){
        if(visited[i]==0){
            printf("nó inicial que visita: %d\n\n", i);
            if(DFSComm(graph, i, visited, -1)){
                printf(" %d", i+1);
                printf("\n\n");
                return;
            }
        }
    }
    printf("Graph is acyclic!\n\n");
    return;

}

/*n is the parent node, visited is a vector to verify is nodes*/
/*have already been visited*/
bool DFSComm(Graph* graph, int n, int visited[], int prev){

    Node* aux;
    aux = graph->nodes[n];

    visited[n] = 1;
    /*goes through the nodes neighbours*/
    while (aux != NULL)
    {   /*verifies if the node has been visited*/
        /*printf("Neighbour node: %d\n", aux->head);*/
        if(visited[aux->head] == 0 && aux->type == 1){
            /*runs DFS on neighbour node recursivelly*/
            prev = n;
            if(DFSComm(graph, aux->head, visited, prev)){
                printf(" %d", aux->head+1);
                return true;
            }
        }
        /*if the node is visited and different to the previous node*/
        else if(aux->head != prev && aux->type == 1 && finalNode(aux)){
            printf("Nodes in cycle: %d", aux->head+1);
            return true;
        }
        aux = aux->next;
    }
    /*visited[n] = 0;*/
    return false;
}

bool finalNode(Node* node){
    Node* aux;
    aux = node;

    while(aux != NULL){
        if(aux->type == 1){
            return true;
        }
        aux = aux->next;
    }
    return false;
}