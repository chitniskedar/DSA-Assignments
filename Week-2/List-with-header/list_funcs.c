#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// some funcs and comments may be repeated as refered from list-without-header folder soln

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

    prev=ptr_list->head_;                       // prev at header
    pres=ptr_list->head_->next_;                // pres at first node

    while(pres!=NULL && pres->key_<key){        // search for node
        prev=pres;
        pres=pres->next_;
    }

    if(pres!=NULL && pres->key_==key){          
        prev->next_=pres->next_;                
        free(pres);                             
        ptr_list->length_--;                    
    }
}

int length(list_t *ptr_list){
    return ptr_list->length_;                   // returns length value
}

void init_list(list_t* ptr_list){               
    ptr_list->head_=malloc(sizeof(node_t));
    ptr_list->head_->next_=NULL;
    ptr_list->length_=0;
}

void insert(list_t* ptr_list, int key){
    node_t *newnode, *pres, *prev;

    newnode=malloc(sizeof(node_t));             // create node
    newnode->key_=key;
    newnode->next_=NULL;

    prev=ptr_list->head_;                       // prev at header
    pres=ptr_list->head_->next_;                // pres at first

    while(pres!=NULL && pres->key_<key){        // goes till pres>key
        prev=pres;
        pres=pres->next_;
    }

    newnode->next_=pres;                        
    prev->next_=newnode;                        

    ptr_list->length_++;                        // length increment
}

void display_node(node_t *ptr_node){            // display by recursion
    if(ptr_node!=NULL){
        printf("%d ",ptr_node->key_);
        display_node(ptr_node->next_);          
    }
}

void disp(list_t *ptr_list){
    display_node(ptr_list->head_->next_);       // starts from actual first node
    printf("\n");
}