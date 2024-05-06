#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <string.h>
#define FIFO "ask.me"
#define CHILD 0


int main(int argc,char* argv[]) {
    if(argc<4) {
        perror("ERROR");
        return -1;
    }
         
  FILE *fifo = fopen(FIFO, "w");
//char str[10000];

     // sprintf(str,"%d:",getpid());
//printf("%s",msg);
    for(int i=1; i<argc; i++) {

       char *msg=argv[i];
        fprintf(fifo,"%s ",msg);
//printf("%s ",argv[i]);
//fflush(fifo);


    }
   // for(int i=1; i < argc; i++) wait(NULL);
   // fclose(fifo);

}

