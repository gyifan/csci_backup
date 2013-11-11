#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

struct timeval tv;

pthread_mutex_t chopsticks[5];

/*
struct parm {
	int id;
	pthread_mutex_t *chopsticks;
};
*/

int getSeed(void){
	if(gettimeofday(&tv, NULL)){
		perror("failed getting the seed");
		exit(-1);
	}
	return(tv.tv_usec);
}

void napping(int t){
	unsigned int seed = getSeed();

#ifdef DEBUG
	unsigned long test = rand_r(&seed)*1000000*t;
	printf("rand is %lu\n",test);
#endif /* DEBUG */
	
	// Cast to unsigned long to make it able to be divided by RAND_MAX
	// otherwise, it will be 0 all the time. 
	//
	// Uses microsecond to give more random selection between 0 and t.
	unsigned int sleepTime = (t*1000000*(unsigned long)rand_r(&seed))/RAND_MAX;

#ifdef DEBUG
	printf("sleepTime is %u\n", sleepTime);
	printf("seed is %u\n", seed);
	printf("Rand_Max is %d\n", (int)RAND_MAX);
#endif /* DEBUG */
	
	// Test if usleep takes usec more than 1000000.	
	if(usleep(sleepTime)){
		perror("usleep failed");
		exit(-1);
	}
}
	
void * Philosopher (void *id){
//	struct parm *param = (struct parm *)p;
//	int n = param->id;
//	pthread_mutex_t *chopsticks = param->chopsticks;
	long long n = (long long)id;

	while(1){
		printf("Philosopher %lld is thinking.\n", n);
		napping(2);
		printf("Philosopher %lld is hungry.\n", n);
		
		// Tries to get chopsticks
		if(pthread_mutex_lock(&chopsticks[n])){
			perror("Wait for mutex failed left");
			exit(-1);
		}
		if(pthread_mutex_lock(&chopsticks[(n+1)%5])){
			perror("Wait for mutex failed right");
			exit(-1);
		}

		printf("Philosopher %lld is starting to eat.\n", n);
		napping(1);
		printf("philosopher %lld is done eating.\n", n);
		
		// Put down the chopsticks
		if(pthread_mutex_unlock(&chopsticks[n])){
			perror("Unlock mutex failed left");
			exit(-1);
		}
		if(pthread_mutex_unlock(&chopsticks[(n+1)%5])){
			perror("Unlock mutex failed right");
			exit(-1);
		}
		fflush(stdout);
	}
	pthread_exit(NULL);
}	

int main(int argc, char *argv[]){
	pthread_t threads[5];
	int rc;
	
	long long t;
//	int t;
//	struct parm *parameter = malloc(sizeof(struct parm));
	
	// Declare and define mutexes as chopsticks
//	pthread_mutex_t chopsticks[5];
	for(t=0; t<5; t++){
		if(pthread_mutex_init(&chopsticks[t], NULL)){
			perror("Unable to initializem mutex");
			exit(-1);
		}
	}
	
	// store mutex in the parm struct
//	parameter->chopsticks = chopsticks;

	// Creates Philosopher threads
	for(t=0; t<5; t++){

#ifdef DEBUG
	printf("creating thread %lld\n", t);
#endif /* DEBUG */
//		parameter->id = t;
//		rc = pthread_create(&threads[t], NULL, Philosopher, (void *)parameter);
		rc = pthread_create(&threads[t], NULL, Philosopher, (void *)t);

		if (rc){
			perror("Failed creating Philosopher thread");
			exit(-1);
		}
	}

	pthread_exit(NULL);
}	
