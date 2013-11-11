#include <stdlib.h>
#include <stdio.h>
#include "allocator.h"
#include "dnode.h"
#include "dlist.h"

#define SIZE 1024 /* size of the allocatable memory */

int test(int policy, unsigned int seed, int requests){
	
	return 0;
}

int main(int argc, char *argv[]) {
	int policy;
	unsigned int seed;
	int requests;
	/* temp pointer to the memory */
	void *p = NULL;
	int counter=0;
	int s; /* temp size of the allocated memory */
	double frag; /* Average fragmentation size */
	
	if(argc!=4){
		printf("usage: frag-eval [algorithm] [seed] [int requests]\n");
		exit(-1);
	}else{
		policy=atoi(argv[1]);
		seed=atoi(argv[2]);
		requests=atoi(argv[3]);
	}

#ifdef DEBUG
	printf("policy: %d, seed: %u, requests: %d\n", policy, seed, requests);
#endif /* DEBUG */
	
	srand(seed);
	
	if(allocator_init(SIZE, policy)){
		printf("init failed");
		exit(-1);
	}
	
#ifdef DEBUG
	printf("successful init\n");
#endif /* DEBUG */
	
	while(counter<requests) {
		s = rand()%900+100;
		printf("#################### Allocating size: %d#######################\n", s);
		p = allocate(policy, s);
		if(NULL==p) printf("\n");
		else{
			deallocate(p);
			printf("------------------ Deallocated size: %d------------------\n\n",s);
		}
		counter++;
	}
	
	frag = average_frag();
	printf("Average fragmentation size: %f\n", frag);
/*
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
*/
	return 0;
}
