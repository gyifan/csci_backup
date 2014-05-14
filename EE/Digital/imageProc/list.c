#include "list.h"
#include "bmp-utl.h"
#include <stdio.h>

/*
 * Initilize the list
 */

struct list_t * initList()
{
  struct list_t * list;
  list = (struct list_t *)malloc(sizeof(struct list_t));
  list->head = NULL;
  list->tail = NULL;
  
  return list;
}
/*
 * Insert a node to the list
 * Precondition: node is made, list itself is not null
 * Postcondition: node is inserted into the list
 */
void insert(struct list_t * list, struct node_t * node) {

  if (list->head == NULL) { // new list
    list->head = node;
  } else {   // list already there
    list->tail->next = node;
  }
  list->tail = node;
}

/*
 * Check if the list is empty
 * Precondition: list itself is not null
 * Postcondition: none changed
 */
int isEmpty(struct list_t list) {

  return (list.head == NULL);
}

/*
 * Make a list node with a header and a data pointers
 * Precondition: none
 * Postcondition: a list node is made and returned
 */
struct node_t * make_node(struct pixel_t * px) {

  struct node_t * anode = (struct node_t *)malloc(sizeof(struct node_t));
  anode->px = px;
  anode->next = NULL;

  return anode;
}

/*
 * Print the content of the list
 * Precondition: a list has been made
 * Postcondition: the content of the list printed
 */
void print_list( struct list_t *thislist ) {

  struct node_t *current = thislist->head;
  int i = 0;
  while (current != NULL) {
    printf("node %d ->\n", i);
    printPx(current->px);
    current = current->next;
  }
}

/*
 * Remove the head node of the list
 * Return the pointer to head node
 */
struct node_t * remove_head(struct list_t *thislist){

	struct node_t *tmp = thislist->head;
	if(tmp != NULL)
		thislist->head = tmp->next;
	return tmp;
}
