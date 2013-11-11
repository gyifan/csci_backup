/*
 * CSCI315 - Operating System
 * Lab2
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
	int fd; int pid;
	char ch1, ch2;
	fd = open("data.txt", O_RDWR);
	read(fd, &ch1, 1);
	printf("In parent: ch1 = %c\n", ch1); fflush(stdout);

	if ((pid = fork()) < 0) {
		perror("something went wrong in fork");
		exit(-1);
	} else if (pid == 0) {
		read(fd, &ch2, 1);
		printf("In child: ch2 = %c\n", ch2); fflush(stdout);
	} else {
		read(fd, &ch1, 1);
		printf("In parent: ch1 = %c\n", ch1); fflush(stdout);
	}
}
