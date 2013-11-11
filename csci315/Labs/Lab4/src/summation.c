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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>

// structure for thread arguments
struct thread_args {
	int tid;
	int a;
	int b;
	double x;
	double result;
	int time;
};

extern int shared;

// Function prints the current time
char * get_time(void){
        struct timeval tv;
        time_t t;
        int rc;
        char *rv;

        rc = gettimeofday(&tv, NULL);
        if(rc){
                perror("gettimeofday failed");
                exit(-1);
        }

        t = tv.tv_sec;

        rv = ctime(&t);
        if(rv == NULL){
                perror("ctime failed");
                exit(-1);
        }
        return(rv);
}


// function that each thread will execute
void *SumExp(void *args_ptr) {
	// Gets time when the program starts
	struct timeval *t_start;
	struct timeval *t_end;
	t_start = (struct timeval *)malloc(sizeof(struct timeval));
	t_end = (struct timeval *)malloc(sizeof(struct timeval));
	gettimeofday(t_start, NULL);	
	
	int i;
	struct thread_args *myargs_ptr = (struct thread_args*) args_ptr;
	myargs_ptr->result = 0;
	// exit(-1);
	shared = 123;
	// execl("/bin/ls","ls",NULL);

	printf("Thread %d starting a= %d, b= %d, x= %lf\n",
			myargs_ptr->tid,
			myargs_ptr->a,
			myargs_ptr->b,
			myargs_ptr->x);
	// exit(-1);
	// execl("/bin/ls","ls",NULL);
	for (i=myargs_ptr->a; i<myargs_ptr->b; i++) {
		myargs_ptr->result += pow(i, myargs_ptr->x);
	}
	
	// Get the time it took	
	gettimeofday(t_end,NULL);
	myargs_ptr->time = (int)(t_end->tv_usec-t_start->tv_usec);

	printf("Thread %d done a= %d, b= %d, x= %lf -> result = %lf\nTime eclapsed: %dus %s",
			myargs_ptr->tid,
			myargs_ptr->a,
			myargs_ptr->b,
			myargs_ptr->x,
			myargs_ptr->result,
			myargs_ptr->time,
			get_time());
	fflush(stdout);
	pthread_exit((void*) args_ptr);
}

int shared;

int main (int argc, char *argv[]) {
	// Gets time when the program starts
	struct timeval *t_start;
	struct timeval *t_end;
	t_start = (struct timeval *)malloc(sizeof(struct timeval));
	t_end = (struct timeval *)malloc(sizeof(struct timeval));
	gettimeofday(t_start, NULL);

	pthread_attr_t attr;

	struct thread_args *targs; // array for thread argument structs
	struct thread_args **tstatus; // array of pointers to returns from threads
	pthread_t *tidp; // array for thread ids

	int ret_val;
	int i;
	void *status;
	double summation = 0;

	int num_threads, increment; // command line parameters

	if (argc < 3) {
		printf("usage: summation [numthreads] [increment]\n");
		exit(-1);
	}

	num_threads = atoi(argv[1]);
	increment = atoi(argv[2]);

	targs = (struct thread_args *) calloc(num_threads, sizeof(struct thread_args));
	tstatus = (struct thread_args **) calloc(num_threads, sizeof(struct thread_args *));
	tidp = (pthread_t *) calloc(num_threads, sizeof(pthread_t));

	// initialize attr variable
	pthread_attr_init(&attr);

	// initialize thread detached state to joinable
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i=0; i<num_threads; i++) {
		tstatus[i] = malloc(sizeof(struct thread_args));

		targs[i].a = increment*i;
		targs[i].b = increment*(i+1);
		targs[i].x = 2;
		targs[i].tid = i;
		targs[i].result = 0;

		ret_val = pthread_create(&tidp[i], &attr, SumExp, (void *) &targs[i]);
		if (ret_val) {
			printf("ERROR in pthread_create for thread %d: return value= %d\n", 
					i, ret_val);
			exit(-1);
		}
	}

	// free attribute variable
	pthread_attr_destroy(&attr);

	// main thread waits for spawned threads to terminate
	for(i=0; i<num_threads; i++) {
		// 
		ret_val = pthread_join(tidp[i], (void **) &tstatus[i]);
		if (ret_val) {
			printf("ERROR in pthread_join() for thread %d = return value= %d\n",
					i, ret_val);
			exit(-1);
		}

		summation += tstatus[i]->result;
		printf("Joined thread %d; returned= %lf\n", i, tstatus[i]->result);
	}

	printf("Total value computed = %lf\n", summation);
	
	// Gets time when the program ends and compute the time it elapsed
	gettimeofday(t_end,NULL);
	printf("Total time elapsed: %dus\n", (int)(t_end->tv_usec-t_start->tv_usec));
	
	pthread_exit(NULL);
	printf("still here\n");
}
