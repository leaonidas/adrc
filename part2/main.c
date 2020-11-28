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
	int totalCounter_c = 0;
	int totalCounter_r = 0;
	int totalCounter_p = 0;

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
			totalCount_typePaths(&totalCounter_p, &totalCounter_r, &totalCounter_c, type);
		}
		fclose(fp);
	}else{
		printf("Unable to open file!\n");
		exit(1);
	}

	printf("%d nós \n\n", graph->n);
	
	printGraph(graph);

	printf("\nC: %d\nR: %d\nP: %d\n", totalCounter_c, totalCounter_r, totalCounter_p);

	while(strcmp(&option,"4")!=0){

		printf("\nSelect the algorithm:\n\n");
		printf("1- Type of BGP path\n");
		printf("2- Length of shortest BGP path\n");
		printf("4- exit\n");
		printf("\n");

		scanf("%s", &option);
		printf("\n");


		if(strcmp(&option,"1")==0){
			pathType(graph, src, dest);
		}
		else if(strcmp(&option,"2")==0){
			shortestPath(graph, src, dest);
		}
		else if(strcmp(&option,"4")!=0){
			printf("Invalid input\n\n");
		}
	}

	/*freeGraph(graph);*/
	
	return 0;
}

void totalCount_typePaths(int* totalCounter_p, int* totalCounter_r, int* totalCounter_c, int type){
    switch(type){

        case 1://provider link
            *totalCounter_p += 1;
            break;

        case 2: //peer link
            *totalCounter_r +=1;
            break;

        case 3: //customer link
            *totalCounter_c += 1;
            break;
            
    }
    return;
}