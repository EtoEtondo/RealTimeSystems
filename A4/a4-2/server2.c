#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<limits.h>
#include<string.h>
#define FIFO "ask.me"
#define PIPE_BUF 4096
int main() {
    mkfifo(FIFO, S_IRUSR | S_IWUSR);
    int fd = open(FIFO, O_RDONLY);

    char buf[PIPE_BUF];
   // int i=0;
    while(1) {


        int n = read(fd, buf, PIPE_BUF);


        if(n<1)break;
        printf("\n\n%d:%s",getpid(),buf);

    }
close(fd);
/*int fd3 = open(FIFO, O_RDONLY);
 char num[PIPE_BUF];
 while(1) {


        int x = read(fd3, num, PIPE_BUF);


        if(x<1)break;
        printf("%s",num);

    }*/

//---------------answer.me-------------------
   char FIFO2[PIPE_BUF];
  sprintf(FIFO2,"answer.%d",getpid());
    FILE *fifo2 = fopen(FIFO2, "w");
    //fprintf(fifo2,"%s",buf);


    

    if(strrchr(&buf[strlen(buf)-2],'?')) {


        if(strrchr(&buf[strlen(buf)-3],'a')||strrchr(&buf[strlen(buf)-3],'e')||strrchr(&buf[strlen(buf)-3],'i')||strrchr(&buf[strlen(buf)-3],'u')||strrchr(&buf[strlen(buf)-3],'o')) {

           fprintf(fifo2,"JA");
         // printf("JA");
        } else {
            fprintf(fifo2,"NEIN");
  
        }
//char c;
//strrchr(&buf2[strlen(buf)-4],c);
        /*switch(c){
        	case 'a': printf("Ja"); break;
        	case 'e': printf("Ja"); break;
        	case 'i': printf("Ja"); break;
        	case 'u': printf("Ja"); break;
        	case 'o': printf("Ja"); break;
         	default:  printf("Nein"); break;

        }*/

    } else {
       fprintf(fifo2,"DAS ist KEINE Frage");
    }

   // printf("\n %ld, %s",strlen(buf),&buf[strlen(buf)-3]);



   // close(fd);
   //fclose(fifo2);
   // sleep(2);
   // unlink(FIFO2);

}

