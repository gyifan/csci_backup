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

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <unistd.h>
#include <sys/time.h>

#include "circular-list.h" 

// global variables -----------------------

struct circular_list mylist;
struct timeval tv;

// end of global variables ----------------

int getSeed(void){
  // uses the time of the day for random seed
  if(gettimeofday(&tv, NULL)){
    perror("failed getting the seed");
    exit(-1);
  }
  return(tv.tv_usec);
}


void *producer (void *param) {
  item i;
  unsigned int seed = getSeed();
  unsigned int sleeptime = 5;

  while (true) {
    // sleep for random period of time
    sleeptime = abs(rand_r(&seed)) / (RAND_MAX/1000);

#ifdef DEBUG
    printf("seed = %d\n", seed);
    printf("producer slept %d\n", sleeptime);
#endif /* DEBUG*/

    usleep(sleeptime); 
    
    // generate a random number
    i = (item) (((double) rand_r(&seed)) / RAND_MAX);

    if (circular_list_insert(&mylist, i) == -1) {
      printf("PRODUCER: error condition\n");
    } else {
      printf("PRODUCER: produced value %lf\n", i);
    }
  }
}

void *consumer (void *param) {
  item i;
  unsigned int seed = getSeed();
  unsigned int sleeptime = 0;

  while (true) {
    // sleep for random period of time
    sleeptime = abs(rand_r(&seed)) / (RAND_MAX/1000);

#ifdef DEBUG
    printf("seed = %d\n", seed);
    printf("consumer slept %d\n", sleeptime);
#endif /* DEBUG*/

    usleep(sleeptime);

    if (circular_list_remove(&mylist, &i) == -1) {
      printf("CONSUMER: error condition\n");
    } else {
      printf("CONSUMER: consumed value %lf\n", i);
    }
  }
}

int main (int argc, char *argv[]) {

  // get command line arguments
  if ( argc != 4 ){ /* argc should be 3 for correct execution */  
  // if error in command line argument usage, terminate with helpful
    printf( "usage: solution [num_prod] [num_cons] [sleep_time]\n");
    exit(-1);
  }

  // initialize buffer
  circular_list_create(&mylist, 20);
  int i;
  int num_prod = atoi(argv[1]);
  int num_cons = atoi(argv[2]);
  int sleep_time = atoi(argv[3]);
  pthread_t prods[num_prod];
  pthread_t cons[num_cons];
  void *unused_parm = malloc(sizeof(int));
  
  // create producer thread(s)
  for(i=0; i<num_prod; i++){
    printf("Creating producer %d\n", i);
    if(pthread_create(&prods[i], NULL, producer, unused_parm)){
      perror("Creating producer failed");
      exit(-1);
    }
  }

  // create consumer thread(s)
  for(i=0; i<num_cons; i++){
    printf("Creating consumer %d\n", i);
    if(pthread_create(&cons[i], NULL, consumer, unused_parm)){
      perror("Creating consumer failed");
      exit(-1);
    }
  }

  // sleep to give time for threads to run
  usleep(sleep_time);
  // exit
  return (0);
}
