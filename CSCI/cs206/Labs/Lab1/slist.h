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

#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdint.h>
#include <stdbool.h>
#include "snode.h"

#define FALSE 0
#define TRUE 1

/**
 * Singly-linked list.
 */
struct slist {
	struct snode *front; // front node
	struct snode *back;  // back node
	uint32_t counter;    // number of nodes
};

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create();

/**
 * Deallocates all nodes in a slist and the data they point to, but
 * preserve the list.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_destroy(struct slist *l);

/**
 * Deallocates all nodes in a slist and the data they point to; deallocate
 * the list itself as well. This is the inverse of slist_create.
 * @param l pointer to the list (non-NULL)
 */
void slist_obliterate(struct slist *l);

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 */
void slist_add_back(struct slist *l, char *str);

/**
 * Returns TRUE or FALSE (as an integer) to indicate whether
 * there is a match to the given string in some node of the list.
 * 
 * @parap str pointer to a string
 * @return TRUE or FALSE (1 or 0, respectively)
 */
int slist_find(struct slist *l, char *str);

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_num_elems(struct slist *l);

/**
 * Traverse the list printing to stdout the string found in each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l);

#endif /* _SLIST_H_ */
