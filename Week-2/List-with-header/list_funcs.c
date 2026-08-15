#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deinit_list(list_t* ptr_list){             // deleting nodes till we hit NULL
    node_t *temp;

    while(ptr_list->head_->next_!=NULL){
        temp=ptr_list->head_->next_;            // temp at first node
        ptr_list->head_->next_=temp->next_;     // header points to second node
        free(temp);                             // deletes temp node
    }

    free(ptr_list->head_);                      // delete header in end
    ptr_list->head_=NULL;
    ptr_list->length_=0;                        // length = 0
}

void delete(list_t* ptr_list, int key){
    node_t *pres, *prev;

    prev=ptr_list->head_;                       // prev starts at header
    pres=ptr_list->head_->next_;                // pres starts at first actual node

    while(pres!=NULL && pres->key_<key){        // searching for node till NULL or key
        prev=pres;
        pres=pres->next_;
    }

    if(pres!=NULL && pres->key_==key){          // found node with key
        prev->next_=pres->next_;                // links prev to node after key
        free(pres);                             // deletes node
        ptr_list->length_--;                    // length decrement
    }
}

int length(list_t *ptr_list){
    return ptr_list->length_;                   // returns length value
}

void init_list(list_t* ptr_list){               // list init
    ptr_list->head_=malloc(sizeof(node_t));
    ptr_list->head_->next_=NULL;
    ptr_list->length_=0;
}

void insert(list_t* ptr_list, int key){
    node_t *newnode, *pres, *prev;

    newnode=malloc(sizeof(node_t));
    newnode->key_=key;
    newnode->next_=NULL;

    prev=ptr_list->head_;                       // prev starts at header
    pres=ptr_list->head_->next_;                // pres starts at first actual node

    while(pres!=NULL && pres->key_<key){        // goes ahead till pres >= key
        prev=pres;
        pres=pres->next_;
    }

    newnode->next_=pres;                        // new node points to pres
    prev->next_=newnode;                        // prev points to new node

    ptr_list->length_++;                        // length increment
}

void display_node(node_t *ptr_node){            // display by recursion
    if(ptr_node!=NULL){
        printf("%d ",ptr_node->key_);
        display_node(ptr_node->next_);          // recursive call
    }
}

void disp(list_t *ptr_list){
    display_node(ptr_list->head_->next_);       // start after header
    printf("\n");
}