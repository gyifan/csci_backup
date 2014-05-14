#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
  struct pixel_t * px;
  struct node_t * next;
};

struct list_t {
  struct node_t * head;
  struct node_t * tail;
};

struct list_t * initList();
void insert(struct list_t * list, struct node_t * node);
int isEmpty(struct list_t list);
struct node_t * make_node(struct pixel_t * px);
void print_list(struct list_t * list);
struct node_t * remove_head(struct list_t * list);

