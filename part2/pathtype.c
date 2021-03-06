#include "pathtype.h"

int typeOfPath = -1;

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
        visit = nextVisit(dist, visited, typePrev, graph->n);
        if(visit == -1){
            printf("No commercial path found between nodes!\n");
            return;
        }
        visited[visit] = true;
        printf("Nó em que está: %d\n", visit + 1);
        aux = graph->nodes[visit];
        while(aux != NULL){
            if(!visited[aux->head] && (dist[visit] + 1) < dist[aux->head] && verifyComm(typePrev[visit], aux->type)){
                dist[aux->head] = dist[visit] + 1;
                prev[aux->head] = visit;
                typePrev[aux->head] = aux->type;
                printf("Nó vizinho visitado: %d   Distância até ao nó: %d\n", aux->head+1, dist[aux->head]);
                if(aux->head == dest-1){
                    printSolution(dist, prev, typePrev, src, dest);
                    return;
                }
            }
            aux = aux->next;
            printf("\n\n");
        }
    }
}

void shortestPath(Graph* graph, int src, int dest){

    //dijkstra completo

    int i = 0, visit = 0, next = 0;
    double inf = 70000;
    int dist[graph->n];
    int prev[graph->n];
    int typePrev[graph->n];
    bool visited[graph->n];
    Node* aux;

    if(typeOfPath == -1){
        printf("Please run option 1 first!\n");
        return;
    }

    for(i=0; i<graph->n; i++){
        dist[i] = inf; prev[i] = -1; visited[i] = false;
    }
    dist[src-1] = 0;
    typePrev[src-1] = 0;
    
    for(i = 0; i < graph->n; i++){
        visit = nextVisit(dist, visited, typePrev, graph->n);
        visited[visit] = true;
        printf("Nó em que está: %d\n", visit + 1);
        aux = graph->nodes[visit];
        while(aux != NULL){
            if(!visited[aux->head] && (dist[visit] + 1) < dist[aux->head] && verifyComm(typePrev[visit], aux->type)){
                if(i==0 && aux->type==typeOfPath){
                    dist[aux->head] = dist[visit] + 1;
                    prev[aux->head] = visit;
                    typePrev[aux->head] = aux->type;
                    printf("Nó vizinho visitado: %d   Distância até ao nó: %d\n", aux->head+1, dist[aux->head]);
                }
                else if(i!=0){
                    dist[aux->head] = dist[visit] + 1;
                    prev[aux->head] = visit;
                    typePrev[aux->head] = aux->type;
                    printf("Nó vizinho visitado: %d   Distância até ao nó: %d\n", aux->head+1, dist[aux->head]);
                }
            }
            aux = aux->next;
            printf("\n\n");
        }
    }
    printf("Length of shortest path: %d\n", dist[dest-1]);
}


int nextVisit(int* dist, bool* visited, int* typePrev, int size){
    int min = 70000, next = -1, i = 0, priority = 4;
    for(i = 0; i < size; i++){
        if(dist[i] < min && visited[i] == false && typePrev[i] < priority){
            next=i; min = dist[i]; priority = typePrev[i];
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


void printSolution(int* dist, int* prev, int* typePrev, int src, int dest){
    int aux = dest-1, second = 0; 
    
    printf("Shortest path cost: %d\n", dist[aux]);
    printf("Shortest path: %d", dest);
    while(aux != src-1){
        printf("-%d", prev[aux]+1);
        second = aux;
        aux=prev[aux];
    }
    printf("\n");
    typeOfPath = typePrev[second];
    if(typePrev[second] == 1) printf("Costumer path.\n");
    else if(typePrev[second] == 2) printf("Peer path.\n");
    else if(typePrev[second] == 3) printf("Provider path.\n");
}

