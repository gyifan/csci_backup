/*
 * CSCI 315 - Operating System
 * Lab4 - prelab
 * Yifan Ge
 * 2/7/2013
 */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* print_thread(void* parm){
	int* mode = (int*)parm;
	switch (*mode){
		case 0:{
			       int i = 0;
			       for(;;){
				       for(i=0;i<10;i++){
					       printf("%d",i);
					       fflush(stdout);
					       sleep(1);
				       }
				       i = 0;
			       }
			       break;
		       }
		case 1:{
			       char c = 'a';
			       for(;;){
				       for(c='a';c<='z';c++){
					       printf("%c",c);
					       fflush(stdout);
					       sleep(1);
				       }
				       c = 'a';
				       printf("\n");
			       }
			       break;
		       }
	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[]){
	pthread_t threads[2];
	int* mode[2];
	pthread_attr_t attr; 
	int rc[2]; // return value
	int i;
	
	// Initialize attr variable and set to joinable
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for(i=0;i<2;i++){
		mode[i] = (int*) malloc(sizeof(int));
		*mode[i] = i;
		rc[i] = pthread_create(&threads[i],NULL,print_thread,(void*)mode[i]);
		if(rc[i]){
			perror("Thread create failed");
			exit(-1);
		}
	}
	for(i=0;i<2;i++){
		if(pthread_join(threads[i],NULL)){
			perror("Thread join failed");
			exit(-1);
		}
	}
}
