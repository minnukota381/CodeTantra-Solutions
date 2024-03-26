#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void label(int arr[MAX_ROWS][MAX_COLS], int i, int j, int rowSize, int colSize){
    if(arr[i][j] == 1){
        arr[i][j] = 0;
        if(i!=0)
            label(arr, i-1, j, rowSize, colSize);
        if(i!=rowSize-1)
            label(arr, i+1, j, rowSize, colSize);
        if(j!=0)
            label(arr, i, j-1, rowSize, colSize);
        if(j!=colSize-1)
            label(arr, i, j+1, rowSize, colSize);
    }
}

int numIslands(int arr[MAX_ROWS][MAX_COLS], int rowSize, int colSize){
    int i, j;
    int newLabel = 0;
    for(i=0; i<rowSize; i++){
        for(j=0; j<colSize; j++)
            if(arr[i][j] == 1) {
                newLabel++;
                label(arr, i, j, rowSize, colSize);
            }
    }
    return newLabel;
}

int main(){
    int row, col;
    int arr[MAX_ROWS][MAX_COLS];
    scanf("%d", &row);
    scanf("%d", &col);
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            scanf("%d", &arr[i][j]);
    int result = numIslands(arr, row, col);
    printf("%d\n", result);
    return 0;
}
