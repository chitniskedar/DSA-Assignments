#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct stack
{
    int data_[MAX];
    int top_;
} stack_t;

void stackinit(stack_t *ptr_stack);
int stackempty(stack_t *ptr_stack);
int stackfull(stack_t *ptr_stack);
int stackpop(stack_t *ptr_stack);
void stackpush(stack_t *ptr_stack, int val);

int get_ith_element(stack_t *ptr_stack, int i);
int set_ith_element(stack_t *ptr_stack, int i, int val);

#endif