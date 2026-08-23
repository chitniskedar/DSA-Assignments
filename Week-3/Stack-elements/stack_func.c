#include <stdio.h>
#include "stack2.h"

void stackinit(stack_t *ptr_stack)
{
    ptr_stack->top_ = -1;
}

int stackempty(stack_t *ptr_stack)
{
    return ptr_stack->top_ == -1;
}

int stackfull(stack_t *ptr_stack)
{
    return ptr_stack->top_ + 1 == MAX;
}

int stackpop(stack_t *ptr_stack)
{
    if(stackempty(ptr_stack))
    {
        printf("Error - Stack is empty.\n");
        return -1;
    }

    return ptr_stack->data_[ptr_stack->top_--];
}

void stackpush(stack_t *ptr_stack, int val)
{
    if(stackfull(ptr_stack))
    {
        printf("Error - Stack is Full.\n");
    }
    else
    {
        ptr_stack->data_[++ptr_stack->top_] = val;
    }
}

int get_ith_element(stack_t *ptr_stack, int i){
    stack_t localstack;
    stackinit(&localstack);

    int result;
    for (int j=0; j<i; j++)
    {
        stackpush(&localstack, stackpop(ptr_stack));    // skips elements till i
    }
    result = stackpop(ptr_stack);       // takes i element
    stackpush(ptr_stack, result);       // puts back ith element

    while(!stackempty(&localstack))     // pushes back the other elements to original
    {                                   
    stackpush(ptr_stack, stackpop(&localstack));
    }
    return result;
}

int set_ith_element(stack_t *ptr_stack, int i, int val)
{
    stack_t localstack;
    stackinit(&localstack);

    for (int j=0; j<i; j++)
    {
        stackpush(&localstack, stackpop(ptr_stack));    // skips elements till i
    }
    int old_val = stackpop(ptr_stack);

    stackpush(ptr_stack, val);          // ith element set to val

    while(!stackempty(&localstack))     // pushes back the other elements to original
    {                                   
    stackpush(ptr_stack, stackpop(&localstack));
    }

    return old_val;
}