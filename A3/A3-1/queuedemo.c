#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include <stdint.h>
#include "queue.h"
void sigusr1_handle(int signum){
if(signum==SIGUSR1){
block(&ctx);
}
}


void sigusr2_handle(int signum){
if(signum==SIGUSR2){
unblock(&ctx);
}
}


int main(){

signal(SIGUSR1,sigusr1_handle);
signal(SIGUSR2,sigusr2_handle);
printf("A2\n");
process p1={123, READY};
process p2={234, RUNNING};
process p3={345, READY};
queue q;
q.start=NULL;
q.end=NULL;


puts("");
q_add(&q, &p1);
q_print(&q);

puts("");
q_add(&q, &p2);
q_print(&q);

puts("");
q_add(&q, &p3);
q_print(&q);
puts("");



q_remove(&q);
q_print(&q);
puts("");

q_remove(&q);
q_print(&q);
puts("");

q_remove(&q);
q_print(&q);
puts("");

q_remove(&q);
q_print(&q);
puts("");

return 0;
}
