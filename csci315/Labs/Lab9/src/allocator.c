/*
 * This is file implements a custom memory allocator. It provides detailed
 * implementation for the functions in allocator.h. 
 */

#include <stdlib.h>
#include <stdio.h>
#include "allocator.h"
#include "dlist.h"

/* Global Variables */
struct dlist *free_list;
struct dlist *allocated_list;

void print_list(struct dlist *l) {
	struct block *blk;
	printf("List:\n");
	for (blk = (struct block*)dlist_iter_begin(l); blk != NULL;
			blk = (struct block*) dlist_iter_next(l)){
		printf("block ptr = %p; size = %zu\n", 
				blk->ptr, blk->size);
	}
}

int allocator_init(size_t size){
	/* initialize the lists */
	free_list = dlist_create();
	allocated_list = dlist_create();

	/* initialize the block with the size and pointer */ 
	struct block *blk = malloc(sizeof (struct block));
	blk->size = size;
	/* allocate the memory with malloc */
	if(NULL == (blk->ptr = malloc(size))){
		perror("malloc failed\n");
		return -1;
	}

	/* add the dnode into the free_list */
	dlist_add_front(free_list, blk);

#ifdef FIRSTFIT
	printf("first-fit is chosen.\n");
#elif WORSTFIT
	printf("worst-fit is chosen.\n");
#else
	printf("best-fit is chosen.\n");
#endif

	return 0;
}

void *allocate(size_t size){
	/*
	 * The allocation policy needs to be define at compile time. 
	 * Options: FIRST-FIT, WORST-FIT, BEST-FIT(default)
	 */

	/* create the blk that will be added to the list */
	struct block *blk = malloc(sizeof (struct block));
	blk->size = size;

	struct dnode *counter; /* temp node for looping */
	struct dnode *temp;

#ifdef DEBUG
	printf("free_list->front: %p\n", free_list->front);
#endif /* DEBUG */

/*
 * =====================================================================
 * First-fit
 * =====================================================================
 */
#ifdef FIRSTFIT
	/* Get node from free_list and check size whether it fits */
	struct block *cData;
	struct block *tData;
	
	temp=NULL;
	counter=free_list->front;
#ifdef DEBUG
	printf("==========================================\n");
#endif /* DEBUG */

	while((temp==NULL) && (counter!=NULL)){
		cData=(struct block *)counter->data;
		if(cData->size>=size){
			temp=counter;
			tData=cData;
		}
		counter=counter->next;
	}
	if(temp==NULL){
		printf("Not enough space in the memory!\n");
		return NULL;
	}

	/* Set the pointer in the new block and set new node */
	blk->ptr = tData->ptr;

	/* Change the size of the original node in the list */
	tData->size -= size;
	tData->ptr += size;
	dnode_setdata(temp, tData);

#ifdef DEBUG
	printf("==========================================\n");
	printf("new size: %zu\n", tData->size);
	printf("new ptr: %p\n", tData->ptr);
	printf("blk size: %zu\n", blk->size);
	printf("blk ptr: %p\n", blk->ptr);
#endif /* DEBUG */

	/* Add the new node into allocated_list */
	dlist_add_front(allocated_list, blk);

/*
 * =====================================================================
 * Worst-fit
 * =====================================================================
 */
#elif WORSTFIT	
	struct block *tData;
	struct block *cData;

	/* Get node from free_list */
	counter=free_list->front;
	temp=NULL;
#ifdef DEBUG
	printf("==========================================\n");
	printf("counter is set: %p\n", counter);
#endif /* DEBUG */
	while(counter!=NULL){
		cData=(struct block *)counter->data;
		if(cData->size>=size){
			if(temp==NULL){
				temp=counter;
				tData=cData;
			}else if(cData->size > tData->size){
				temp = counter;
				tData = cData;
			}
		}
		counter = counter->next;
	}
	if(temp==NULL){
		printf("Not enough space in the memory!\n");
		return NULL;
	}

	/* Set the pointer in the new block and set new node */
	blk->ptr = tData->ptr;

	/* Change the size of the original node in the list */
	tData->size -= size;
	tData->ptr += size;
	dnode_setdata(temp, tData);

#ifdef DEBUG
	printf("==========================================\n");
	printf("new size: %zu\n", tData->size);
	printf("new ptr: %p\n", tData->ptr);
	printf("blk size: %zu\n", blk->size);
	printf("blk ptr: %p\n", blk->ptr);
#endif /* DEBUG */

	/* Add the new node into allocated_list */
	dlist_add_front(allocated_list, blk);

/*
 * =====================================================================
 * Best-fit
 * =====================================================================
 */
#else
	struct block *tData;
	struct block *cData;

	/* Get node from free_list with best fit policy */
	temp=NULL;
	counter=free_list->front;

#ifdef DEBUG
	printf("==========================================\n");
	printf("counter is set: %p\n", counter);
#endif /* DEBUG */

	while(counter!=NULL){
		cData = (struct block *)counter->data;

#ifdef DEBUG
	printf("cData->size: %zu\n",cData->size);
	printf("size wanted: %zu\n",size);
	if(temp==NULL)
		printf("no block matched.\n");
	else
		printf("tData->size: %zu\n",tData->size);
#endif /* DEBUG */	

		if(cData->size>=size){
			if(temp==NULL){
				temp=counter;
				tData=cData;
			}else if(cData->size<tData->size){
				temp=counter;
				tData=cData;
			}
#ifdef DEBUG
	printf("updated temp\n");
#endif /* DEBUG */

		}
		counter = counter->next;
	}
	if(temp==NULL){
		printf("Not enough space in the memory!\n");
		return NULL;
	}

	/* Set the pointer in the new block and set new node */
	blk->ptr = tData->ptr;

	/* Change the size of the original node in the list */
	tData->size -= size;
	tData->ptr += size;
	dnode_setdata(temp, tData);

#ifdef DEBUG
	printf("==========================================\n");
	printf("new size: %zu\n", tData->size);
	printf("new ptr: %p\n", tData->ptr);
	printf("blk size: %zu\n", blk->size);
	printf("blk ptr: %p\n", blk->ptr);
#endif /* DEBUG */

	/* Add the new node into allocated_list */
	dlist_add_front(allocated_list, blk);

#endif
	if(0==tData->size){
		if(NULL==temp->prev){
			if(NULL==temp->next){
				/* No node left */
				free_list->front=NULL;
				free_list->back=NULL;
				dnode_destroy(temp);
			}else{
				/* This is the first node */
				dlist_remove_front(free_list);
			}
		}else{
			if(NULL==temp->next){
				/* This is the last node */
				dlist_remove_back(free_list);
			}else{
				/* This node is in the middle of the list */
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				dnode_destroy(temp);
			}
		}
	}

#ifdef DEBUG
	printf("free_list: \n");
	print_list(free_list);
	printf("allocated_list: \n");
	print_list(allocated_list);
#endif /* DEBUG */

	return blk->ptr;
}

int deallocate(void *ptr){
	/* Go through the allocated_list and find the node */
	struct dnode *temp;
	struct block *tData;

	temp = allocated_list->front;
	tData = (struct block*)temp->data;

#ifdef DEBUG
	printf("free location: %p\n", ptr);
	printf("temp: %p\n",temp);
	printf("tData->ptr: %p\n",tData->ptr);
	printf("tData->size: %zu\n",tData->size);
#endif /* DEBUG */

	if((temp!=NULL) && (tData->ptr != ptr))
		do {
			temp = temp->next;
			tData = (struct block*)temp->data;
		} while((temp!=NULL) && (tData->ptr != ptr));
	if(temp==NULL){
		printf("Pointer not found.\n");
		return -1;
	}
#ifdef DEBUG
	printf("tData->ptr: %p\n",tData->ptr);
#endif /* DEBUG */

	/* Remove the node from allocated_list */
	struct block *newblk;
	if(NULL==temp->prev){
		if(NULL==temp->next){
			/* No node left */
			allocated_list->front=NULL;
			allocated_list->back=NULL;
			newblk=(struct block *)dnode_destroy(temp);
		}else{
			/* This is the first node */
			newblk=(struct block *)dlist_remove_front(allocated_list);
		}
	}else{
		if(NULL==temp->next){
			/* This is the last node */
			newblk=(struct block *)dlist_remove_back(allocated_list);
		}else{
			/* This node is in the middle of the list */
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			newblk=(struct block *)dnode_destroy(temp);
		}
	}
#ifdef DEBUG
	printf("newblk->ptr: %p; size: %zu\n",
			newblk->ptr,newblk->size);
#endif /* DEBUG */

	dlist_add_front(free_list,newblk);
	
#ifdef DEBUG
	printf("free_list: \n");
	print_list(free_list);
	printf("allocated_list: \n");
	print_list(allocated_list);
#endif /* DEBUG */

	return 0;
}
