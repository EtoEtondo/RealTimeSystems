#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include <stdint.h>



	void p_switch_state(struct process *p){
		if(p == NULL) fprintf(stderr,"Keine Daten vorhanden\n");
		if(p->p_state == READY){
			p->p_state = RUNNING;
			return;			
		}
		if(p->p_state == RUNNING){
			p->p_state = READY;
			return;			
		}
	}

	void p_print(struct process *p){
		if(p == NULL) fprintf(stderr,"Keine Daten vorhanden\n");
		char* current_state=0;
		if (p->p_state == READY) current_state="READY";
		if (p->p_state == RUNNING) current_state="RUNNING";
		printf("PID: %u (%s)\n", p->p_id, current_state);
		
	}


