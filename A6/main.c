#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <byteswap.h>
#include <sys/wait.h>
#include "quersumme.h"
#include <pthread.h>

int main(int argc,char*argv[]) {
   
    FILE *fp;
   // int start=0;
    int len=1000;
    char *line[len];
   
    int x=atoi(argv[2]);
  

    if(argc!=3) {
        perror("ERROR");
        return 1;
    }

    if((fp=fopen(argv[1],"r"))==NULL) {
        perror(" open failed\n");
        return -1;
    } else {
        puts("open success\n");

            store(fp, &line[0]);
            pthread_t *thread = malloc(sizeof(pthread_t)*x);
            for(int i=0; i<x; i++) {

            pthread_create(&thread[i], NULL, quersumme,&line[0]);
               
//printf("%d",sum);
            
                   // write_in( pfd, len, i, x, &line[0],summe);

                   
                 
                
            }
           
               
               
		
          
        }
    

}

