#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*

 */

#define MAX_SIZE 100001
void GetIdx(int *idx, int numsSize, int **nums, int curRstCnt)
{
    if (*idx < numsSize) {
        nums[*idx][1] -= curRstCnt;
        *idx = (nums[*idx][1] > 0) ? *idx : (*idx + 1);
    }
}
int **GetCompressedData(int **numsA, int numsASize, int **numsB, int numsBSize, int *returnSize)
{
    int numsLen = fmax(numsASize, numsBSize);
    int idxA = 0;
    int idxB = 0;
    int size = 0;
    int **result = (int *)malloc(sizeof(int *) * MAX_SIZE);
    if (result == NULL) {
        return NULL;
    }
    while (idxA < numsASize || idxB < numsBSize) {
        int valA = (idxA < numsASize) ? numsA[idxA][0] : 0;
        int cntA = (idxA < numsASize) ? numsA[idxA][1] : MAX_SIZE;
        int valB = (idxB < numsBSize) ? numsB[idxB][0] : 0;
        int cntB = (idxB < numsBSize) ? numsB[idxB][1] : MAX_SIZE;
        int curRstVal = valA * valB;
        int curRstCnt = fmin(cntA, cntB);
        GetIdx(&idxA, numsASize, numsA, curRstCnt);
        GetIdx(&idxB, numsBSize, numsB, curRstCnt);
        if (size > 0 && result[size - 1][0] == curRstVal) {
            result[size - 1][1] += fmin(curRstCnt, MAX_SIZE);
        } else {
            result[size] = (int *)calloc(2, sizeof(int));
            result[size][0] = curRstVal;
            result[size][1] = curRstCnt;
            size++;
        }
    }
    *returnSize = size;
    return result;
}
int main()
{
    // @formatter:off
    // int numsA[][2] = {{3,3},{4,1}};
    // int numsB[][2] = {{2,1},{4,2},{3,2}}; // 输出：[[6,1],[12,3],[0,1]]
    // int numsA[][2] = {{2,3},{5,3},{1,4},{3,3}};
    // int numsB[][2] = {{1,2},{7,1},{3,8}}; // 输出：{{2,2},{14,1},{15,3},{3,4},{9,1},{0,2}}
    int numsA[][2] = {{2,1000000},{3,1000000}};
    int numsB[][2] = {{7,999999},{8,2},{6,999999}}; // 输出：{{14,999999},{16,1},{24,1},{18,999999}}
    int asize=sizeof(numsA)/sizeof(numsA[0]);
    int bsize=sizeof(numsB)/sizeof(numsB[0]);
    int* aa[asize];
    int* bb[bsize];
    for (int i = 0; i < asize; ++i){
        aa[i]=numsA[i];
    }
    for (int i = 0; i < bsize; ++i){
        bb[i]=numsB[i];
    }
    int rsize;
    int **ans = GetCompressedData(aa,asize,bb,bsize,&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d,%d  \n",ans[i][0],ans[i][1]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}