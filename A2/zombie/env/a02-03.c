#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MENUEPOINTS 6

extern char **environ;

void printHead(char *text){
	printf("------------------------\n");
	printf("%s\n", text);
	printf("------------------------\n");
}
void printMenue(char *text[MENUEPOINTS]){

	for(int i = 0; i < MENUEPOINTS; i++){
		printf("%s", text[i]);
	}
}

void addenv(){
	char *name = readline("Environment name: ");
	//printf("%s\n", name);

	char *value = readline("Environment value: ");
	//printf("%s\n", value);

	//setenv mit 0 legt einen neuen an
	int x = setenv(name, value, 0);
	if(!x) printf("geklappt\n");
	else perror("fail\n");

	free(name);
	free(value);
}

void modifyenv(){
	char *name = readline("Environment name: ");
	//printf("%s\n", name);

	char *value = readline("Environment value: ");
	//printf("%s\n", value);

	//setenv mit 1 modifiziert
	int x = setenv(name, value, 1);
	if(!x) printf("geklappt\n");
	else fputs("fail\n",stderr);

	free(name);
	free(value);
}
void removeenv(){
	int result = -1;
	
	char *name = readline("Environment name: ");

	result = unsetenv(name);
	if(!result)
		printf("%s deleted\n", name);
	else fputs("deleting fail\n",stderr);
}
void printenv_list(){
	int i = 0;
	while(*(environ+i)){
		printf("Environment: %s\n", *(environ+i));
		i++;
	}
}
void printenv_entry(){
	char *value = NULL;
	
	char *name = readline("Environment name: ");

	value = getenv(name);
	if(value)
		printf("%s=%s\n", name, value);
	else fprintf(stderr,"%s not found", name);	
}
int main(){
	int auswahl = -1;
	char *menu[MENUEPOINTS] ={"[1]: Print environment list\n",
			"[2]: Print environment entry (getenv)\n",
			"[3]: Add environment entry (putenv)\n",
			"[4]: Modify environment entry (setenv)\n",
			"[5]: Remove environment entry (unsetenv)\n",
			"[0]: End\n"
	};

	do{	
		printHead("Environment-List Menu");
		printMenue(menu);
		scanf("%d", &auswahl);
		if(auswahl>=0 && auswahl<MENUEPOINTS)
		switch(auswahl){
		case 1: printenv_list(); 
			break;
		case 2: printenv_entry();
			break;
		case 3: addenv();
			break;
		case 4: modifyenv();
			break;
		case 5: removeenv();
			break;
		case 0: 
			break;
		}	

	}while(auswahl>0 && auswahl<MENUEPOINTS);
	
	return 0;
}
