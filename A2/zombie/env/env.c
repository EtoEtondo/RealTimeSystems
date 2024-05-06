#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

extern char **environ;
//------------------------------MENUE----------------------
void menu() {
    printf("\n\n");
    printf("---------------------\n");
    printf("Environment-List Menu\n");
    printf("---------------------\n");

    printf("[1]: Print environment list\n");
    printf("[2]: Print environment entry\n");
    printf("[3]: Add   environment list\n");
    printf("[4]: Modify environment entry\n");
    printf("[5]: Remove environment entry\n");
    printf("[0]: End\n");
    printf("\n");

}
//--------------------------[1]-PrintList------------------------
void printList() {
    int i = 0;
    puts("\n|------------Environment------------|\n");
    while(*(environ+i)) {
        puts(*(environ+i));
        i++;
    }

}
//-------------------------[2]-Environmenvariablen-printen------------------------------
void envprint() {

    char *value = NULL;
    char *name = readline("Environment name: ");

    value= getenv(name);
    if(value) {
        printf("%s=%s\n", name, value);
    } else {
        fprintf(stderr,"\n %s not found\n", name);
    }
}
//-----------------------[3]-Evironmentvariable-adden------------------------------
void envadd() {
    char* s;
   
    char *name = readline("Environment name: ");
    
    s=getenv(name);
  
    if(s) {
        printf("\nSUCCESS!!\n");
      
   printf("Wert (%s) : %s\n", name,getenv(name));
    } else {
      char *value = readline(" New Environment value: ");
      

    int x= setenv(name,value,0);
    if(!x) {
        printf("Neuer Wert (%s) : %s\n", name, value);
    } else {
        fprintf(stderr,"\n Konnte nicht modifiziert werden\n");
    }

        
    }

    free(name);
    
   
}
//-----------------------[4]-Environment-modify----------------------------------------
void envmod() {
    printf("Umgebungsvariable modifizieren: \n");

    char *name = readline("Environment name: ");
    printf("Wert      : %s\n", getenv(name));

    printf("\n Wert ändern/setzen durch : \n");

    char *value = readline(" New Environment value: ");

    int x= setenv(name,value,0);
    if(!x) {
        printf("Neuer Wert (%s) : %s\n", name, getenv(name));
    } else {
        fprintf(stderr,"\n Konnte nicht modifiziert werden\n");
    }

    free(name);
    free(value);



}
//-------------------[5]-Environment-remove-----------------------------------------
void envremove() {

    printf("Umgebungsvariable löschen: \n");

    char *name = readline("Environment name: ");
    printf("Wert      : %s\n", getenv(name));
    unsetenv(name);
    printf("\n (%s) : %s\n wurde gelöscht", name, getenv(name));


//------------------MAIN------------------------------------------------------------
}

int main () {
    int auswahl=-1;



    do {

        menu();
        scanf("%d", &auswahl);
        if(auswahl>=0 && auswahl<6)
            switch(auswahl) {
            case 1:
                printList();
                break;
            case 2:
                printf("\n");
                envprint();

                break;
            case 3:
                envadd();

                break;
            case 4:
                printf("\n");
                envmod();
                break;
            case 5:
                printf("\n");
                envremove();
                break;
            case 0:

                break;
            default:

                printf("Ungültige Eingabe. Bitte Menüpunkt auswählen!\n");
                
                break;

            }




    } while(auswahl>0 && auswahl<6);

    return 0;
}











/*enum{MAX=300};
int k;
char name[MAX] , neu_name[MAX];
//-------------------------Menue------------------------------

 k=menu(k);
//-------------[1]Environment list printen-------------------------
if(k==1){

 /puts("Arguments");
  if(args>0) while(*argv) puts(*argv++);

 puts("\nEnvironment");
  while(*envp) puts(*envp++);

 k=menu(k);

 }
//-------------------[2]Environment entry printen------------------
if(k==2){


  char *name = readline("Environment name: ");
  printf("Wert      : %s\n", getenv(name));


}
//-----------------[3] Environment entry adden---------------------

//-----------------[4]modifizieren---------------------------------
if(k==4){
printf("Umgebungsvariable modifizieren: ");

  scanf("%254s",name);
  printf("Wert      : %s\n", getenv(name));

 printf("Wert ändern/setzen durch : ");
  scanf("%254s",neu_name);

  setenv(name,neu_name,1);

 printf("Neuer Wert (%s) : %s\n", name, getenv(name));






}
//----------------------[5]removen----------------------------------------
if(k==5){
 printf("Umgebungsvariable löschen: ");

  scanf("%254s",name);
  printf("Wert      : %s\n", getenv(name));
  unsetenv(name);
 printf("Neuer Wert (%s) : %s\n", name, getenv(name));

  //return EXIT_SUCCESS;

}
//----------------------[0]End----------------------------------------
if(k==0){
exit(0);
}
return 0;
}*/
