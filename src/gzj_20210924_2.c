#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
有一个0和1组成的矩形grid，0代表绿化场地，1代表厂房，求厂房能连成的最大周长？
例子：如图，给定rowLen长度为3，colLen长度为4的矩形grid=
[[1, 0, 0, 1, 0],
 [1, 1, 1, 1, 1],
 [0, 1, 1, 1, 1]]，
 其中grid[0][0]周长为3(左右上3边)，grid[2][0]周长为2(左下2边)，这个矩形最大周长为18
 矩形不会有封闭独立的绿化场地，即如下图所示的情况不存在
 */
/*
 * 输入**grid是长度为gridSize的数组指针的数组，其中每个元素（也是一个数组）
 * 的长度组成 *gridColSize数组作为另一输入，*gridColSize数组的长度也为gridSize
 */
int GetSideLengthSum(int **grid, int gridSize, int *gridColSize)
{
    int row = gridSize;
    int col = *gridColSize;
    int lengthSum = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] != 1) {
                continue;
            }
            lengthSum += 4;
            if (i > 0 && grid[i - 1][j] == 1) {
                lengthSum--;
            }
            if (i < row - 1 && grid[i + 1][j] == 1) {
                lengthSum--;
            }
            if (j > 0 && grid[i][j - 1] == 1) {
                lengthSum--;
            }
            if (j < col - 1 && grid[i][j + 1] == 1) {
                lengthSum--;
            }
        }
    }

    return lengthSum;
}
int main() {
    int arr[][3]={{1,1,1},{1,0,1},{1,1,1}};
    int* grid[3];
    int gridSize=sizeof(arr)/sizeof(arr[0]);
    for (int a = 0; a < gridSize; ++a) {
        grid[a]=arr[a];
    }
    int* gridColSize=(int*)malloc(sizeof(int));
    int i = GetSideLengthSum(grid, gridSize, gridColSize);
    printf("%d ",i );fflush(stdout);
    return 0;
}