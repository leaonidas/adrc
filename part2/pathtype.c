#include "pathtype.h"

void pathType(Graph* graph, int src, int dest){
    /*implementar apenas dijkstra para dar o path cost minimo*/
    /*implementar para imprimir o caminho optimo*/
    /*adicionar regras bgp*/
    int i = 0, visit = 0, next = 0;
    double inf = 70000;
    int dist[graph->n];
    int prev[graph->n];
    int typePrev[graph->n];
    bool visited[graph->n];
    Node* aux;

    for(i=0; i<graph->n; i++){
        dist[i] = inf; prev[i] = -1; visited[i] = false;
    }
    dist[src-1] = 0;
    typePrev[src-1] = 0;
    
    for(i = 0; i < graph->n; i++){
        visit = nextVisit(dist, visited, graph->n);
        if(visit == -1){
            printf("No commercial path found between nodes!\n");
            return;
        }
        visited[visit] = true;
        printf("Nó em que está: %d\n", visit);
        aux = graph->nodes[visit];
        while(aux != NULL){
            if(!visited[aux->head] && (dist[visit] + 1) < dist[aux->head] && verifyComm(typePrev[visit], aux->type)){
                dist[aux->head] = dist[visit] + 1;
                prev[aux->head] = visit;
                typePrev[aux->head] = aux->type;
                printf("Nó vizinho visitado: %d   Distância até ao nó: %d\n", aux->head, dist[aux->head]);
                if(aux->head == dest-1){
                    printSolution(dist, prev, src, dest);
                    return;
                }
            }
            aux = aux->next;
            printf("\n\n");
        }
    }
}

int nextVisit(int* dist, bool* visited, int size){
    int min = 70000, next = -1, i = 0;
    for(i = 0; i < size; i++){
        if(dist[i] < min && visited[i] == false){
            next=i; min = dist[i];
        }
    }
    return next;
}

bool verifyComm(int prevConn, int nextConn){

    if(prevConn == 0) return true;

    if(nextConn == 1) return true;

    else if(nextConn == 2 && prevConn == 3) return true;

    else if(nextConn == 3 && prevConn == 3) return true;

    return false;

}


void printSolution(int* dist, int* prev, int src, int dest){
    int aux = dest-1;
    
    printf("Shortest path cost: %d\n", dist[aux]);
    printf("Shortest path: %d", dest);
    while(aux != src-1){
        printf("-%d", prev[aux]+1);
        aux=prev[aux];
    }
    printf("\n");
}