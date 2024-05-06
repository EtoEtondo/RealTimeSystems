#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int sum_of_digits(char *num) {
    int sum=0;
  
  printf("%s\n",&num[0]);
for(unsigned int i=0;i<strlen(&num[0]);i++){
    if(!isdigit(num[0])) {

        fprintf(stderr,"sum_of_digits(""not a number"")== -1\n");

        return-1;
    }else{

    while(isdigit(num[0])) {
        int value=num[0]-'0';
        
        sum+=value;
        num++;
    }
}
}
    return sum;

}




 

int main() {


    char num[]="1abc";
  //printf("%s\n",&num[0]);
    int erg=sum_of_digits(&num[0]);

    printf("Quersumme=%d",erg);


}
