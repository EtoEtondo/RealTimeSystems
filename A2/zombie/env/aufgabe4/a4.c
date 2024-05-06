#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void printpid(char *id) {
    printf("%s PID: %d\n",id,getpid());
}

void printppid(char *id) {
    printf("%s PID: %d\n",id,getppid());
}


int main() {

pid_t pid=fork();

    if(pid==0){
		
        if (fork()==0) {

            printpid("Kind");
            sleep(2);
			//Vater stirbt
            printppid("Kind spricht:");
			//Opa wait
            sleep(5);
            printppid("Kind ich bin dein Vater :");
        }
        else{
            printpid("Vater");
            exit(0);
        }
		
    }
    else{
        printpid("Opa");
        sleep(5);
        wait(0);
    }

    return 0;
}
