#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include <stdint.h>
#include <signal.h>


void p_switch_state(struct process *p) {
    if(p == NULL) {
fprintf(stderr,"Keine Datens vorhanden\n");
}else{
    if(p->p_state == READY) {
        p->p_state = RUNNING;
         return;
    }
    if(p->p_state == RUNNING) {


        p->p_state = READY;

         return;
    }
    /*if(p->p_state == BLOCKED){
    	p->p_state = READY;
    	return;
    }*/
}
}
void p_block_state(struct process *p) {

    p->p_state=BLOCKED;

}
void p_unblock_state(struct process *p) {

    p->p_state=READY;

}

void p_print(struct process *p) {
    if(p == NULL){
fprintf(stderr,"Keine Datenp vorhanden\n");
return;
}else{
    char* current_state=0;
    if (p->p_state == READY) current_state="READY";
    if (p->p_state == RUNNING) current_state="RUNNING";
    if (p->p_state == BLOCKED) current_state="BLOCKED";
    printf("PID: %u (%s)\n", p->p_id, current_state);
}

}


