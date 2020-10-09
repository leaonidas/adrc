
#include "graph.h"

#define N 5

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
    node->head=head;
}

void printGraph(Graph* graph){

    Node* aux=NULL;
    int i = 0;

    for(i=0;i<N;i++){
        if(graph->nodes[i]!=NULL){
            printf("Node %d -> %d(%d)", i+1, graph->nodes[i]->head, graph->nodes[i]->type);
            aux=graph->nodes[i];
            while(aux->next!=NULL){
                aux=aux->next;
                printf(", %d(%d)", aux->head, aux->type);
            }
            printf("\n");
        }
    }
}
