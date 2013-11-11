#include <stdlib.h>
#include <stdio.h>
#include "allocator.h"
#include "dnode.h"
#include "dlist.h"

#define POLICY 0 /* 0-first-fit; 1-best-fit; 2-worst-fit */

int main(int argc, char *argv[]) {
	size_t size = 1024;
#ifdef DEBUG
	printf("initial size: %zu\n", size);
#endif /* DEBUG */
	if(allocator_init(size, POLICY)){
		printf("init failed");
		exit(-1);
	}
#ifdef DEBUG
	printf("successful init\n");
#endif /* DEBUG */
	int i;	
	void *ptr[10]; 
	for(i=0; i<10; i++)
		ptr[i]= malloc(sizeof(void *));

	printf("**********allocating blk1: 128************\n");
	allocate(POLICY, 128, &ptr[1]);
	if(NULL==ptr[1])
		printf("allocation failed.\n");
	else printf("blk1 is allocated: %p\n", ptr[1]);
	
	printf("**********allocating blk2: 512************\n");
	allocate(POLICY, 512, &ptr[2]);
	if(NULL==ptr[2])
		printf("allocation failed.\n");
	else printf("blk2 is allocated: %p\n", ptr[2]);
	

	printf("**********allocating blk3: 64************\n");
	allocate(POLICY, 64, &ptr[3]);
	if(NULL==ptr[3])
		printf("allocation failed.\n");
	else printf("blk3 is allocated: %p\n", ptr[3]);

	
	printf("**********Deallocating blk2: 512************\n");
	if(deallocate(ptr[2])){
		printf("failed deallocation");
		exit(-1);
	}else printf("blk2 is deallocated.\n");


	printf("**********allocating blk4: 256************\n");
	allocate(POLICY, 256, &ptr[4]);
	if(NULL==ptr[4])
		printf("allocation failed.\n");
	else printf("blk4 is allocated: %p\n", ptr[4]);

	printf("**********Deallocating blk3: 64************\n");
	if(deallocate(ptr[3])){
		printf("failed deallocation");
		exit(-1);
	}else printf("blk3 is deallocated.\n");

	printf("**********allocating blk5: 64************\n");
	allocate(POLICY, 64, &ptr[5]);
	if(NULL==ptr[5])
		printf("allocation failed.\n");
	else printf("blk5 is allocated: %p\n", ptr[5]);
	
	printf("**********allocating blk6: 512************\n");
	allocate(POLICY, 512, &ptr[6]);
	if(NULL==ptr[6])
		printf("allocation failed.\n");
	else printf("blk6 is allocated: %p\n", ptr[6]);

	return 0;
}
