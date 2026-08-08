#include <stdio.h>
#include "duplicate.h"
#include <stdlib.h>

int main(){
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int *arr=(int*)malloc(n*sizeof(int));

    printf("Enter array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);}

    n=remove_duplicate(arr,n);
    arr=(int*)realloc(arr, n*sizeof(int));

    printf("Array after removing duplicates: ");
    for(int i=0; i<n; i++)
    printf("%d ",arr[i]);
    
    return 0;
}