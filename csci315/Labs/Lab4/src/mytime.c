/*
 * CSCI 315 - Operating System
 * Lab4 - prelab
 * Yifan Ge
 * 2/7/2013
 */

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
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
