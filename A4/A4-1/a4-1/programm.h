#ifndef PROGRAMM_H
#define PROGRAMM_H

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
int quersumme(int start,int end,char *line[]);
void write_in(int pfd[2],int len,int i,int x,char *line[],int summe);
int read_out(int pfd[2],int summe,int x);
void store(FILE *fp,char* line[]);


#endif
