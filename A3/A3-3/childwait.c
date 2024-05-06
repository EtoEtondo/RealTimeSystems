#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int n=0;

void signalhandler() {
 pid_t pid;

  pid=wait(NULL);
  n--;
printf("Child(%d): terminated (n=%d)\n\n",pid,n);
}

int main(int argc, char* argv[]) {
    if(argc !=2) {
        perror("ERROR");
        return 1;
    }
    pid_t pid;
    int k= atoi(argv[1]);
    int i=0;

    //int status;



    signal(SIGCHLD,signalhandler);


//pid=fork();
    for(i=0; i<k; i++) {


        pid=fork();

        if(pid==0) {



            sleep(i+k-1);

            exit(0);


        }

        if(pid>0) {

            n++;

            printf("CHILD(%d): started (n=%d)\n",pid,n);



        }

    }
    for(int j = 0; j < 1; j++) {

        //printf("Parent(%d): sleep(2)\n", getppid());
        sleep(2);
 //printf("Parent(%d): sleep(2)\n", getppid());
        //pid=wait(&status);
       // printf("Child(%d): terminated (n=%d)\n\n",pid,n);
        //c++;
        if(n != 0) {
printf("Parent(%d): sleep(2)\n", getpid());

            j--;

        }

    }
    printf("Parent(%d): terminated\n", getpid());

    return 0;
}
/*while(n!=0){

      printf("Parent (%d): sleep(2)\n",getppid());
    sleep(2);

}*/




/*  n++;
int t=i;
 pid=fork();
if(pid==0){
printf("Child:%d:sleep(%d) (n=%d)\n",getpid(),t,n);
sleep(t);
printf("Child:%d:terminated (n=%d)\n",getpid(),n);
return 0;
}
}
while(n!=0){
printf("parent%d:sleep(2)\n",getpid());
sleep(2);
}
return 0;



}*/












