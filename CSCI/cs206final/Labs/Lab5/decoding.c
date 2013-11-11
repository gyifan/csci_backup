/*
 * CSCI 206 Computer Organization & Programming
 * Author: L. Felipe Perrone
 * Date: 2011-09-21
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

 /* 
 * Exercize in decoding the stack
 *
 * Derived from:
 * EX7-17, from http://www.buildingsecuresoftware.com
 *
 */

#include <stdio.h>

char *j;

// function prototype for main, so the symbol can be used in test()
int main();

// print the address of a few items
// remember that parameter i is passed on the stack
void test(int i) {

  // declaration of local buffer; buf resides on the stack
  static char buf[12];

	// declaration of local variable used in for loop
	int k;

  // print the address of function main, which contains a call to test
  printf("&main = %p\n", &main);

  // print the address of variable i, a formal parameter of test
  printf("&i = %p\n", &i);

  for (k=0; k<12; k++) {
    printf("&buf[%d] = %p\n", k, &(buf[k]));
  }

  printf("\n---------------- Memory dump starts\n");
  for (j = buf; j < ((char *)&i) + 8; j++)
    printf("%p: 0x%02x\n", j, *(unsigned char *)j);
  printf("---------------- Memory dump ends\n");
}

int main()
{
  test(12);
	return 0;
}
