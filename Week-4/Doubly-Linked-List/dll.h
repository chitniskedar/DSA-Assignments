#ifndef DLL_H
#define DLL_H 
struct node 
{
	int key_;
	struct node* prev_;
	struct node* next_;
};
typedef struct node node_t;
struct dll 
{
	node_t* head_;
	node_t* tail_;
};
typedef struct dll dll_t;
void init(dll_t *ptr_dll);
void add_in_begin(dll_t *ptr_dll, int key);
void add_at_end(dll_t *ptr_dll, int key);
void remove_in_begin(dll_t *ptr_dll);
void remove_at_end(dll_t *ptr_dll);
void disp_forward(dll_t *ptr_dll);
void disp_backward(dll_t *ptr_dll);

void add_before_key(dll_t *ptr_dll, int key, int new_key);
void add_after_key(dll_t *ptr_dll, int key, int new_key);
void remove_where_key(dll_t *ptr_dll, int key);
#endif 
