#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biconnected.h"
#include "cyclic.h"

FILE *fp;

/*neste ficheiro devemos ter apenas a leitura do ficheiro e a invocação dos algoritmos*/
int main(){

	int tailID = 0, headID = 0, type = 0;
	//int option=0;
	char file, option;

	Graph* graph=allocateGraph();

	printf("Insert file name:\n");
	scanf("%s", &file);

	//exbiconnected.txt
	/*Opens and reads file that contains the graph
	If it's unable to find the file gives a warning and exits the program*/
	fp = fopen(&file, "r");
	if(fp != NULL){
		while(fscanf(fp, "%d %d %d", &tailID, &headID, &type) != EOF){
			addNode(graph, tailID, headID, type);
		}
		fclose(fp);
	}else{
		printf("Unable to open file!\n");
	}
	
	printGraph(graph);

	while(strcmp(&option,"5")!=0){

		printf("Select the algorithm:\n\n");
		printf("1- connected\n");
		printf("2- biconnected\n");
		printf("3- commercially acyclic\n");
		printf("4- commercially connected\n");
		printf("5- exit\n");
		printf("\n");

		scanf("%s", &option);
		printf("\n");


		if(strcmp(&option,"1")==0){

		}
		else if(strcmp(&option,"2")==0){
			isBiconnected(graph);
		}
		else if(strcmp(&option,"3")==0){
			commercialyCyclic(graph);
		}
		else if(strcmp(&option,"4")==0){
			
		}
		else if(strcmp(&option,"5")!=0){
			printf("Invalid input\n\n");
		}
	}
	
	return 0;
	
}

