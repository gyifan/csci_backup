/*
 * CSCI 206 Computer Orgainization & Programming
 * Author: Yifan Ge
 * Date: 2011-09-11
 */

#include <stdlib.h>
#include <stdio.h>

// The increasing counter
int counter;

// Sum of the program
int sum;

//------------- MY MAIN FUNCTION --------------------------------------

int main(void){
	
	//Initialize the counter and sum
	counter = 0;
	sum = 0;

	// Loop for adding 1 through 10 to sum
	for(counter;counter <= 10;counter++)
		sum += counter;
	
	// Display the result
	printf("The result is %d.\n",sum);
}
