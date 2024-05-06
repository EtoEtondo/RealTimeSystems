#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main(int argc, char* argv[]){

if(argc != 2) fprintf(stderr,"./main.c <graph.txt>");

FILE *f= fopen(argv[1],"r");
if(!f){
	fprintf(stderr,"File not found!");
	return -1;
}

char *buffer=NULL;
size_t n=0;

getline(&buffer,&n,f);
int anzthreads= atoi(buffer);

getline(&buffer,&n,f);
int anzresources = atoi(buffer);

int reihe, spalte;
reihe = spalte = anzthreads + anzresources;

printf("Threads: %d, Reasources: %d, Anz. Reihe/Spalten: %d\n",anzthreads, anzresources, reihe);

int *graph = (int*) malloc(reihe*reihe*sizeof(int));

while(getline(&buffer,&n,f) != -1){

char typ; int von, zu;
sscanf(buffer,"%c %d %d", &typ, &von, &zu);
von--; zu--; 

	if(typ=='o'){
		von += anzthreads;
	}
	else if(typ=='w'){
		zu += anzthreads;
	}else{
		fprintf(stderr,"Unbekannter Typ\n");
	}

graph[reihe*spalte + zu]=1;
}


print_header(anzthreads, anzresources);
print_matrix(graph, reihe);

int deadlock= deadlock_cycle(graph, reihe);
printf("Deadlock found: %d\n",deadlock);


free(graph);
free(buffer);
fclose(f);

return 0;
}
