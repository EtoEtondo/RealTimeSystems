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
#include "quersumme.h"


#define LEN 1000

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
void *quersumme(void *v) {
    int sum=0;
    int len =1000;
    int start=0;
	char *nums[LEN];
	memcpy(nums,(char*)v,LEN);
	printf("%s",nums);
    for(int i=start; i<len; i++) {

        sum+=sum_of_digits(nums[0+i]);

    }
       return 0;
}
//-----------------------------------------------------------------------------------
void store(FILE *fp,char* line[]){

 for(int i=0; i<1000; i++) {
    size_t n=0;
  
    getline(&line[i],&n,fp);

                }

}

//-----------------------------------------------------------------------------------




