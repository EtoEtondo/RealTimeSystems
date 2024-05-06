#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int n = 0;

void sig_child(){
	n--;
	printf("(%d)\n", n);
}

int main(int argc, char *argv[]){
	if(argc !=2){
		perror("USAGE: ./childwait int");
		return 1;
	}

	signal(SIGCHLD, sig_child);

	int k = atoi(argv[1]);
	int pid;

	for(int i = 0; i < k; i++){
		switch(pid = fork()){
			case -1: perror("error"); break;
			case 0:  sleep(i+2);
				 printf("\nChild %d: kill", getpid());
				 return 0; break;
			default: n++;
				 printf("\nChild %d: born(n = %d)\n", pid, n); break;
		}
	}
	printf("\nfull\n");
	for(int j = 0; j < 1; j++){
		printf("\nParent %d: sleeping\n", getpid());
		pause();
		if(n != 0) --j;
	}
	printf("Parent %d: dying in their sleep\n", getpid());

	return 0;
}
