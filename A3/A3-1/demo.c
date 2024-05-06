#include <stdio.h>
#include "process.h"
#include <stdint.h>
#include <stdlib.h>
#include "queue.h"
#include "processmodel.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
pctx ctx;
void sigusr1_handle(int signum){

if(signum==SIGUSR1){
block(&ctx);
//print(&ctx);
}
}


void sigusr2_handle(int signum){


if(signum==SIGUSR2){
unblock(&ctx);
//print(&ctx);
}
}
int main(){
printf("A3\n");

sigset_t set, mask;

sigfillset (&set);
sigfillset (&mask);

struct sigaction saction;

memset(&saction, 0, sizeof(struct sigaction));

saction.sa_handler = sigusr1_handle;
saction.sa_mask = set;
sigaction(SIGUSR1, &saction, NULL);

saction.sa_handler = sigusr2_handle;
sigaction(SIGUSR2, &saction, NULL);

process p1={111, READY};
process p2={222, READY};
process p3={333, READY};
process p4={444, READY};
process p5={555, READY};
process p6={666, READY};
process p7={777, READY};
process p8={888, READY};
process p9={999, READY};
process p10={123, READY};



queue q;

q.start=NULL;
q.end=NULL;

 queue bq;
bq.start=NULL;
bq.end=NULL; 

q_add(&q, &p1);
q_add(&q, &p2);
q_add(&q, &p3);
q_add(&q, &p4);
q_add(&q, &p5);
q_add(&q, &p6);
q_add(&q, &p7);
q_add(&q, &p8);
q_add(&q, &p9);
q_add(&q, &p10);

ctx.qready = &q;
ctx.running = NULL;
ctx.qblocked =&bq; 



for(;;){

	puts("");
	step(&ctx);
	print(&ctx);
	sleep(1);   //1
}

return 0;
}

