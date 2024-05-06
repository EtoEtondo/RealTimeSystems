#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "process.h"
#include <stdint.h>

void q_add(struct queue *q, struct process *p) {
      

   q_node* node = (q_node*)malloc(sizeof(q_node));
    node->p = p;
    node->next = NULL;
    if(q->start==NULL || q->end==NULL) {
        q->start = node;
        q->end = node;
        return;
    } else {
        q->end->next = node;
        q->end = node;
        return;

    }
}

process* q_remove(struct queue *q) {



   if(q == NULL  || q->start == NULL) {

        fprintf(stderr, "Liste ist aleer\n");
       
        return NULL;
    }

    if(q->start->p == NULL) {
        fprintf(stderr, "Keine Daten vorhanden\n");

        return NULL;
    }else{
        q_node* temp = NULL;
        process* p = NULL;

         temp = q->start;
            p = q->start->p;

        if(q->start->next != NULL) {
            q->start = q->start->next;
        } else {
            q->start = NULL;
            q->end = NULL;
        }
        free(temp);

        return p;
    } 
}

void q_print(struct queue *q) {

    if(q == NULL) {
        fprintf(stderr,"Liste ist leer\n");
            return;
    }else{

        q_node* temp= q->start;

//if(q == NULL) fprintf(stderr,"Liste ist leer\n");
        while(temp != NULL) {

            //p_print(temp->p);
//-------------------------------------
 if(temp->p == NULL){
fprintf(stderr,"Keine Datenx vorhanden\n");
return;
}else{
    char* current_state=0;
    if (temp->p->p_state == READY) current_state="READY";
    if (temp->p->p_state == RUNNING) current_state="RUNNING";
    if (temp->p->p_state == BLOCKED) current_state="BLOCKED";
    printf("PID: %u (%s)\n", temp->p->p_id, current_state);
}
//-----------------------------
            temp = temp->next;
        }
    } 
}
