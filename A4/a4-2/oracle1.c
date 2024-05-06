/* fifo2.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define FIFO "ask.me"
#define FIFO2 "answer.PID_desFragestellers"
int main (int argc ,char *argv[]) {
   int fd_fifo;   
   int fd_fifo2;   /*Handle für das FIFO */
   char *puffer=argv[1]; 
   char *puffer2=argv[2];
   char buf[100];
   char buf2[100];
   int n;
   int k;


    if(argc<2) {
        perror("ERROR");
        return 1;
    }
   /*Alle Zugriffsrechte der Dateikreierungsmaske erlauben*/
   umask(0);
   /* Wir erzeugen das FIFO*/
   if ((mkfifo (FIFO, 0666)) == -1) {
      /* FIFO bereits vorhanden - kein fataler Fehler */
      if(errno == EEXIST)
         perror ("mkfifo()");
      else {
         perror("mkfifio()");
         exit (EXIT_FAILURE);
      }
   }
   /* FIFO zum Lesen und Schreiben öffnen */

if ((fd_fifo = open (FIFO, O_RDWR)) == -1) {
      perror ("open()");
      exit (EXIT_FAILURE);
   }
/*for(int i=1;i<argc;i++){

             puffer=*(argv+i);
		printf("%s\n",puffer);

 n = write (fd_fifo, puffer, strlen (puffer));


}*/
   n = write (fd_fifo, puffer, strlen (puffer));
	printf("%d\n",n);
   if (read (fd_fifo, &buf, n ) == -1) {
      perror ("read()");
      exit(EXIT_FAILURE);
   }
   buf[n] = '\0';
   printf ("Gelesen aus dem FIFO : %s\n", buf);
   return EXIT_SUCCESS;
close(fd_fifo);
umask(0);
if ((mkfifo (FIFO2, 0666)) == -1) {
      /* FIFO bereits vorhanden - kein fataler Fehler */
      if(errno == EEXIST)
         perror ("mkfifo()");
      else {
         perror("mkfifio()");
         exit (EXIT_FAILURE);
      }
if ((fd_fifo2 = open (FIFO2, O_RDWR)) == -1) {
      perror ("open()");
      exit (EXIT_FAILURE);
   }
/*for(int i=1;i<argc;i++){

             puffer=*(argv+i);
		printf("%s\n",puffer);

 n = write (fd_fifo, puffer, strlen (puffer));


}*/
   k = write (fd_fifo, puffer2, strlen (puffer2));
	
   if (read (fd_fifo2, &buf2, k ) == -1) {
      perror ("read()");
      exit(EXIT_FAILURE);
   }
   buf[k] = '\0';
   printf ("Gelesen aus dem FIFO2 : %s\n", buf2);
   return EXIT_SUCCESS;
   }




}//main
