#include <stdio.h>
#include <stdlib.h> 
#include "clist.h"

void init_clist(clist_t *ptr_clist)
{
	ptr_clist->head_ = NULL;
}
// this function can be used only in this file 
// others cannot use it 
// function has internal linkage
static node_t* create_node(int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key_ = key;
	temp->next_ = NULL;
	return temp;
}

// add after the head
void add(clist_t *ptr_clist, int key)
{
	node_t* temp = create_node(key);
	if(ptr_clist->head_ == NULL)
	{
		ptr_clist->head_ = temp;
		temp->next_ = temp;
	}
	else 
	{
		temp->next_ = ptr_clist->head_->next_;
		ptr_clist->head_->next_ = temp;
	}
}

void disp(clist_t *ptr_clist)
{
	node_t* pres = ptr_clist->head_;
	if(pres == NULL)
	{
		printf("empty clist\n");
	}
	else
	{
		do		
		{
			printf("%d ", pres->key_);
			pres = pres->next_;
		} 	while(pres != ptr_clist->head_);
	}
	printf("\n");
}

void delete(clist_t *ptr_clist, int key)
{
    node_t *pres = ptr_clist->head_;
    node_t *prev = NULL;
    if (ptr_clist->head_ == NULL)
	{
        return;
	}

    do
    {
        if (pres->key_ == key)	// find
		{		
            break;
		}
        prev = pres;
        pres = pres->next_;
    } while(pres != ptr_clist->head_);

    if (pres->key_ != key)		// key doesnt exist
	{		
        return;
	}

    if (pres == pres->next_)	// only one node
    {
        ptr_clist->head_ = NULL;
        free(pres);
        return;
    }

    if (pres == ptr_clist->head_)	// head case
    {
        node_t *last = ptr_clist->head_;

        while (last->next_ != ptr_clist->head_)
		{
            last = last->next_;
		}

        ptr_clist->head_ = pres->next_;
        last->next_ = ptr_clist->head_;

        free(pres);
        return;
    }

    // common case
    prev->next_ = pres->next_;
    free(pres);

}

void deinit_clist(clist_t *ptr_clist)
{
    node_t *pres;
    node_t *next;

    if (ptr_clist->head_ == NULL)
        return;

    pres = ptr_clist->head_->next_;

    while (pres != ptr_clist->head_)
    {
        next = pres->next_;
        free(pres);
        pres = next;
    }

    free(ptr_clist->head_);
    ptr_clist->head_ = NULL;
}