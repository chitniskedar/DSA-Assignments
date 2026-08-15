#ifndef LIST_H
#define LIST_H

typedef struct node {
	int key_;
	struct node *next_;
} node_t;

typedef struct list {
	node_t* head_;
    int length_;
} list_t;

void init_list(list_t* ptr_list);
void deinit_list(list_t* ptr_list);
void insert(list_t* ptr_list, int key);
void delete(list_t* ptr_list, int key);
void disp(list_t* ptr_list);
int length(list_t* ptr_list);

#endif