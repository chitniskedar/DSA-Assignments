#ifndef CLIST_H
#define CLIST_H
struct node
{
	int key_;
	struct node* next_;
};
typedef struct node node_t;

struct clist
{
	node_t* head_;
};
typedef struct clist clist_t;
void init_clist(clist_t *ptr_clist);
void add(clist_t *ptr_clist, int key);
void disp(clist_t *ptr_clist);
void delete(clist_t *ptr_clist, int key);
void deinit_clist(clist_t *ptr_clist);
#endif