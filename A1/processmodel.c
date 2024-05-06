#include <stdio.h>
#include "process.h"
#include <stdint.h>
#include <stdlib.h>
#include "queue.h"
#include "processmodel.h" 

void print(struct pctx *ctx){
printf("Actual Process:\n");
if(ctx==NULL || ctx->running == NULL) fprintf(stderr,"Keine Daten vorhanden\n");
p_print(ctx->running);
q_print(ctx->qready);
}

void step(struct pctx *ctx){
	if(ctx->running == NULL){
	 	ctx->running = q_remove(ctx->qready);	
		p_switch_state(ctx->running);
		
	}else {
		p_switch_state(ctx->running);
		q_add(ctx->qready, ctx->running);
		process* one = q_remove(ctx->qready);
		p_switch_state(one);
		ctx->running = one;
	}
}
