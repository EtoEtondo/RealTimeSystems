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
#include "programm.h"


int main(int argc,char*argv[]) {
    int pfd[2];
    FILE *fp;
    int len=1000;
    char *line[len];
    int summe=0;
    int x=atoi(argv[2]);
    pid_t pid;

    if(argc!=3) {
        perror("ERROR");
        return 1;
    }

    if((fp=fopen(argv[1],"r"))==NULL) {
        perror(" open failed\n");
        return -1;
    } else {
        puts("open success\n");

        if(pipe(pfd)<0) {
            perror("pipe");

        } else {

            store(fp, &line[0]);

            for(int i=0; i<x; i++) {

                pid=fork();

                if(pid==0) {
                    write_in( pfd, len, i, x, &line[0],summe);

                    fclose(fp);
                    exit(0);
                }
            }
            if(pid>0) {
                int total1=read_out(pfd, summe, x);
                printf("Totale Quersumme:%d\n",total1);
		wait(NULL);
            }
        }
    }

}

