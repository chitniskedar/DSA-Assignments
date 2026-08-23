#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main()
{
    int coeff[] = {5, 4, 3, 2, 1};
    int expo[]  = {2, 6, 0, 4, 8};
    int n = 5;

    poly_t mypoly;
    poly_t mypoly_new;
    poly_t diff_poly;

    init_poly(&mypoly);

    for(int i = 0; i < n; ++i)
    {
        insert(&mypoly, coeff[i], expo[i]);
    }

    printf("Original polynomial:\n");
    disp(&mypoly);

    copy_poly(&mypoly_new, &mypoly);

    printf("\nCopied polynomial:\n");
    disp(&mypoly_new);

    differentiate(&mypoly, &diff_poly);

    printf("\nDifferentiated polynomial:\n");
    disp(&diff_poly);

    int a = 0;
    int b = 2;

    printf("\nApproximate Definite integral from %d to %d: %d\n", a, b, definite_integral(&mypoly, b, a));
    return 0;
}