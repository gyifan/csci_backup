#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "allocator.h"
#include "dnode.h"
#include "dlist.h"

#define SIZE 1024 /* size of the allocatable memory */

struct param {
	int policy;
	unsigned int seed;
	int requests;
};

void *test(void *ptr) {
	
#ifdef DEBUG
	pthread_t id;
	id = pthread_self();
	printf("test %zu started\n", id);
#endif /* DEBUG */

	struct param *inf = (struct param *)ptr;
	int policy;
	unsigned int seed;
	int requests;
	
	struct dlist *free_list;
	struct dlist *allocated_list;
	free_list = dlist_create();
	allocated_list = dlist_create();
	/* temp pointer to the memory */
	void *p = NULL;
	int counter=0;
	int size; /* temp size of the allocated memory */
	double *frag = malloc(sizeof(double)); /* Average fragmentation size */

	policy=inf->policy;
	seed=inf->seed;
	requests=inf->requests;

#ifdef DEBUG
	printf("%zu policy: %d, seed: %d, requests: %d\n",id, policy, seed, requests);
#endif /* DEBUG */
	
	/* Set the random buffer with given seed */
	
	if(allocator_init_r(SIZE, policy, free_list, allocated_list)){
		printf("init failed");
		exit(-1);
	}
	
#ifdef DEBUG
	printf("%zu successful init\n",id);
#endif /* DEBUG */
	
	while(counter<requests) {
		size = rand_r(&seed)%900+100;
#ifdef DEBUG
	printf("\n%zu size: %d\n\n",id, size);
#endif /* DEBUG */
		allocate_r(policy, size, &p, free_list, allocated_list);
#ifdef DEBUG
	printf("%zu size: %d, pointer: %p",id,size,p);
#endif /* DEBUG */
		if(NULL==p){
#ifdef DEBUG
			printf("Allocation Failed!\n");
#endif /* DEBUG */
			;
		}
		else
			deallocate_r(p, free_list, allocated_list);
		counter++;
	}
		
	*frag = average_frag_r(free_list);
	printf("%u	 %f\n", seed, *frag);

	pthread_exit((void *)frag);
}

int main(int argc, char *argv[]){
	int policy;
	unsigned int seed_m;
	int requests;
	int repetitions;

	/* NEED TO READ FROM INPUT */
	if(argc<5){
		printf("\nUSAGE: automated_test policy seed_master requests repetitions \n");
		printf("==================================================================\n");
		printf("-> policy:   0-First-fit   1-Best-fit   2-Worst-fit\n");
		printf("-> seed_master: The seed put into main thread\n");
		printf("-> requests: # of requests for each test\n");
		printf("-> repetitions (R): # of test\n\n");
		exit(-1);
	}else{
		policy = atoi(argv[1]);
		switch (policy){
			case 0: printf("first-fit is chosen.\n");
				break;
			case 2: printf("worst-fit is chosen.\n");
				break;
			default: printf("best-fit is chosen.\n");
		}
		seed_m = atoi(argv[2]);
		printf("Master seed: %u\n", seed_m);
		requests = atoi(argv[3]);
		printf("# of Requests: %d\n", requests);
		repetitions = atoi(argv[4]);
		printf("# of Repetitions (R): %d\n", repetitions);
	}
	
	pthread_t threads[repetitions];
	int rc = 0;
	int t = 0;
	double frag;
	void *status;
	struct param *ptr[repetitions];
	unsigned int seed[repetitions];
	srand(seed_m);
	
	printf("Seed	Average_Fragmentation\n");
	
	for(t=0; t<repetitions; t++){
		ptr[t] = malloc(sizeof(struct param));
		seed[t] = rand();
//		printf("seed[%d]: %u\n", t, seed[t]);
		ptr[t]->policy = policy;
		ptr[t]->requests=requests;
//		printf("seed[%d]: %u", t, seed[t]);
		ptr[t]->seed=seed[t];
//		printf("In main: creating thread %d; seed[%d]: %d\n; seed: %d\n", t, t, seed[t], ptr[t]->seed);
		rc = pthread_create(&threads[t], NULL, test,(void *)ptr[t]);
#ifdef DEBUG
	printf("thread created\n");
#endif /* DEBUG */

		if(rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	for(t=0; t<repetitions; t++){
		rc = pthread_join(threads[t], &status);
		if(rc){
			printf("ERROR: pthread_join failed");
			exit(-1);
		}
/*
		frag=*(double *)status;
		printf("**********************%d; %f\n", t, frag);
*/
	}
	pthread_exit(NULL);
}
