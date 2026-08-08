#include <stdio.h>
#include "pascal_triangle.h"

int main(){

    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    return pascal_triangle(n);

}