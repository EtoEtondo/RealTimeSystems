#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H

#include "queue.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "process.h"


typedef struct pctx{struct queue *qready; struct process *running; struct queue *qblocked;} pctx;

void print(struct pctx *ctx);
void step(struct pctx *ctx);
void block(struct pctx *ctx);
void unblock(struct pctx *ctx);


#endif
