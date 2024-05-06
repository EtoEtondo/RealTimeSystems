#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum state{READY=0, RUNNING=1} state;
typedef struct process{uint32_t p_id; state p_state;} process;

void p_switch_state(struct process *p);

void p_print(struct process *p);

#endif
