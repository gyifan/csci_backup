/*
 * CSCI315 - Operating System
 * Lab 2 - prelab
 * Yifan Ge
 * 01/23/2013
 */

#include <unistd.h>

int main(int argc, char* argv[]) {
	if (fork()==0) {
		int counterP = 1;
		while(1) {
			printf("parent: %d\n", counterP);
			counterP ++;
		}
	} else {
		int counterC = 1;
		while(1) {
			printf("child: %d\n", counterC);
			counterC ++;
		}
	}
	
	return 0;

}
