#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"

int *create_delim_dict(char *delim)
{
	int *d = (int*)malloc(sizeof(int)*DICT_LEN);
	memset((void*)d, 0, sizeof(int)*DICT_LEN);

	int i;
	for(i=0; i< strlen(delim); i++) {
		d[delim[i]] = 1;
	}
	return d;
}



char *_strtok(char *str, char *delim)
{
	
	static char *last, *to_free;
	int *deli_dict = create_delim_dict(delim);

	if(!deli_dict) {
	/*this check if we allocate and fail the second time with entering this function */
		if(to_free) {
		    free(to_free);
		    to_free = NULL;
		}
		return NULL;
	}

	if(!deli_dict) {
		
		return NULL;
	}

	if(str) {
		last = (char*)malloc(strlen(str)+1);
		if(!last) {
			free(deli_dict);
			deli_dict = NULL;
			return NULL;
		}
		to_free = last;
		strcpy(last, str);
	}

	while(deli_dict[*last] && *last != '\0') {
		last++;
	}
	str = last;
	if(*last == '\0') {
		free(deli_dict);
		deli_dict = NULL;
		free(to_free);
		to_free = NULL;
		return NULL;
	}
	while (*last != '\0' && !deli_dict[*last]) {
		last++;
	}
	
	*last = '\0';
	last++;
    if(deli_dict) {
		free(deli_dict);
	    deli_dict = NULL;
	}
	return str;
}


pid_t spawnChild(char *buffer)
{
    int i = 0;
    char *p = strtok (buffer, " ");
    char *array[] = {};

    while (p != NULL)
    {
        array[i] = p;
        p = strtok (NULL, " ");
	i++;
    }

    for (i = 0; i < 3; ++i) 
        printf("%s\n", array[i]);

    pid_t ch_pid = fork();
    if (ch_pid == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    printf("list : %s\n", array[0]);

    if (ch_pid == 0) {
        if ((-1) == execve(array[0], array, NULL))
	{
		printf("lol");
		exit(0);
	}
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        printf("spawned child with pid - %d\n", ch_pid);
        return ch_pid;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 1024

int main(){
    char line[BUFFER_LEN];  //get command line
    char* argv[100];        //user command
    char* path= "/bin/";    //set path at bin
    char progpath[20];      //full file path
    int argc;               //arg count

while(1){

    printf("My shell>> ");                    //print shell prompt

        if(!fgets(line, BUFFER_LEN, stdin))
	{ 
        break;                                //if user hits CTRL+D break
    }
    		size_t length = strlen(line);
if (line[length - 1] == '\n')
    line[length - 1] = '\0';

    if(strcmp(line, "exit")==0){            //check if command is exit
        break;
    }

    char *token;                  //split command into separate strings
    token = strtok(line," ");
    int i=0;
    while(token!=NULL){
        argv[i]=token;      
        token = strtok(NULL," ");
        i++;
    }
    argv[i]=NULL;                     //set last value to NULL for execvp

    argc=i;                           //get arg count
    for(i=0; i<argc; i++){
        printf("%s\n", argv[i]);      //print command/args
    }
    strcpy(progpath, path);           //copy /bin/ to file path
    strcat(progpath, argv[0]);            //add program to path

    for(i=0; i<strlen(progpath); i++){    //delete newline
        if(progpath[i]=='\n'){      
            progpath[i]='\0';
        }
    }
    int pid= fork();              //fork child

    if(pid==0){               //Child
        execve(progpath, argv);
        fprintf(stderr, "Child process could not do execvp\n");

    }else{                    //Parent
        wait(NULL);
        printf("Child exited\n");
    }

}
}