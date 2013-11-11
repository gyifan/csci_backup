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

#ifndef _SNODE_H_
#define _SNODE_H_

/**
 * Node in a singly-linked list.
 */
struct snode {
	struct snode *next;
	char *text;
};

/**
 * Allocates a new dnode leaving the pointer to data as null.
 *
 * @return pointer to a new dnode
 */
struct snode *snode_create();

/**
 * Sets the pointer to text with the value passed in.
 *
 * @param n pointer to the snone
 * @param ptr pointer to a C string to store in snode
 */
void snode_setdata(struct snode *n, char *s);

/**
 * Deallocates snode but not the string it points to. The caller must take
 * the responsibility of deallocating the string later on.
 *
 * @param n pointer to the snode
 * @return pointer to the C string stored in the snode
 */
void *snode_destroy(struct snode *n);

/** 
 * Deallocates a snode and also the data it points to.
 *
 * @param ptr pointer to the snode
 */
void snode_obliterate(struct snode *n); 

#endif /* _SNODE_H_ */
