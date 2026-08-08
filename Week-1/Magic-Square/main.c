#include <stdio.h>
#include "magicsquare.h"

int main(){

    int n;
    printf("Size of matrix: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter matrix elements:\n");
    read_matrix(n,arr);
    
    if(is_magic(n,arr)){
        printf("Magic square\n");
    }
    else{
        printf("Not a magic square\n");
    }
    return 0;
}
