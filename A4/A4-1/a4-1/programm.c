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
#include "programm.h"


#define BUFFLEN 300

//----------------------------------------------------------------------------------
int sum_of_digits(char *num) {
    int sum=0;
for(unsigned int i=0;i<strlen(&num[0]);i++){
    if(!isdigit(num[0])) {

        fprintf(stderr,"sum_of_digits(""not a number"")== -1\n");


        return-1;
    }
        while(isdigit(num[0])) {
            int value=num[0]-'0';

            sum+=value;
            num++;
        }
}
        return sum;
    
}
//-------------------------------------------------------------------------------------
int quersumme(int start,int end,char *line[]) {
    int sum=0;
    for(int i=start; i<end; i++) {

        sum+=sum_of_digits(line[0+i]);

    }
    return sum;

}
//-----------------------------------------------------------------------------------
void store(FILE *fp,char* line[]){

 for(int i=0; i<1000; i++) {
    size_t n=0;
    &line[i]=NULL;
    getline(&line[i],&n,fp);

                }

}

//-----------------------------------------------------------------------------------
void write_in(int pfd[2],int len,int i,int x,char *line[],int summe) {
    int sum2=0;

    
    close(pfd[0]);
    int start = i * (len/x);
    int end = (i+1)*(len/x);
    sum2=quersumme(start,end,&line[0]);



    summe=sum2;

  
    write(pfd[1], &summe, sizeof(summe));
    printf ("Teilsumme:%d\n\n",summe);
}
//-------------------------------------------------------------------------------------
	int read_out(int pfd[2],int summe,int x){
                     int total=0;
                    close(pfd[1]);
                    while(x!=0) {
                        read(pfd[0],&summe,sizeof(summe));
                        wait(NULL);
                        total=total+summe;

                        x--;


}
return total;
}
//-------------------------------------------------------------------------------------



