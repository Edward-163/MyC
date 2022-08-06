#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
第2题
求给出数组中距离原点（0，0）的最短的 num 个坐标点所在数组中的下标，距离计算为：sqrt(x^2 + y^2)
输入：positions = [[1,3],[-2,2]], num = 1
输出：[1]
解释：
(1, 3) 和原点之间的距离为 sqrt(10)，10 = 1^2 + 3^2
(-2, 2) 和原点之间的距离为 sqrt(8)，8 = (-2)^2 + 2^2
(-2, 2) 比 (1, 3) 站点离原点的距离更近（8 < 10）。
(-2, 2) 在positions中的下标为 1，因此输出 [1]。
输入：positions = [[3,3],[5,-1],[-2,4]], num = 2
输出：[0,2]
解释：
(3, 3), (-2, 4) 离原点较 (5, -1) 更近，下标分别为 0 和 2，按升序输出 [0,2]
 */
int cmp(const void* a,const void* b){
    int* aa=*(int**)a;
    int* bb=*(int**)b;
    return aa[1]-bb[1];
    /// 最开始我还在想转int**后,我不知道下标咋办?? 后来我好像发现规律模板了,*(传进来指针的类型)a=="数组的元素的内容"
    return (*(int**)a)[1]-(*(int**)b)[1];
}

int* fn(int** arr,int arrSize,int num){
    int* res=(int*)malloc(sizeof(int)*num);
    int** newarr=(int**)malloc(sizeof(int*)*arrSize);
    for (int i = 0; i < arrSize; ++i){
        newarr[i]=(int*)malloc(sizeof(int)*2);
        newarr[i][0]=i;
        newarr[i][1]=arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1];
    }
    qsort(newarr,arrSize,sizeof(int*),cmp);
    for (int i = 0; i < arrSize; ++i){
        printf("%d ", newarr[i][0]);fflush(stdout);
        printf("%d ", newarr[i][1]);fflush(stdout);
        printf("\n");fflush(stdout);
    }
    for (int i = 0; i < num; ++i){
        res[i]=newarr[i][0];
    }
    return res;
}
int main() {
    // @formatter:off
    int arr[][2]={{3,3},{-2,4},{5,-1}};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    int* parr[arrSize];
    for (int i = 0; i < arrSize; ++i){
        parr[i]=arr[i];
    }
    int num=3;
    int *pInt = fn(parr, arrSize, num);
    for (int i = 0; i < num; ++i){
        printf("%d ", pInt[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}
