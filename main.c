#include <stdio.h>
#include <stdlib.h>

FILE *fp;

/*neste ficheiro devemos ter apenas a leitura do ficheiro e a invocação dos algoritmos*/
int main(){

	int tailID = 0, headID = 0, type = 0;

	/*Opens and reads file that contains the graph
	If it's unable to find the file gives a warning and exits the program*/
	fp = fopen("ex.txt", "r");
	if(fp != NULL){
		while(fscanf(fp, "%d %d %d", &tailID, &headID, &type) != EOF){
			printf("%d %d %d\n", tailID, headID, type);
		}
		fclose(fp);
	}else{
		printf("Unable to open file!\n");
	}

	return 0;
	
}

