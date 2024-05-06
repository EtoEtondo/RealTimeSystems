#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main (){

pid_t pid;
pid=fork();

if(pid==0){
printf("i am the child\n");
printf ("Kindprozess: (PID: %d)\n", getpid());
printf ("Elternprozess: (PID: %d)\n", getpid());
}


if(pid>0){
	printf("I am the parent\n");
	
	printf ("Elternprozess: (PID: %d)\n", getpid());
	printf ("Kindprozess: (PID: %d)\n", getpid());
}
printf("\n");
	








}

