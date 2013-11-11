/*
 * CSCI315 - Operating System
 * Lab 2
 * Yifan Ge
 * 01/24/2013
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int fd; int pid; int num;
	if ((pid = fork()) < 0) {
		perror("something went wrong in fork");
		exit(-1);
	} else if (pid == 0) {
		for (num=0; num<20; num++) {
		printf("child: %d\n", num); fflush(stdout);
		sleep(1);
		}
	} else {
		for (num=0; num<20; num+=3) {
		printf("parent: %d\n", num); fflush(stdout);
		sleep(1);
		}
	}
}
