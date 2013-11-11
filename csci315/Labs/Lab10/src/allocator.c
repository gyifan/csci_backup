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
	printf("List: %d elements\n", l->counter);
	for (blk = (struct block*)dlist_iter_begin(l); blk != NULL;
			blk = (struct block*) dlist_iter_next(l)){
		printf("block ptr = %p; size = %zu\n", 
				blk->ptr, blk->size);
	}
}

double average_frag(){
	struct dnode *temp;
	struct block *tData;
	size_t size = 0;
	int count = 0;

	for(temp=free_list->front;temp!=NULL;temp=temp->next){
		tData = (struct block *)temp->data;
		size += tData->size;
		count ++;
	}

	return (double)size/(double)count;
}

double average_frag_r(struct dlist *free_list_r){
	struct dnode *temp;
	struct block *tData;
	size_t size = 0;
	int count = 0;

	for(temp=free_list_r->front;temp!=NULL;temp=temp->next){
		tData = (struct block *)temp->data;
		size += tData->size;
		count ++;
	}

	return (double)size/(double)count;
}

int allocator_init(size_t size, int p){
	/* initialize the lists */
	int policy;

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
#ifdef DEBUG
	printf("free_list->front: %p\n", free_list->front);
	struct block *beginning;
	beginning = (struct block *)free_list->front->data;
	printf("Memory start: %p, end: %p\n", beginning->ptr, beginning->ptr+size);
#endif /* DEBUG */

	/* specify the policy */
	policy = p;
	switch (policy){
		case 0: printf("first-fit is chosen.\n");
			break;
		case 2: printf("worst-fit is chosen.\n");
			break;
		default: printf("best-fit is chosen.\n");
	}
	return 0;
}

int allocator_init_r(size_t size, int p, struct dlist *free_list_r, struct dlist *allocated_list_r){
	/* initialize the lists */
	int policy;
	
	/* initialize the block with the size and pointer */ 
	struct block *blk = malloc(sizeof (struct block));
	blk->size = size;
	/* allocate the memory with malloc */
	if(NULL == (blk->ptr = malloc(size))){
		perror("malloc failed\n");
		return -1;
	}

	/* add the dnode into the free_list_r */
	dlist_add_front(free_list_r, blk);
#ifdef DEBUG
	printf("free_list_r->front: %p\n", free_list_r->front);
	struct block *beginning;
	beginning = (struct block *)free_list_r->front->data;
	printf("Memory start: %p, end: %p\n", beginning->ptr, beginning->ptr+size);
#endif /* DEBUG */

	/* specify the policy */
	policy = p;
/*
	switch (policy){
		case 0: printf("first-fit is chosen.\n");
			break;
		case 2: printf("worst-fit is chosen.\n");
			break;
		default: printf("best-fit is chosen.\n");
	}
*/
	return 0;
}

int allocate(int p, size_t size, void **rval){
	/* selects policy */
	int policy;
	policy = p;
	/*
	   switch (policy){
	   case 0: printf("first-fit is chosen.\n");
	   break;
	   case 2: printf("worst-fit is chosen.\n");
	   break;
	   default: printf("best-fit is chosen.\n");
	   }
	   */	
	/* create the blk that will be added to the list */
	struct block *blk = malloc(sizeof (struct block));
	blk->size = size;

	struct dnode *temp; /* temp node to store ptr to selected node */
	struct dnode *counter; /* temp node for looping */
	struct block *cData;
	struct block *tData; /* temp->data */

#ifdef DEBUG
	printf("free_list->front: %p\n", free_list->front);
#endif /* DEBUG */

	switch (policy){
		case 0:{
			       /*
				* =====================================================================
				* First-fit
				* =====================================================================
				*/
			       /* Get node from free_list and check size whether it fits */
			       
			       temp=NULL;
			       counter=free_list->front;
			       cData=(struct block *)counter->data;
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
				       *rval=NULL;
				       return -1;
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
			       break;
		       }
		case 2:{
			       /*
				* =====================================================================
				* Worst-fit
				* =====================================================================
				*/	

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
				       *rval=NULL;
				       return -1;
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
			       break;
		       }
		default:{
				/*
				 * =====================================================================
				 * Best-fit
				 * =====================================================================
				 */

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
					*rval=NULL;
					return -1;
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

			}
	}

	/* clear node with 0 size */
	if(0==tData->size){
		if(NULL==temp->prev){
			if(NULL==temp->next){
				/* No node left */
				dlist_destroy(free_list);
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
				free_list->counter --;
			}
		}
	}

#ifdef DEBUG
	printf("free_list: \n");
	print_list(free_list);
	printf("allocated_list: \n");
	print_list(allocated_list);
#endif /* DEBUG */

	*rval = blk->ptr;
#ifdef DEBUG
	printf("## Done allocating ##\n");
#endif /* DEBUG */
	return 0;
}

int allocate_r(int p, size_t size, void **rval, struct dlist *free_list_r, struct dlist *allocated_list_r){
	/* selects policy */
	int policy;
	policy = p;
	/*
	   switch (policy){
	   case 0: printf("first-fit is chosen.\n");
	   break;
	   case 2: printf("worst-fit is chosen.\n");
	   break;
	   default: printf("best-fit is chosen.\n");
	   }
	   */	
	/* create the blk that will be added to the list */
	struct block *blk = malloc(sizeof (struct block));
	blk->size = size;

	struct dnode *temp; /* temp node to store ptr to selected node */
	struct dnode *counter; /* temp node for looping */
	struct block *cData;
	struct block *tData; /* temp->data */

#ifdef DEBUG
	printf("free_list_r->front: %p\n", free_list_r->front);
#endif /* DEBUG */

	switch (policy){
		case 0:{
			       /*
				* =====================================================================
				* First-fit
				* =====================================================================
				*/
			       /* Get node from free_list_r and check size whether it fits */
			       
			       temp=NULL;
			       counter=free_list_r->front;
			       cData=(struct block *)counter->data;
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
#ifdef DEBUG
				       printf("Not enough space in the memory!\n");
#endif /* DEBUG */
				       *rval=NULL;
				       return -1;
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

			       /* Add the new node into allocated_list_r */
			       dlist_add_front(allocated_list_r, blk);
			       break;
		       }
		case 2:{
			       /*
				* =====================================================================
				* Worst-fit
				* =====================================================================
				*/	

			       /* Get node from free_list_r */
			       counter=free_list_r->front;
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
#ifdef DEBUG
				       printf("Not enough space in the memory!\n");
#endif /* DEBUG */
				       *rval=NULL;
				       return -1;
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

			       /* Add the new node into allocated_list_r */
			       dlist_add_front(allocated_list_r, blk);
			       break;
		       }
		default:{
				/*
				 * =====================================================================
				 * Best-fit
				 * =====================================================================
				 */

				/* Get node from free_list_r with best fit policy */
				temp=NULL;
				counter=free_list_r->front;

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
#ifdef DEBUG
					printf("Not enough space in the memory!\n");
#endif /* DEBUG */
					*rval=NULL;
					return -1;
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

				/* Add the new node into allocated_list_r */
				dlist_add_front(allocated_list_r, blk);

			}
	}

	/* clear node with 0 size */
	if(0==tData->size){
		if(NULL==temp->prev){
			if(NULL==temp->next){
				/* No node left */
				dlist_destroy(free_list_r);
			}else{
				/* This is the first node */
				dlist_remove_front(free_list_r);
			}
		}else{
			if(NULL==temp->next){
				/* This is the last node */
				dlist_remove_back(free_list_r);
			}else{
				/* This node is in the middle of the list */
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				dnode_destroy(temp);
				free_list_r->counter --;
			}
		}
	}

#ifdef DEBUG
	printf("free_list_r: \n");
	print_list(free_list_r);
	printf("allocated_list_r: \n");
	print_list(allocated_list_r);
#endif /* DEBUG */

	*rval = blk->ptr;
#ifdef DEBUG
	printf("## Done allocating ##\n");
#endif /* DEBUG */
	return 0;
}

int deallocate(void *ptr){
	/* Go through the allocated_list and find the node */
	struct dnode *temp;
	struct block *tData;

	temp = allocated_list->front;
	tData = (struct block*)temp->data;

#ifdef DEBUG
	printf("free location: %p\n", ptr);
	printf("temp: %p, allocated_list->front: %p\n",temp, allocated_list->front);
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
			newblk=(struct block *)dnode_destroy(temp);
			allocated_list->front=allocated_list->back=NULL;
			allocated_list->counter --;
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
			allocated_list->counter --;
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

int deallocate_r(void *ptr, struct dlist *free_list_r, struct dlist *allocated_list_r){
	/* Go through the allocated_list_r and find the node */
	struct dnode *temp;
	struct block *tData;

	temp = allocated_list_r->front;
	tData = (struct block*)temp->data;

#ifdef DEBUG
	printf("free location: %p\n", ptr);
	printf("temp: %p, allocated_list_r->front: %p\n",temp, allocated_list_r->front);
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

	/* Remove the node from allocated_list_r */
	struct block *newblk;
	if(NULL==temp->prev){
		if(NULL==temp->next){
			/* No node left */
			newblk=(struct block *)dnode_destroy(temp);
			allocated_list_r->front=allocated_list_r->back=NULL;
			allocated_list_r->counter --;
		}else{
			/* This is the first node */
			newblk=(struct block *)dlist_remove_front(allocated_list_r);
		}
	}else{
		if(NULL==temp->next){
			/* This is the last node */
			newblk=(struct block *)dlist_remove_back(allocated_list_r);
		}else{
			/* This node is in the middle of the list */
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			newblk=(struct block *)dnode_destroy(temp);
			allocated_list_r->counter --;
		}
	}
#ifdef DEBUG
	printf("newblk->ptr: %p; size: %zu\n",
			newblk->ptr,newblk->size);
#endif /* DEBUG */

	dlist_add_front(free_list_r,newblk);

#ifdef DEBUG
	printf("free_list_r: \n");
	print_list(free_list_r);
	printf("allocated_list_r: \n");
	print_list(allocated_list_r);
#endif /* DEBUG */

	return 0;
}
