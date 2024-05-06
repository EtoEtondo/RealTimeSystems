#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void copie(){
 pid=fork();

            if(pid==0) {

               
                exit(0);

            }
}

int main(int argc, char* argv[]) {

    pid_t pid;
    int k= atoi(argv[1]);
    int i;


  
//-------------------für k =-1---------------------------
    if(k ==-1) {

        for(;;) {

          copie();
          
        }
    }
//--------------k=Eingabe------------------------
    for(i=0; i<k; i++) {

       copie();

    for(;;) {

        sleep(1);


    }
    return 0;





}

