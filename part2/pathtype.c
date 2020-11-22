#include "pathtype.h"

void pathType(Graph* graph, int src, int dest){
    /*implementar apenas dijkstra para dar o path cost minimo*/
    /*implementar para imprimir o caminho optimo*/
    /*adicionar regras bgp*/
    int i = 0, visit = 0, next = 0;
    double inf = 70000;
    int dist[graph->n];
    int prev[graph->n];
    bool visited[graph->n];
    Node* aux;

    for(i=0; i<graph->n; i++){
        dist[i] = inf; prev[i] = -1; visited[i] = false;
    }
    dist[src-1] = 0;
    printf("Entering main loop!\n");
    for(i = 0; i < graph->n; i++){
        visit = nextVisit(dist, visited, graph->n);
        printf("tens de dar return\n");
        printf("não curtes do visit: %d", visit);
        visited[visit] = true;

        aux = graph->nodes[visit];
        while(aux != NULL){
            if(!visited[visit] && (dist[visit] + 1) < dist[aux->head]){
                dist[aux->head] = dist[visit] + 1;
                prev[aux->head] = visit;
            }
        }
    }

}

int nextVisit(int* dist, bool* visited, int size){
    int min = 70000, next = 0, i = 0;
    for(i = 0; i < size; i++){
        if(dist[i] <= min && visited[i] == false){
            next=i; min = dist[i];
        }
    }
    printf("antes do return: %d\n", next);
    return next;
}

void printSolution(int* dist, int* prev, int src, int dest){
    int aux = dest;
    
    printf("Shortest path cost: %d\n", dist[dest]);
    printf("Shortest path: %d", dest);
    while(aux != src){
        printf("-%d", prev[aux]);
        aux=prev[aux];
    }
    printf("\n");
}