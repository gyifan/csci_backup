#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int* a = (int*)malloc(sizeof(int));
	*a = 10;
	pid_t child;	

	if(-1==(child=fork())){
		perror("fork() failed");
		exit(-1);
	}
	
	if(0==child){
		printf("memory in heap Child: %d\n",*a);
		fflush(stdout);
		*a = 5;
		printf("memory in heap Child new: %d\n",*a);
	}else{
		wait(&child);
		printf("memory in heap Parent: %d\n",*a);
	}
}
