/*
 * Copyright (c) 2012 Bucknell University
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: L. Felipe Perrone (perrone@bucknell.edu)
 */

#ifndef _DNODE_H_
#define _DNODE_H_

/**
 * Node in a doubly-linked list.
 */
struct dnode {
	struct dnode *prev;
	struct dnode *next;
	void *data;
};

/**
 * Allocates a new dnode leaving the pointer to data as null.
 *
 * @return pointer to a new dnode
 */
struct dnode *dnode_create();

/**
 * Sets the pointer to data with the value passed in.
 *
 * @param n pointer to the dnone
 * @param ptr pointer to a generic data type to store in dnode
 */
void dnode_setdata(struct dnode *n, void *ptr);

/**
 * Deallocates a dnode but not the data it points to. The caller must take
 * the responsibility of deallocating the data later on.
 *
 * @param n pointer to the dnode
 * @return pointer to the generic data type associated with node
 */
void *dnode_destroy(struct dnode *n);

/** 
 * Deallocates a dnode and also the data it points to.
 *
 * @param ptr pointer to the dnode
 */
void dnode_obliterate(struct dnode *n); 

#endif /* _DNODE_H_ */
