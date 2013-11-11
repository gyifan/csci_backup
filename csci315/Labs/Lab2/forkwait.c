/*
 * CSCI315 - Operating System
 * Lab 2
 * Yifan Ge
 * 01/24/2013
 */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	int child1 = fork();
	if (child1==0){
		int counter;
		int result;
	    	for(counter=1; counter<11; counter++){
	    		result=fact(counter);
			printf("CHILD1:fact(%d)=%d\n",counter,result);
			usleep(10);
		}
	}else{
		int child2 = fork();
		if(child2==0){
			int counter;
			int result;
			for(counter=1; counter<11; counter++){
				result=fact(counter);
				printf("CHILD2:fact(%d)=%d\n",counter,result);
				usleep(10);
			}
		}else{
			wait(&child1);
			wait(&child2);
		}
	}
	return 0;
}

int fact(int input){
	if(input == 0 | input == 1)
		return 1;
	else
		return input*fact(input-1);
}
