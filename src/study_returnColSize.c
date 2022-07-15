#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
void fn(int* returnSize,int** returnColSize){
    *returnSize=2;//代表ans有2行
    (*returnColSize)=(int*)malloc(sizeof(int)*(*returnSize));
    (*returnColSize)[0]=2;
    (*returnColSize)[1]=3;
}
int main() {
    int returnSize=0;
    /// 不知道ans有几行,所以不能以固定长度数组返回
//    int returnColSize[];
    int* returnColSize;
    fn(&returnSize,&returnColSize);
    for (int i = 0; i < returnSize; ++i){
        printf("%d ", returnColSize[i]);fflush(stdout);
    }
    return 0;
}