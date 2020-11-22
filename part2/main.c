#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pathtype.h"

FILE *fp;
int graphSize=0;

/*neste ficheiro devemos ter apenas a leitura do ficheiro e a invocação dos algoritmos*/
int main(int argc, char *argv[]){

	int tailID = 0, headID = 0, type = 0;
	int src = 0, dest = 0;
	char file[30], temp[5], option;
	int* visited = NULL;
	Graph* graph = NULL;

	if(argc<2) exit(0);

	strcpy(file, argv[1]);
	strcpy(temp, argv[2]);
	src = atoi(temp);
	strcpy(temp, argv[3]);
	dest = atoi(temp);

	printf("Source: %d\nDest: %d\n", src, dest);

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
	
	printGraph(graph);

	while(strcmp(&option,"4")!=0){

		printf("\nSelect the algorithm:\n\n");
		printf("1- Type of BGP path\n");
		printf("2- Length of BGP path\n");
		printf("3- commercially acyclic\n");
		printf("4- exit\n");
		printf("\n");

		scanf("%s", &option);
		printf("\n");


		if(strcmp(&option,"1")==0){
			pathType(graph, src, dest);
		}
		else if(strcmp(&option,"2")==0){
			printf("developing...\n");
		}
		else if(strcmp(&option,"3")==0){
			printf("developing...\n");
		}
		else if(strcmp(&option,"4")!=0){
			printf("Invalid input\n\n");
		}
	}

	/*freeGraph(graph);*/
	
	return 0;
}

