#include <stdio.h>
#include <string.h>
#include "stack.h"

int main(){
    stack_t stk;
    char str[MAX];
    int i, mid, palindrome=1;

    stackinit(&stk);
    printf("Enter a string: ");         // assuming middle char will be C
    scanf("%s", str);

    mid = strlen(str)/2;

    for(i=0; i<mid; i++){               // input characters before middle 'c' into stack
        stackpush(&stk, str[i]);
    }

    for(i=mid+1; str[i]!='\0'; i++){    // comparing remaining chars with popped chars
        if(str[i]!=stackpop(&stk)){
            palindrome=0;
            break;
        }
    }

    if(palindrome){
        printf("Is a palindrome\n");
    }
    else{
        printf("Not a palindrome\n");
    }

    return 0;
}