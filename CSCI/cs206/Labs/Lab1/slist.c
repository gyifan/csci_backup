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

#include "snode.h"
#include "slist.h"

struct slist *
slist_create () {
	return calloc(1, sizeof(struct slist));
}

void 
slist_destroy(struct slist *l) {
	struct snode *p = l->front;

	do {
		l->front = l->front->next;
		free(p->text);
		free(p);
		p = l->front;
	} while (l->front != NULL);

	l->front = l->back = NULL;
	l->counter = 0;
}

void 
slist_obliterate(struct slist *l) {
	slist_destroy(l);
	free(l);
}

void 
slist_add_back(struct slist *l, char *str) {
	struct snode *newp;
	newp = snode_create();
	snode_setdata(newp,str);
	if(l->front == NULL)
		l->front = newp;
	if(l->back != NULL)
		l->back->next = newp;
	l->back = newp;
	l->counter++;

#ifdef DEBUG
	printf("counter= %d, %s\n", l->counter, (char *) ptr);
	printf("front= %s\n", (char *) l->front->data);
	printf("back= %s\n\n", (char *) l->back->data);
#endif /* DEBUG */
}

int 
slist_find(struct slist *l, char *str) {
	struct snode *temp;
	temp = l->front;
	while(temp != NULL){
		if(strcmp(str,temp->text)!=0)
			temp=temp->next;
		else
			return 1;
	}
	return 0;
}

void
slist_traverse(struct slist *l) {
	struct snode *temp;
	temp = l->front;
	while(temp != NULL){
		printf("%s",temp->text);
		temp=temp->next;
	}	
}

uint32_t 
slist_num_elems(struct slist *l) {
	return l->counter;
}

