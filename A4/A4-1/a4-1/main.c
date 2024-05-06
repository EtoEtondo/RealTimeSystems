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

#define BUFFLEN 300


int sum_of_digits(char *num) {
    int sum=0;
    printf("%s\n",&num[0]);
    for(unsigned int i=0;i<strlen(&num[0]);i++){
    if(!isdigit(num[0])) {

        fprintf(stderr,"sum_of_digits(""not a number"")== -1\n");
        // printf("%d\n",value);

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

//-----------------------------------------------------
int func1(int start,int end,char *line[]) {
    int sum1=0;
    for(int i=start; i<end; i++) {

        sum1+=sum_of_digits(line[0+i]);
      
    }
    return sum1;

}
//-----------------------------------------------
int main(int argc,char*argv[]) {
    FILE *fp;
    int len=1000;
    char *line[len];
    int sum2=0;
    int start=1;
    int end=3;
    if(argc!=2) {
        perror("ERROR");
        return 1;
    }
    if((fp=fopen(argv[1],"r"))==NULL) {
        perror(argv[1]);
        return -1;
    } else {
        for(int i=0; i<1000; i++) {
            size_t n=0;
            getline(&line[i],&n,fp);
            
        }
        sum2=func1(start,end,&line[0]);
        
        printf("erg:%d\n",sum2);
      
        fclose(fp);
    }

}

