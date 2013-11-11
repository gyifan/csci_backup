/*
 * This program is a custom memory allocator. It includes the basic
 * functionalities of the memory allocator in operating system:
 * malloc, free. In order to use this allocator, user would need to 
 * initialize it first by calling allocator_init()
 *
 */

#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include "dnode.h"
#include "dlist.h"

/**
 * block representing memory space
 */
struct block {
	size_t size;
	void *ptr;
};

/**
 * This function will create and initialize two memory management 
 * lists: one which keeps track of the memory that is available 
 * (call it free_list) and another which keeps track of memory 
 * which is already in use (call it allocated_list). All the memory 
 * manipulated by the allocator will reside in the heap of the 
 * process that uses it. When allocator_init starts, it will call 
 * the standard malloc to request a contiguous space of size bytes 
 * from the underlying operating system. The pointer received from 
 * malloc will be used to initialize a single node in the free_list; 
 * the allocated_list will start out empty. If the malloc call does 
 * not succeed, this function must return -1, otherwise, it must 
 * return 0.
 *
 * parameters: 	size - total size of the allocatable memory
 * 		policy - 0(first-fit), 1(best-fit), 2(worst-fit)
 */
int allocator_init(size_t size, int policy);
int allocator_init_r(size_t size, int policy, struct dlist *free, struct dlist *allocated);

/**
 * Equivalent to malloc. This function will traverse the free_list and
 * find a contriguous chunk of memory that can be used to satisfy the
 * request of an area of size bytes. It the caller makes a request 
 * for memory that is larger than what the allocator can honor, this
 * function will return NULL. This function will be flexible enough to
 * allow for different allocation policies, namely first-fit, best-fit,
 * and worst-fit.
 *
 * Allocated address is returned in rval
 * Return value: Success: 0 Error: -1. 
 */
int allocate(int policy, size_t size, void **rval);
int allocate_r(int policy, size_t size, void **rval, struct dlist *free, struct dlist *allocated);

/**
 * Equivalent to free. This function will use ptr to find the
 * corresponding node in the allocated_list and free up that chunk of 
 * memory. If the caller attempts to deallocate a pointer that cannot
 * be found in the allocated_list, this function will return -1,
 * otherwise it will return 0.
 */
int deallocate(void *ptr);
int deallocate_r(void *ptr, struct dlist *free, struct dlist *allocated);

/**
 * This function will compute the average fragmentation created in memory
 * after repeated, randomly interleaved calls to allocate an deallocate
 * functions.
 */
double average_frag();
double average_frag_r(struct dlist *free);

#endif /* _ALLOCATOR_H_ */
