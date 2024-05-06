#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"

typedef struct q_node{struct q_node *next; struct process *p;} q_node;
typedef struct queue{struct q_node *start; struct q_node *end;} queue;

void q_add(struct queue *q, struct process *p);

process *q_remove(struct queue *q);

void q_print(struct queue *q);

#endif
