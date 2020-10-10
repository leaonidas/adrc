
#include "graph.h"

#define N 11

Graph* allocateGraph(){

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    
    return graph;
}


/*Cada posição do vector vai apresentar apenas os seus "vizinhos"
a procura do nó será feita por índice*/

void addNode(Graph* graph, int tail, int head, int type){ //we are adding the new nodes in the beginning of the list!!!
    
    Node* aux = NULL;
    
    Node* node = (Node*)malloc(sizeof(Node));
    
    aux=graph->nodes[tail-1];    //aux fica com a primeira posição||
    graph->nodes[tail-1]=node;  //adicionar o novo nó na head do 
    node->next=aux;

    node->type=type;
    node->head=head-1;
}

void printGraph(Graph* graph){

    Node* aux=NULL;
    int i = 0;

    for(i=0;i<N;i++){
        if(graph->nodes[i]!=NULL){
            printf("Node %d -> %d(%d)", i, graph->nodes[i]->head, graph->nodes[i]->type);
            aux=graph->nodes[i];
            while(aux->next!=NULL){
                aux=aux->next;
                printf(", %d(%d)", aux->head, aux->type);
            }
            printf("\n");
        }
    }
}

void freetheGraph(Graph* graph, int graph_vector_size){
    int i;
    Node *aux, *aux2, *target;

    for(i=0; i < graph_vector_size; i++){
        target = graph->nodes[i]; //apontar para o primeiro nó de cada lista de nós
        aux = target;
        while(aux != NULL){ //percorrer essa respectiva lista enquanto se faz free das alocações do nó anterior
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }
        free(target); //dar free do primeiro nó de cada lista
    }
    free(graph); //dar free da estrutura do graph   
}