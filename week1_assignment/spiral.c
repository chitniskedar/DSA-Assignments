#include <stdio.h>

void spiral_matrix(int rows, int cols, int arr[rows][cols]){

    int num=1;
    int top=0;
    int left=0;
    int bottom=rows-1;
    int right=cols-1;
    while (top<=bottom && left<=right){
        for(int j=left; j<=right; j++){ //left to right, ignore filled row
        arr[top][j]=num++;}
        top++;
        
        for(int i=top; i<=bottom; i++){ //top to bottom, ignore filled coloumn
        arr[i][right]=num++;}
        right--;
        
        if(top<=bottom){
        for(int j=right; j>=left; j--){ //right to left, ignore filled row
        arr[bottom][j]=num++;}
        bottom--;}
        
        if(left<=right){
        for(int i=bottom; i>=top; i--){ //bottom to top, ignore filled coloumn
        arr[i][left]=num++;}
        left++;}
    }
}

void spiral_display(int rows, int cols, int arr[rows][cols]){
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
}


