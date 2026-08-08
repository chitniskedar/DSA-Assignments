#include <stdio.h>
#include "spiral.h"

int main(){

    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    spiral_matrix(rows, cols, matrix);
    spiral_display(rows, cols, matrix);

    return 0;
}