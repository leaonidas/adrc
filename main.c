#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biconnected.h"
#include "cyclic.h"
#include "connected.h"
#include "commer_connected.h"

FILE *fp;

/*neste ficheiro devemos ter apenas a leitura do ficheiro e a invocação dos algoritmos*/
int main(int argc, char *argv[]){

	int tailID = 0, headID = 0, type = 0;
	/*int option=0;*/
	char file[30], option;
	int* visited = NULL;
	Graph* graph = NULL;

	if(argc<2) exit(0);

	strcpy(file, argv[1]);

	graph=allocateGraph();
	visited = allocateVisited();

	/*printf("Insert file name:\n");*/
	/*scanf("%s", &file);*/

	/*exbiconnected.txt*/
	/*Opens and reads file that contains the graph
	If it's unable to find the file gives a warning and exits the program*/
	fp = fopen(file, "r");
	if(fp != NULL){
		while(fscanf(fp, "%d %d %d", &tailID, &headID, &type) != EOF){
			addNode(graph, tailID, headID, type, visited);
		}
		fclose(fp);
	}else{
		printf("Unable to open file!\n");
		exit(1);
	}

	printf("%d nós \n\n", graph->n);
	
	/*printGraph(graph);*/

	while(strcmp(&option,"5")!=0){

		printf("\nSelect the algorithm:\n\n");
		printf("1- connected\n");
		printf("2- biconnected\n");
		printf("3- commercially acyclic\n");
		printf("4- commercially connected\n");
		printf("5- exit\n");
		printf("\n");

		scanf("%s", &option);
		printf("\n");


		if(strcmp(&option,"1")==0){
			isConnected(graph, visited);
		}
		else if(strcmp(&option,"2")==0){
			isBiconnected(graph);
		}
		else if(strcmp(&option,"3")==0){
			commercialyCyclic(graph);
		}
		else if(strcmp(&option,"4")==0){
			isCommercial_Connected(graph, visited);
		}
		else if(strcmp(&option,"5")!=0){
			printf("Invalid input\n\n");
		}
	}

	/*freeGraph(graph);*/
	
	return 0;
}

