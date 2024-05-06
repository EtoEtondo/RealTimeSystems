#include <stdio.h>
#include "process.h"
#include <stdint.h>
#include <stdlib.h>
#include "queue.h"
#include "processmodel.h"
#include <unistd.h>

int main(){
printf("A3\n");

process p1={111, READY};
process p2={222, READY};
process p3={333, READY};
process p4={444, READY};
process p5={555, READY};
process p6={666, READY};
process p7={777, READY};
process p8={888, READY};
process p9={999, READY};
process p10={000, READY};

queue q;
q.start=NULL;
q.end=NULL;

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


pctx ctx;
ctx.qready = &q;
ctx.running = NULL;

for(;;){

puts("");
step(&ctx);
print(&ctx);
sleep(1);
}

return 0;
}

