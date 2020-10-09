#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

FILE *fp;

/*neste ficheiro devemos ter apenas a leitura do ficheiro e a invocação dos algoritmos*/
int main(){

	int tailID = 0, headID = 0, type = 0;
	int option=0;

	Graph* graph=allocateGraph();

	/*Opens and reads file that contains the graph
	If it's unable to find the file gives a warning and exits the program*/
	fp = fopen("ex.txt", "r");
	if(fp != NULL){
		while(fscanf(fp, "%d %d %d", &tailID, &headID, &type) != EOF){
			addNode(graph, tailID, headID, type);
		}
		fclose(fp);
	}else{
		printf("Unable to open file!\n");
	}
	
	printGraph(graph);

	while(option!=5){

		printf("Select the algorithm:\n\n");
		printf("1- connected\n");
		printf("2- biconnected\n");
		printf("3- commercially acyclic\n");
		printf("4- commercially connected\n");
		printf("5- exit");
		printf("\n");

		scanf("%d", &option);

		if(option==1){

		}
		else if(option==2){
			
		}
		else if(option==3){
			
		}
		else if(option==4){
			
		}
	}
	
	return 0;
	
}

