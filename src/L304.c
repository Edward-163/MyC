#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*

 */
typedef struct {
    int** psum;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* res=(NumMatrix*)malloc(sizeof(NumMatrix));
    /// bug,二维数组,不是int*row*col,牢记本质只有一维数组
    int** psum=(int**)malloc(sizeof(int*)*matrixSize);
    res->psum=psum;
    for(int r=0;r<matrixSize;r++){
        int* tmp=(int*)malloc(sizeof(int)*matrixColSize[r]);
        /// 要明白matriccolsize本质是每行len组成的数组
        for(int c=0;c<matrixColSize[r];c++){
            tmp[c]=matrix[r][c]+(c>0?tmp[c-1]:0);
        }
        psum[r]=tmp;
    }
    return res;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int** psum=obj->psum;
    int res=0;
    for(int r=row1;r<=row2;r++){
        int rowSum=psum[r][col2]-(col1==0?0:psum[r][col1-1]);
        res+=rowSum;
    }
    return res;
}

void numMatrixFree(NumMatrix* obj) {
    free(obj);
    obj=NULL;
}
int main() {

    return 0;
}