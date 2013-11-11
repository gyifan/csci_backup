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
#include "circular-list.h" 
#include <stdio.h>

int circular_list_create(struct circular_list *l, int size) {
	l->buffer = calloc(size, sizeof(item));
	l->start = -1;
	l->end = -1;
	l->elems = 0;
	l->size = size;
	l->full = malloc(sizeof(sem_t));
	l->empty = malloc(sizeof(sem_t));
	l->mutex = malloc(sizeof(pthread_mutex_t));
	if(-1 == (sem_init(l->full, 0, 0))){
		perror("Unable to initialize semaphore-full");
		exit(-1);
	}
	if(-1 == (sem_init(l->empty, 0, size))){
		perror("Unable to initialize semaphore-empty");
		exit(-1);
	}
	if(pthread_mutex_init(l->mutex, NULL)){
		perror("Unable to initialize mutex");
		exit(-1);
	}
	return 0;
}

int circular_list_insert(struct circular_list *l, item i) {
	
	// waits for empty space in the list
	if(sem_wait(l->empty)){
		perror("Wait for empty semaphore failed");
		exit(-1);
	}
	
	// waits for the mutex to access the list
	if(pthread_mutex_lock(l->mutex)){
		perror("Wait for mutex failed");
		exit(-1);
	}
	
	// if the list is full, exit with -1.
	if(l->elems == l->size){
		printf("The list is full!\n");
		exit(-1);
	}

	l->elems ++;

	// if the list is empty (start == -1), make start and end to be 0.
	if(l->start == -1)
		l->start = l->end = 0;
	else if(l->end == (l->size-1))
		// if the end is at the end of the list, restart from the front.
		l->end = 0;
	else  // otherwise, increment the end index
		l->end ++;

	l->buffer[l->end] = i;
	
	// Unlock the mutex
	if(pthread_mutex_unlock(l->mutex)){
		perror("Unlock mutex failed");
		exit(-1);
	}
	
	// increment the full semaphore
	if(sem_post(l->full)){
		perror("Signal full semaphore failed");
		exit(-1);
	}
	return 0;
}

int circular_list_remove(struct circular_list *l, item *i) {

	// waits for occupied space in the list
	if(sem_wait(l->full)){
		perror("Wait for full semaphore failed");
		exit(-1);
	}
	
	// waits for the mutex to access the list
	if(pthread_mutex_lock(l->mutex)){
		perror("Wait for mutex failed");
		exit(-1);
	}
	
	//if the list is empty, exit with -1
	if(l->elems == 0){
		printf("The list is empty!\n");
		exit(-1);
	}

	//pop the first element
	*i = l->buffer[l->start];
	l->elems --;

	//if there was only one element in the list, make start and end -1.
	if(0 == l->elems)
		l->start = l->end = -1;
	else if((l->size-1) == l->start)
		//if start index is at the end of the list, move it to index 0.
		l->start = 0;
	else // otherwise, increment the start index
		l->start ++;

	// Unlock the mutex
	if(pthread_mutex_unlock(l->mutex)){
		perror("unlock mutex failed");
		exit(-1);
	}
	
	// increment the empty semaphore
	if(sem_post(l->empty)){
		perror("signal empty semaphore failed");
		exit(-1);
	}
	return 0;
}
