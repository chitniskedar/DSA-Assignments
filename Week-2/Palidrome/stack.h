#ifndef STACK_H
#define STACK_H
#define MAX 100

typedef struct stack{
    char ch_[MAX];
    int top_;
} stack_t;
void stackinit(stack_t *ptr_stack);
int stackempty(stack_t *ptr_stack);
int stackfull(stack_t *ptr_stack);
void stackpush(stack_t *ptr_stack, char ch);
char stackpop(stack_t *ptr_stack);

#endif