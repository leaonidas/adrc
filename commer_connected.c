#include "commer_connected.h"

void isCommercial_Connected(Graph* graph, int* visited){ /*returns true if connected*/

	int root_index = 0; /*0 set as the top root by default*/
	int i = 0;
    int previous_type = -1; /*-1 if uninitialized || 1 if it comes FROM a customer || 0 if it doesn't come FROM a customer*/

	visit_commercial_neighbors_DFS(graph, visited, root_index, previous_type);

	/*AFTER PROCESSING THE DFS and VISITED ALL NODES*/

    /*NOW IT'S TIME TO CHECK THE VISITED ARRAY*/
	for(i = 0; i < N; i++)
	{
		if(visited[i] == -1){
			printf("the graph is NOT COMMERCIALLY CONNECTED\n\n");
			return;
		}
	}
	printf("the graph is COMMERCIALLY CONNECTED\n\n");
	return;
}

void visit_commercial_neighbors_DFS(Graph* graph, int* visited, int target_index, int previous_type){

	Node* aux = graph->nodes[target_index]; /*gets the first linked*/
    int aux_previous_type = previous_type; /*in order 2 don't loose the current type after the recursive method*/

	visited[target_index] = 1; /*visit this node*/

	while(aux != NULL){
		if(visited[aux->head] == -1){ /*if not visited*/

            switch(aux->type){
                case 1: /*if the head is a CUSTOMER*/
                    assign_previoustype_b4_recursive(previous_type, &aux_previous_type);

                    previous_type = 0;/*it comes from a PROVIDER*/
			        visit_commercial_neighbors_DFS(graph,visited,aux->head,previous_type); /*recursive method*/
                    reassign_previoustype_after_recursive(&previous_type, aux_previous_type);
                    break;

                case 3:/*if the head is a PROVIDER*/
                    if( check_iniciativa_or_customer(previous_type) ){ /*if we are in the 1st node OR if it comes from a customer*/
                        assign_previoustype_b4_recursive(previous_type, &aux_previous_type);

                        previous_type = 1; /*it comes from a CUSTOMER*/
                        visit_commercial_neighbors_DFS(graph,visited, aux->head, previous_type);
                        reassign_previoustype_after_recursive(&previous_type, aux_previous_type);
                    }
                    break;

                case 2: /*if the head is a PEER*/
                    if( check_iniciativa_or_customer(previous_type) ){
                        assign_previoustype_b4_recursive(previous_type, &aux_previous_type);

                        previous_type = 0;/*it comes from a PEER*/
                        visit_commercial_neighbors_DFS(graph,visited,aux->head, previous_type);
                        reassign_previoustype_after_recursive(&previous_type, aux_previous_type);
                    }
                    break;

                default:
                    break;
            }
        }

        aux = aux->next;
	}

	return;
}


int check_iniciativa_or_customer(int previous_type){

    if(previous_type == -1 || previous_type == 1)
        return 1;

    return 0;
}

void assign_previoustype_b4_recursive(int previous_type, int* aux_previous_type){
    *aux_previous_type = previous_type;

    return;
}

void reassign_previoustype_after_recursive(int* previous_type, int aux_previous_type){
    *previous_type = aux_previous_type;

    return;
}