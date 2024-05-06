#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include <stdint.h>
#include "queue.h"

int main(){
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
