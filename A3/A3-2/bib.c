#include "bib.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>





int my_sigemptyset(my_sigset_t *set){

   set->sigset=0x00000000;

   return 0;


}

int my_sigfillset(my_sigset_t *set){
set->sigset=0xffffffff;

return 0;
}

int my_sigaddset(my_sigset_t *set,int signum){

set->sigset|=(1<<signum);
return 0;
}

int my_sigdelset(my_sigset_t *set,int signum){
set->sigset&=~(1<<signum);

return 0;
}

int my_sigismember(my_sigset_t *set,int signum){

	if(set->sigset & (1<<signum)){
		return 1;
	}else{
		return 0;
	}
}













