#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include <string.h>
#include<limits.h>
#include<sys/stat.h>
#include<fcntl.h>
#define FIFO "ask.me"
#define PIPE_BUF 4096

int main(int argc,char* argv[]) {
    if(argc<4) {
        perror("ERROR");
        return -1;
    }
    FILE *fifo = fopen(FIFO, "w");
    for(int i=1; i<argc; i++) {

        char *msg= argv[i];
        fprintf(fifo,"%s ",msg);
//printf("%s ",argv[i]);
//fflush(fifo);

    }
    //for(int i=1; i < argc; i++) wait(NULL);
    fclose(fifo);
/*FILE *fifo5 = fopen(FIFO, "w");
char str[PIPE_BUF];
sprintf(str,"%d",getpid());
fprintf(fifo5,"%s ",str);*/



 char FIFO2[PIPE_BUF];
sprintf(FIFO2,"answer.%d",getpid());
printf("%d",getpid());
    int fd1 = open(FIFO2, O_RDONLY);
    char buf2[PIPE_BUF];
    while(1) {


        int n2 = read(fd1, buf2, PIPE_BUF);


        if(n2<1)break;
 printf("\n%s",buf2);
    }
close (fd1);
}
