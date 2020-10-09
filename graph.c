#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

Graph* allocateGraph(){

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    
    return graph;
}


/*Cada posição do vector vai apresentar apenas os seus "vizinhos"
a procura do nó será feita por índice*/

void addNode(Graph* graph, int i){ //we are adding the new nodes in the beginning of the list!!!
    
    Node* aux = NULL;
    
    Node* node = (Node*)malloc(sizeof(Node));
    
    aux=graph->nodes[i];    //aux fica com a primeira posição||
    graph->nodes[i]=node;  //adicionar o novo nó na head do 
    node->next=aux;
    // aux = graph
}




int check_if_node_exits(int nodeValue, Graph* graphHead){ //percorre o vector para checkar se o nó já existe || Se existir, retorna o index respectivo desse mesmo valor

    Graph* aux = graphHead; //the aux gets the graph_head
    int index = 0;
    
    while(aux->nodes[index] != NULL){ //if null there is nothing from this point from now on
        if(aux->nodes[index] == nodeValue) //node founded
            return index;

        index++;
    } 

    return index; //if there is no node with this value
}