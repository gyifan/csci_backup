/*
 * CSCI 206 Computer Organization & Programming
 * Author: L. Felipe Perrone
 * Date: 2011-08-29
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "slist.h"

// global variables (data segment)

// pointer to an internal string
char *my_str;

// buffer to read user input
char user_str[80];

// pointer to a singly-linked list
struct slist *my_list;

// loop sentinel
int done;

//------------ MY MAIN FUNCTION ----------------------------------------

int main(int argc, char *argv[]) {

	// create an instance of singly-linked list
	my_list = slist_create();

	printf("list_test running...\n");

	// create storage for a string to mark the first node in list
	my_str = malloc(6);
	strncpy(my_str, "START\n", 7);	

	// add the string as first node in the list
	slist_add_back(my_list, my_str);

	// traverse list to see that first node was added correctly
	slist_traverse(my_list);

	// loop user input creating nodes for every new string typed
	done = FALSE;

	while (!done) {
		// read into user_str a new string from stdin
		char *user_str;
		fgets(user_str, 79, stdin);
		if (strncmp(user_str, ".", 1) != 0) {
			if (slist_find(my_list, user_str)==0){
				// create space to store the string that was read
				char *new_str;
				new_str = malloc(sizeof(user_str));
				// copy entered string into new space
				strncpy(new_str,user_str,sizeof(user_str));
				// add malloc'ed string to list
				slist_add_back(my_list, new_str);
			}
			// traverse list to check	
			slist_traverse(my_list);
		} else {
			done = TRUE;
		}

		// traverse list
	}
}

