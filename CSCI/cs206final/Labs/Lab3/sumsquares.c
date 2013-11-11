/*
 * CSCI 206 Computer Organization & Programming
 * Author: L. Felipe Perrone
 * Date: 2011-09-13
 * Copyright (c) 2011 Bucknell University
 *
 * Permission is hereby granted, free of charge, to any individual or
 * institution obtaining a copy of this software and associated
 * documentation files (the "Software"), to use, copy, modify, and
 * distribute without restriction, provided that this copyright and
 * permission notice is maintained, intact, in all copies and supporting
 * documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>

int squares[100];

int sum;

int i;

int main(int argv, char* arcv[]) {

	sum = 0;

	i = 0;
	
	printf("Label\tAddress\tValue\n");
	while (i < 100) {
		squares[i] = i*i;
		printf("squares[%d]\t%p\t%d\n",i,&squares[i],squares[i]);
		sum = sum + squares[i];
		i++;
	}
	printf("sum\t%p\t%d\n",&sum,sum);
	printf("i\t%p\t%d\n",&i,i);

	i = 0;
	while (i < 100) {
		printf("squares[%d]= %d\n", i, squares[i]);
		i++;
	}

	printf("sum of squares from 0 to 99 = %d\n", sum);

}
