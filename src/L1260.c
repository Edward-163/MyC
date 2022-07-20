#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */

void Fn(int **grid, int gridSize, int *gridColSize)
{
    int col = gridColSize[0];
    int tmp = grid[gridSize - 1][col - 1];
    for (int a = gridSize - 2; a >= 0; a--) {
        grid[a + 1][col - 1] = grid[a][col - 1];

    }
    grid[0][col - 1] = tmp;

    for (int r = 0; r < gridSize; r++) {
        int tmp = grid[r][col - 1];
        for (int c = col - 2; c >= 0; c--) {
            grid[r][c + 1] = grid[r][c];
        }
        grid[r][0] = tmp;
    }
}

int **shiftGrid(int **grid, int gridSize, int *gridColSize, int k, int *returnSize, int **returnColumnSizes)
{
    /// bug
    // k %= 16;
    k %= gridSize * gridColSize[0];
    for (int i = 0; i < k; i++) {
        Fn(grid, gridSize, gridColSize);
    }
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}

int main()
{
    // @formatter:off
    int arr[][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int size=sizeof(arr)/sizeof(arr[0]);
    int* grid[size];
    int colsize[size];
    for (int i = 0; i < size; ++i){
        grid[i]=arr[i];
        colsize[i]=sizeof(arr[i])/sizeof(arr[i][0]);
    }
    int k=1;
    int rsize=0;
    int *rcolsize;
    shiftGrid(grid,size,colsize,k,&rsize,&rcolsize);
    for (int r = 0; r < rsize; ++r){
        for (int c = 0; c < rcolsize[r]; ++c){
            printf("%d ",grid[r][c]);fflush(stdout);
        }
        printf("\n");fflush(stdout);
    }
    return 0;
    // @formatter:on
}