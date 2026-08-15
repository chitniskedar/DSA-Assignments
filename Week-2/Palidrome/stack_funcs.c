#include <stdio.h>
#include "stack.h"

void stackinit(stack_t *ptr_stack){
    ptr_stack->top_=-1;
}

int stackempty(stack_t *ptr_stack){
	return ptr_stack->top_==-1;
}

int stackfull(stack_t *ptr_stack){
	return ptr_stack->top_+1==MAX;
}

char stackpop(stack_t *ptr_stack){
    if(stackempty(ptr_stack)){
        printf("Error - Stack is empty.\n");
    }
    else{
        return ptr_stack->ch_[ptr_stack->top_--];
    }
}

void stackpush(stack_t *ptr_stack, char ch){
    if(stackfull(ptr_stack)){
        printf("Error - Stack is Full.\n");
    }
    else{
        ptr_stack->ch_[++ptr_stack->top_]=ch;
    }
}