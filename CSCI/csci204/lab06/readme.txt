/*
 *===================================================
 *  Name: Yifan Ge
 *  Course: CSCI 204 / Prof. Wittie
 *  Assignment: Lab #6
 *  Date: 03/03/2011
 *
 *===================================================
 */
 
Question 1: if(n == 1) --> return 1;
	The final result will not change if we didn't enter 0. This is because that
	1 and 0 can both be base cases and the factorial values for both 1 and 0 
	are the same, which is 1. Since we are doing multiplication, the only 
	difference would be the times that we multiply the previous number by 1, 
	which doesn't change the result. However, if we enter 0 in this case, the
	program will give us a invalid number. 
	
Question 2: if(n == 0) --> return 0;
	The final result will change and is always 0. As we will always multiply
	with the result of the base case, which is 0 in this case, we will always
	get 0 for the answer.
	
Question 3: else return 2*n*factorial(n-1);
	The final result will be enlarged by a factor of 2^n. 
	
