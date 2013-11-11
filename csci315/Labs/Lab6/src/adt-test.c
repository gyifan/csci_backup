#include <stdlib.h>
#include <stdio.h>
#include "circular-list.h"

int printList(struct circular_list *l){

	int i;

	if(l->start == -1)
		printf("Empty list.\n");
	else {
		for(i=0; i<(l->size); i++){
			printf("%f", l->buffer[i]);
			fflush(stdout);
		}
	}

	printf("\n");
	return(0);
}

int main (int argc, char *argv[]){

	struct circular_list mylist;

	circular_list_create(&mylist, 3);

	item *i;
	item *rev;
	i = calloc((mylist.size), sizeof(item));
	rev = malloc(sizeof(int));
	i[0] = 10;
	i[1] = 20;
	i[2] = 30;

	int j;
	for(j=0; j<3; j++){
		if (circular_list_insert(&mylist, i[j]) == -1) {
			printf("Insert error\n");
		} else 
			printList(&mylist);
	}

	for(j=0; j<3; j++){
		if (circular_list_remove(&mylist, rev) == -1) {

			printf("Remove error\n");
		} else {
			printf("item removed: %lf", *rev);
			printList(&mylist);
		}
	}
	
}





