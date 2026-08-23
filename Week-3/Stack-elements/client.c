#include <stdio.h>
#include "stack2.h"

int main()
{
    stack_t stack;
    int i, val;
    stackinit(&stack);

    stackpush(&stack, 10);
    stackpush(&stack, 20);
    stackpush(&stack, 30);
    stackpush(&stack, 40);
    stackpush(&stack, 50);

    printf("Enter i: ");
    scanf("%d", &i);
    printf("\noriginal stack:\n");

    stack_t temp = stack;
    while(!stackempty(&temp))
    {
        printf("%d ", stackpop(&temp));
    }
    printf("\n");

    printf("\nElement at index %d: %d\n", i, get_ith_element(&stack, i));

    printf("\nEnter new value: ");
    scanf("%d", &val);
    int old_val = set_ith_element(&stack, i, val);
    printf("old value: %d\n", old_val);

    printf("\nstack after set:\n");
    temp = stack;
    while(!stackempty(&temp))
    {
        printf("%d ", stackpop(&temp));
    }

    return 0;
}