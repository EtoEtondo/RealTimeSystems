#ifndef PROCESSMODEL_H
#define PROCESSMODEL_H

#include "queue.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"


typedef struct pctx{struct queue *qready; struct process *running;} pctx;

void print(struct pctx *ctx);

void step(struct pctx *ctx);

#endif
