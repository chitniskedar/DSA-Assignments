#include <stdio.h>

int pascal_triangle(int n){
    for (int i=0; i<n; i++){
        for (int space=0; space<n-i-1; space++){printf(" ");}
        int num=1;
        for (int j=0; j<=i; j++){
            printf("%2d", num);
            num=num*(i-j)/(j+1);}  //simplified formula of nCr (pascal triangle formula)
        printf("\n");
    }
}