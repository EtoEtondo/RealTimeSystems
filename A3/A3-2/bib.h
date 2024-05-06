#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#pragma once


typedef struct{
	unsigned int sigset;
}my_sigset_t;

int my_sigemptyset(my_sigset_t *set);

int my_sigfillset(my_sigset_t *set);

int my_sigaddset(my_sigset_t *set,int signum);

int my_sigdelset(my_sigset_t *set,int signum);

int my_sigismember(my_sigset_t *set,int signum);
