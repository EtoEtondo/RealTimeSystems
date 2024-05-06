#ifndef QUERSUMME_H
#define QUERSUMME_H

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <byteswap.h>
#include <sys/wait.h>

int sum_of_digits(char *num);
void *quersumme(void *v);
void store(FILE *fp,char* line[]);


#endif
