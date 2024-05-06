#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



void txt() {
    char *owner = getlogin();
    printf("Goodbye... %s \n",owner);

}


int main () {

    pid_t pid;

 
    printf("-----------------------------------\n");

    pid=fork();

    if(pid<0) {

        fprintf(stderr,"Fehler!!!!\n");
        return EXIT_FAILURE;

    }


    if(pid==0) {

        printf("IM KINDPROZESS: (PID: %d)\n", getpid());
        printf("dessen Elternprozess:(PID: %d)\n",getppid());

        sleep(2);
        printf("\n");

        printf ("Im Kindprozess (PID: %d)\n",getpid());
        printf("dessen neues Elternprozess : (PID:%d)\n", getppid());


    }

    if(pid>0) {
        printf("IM ELTERNPROZESS: (PID: %d)\n", getpid());
        printf("\n");

        atexit(txt);
        exit(0);


    }
    return 0;

}



