#include <stdio.h>
#include "process.h"
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "queue.h"
#include "processmodel.h"

void print(struct pctx *ctx) {
    if(ctx==NULL /*|| ctx->running == NULL*/) {
        fprintf(stderr,"NO PROCESS\n");
    }
        puts("Running");
//if(ctx->running!=NULL){   //damit kein block
        p_print(ctx->running);
//}
        puts("Ready Queue");
//if(ctx->running!=NULL){     //damit kein block
          q_print(ctx->qready);
//}
        puts("Blocked Queue");
        q_print(ctx->qblocked);
        puts("");

    
}

void step(struct pctx *ctx) {

    if(ctx->running == NULL) {

        ctx->running = q_remove(ctx->qready);

       p_switch_state(ctx->running);
     
        //q_add(ctx->qready,ctx->running);
 
        



}






   p_switch_state(ctx->running);
    q_add(ctx->qready, ctx->running);
    process* one = q_remove(ctx->qready);

    p_switch_state(one);
    ctx->running = one;


}
void block(struct pctx *ctx) {
    /*struct process *p= q_remove(ctx->running);

                          if(one!=NULL){
                           p_block_state(one);
                           q_add(ctx->qblocked,one);
                           //p=NULL;
    }*/

//q_node* i= (q_node*)malloc(sizeof(q_node));
           process *one;
          if(ctx->running->p_state==BLOCKED){
               fprintf(stderr,"Liste leer");
return;
}else{
           q_add(ctx->qblocked, ctx->running);
           p_block_state(ctx->running);

           one =q_remove(ctx->qready);
           if(one!=NULL){
           p_switch_state(one);
            
          
           ctx->running=one; 
}else{
ctx->running=NULL;

}
}
/*else{    code

if(ctx->qblocked->end->p->p_id==ctx->running->p_id){

              ctx->running=NULL;
	}      code*/
	

/*}else if(ctx->qready->start==NULL){
i=ctx->qblocked->start;

while(i->next!=NULL){

	if(one->p_id==ctx->qblocked->end->p->p_id){
		ctx->running=NULL;

}
i=i->next;

}
//free(i);
*/







         // p_switch_state(one);

         
         // p_switch_state(one);
    /* code if(one!=NULL) {
        //one=ctx->running;
      
  //p_switch_state(ctx->running);
         one=ctx->running;
p_switch_state(ctx->running);
       
           //q_add(ctx->qready, ctx->running);
       // p_switch_state(ctx->running);



    }*/


}
void unblock(struct pctx *ctx) {
          
     struct process *p= q_remove(ctx->qblocked);
     
    if(p!=NULL /*&& ctx->running!=NULL*/) {
       //p=ctx->running;
        p_unblock_state(p);
        q_add(ctx->qready,p);
        
        
    } /*else{

 ctx->running=p;

}*/
if(ctx->running->p_state==BLOCKED){
ctx->running=NULL;


}
}
/*void sig_usr(int signum){
if (signum == SIGUSR1) write(STDOUT_FILENO, "USR1\n", 5);
if (signum == SIGUSR2) write(STDOUT_FILENO, "USR2\n", 5);
sleep(3);
}*/







