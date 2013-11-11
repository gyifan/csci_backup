#include <stdlib.h>
#include <stdio.h>
#include "allocator.h"
#include "dnode.h"
#include "dlist.h"

int main(int argc, char *argv[]) {
	size_t size = 1024;
#ifdef DEBUG
	printf("initial size: %zu\n", size);
#endif /* DEBUG */
	if(allocator_init(size)){
		printf("init failed");
		exit(-1);
	}
#ifdef DEBUG
	printf("successful init\n");
#endif /* DEBUG */

	printf("**********allocating blk1: 128************\n");
	void *ptr1;
	ptr1=allocate(128);
	if(NULL==ptr1)
		printf("allocation failed.\n");
	else printf("blk1 is allocated: %p\n", ptr1);
	
	printf("**********allocating blk2: 512************\n");
	void *ptr2;
	ptr2=allocate(512);
	if(NULL==ptr2)
		printf("allocation failed.\n");
	else printf("blk2 is allocated: %p\n", ptr2);
	

	printf("**********allocating blk3: 64************\n");
	void *ptr3;
	ptr3=allocate(64);
	if(NULL==ptr3)
		printf("allocation failed.\n");
	else printf("blk3 is allocated: %p\n", ptr3);

	
	printf("**********Deallocating blk2: 512************\n");
	if(deallocate(ptr2)){
		printf("failed deallocation");
		exit(-1);
	}else printf("blk2 is deallocated.\n");


	printf("**********allocating blk4: 256************\n");
	void *ptr4;
	ptr4=allocate(256);	
	if(NULL==ptr4)
		printf("allocation failed.\n");
	else printf("blk4 is allocated: %p\n", ptr4);

	printf("**********Deallocating blk3: 64************\n");
	if(deallocate(ptr3)){
		printf("failed deallocation");
		exit(-1);
	}else printf("blk3 is deallocated.\n");

	printf("**********allocating blk5: 64************\n");
	void *ptr5;
	ptr5=allocate(64);
	if(NULL==ptr5)
		printf("allocation failed.\n");
	else printf("blk5 is allocated: %p\n", ptr5);
	
	printf("**********allocating blk6: 512************\n");
	void *ptr6;
	ptr6=allocate(512);
	if(NULL==ptr6)
		printf("allocation failed.\n");
	else printf("blk6 is allocated: %p\n", ptr6);

	return 0;
}
