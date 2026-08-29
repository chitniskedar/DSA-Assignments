#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void init(dll_t *ptr_dll)
{
	ptr_dll->head_ = ptr_dll->tail_ = NULL;
}

node_t* create_node(int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if(temp == NULL)
	{
		perror("malloc failed : ");
	}
	else 
	{
		temp->key_ = key;
		
	}
	return temp;
}
// boundary conditions :
// 1. empty 
// 2. not empty - has some nodes

void add_in_begin(dll_t *ptr_dll, int key)
{
	node_t* temp = create_node(key);
	temp->prev_ = NULL;
	temp->next_ = ptr_dll->head_;
	if(ptr_dll->head_ == NULL)
	{
		ptr_dll->tail_ = temp;
	}
	else 
	{
		ptr_dll->head_->prev_ = temp;
	}
	ptr_dll->head_ = temp;
	
}

void add_at_end(dll_t *ptr_dll, int key)
{
	node_t* temp = create_node(key);
	temp->next_ = NULL;
	temp->prev_ = ptr_dll->tail_;
	if(ptr_dll->head_ == NULL)
	{
		ptr_dll->head_ = temp;
	}
	else 
	{
		ptr_dll->tail_->next_ = temp;
	}
	ptr_dll->tail_ = temp;
}


// 1. empty 
// 2. non empty, single element list
// 2. non empty, mutliple element list
void remove_in_begin(dll_t *ptr_dll)
{
	node_t* temp = ptr_dll->head_;
	if(ptr_dll->head_ == NULL)
	{
		printf("empty list; cannot delete\n");
		return ;
	}
	else if(ptr_dll->head_ == ptr_dll->tail_)
	{
		ptr_dll->tail_ = NULL;
	}
	else 
	{
		ptr_dll->head_->next_->prev_ = NULL;
	}
	ptr_dll->head_ = ptr_dll->head_->next_;
	
	free(temp);
}

void remove_at_end(dll_t *ptr_dll)
{
	node_t* temp = ptr_dll->tail_;
	if(ptr_dll->tail_ == NULL)
	{
		printf("empty list; cannot delete\n");
		return ;
	}
	else if(ptr_dll->head_ == ptr_dll->tail_)
	{
		ptr_dll->head_ = NULL;
	}
	else 
	{
		ptr_dll->tail_->prev_->next_ = NULL;
	}
	ptr_dll->tail_ = ptr_dll->tail_->prev_;
	
	free(temp);
}


void disp_forward(dll_t *ptr_dll)
{
	printf("forward : ");
	node_t* temp = ptr_dll->head_;
//	while(temp != NULL)
	while(temp)
	{
		printf("%d ", temp->key_);
		temp = temp->next_;
	}		
	printf("\n");
}

void disp_backward(dll_t *ptr_dll)
{
	printf("backward : ");
	node_t* temp = ptr_dll->tail_;
	while(temp)
	{
		printf("%d ", temp->key_);
		temp = temp->prev_;
	}		
	printf("\n");
}

// assignment begins here

void add_before_key(dll_t *ptr_dll, int key, int new_key)
{
    node_t* pres = ptr_dll->head_;
    node_t* prev = ptr_dll->head_;

    while (pres!=NULL && pres->key_!=key)      // traversing
    {
        prev = pres;
        pres = pres->next_;
    }

    if(pres==NULL)                           // 1. key doesnt exist
    {
        printf("given key does not exist");
    }

     if (pres==ptr_dll->head_)              // 2. key at head
    {
        add_in_begin(ptr_dll, new_key);
        return;
    }

    // common case
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    new_node->key_ = new_key;

    new_node->prev_ = prev;
    new_node->next_ = pres;
    prev->next_ = new_node;
    pres->prev_ = new_node;  
}

void add_after_key(dll_t *ptr_dll, int key, int new_key)
{
    node_t* pres = ptr_dll->head_;

    while (pres!=NULL && pres->key_!=key)
    {
        pres=pres->next_;
    }

     if(pres==NULL)                           // 1. key doesnt exist
    {
        printf("given key does not exist");
    }

     if (pres==ptr_dll->head_)              // 2. key at head
    {
        add_in_begin(ptr_dll, new_key);
        return;
    }
    // common case
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    new_node->key_ = new_key;

    new_node->prev_ = pres;
    new_node->next_ = pres->next_;
    pres->next_->prev_ = new_node;
    pres->next_ = new_node; 
}

void remove_where_key(dll_t *ptr_dll, int key)
{
    node_t* pres = ptr_dll->head_;

    while (pres != NULL && pres->key_ != key)
    {
        pres = pres->next_;
    }

    if (pres==NULL)
    {
        printf("given key does not exist");
    }
    // key at head
    if (pres == ptr_dll->head_)
    {
        remove_in_begin(ptr_dll);
        return;
    }
    // key at tail
    if (pres == ptr_dll->tail_)
    {
        remove_at_end(ptr_dll);
        return;
    }
    // common case
    pres->prev_->next_ = pres->next_;
    pres->next_->prev_ = pres->prev_;
    free(pres);
}   