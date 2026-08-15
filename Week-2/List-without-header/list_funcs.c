#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deinit_list(list_t* ptr_list){             // goes on deleting nodes from first till we hit NULL
    node_t *temp;

    while(ptr_list->head_!=NULL){
        temp=ptr_list->head_;                   // temp at the first node
        ptr_list->head_=ptr_list->head_->next_; // head goes to next of temp node
        free(temp);                             // deletes temp node
    }
    ptr_list->length_=0;                        // length set to 0
}

void delete(list_t* ptr_list, int key){
    node_t *pres, *prev;
    if(ptr_list->head_==NULL){                  // case - empty list
        return;
    }
    if(ptr_list->head_->key_==key){             // case - beginning of list
        pres=ptr_list->head_;
        ptr_list->head_=ptr_list->head_->next_;
        free(pres);
        ptr_list->length_--;
        return;
    }

    prev=ptr_list->head_;                       // setting up 2 pointer setup (prev and temp)
    pres=ptr_list->head_->next_;

    while(pres!=NULL && pres->key_<key){        // searching for node till we hit NULL or key
        prev=pres;
        pres=pres->next_;
    }

    if(pres!=NULL && pres->key_==key){          // found node with key
        prev->next_=pres->next_;                // links prev to the node after key
        free(pres);                             // deletes node
        ptr_list->length_--;                    // length decrement
    }
}

int length(list_t *ptr_list){
    return ptr_list->length_;                   // returns length value
}

void init_list(list_t* ptr_list){               // list init
    ptr_list->head_=NULL;
    ptr_list->length_=0;
}

void insert(list_t* ptr_list, int key){
    node_t *newnode, *pres, *prev;

    newnode=(node_t*)malloc(sizeof(node_t));
    newnode->key_=key;
    newnode->next_=NULL;

    if(ptr_list->head_==NULL || key<ptr_list->head_->key_){  // inserting before first node
        newnode->next_=ptr_list->head_;
        ptr_list->head_=newnode;
    }
    else{
        prev=ptr_list->head_;               // in middle
        pres=ptr_list->head_->next_;

        while(pres!=NULL && pres->key_<key){    // goes ahead till pres > key
            prev=pres;
            pres=pres->next_;
        }
        newnode->next_=pres;
        prev->next_=newnode;
    }
    ptr_list->length_++;
}

void display_node(node_t *ptr_node){            // display by reccursion
    if(ptr_node!=NULL){
        printf("%d ",ptr_node->key_);
        display_node(ptr_node->next_);          // callback
    }
}

void disp(list_t *ptr_list){
    display_node(ptr_list->head_);
    printf("\n");
}