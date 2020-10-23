
#include "graph.h"


Graph* allocateGraph(){

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    
    return graph;
}

int* allocateVisited(){

    int* visited = (int*)malloc(N*sizeof(int));
    
    return visited;
}


/*Cada posição do vector vai apresentar apenas os seus "vizinhos"
a procura do nó será feita por índice*/

void addNode(Graph* graph, int tail, int head, int type, int* visited){ //we are adding the new nodes in the beginning of the list!!!
    
    Node* aux = NULL;
    
    Node* node = (Node*)malloc(N*sizeof(Node));
    
    aux=graph->nodes[tail-1];    //aux fica com a primeira posição||
    graph->nodes[tail-1]=node;  //adicionar o novo nó na head do 
    node->next=aux;

    node->type=type;
    node->head=head-1;
    visited[node->head] = -1;

    if(tail>graph->n){
        graph->n=tail;
    }

}

void printGraph(Graph* graph){

    Node* aux=NULL;
    int i = 0;

    for(i=0;i<N;i++){
        if(graph->nodes[i]!=NULL){
            printf("Node %d -> %d(%d)", i+1, graph->nodes[i]->head+1, graph->nodes[i]->type);
            aux=graph->nodes[i];
            while(aux->next!=NULL){
                aux=aux->next;
                printf(", %d(%d)", aux->head+1, aux->type);
            }
            printf("\n");
        }
    }
}

void freeGraph(Graph* graph){
    int i = 0;
    int reset = 1;
    Node *aux, *target;

    for(i=0; i < graph->n; i++){
        if (reset == 1) //caso estejamos a analisar 1 nova lista
        {
            target = graph->nodes[i]; //apontar para o primeiro nó de cada lista de nós
            reset = 0; //disable the reset flag
        }

        if (target != NULL) //IF List notempty -> PROCESS IT
        {
            while(target != NULL){ //percorrer essa respectiva lista enquanto se faz free das alocações do nó anterior
                aux = target->next;
                free(target);
                target = aux;
            }
            reset = 1; //since we are going to check another index of the vector
        }
        else{ //we should prepare the reset to process the next vector index
            reset = 1;
        }
    }
    free(graph); //dar free da estrutura do graph   
}