/*
 * CSCI 315 - Operating System
 * Assignment 1 - building a Unix Shell
 * Yifan Ge
 * 2/17/2013
 */

/*
 * Added features:
 * Time: new command "time". It will output the current time in a readable
 * 	 format.
 * Exit: implemented "exit". It will terminates myshell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

#define STRING_SIZE 80
#define NUMOFPARM 6

void get_time(void){
	struct timeval tv; 
	time_t t;
	int rc; 
	char *rv;

	rc = gettimeofday(&tv, NULL);
	if(rc){
		perror("gettimeofday failed");
		exit(-1);
	}   

	t = tv.tv_sec;

	rv = ctime(&t);
	if(rv == NULL){
		perror("ctime failed");
		exit(-1);
	}   
	printf("%s",rv);
	fflush(stdout);
}

int main(int argc, char* argv[]){
	char *input;
	char *command;
	char *parm[NUMOFPARM];
	char *space;
	int *status;
	pid_t child;

	space = malloc(1);
	*space = ' ';
	status =(int *) malloc(sizeof(int));
	input = malloc(STRING_SIZE);	
	while(1){
		// Checks for valid command
		do {
			printf("myshell>");
			fflush(stdout);
			fgets(input, STRING_SIZE, stdin);
		} while (input[0] == '\n');
		//Tokenizes the parameters
		int i = 1;
		command = strtok(input,space);
		parm[0] = command;
		while(NULL!=(parm[i]=strtok(NULL,space)))
			i++;	

#ifdef DEBUG
		if(i!=1)
			printf("i = %d",i);
		printf("command:%s\n",command);
#endif /*DEBUG*/

		//Removes the newline character from the last parameter
		if(i!=1)	
			parm[i-1][strlen(parm[i-1])-1] = '\0';
		else 
			command[strlen(command)-1] = '\0';
		parm[i] = '\0';

#ifdef DEBUG
		if(i!=1){
			printf("%d %d\n",i, (int)strlen(parm[i-1]));
			for(i=0;i<4;i++){
				printf("parm[%d]%s\n",i,parm[i]);
			}
		}

		printf("tokenize done\n");
#endif /*DEBUG*/

		if((child=fork())<0){
			perror("fork failed");
			exit(-1);
		} else if (child == 0){
			if(strcmp("time", command)==0){
				get_time();
				return(0);
			}else if(strcmp("exit", command)==0)
				return(-1);
			else if(execvp(command, parm))
				perror("Command is not recognized");
		}	else {
			wait(status);
			if(*status == 65280)
				exit(0);
#ifdef DEBUG
			printf("%d", *status);
			printf("Child Complete");
#endif /*DEBUG*/
		}
	}
}














