/*
 * CSCI 206 Computer Organization & Programming
 * Author: Yifan Ge
 * Date: 2011-09-25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

	char acctNumberStr[80];        
	char copyStr[1];

        printf("Enter your account number: ");
	fgets(acctNumberStr, sizeof(acctNumberStr), stdin);
        
	strcpy(copyStr, acctNumberStr);

	printf("Account number: %s\n", copyStr);
        return(0);
}

