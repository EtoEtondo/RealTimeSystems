/* fifo2.c */
#include <stdio.h>
#include <unistd. h.>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define FIFO "fifo0001.1"
int main (void) {
   int fd_fifo;      /*Handle für das FIFO */
   char puffer[] = "Dieser Text ist für das FIFO\n";
   char buf[100];
   int n;
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
   n = write (fd_fifo, puffer, strlen (puffer));
   if (read (fd_fifo, &buf, n ) == -1) {
      perror ("read()");
      exit(EXIT_FAILURE);
   }
   buf[n] = '\0';
   printf ("Gelesen aus dem FIFO : %s\n", buf);
   return EXIT_SUCCESS;
}
