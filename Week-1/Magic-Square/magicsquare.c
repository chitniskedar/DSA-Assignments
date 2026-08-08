#include <stdio.h>

int is_magic(int n, int arr[n][n]){
    int target = n*(n*n+1)/2;

    for(int i=0; i<n; i++){   //rows check
        int sum = 0;
        for(int j=0; j<n; j++){
            sum+=arr[i][j];}
        if(sum!=target){
            return 0;}
    }

    for(int j=0; j<n; j++){  //coloumns check
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i][j];}
        if(sum!=target){
            return 0;}
    }

    int sum = 0;              
    for(int i=0; i<n; i++){  // check diagonal-1
        sum+=arr[i][i];}
    if(sum!=target){
        return 0;}
       
    sum = 0;
    for(int i=0; i<n; i++){   // check diagonal-2
        sum+=arr[i][n-1-i];}
    if(sum!=target){
        return 0;}
    return 1;
}

void read_matrix(int n, int arr[n][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);}
    }
}