#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
有一种数组压缩机制，将连续的重复数字以 [数字,重复次数] 的形式记录。
例如，一维数组 [1,1,28,28,28,3] 压缩后形成二维数组 [[1,2],[28,3],[3,1]] 。
现有两个压缩后的二维数组 numsA 与 numsB，对其进行解压，解压后的两个新数组若长度不同，在较短的数组后补 0 使两个数组长度相等。
然后将两个新数组的相同索引的数字相乘，所得结果存入临时数组，最后将临时数组以同样的压缩机制进行压缩后返回。
注：解压后的数组长度可能会超大，请以高效的方式实现整个过程。
输入：
numsA = [[3,3],[4,1]]
numsB = [[2,1],[4,2],[3,2]]
输出：[[6,1],[12,3],[0,1]]
解释：
numsA 解压后得到 [3,3,3,4]，numsB 解压后得到 [2,4,4,3,3];
由于 numsA 长度小于 numsB，使用 0 将 numsA 数组补齐，得到 [3,3,3,4,0];
然后将两数组处于相同索引的数字分别相乘得到 [6,12,12,12,0];
最后将所得结果压缩，返回 [[6,1],[12,3],[0,1]]。
提示
1 <= numsA.length ,numsB.length <= 1000
1 <= numsA[i][0],numsB[i][0] <= 10^4
1 <= numsA[i][1],numsB[i][1] <= 10^6
 */
void Fn(int *anssize, int **numsA, int **numsB, int **ans, int *idxa, int *idxb)
{
    int min = fmin(numsA[*idxa][1], numsB[*idxb][1]);
    if ((*anssize) == 0 || numsA[(*idxa)][0] * numsB[(*idxb)][0] != ans[(*anssize) - 1][0]) {
        int *build = malloc(sizeof(int) * 2);
        build[0] = numsA[(*idxa)][0] * numsB[(*idxb)][0];
        build[1] = min;
        ans[(*anssize)++] = build;
    } else {
        ans[(*anssize) - 1][1] += min;
    }
    numsB[(*idxb)][1] -= min;
    numsA[(*idxa)][1] -= min;
    if (numsA[(*idxa)][1] == 0) {
        (*idxa)++;
    } // step
    if (numsB[(*idxb)][1] == 0) {
        (*idxb)++;
    }
}

int **GetCompressedData(int **numsA, int numsASize, int **numsB, int numsBSize, int *returnSize)
{
    // 06
    int idxa = 0;
    int idxb = 0;
    int anssize = 0;
    int **ans = malloc(sizeof(int *) * (numsASize + numsBSize));
    while (!(idxa >= numsASize || idxb >= numsBSize)) {
        /// 圈复杂度>10开始扣分,>20直接0,下面已经凉了,学习:抽象能力(你摸着良心看下面3段,是不是很相似嘛!!)
        Fn(&anssize, numsA, numsB, ans, &idxa, &idxb);

        // if (numsA[idxa][1] < numsB[idxb][1]) {
        //     if (anssize == 0 || numsA[idxa][0] * numsB[idxb][0] != ans[anssize - 1][0]) {
        //         int *build = malloc(sizeof(int) * 2);
        //         build[0] = numsA[idxa][0] * numsB[idxb][0];
        //         build[1] = numsA[idxa][1];
        //         ans[anssize++] = build;
        //     } else {
        //         ans[anssize - 1][1] += numsA[idxa][1];
        //     }
        //     numsB[idxb][1] -= numsA[idxa][1];
        //     idxa++; // step
        // } else if (numsA[idxa][1] > numsB[idxb][1]) {
        //     if (anssize == 0 || numsA[idxa][0] * numsB[idxb][0] != ans[anssize - 1][0]) {
        //         int *build = malloc(sizeof(int) * 2);
        //         build[0] = numsA[idxa][0] * numsB[idxb][0];
        //         build[1] = numsB[idxb][1];
        //         ans[anssize++] = build;
        //     } else {
        //         ans[anssize - 1][1] += numsB[idxb][1];
        //     }
        //     numsA[idxa][1] -= numsB[idxb][1];
        //     idxb++; // step
        // } else {
        //     if (anssize == 0 || numsA[idxa][0] * numsB[idxb][0] != ans[anssize - 1][0]) {
        //         int *build = malloc(sizeof(int) * 2);
        //         build[0] = numsA[idxa][0] * numsB[idxb][0];
        //         build[1] = numsB[idxb][1];
        //         ans[anssize++] = build;
        //     } else {
        //         ans[anssize - 1][1] += numsB[idxb][1];
        //     }
        //     idxa++;
        //     idxb++;
        // }

    }

    int left = 0;
    // if (idxa >= numsASize && idxb < numsBSize) {
    //     for (int move = idxb; move < numsBSize; move++) {
    //         left += numsB[move][1];
    //     }
    // } else if (idxa < numsASize && idxb >= numsBSize) {
    //     for (int move = idxa; move < numsASize; move++) {
    //         left += numsA[move][1];
    //     }
    // }
    int move = idxa;
    int right = numsASize;
    int **selected = numsA;
    if (idxa >= numsASize && idxb < numsBSize) {
        move = idxb;
        right = numsBSize;
        selected = numsB;
    }
    for (; move < right; move++) {
        left += selected[move][1];
    }

    if (left != 0 && (anssize == 0 || 0 != ans[anssize - 1][0])) {
        int *build = malloc(sizeof(int) * 2);
        build[0] = 0;
        build[1] = left;
        ans[anssize++] = build;
    } else if (left != 0) {
        ans[anssize - 1][1] += left;
    }
    /**
    malloc动态分配----内存是在堆区分配的，分配内存时需要在堆区分配，耗时较大，因为内存管理操作的缘故，分配的内存需要手动析构；
    int a[N] 静态分配 ----存储区是在栈里分配的，耗时相对小，因为该操作只需要移动栈指针就行，分配的内存自动析构
     */
    *returnSize = anssize; // 又出现了这种问题,函数内正常,一出函数结果就不正常了!!
    return ans;
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

