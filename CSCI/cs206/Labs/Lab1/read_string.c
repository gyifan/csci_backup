/*
 * CSCI 206
 * Author: Yifan Ge
 * Pre-Lab1
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char string[80];
int done;

int main(void){
	done = 0;
	while (done == 0) {
                // read a string
                fgets(string, 79, stdin);
		if (strncmp(string, ".", 1) == 0) {
			done = 1;
                } 
	}
}

