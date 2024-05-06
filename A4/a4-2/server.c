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

    while(1) {


        int n = read(fd, buf, PIPE_BUF);


        if(n<1)break;
        printf(" %s",buf);

    }


//---------------answer.me-------------------
    char FIFO2[PIPE_BUF];
    sprintf(FIFO2,"answer.%d",getpid());
    FILE *fifo2 = fopen(FIFO2, "w");
    fprintf(fifo2,"%s",buf);


    fclose(fifo2);
    int fd1 = open(FIFO2, O_RDONLY);
    char buf2[PIPE_BUF];
    while(1) {


        int n2 = read(fd1, buf2, PIPE_BUF);


        if(n2<1)break;
//printf("\n%s",&buf2[25]);
    }

    if(strrchr(&buf2[strlen(buf2)-2],'?')) {


        if(strrchr(&buf2[strlen(buf2)-3],'a')||strrchr(&buf2[strlen(buf2)-3],'e')||strrchr(&buf2[strlen(buf2)-3],'i')||strrchr(&buf2[strlen(buf2)-3],'u')||strrchr(&buf2[strlen(buf2)-3],'o')) {

            printf("\nJA");
        } else {
            printf("\nNEIN");

        }


    } else {
        printf("\n Das ist KEINE frage");
    }

    //printf("\n %ld, %s",strlen(buf2),&buf2[strlen(buf2)-3]);



    close(fd);
    close(fd1);
    sleep(3);
    unlink(FIFO2);

}

