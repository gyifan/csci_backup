/*
 * This program is a custom memory allocator. It includes the basic
 * functionalities of the memory allocator in operating system:
 * malloc, free. In order to use this allocator, user would need to 
 * initialize it first by calling allocator_init()
 *
 */

#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

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
 */
int allocator_init(size_t size);

/**
 * Equivalent to malloc. This function will traverse the free_list and
 * find a contriguous chunk of memory that can be used to satisfy the
 * request of an area of size bytes. It the caller makes a request 
 * for memory that is larger than what the allocator can honor, this
 * function will return NULL. This function will be flexible enough to
 * allow for different allocation policies, namely first-fit, best-fit,
 * and worst-fit.
 *
 * Return value: the pointer to the memory address. Error: -1. 
 */
void *allocate(size_t size);

/**
 * Equivalent to free. This function will use ptr to find the
 * corresponding node in the allocated_list and free up that chunk of 
 * memory. If the caller attempts to deallocate a pointer that cannot
 * be found in the allocated_list, this function will return -1,
 * otherwise it will return 0.
 */
int deallocate(void *ptr);

#endif /* _ALLOCATOR_H_ */
