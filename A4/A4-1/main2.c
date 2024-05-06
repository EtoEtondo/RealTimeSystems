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
    // int value=/*(*num-'0')%48*/atoi(num);
    //  printf("%d\n",value);
    //printf("%s\n",&num[0]);
    if(!isdigit(num[0])) {

        fprintf(stderr,"sum_of_digits(""not a number"")== -1\n");
        // printf("%d\n",value);

        return-1;
    } else {
        while(isdigit(num[0])) {
            int value=num[0]-'0';

            sum+=value;
            num++;
        }
        return sum;
    }
}

void read_from_pipe (int file)
{
    FILE *stream;
    int c;
    stream = fdopen (file, "r");
    while ((c = fgetc (stream)) != EOF)
        putchar (c);
    fclose (stream);
}

void write_to_pipe (int file)
{
    int k =3;
    char msg[3];
    FILE *stream;
    stream = fdopen (file, "w");
    msg[0]=k+'0';
    fprintf (stream, "%c\n",msg[0]);
    fprintf (stream, "goodbye, world!\n");
    fclose (stream);
}


/*void childr(int pfd[2],char *argv[]){
close(pfd[1]);
if(fd=popen(argv[1],O_RDONLY)<0){
 perror(" open failed\n");
return;
}else{
puts("open success\n");
}


}*/
/*int func1(int i, int len, char *line[]) {

    int sum1=0;

    //len=len/x;
    // while(len!=1000) {
    for( int j=i; i<len; i++) {

        sum1+=sum_of_digits(line[0+j]);
        //printf("%d.erg:%d\n",1+i,sum1);
    }
    //i=len;
    // len=len+len;
    //}
    //  printf("erg:%d\n",sum1);
    return sum1;
}*/
/*int func1(int x, int len,char *line[]){

                int c;
                int j;
                int sum2;
                   c=x;

		len=len/c;
                int len1=len;
		while(x>0){
		//len=len/c;
              for(int i=j; i<len; i++) {

               sum2+=sum_of_digits(line[0+i]);
			 // printf("%d.erg:%d\n",1+i,sum1);
            }
		j=len;
                   x--;
		len+=len1;
               //irgendwie data verschicken und dann 2 kind anfangen
            //  printf("erg:%d\n",sum1);

              //sum1=sum_of_digits(line[0]);
              //printf("erg:%d\n",sum1);

              //fclose(fp);
             // sleep(3);

}
return sum2;

}*/






int main(int argc,char*argv[]) {
    int pfd[2];
    FILE *fp;
    int len=1000;
    char *line[len];
    int sum1=0;
    pid_t pid;
    int i=0;
    int c=0;
    FILE *stream;
    //int z=0;
    int j=0;
    char msg[20];




    int x=atoi(argv[2]);
    if(argc!=3) {
        perror("ERROR");
        return 1;
    }
    char *d=argv[1];

    if(strcmp(d,"number.txt")==0) {
        if((fp=fopen(argv[1],"r"))==NULL) {
            perror(" open failed\n");
            return -1;
        } else {
            puts("open success\n");
            if(pipe(pfd)<0) {
                perror("pipe not created\n");

            } else {
                puts("pipe created\n");

                for(i=0; i<x; i++) {
                    pid=fork();
}
                    if(pid<0) {
                        fprintf(stderr,"pid failed");
                    }
                    if(pid==0) {
                        close(pfd[1]);
                        for(int i=0; i<1000; i++) {
                            size_t n=0;
                            getline(&line[i],&n,fp);
                            //sum1=sum_of_digits(line[0]);

                        }
                        //sum1=func1(x, len, &line[0]);
                        // printf("erg:%d\n",sum1);
                        c=x;
                        len=len/c;
                        int len1=len;
                        while(x>0) {
                            //len=len/c;
                            for(int i=j; i<len; i++) {

                                sum1+=sum_of_digits(line[0+i]);
                                // printf("%d.erg:%d\n",1+i,sum1);
                            }
                            j=len;
                            x--;
                            len+=len1;
                            //irgendwie data verschicken und dann 2 kind anfangen
                           // printf("erg:%d\n",sum1);
                          stream = fopen ("erg.txt", "w");
                            msg[0]=sum1+'0';
                           fprintf (stream, "%c\n",msg[0]);
                           
                           fclose (stream);
                            //sum1=sum_of_digits(line[0]);
                            //printf("erg:%d\n",sum1);
                            // z++;
                            //fclose(fp);
                           
                        }

                        fclose(fp);
                        //kann woander liegen siehe childwait
                        if(pid>0) {
                            close(pfd[0]);
                           int c;
    stream = fopen ("erg.txt", "r");
    while ((c = fgetc (stream)) != EOF)
        putchar (c);
    fclose (stream);
                             
                                printf("CHILD(%d))\n",pid);



                            }
                        }
                   // }
                }





            }
        
    } else {
        perror("file not found\n");
    }

    /*int pfd[2];
     FILE *fp;
     FILE *erg;
     pid_t pid;
     int k;


    int len=4900;
     char buf[len];
     char *line[len];
     if(argc!=2) {
         perror("ERROR");
         return 1;
     }
     char *d=argv[1];
     if(strcmp(d,"number.txt")==0) {
         // childr(pfd[2],&argv[1]);

         if((fp=fopen(argv[1],"r"))==NULL) {
             perror(" open failed\n");
             return -1;
         } else {
             puts("open success\n");
             if(pipe(pfd)<0) {
                 perror("pipe not created\n");

             } else {
                 puts("pipe created\n");
                 if((pid=fork())<0) {
                     perror("process not created\n");
                 }
                 if(pid>0) {
                     close(pfd[0]);
    		for(int i=0;i<len;i++){
                          size_t n=0;
                          getline(&line[i],&n,fp);

    		}
                           fclose(fp);
                   int s = sum_of_digits(line[0]);
                     printf("%d\n",s);
                     if((erg=fopen("erg.txt","w"))==NULL) {
    			perror("nicht geöffnet");

    		}else{
    			//fputc(s,erg);
    		}
                           // erg=fopen(pfd[0],"r");
                              k=read(s,buf,len);


    		if((write(pfd[1],buf,k))!=k) {   //pfd[1]
    			perror("write didnt work\n");
    		}
                 }else{
    		close(pfd[1]);
    		k=read(pfd[0],buf,len);
    		if((write(STDOUT_FILENO,buf,k))!=k){
    			perror("write didnt work\n");
    		}

    	}

             }
         }
     } else {
         puts("not the right File");
     }*/





    /*char num[]="1234";
    printf("%s\n",&num[0]);
    int erg=sum_of_digits(&num[0]);

    printf("Quersumme=%d",erg);*/


}

