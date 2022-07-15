#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
#define abs(a) (a)>0?(a):-(a)
int minElements(int* nums, int numsSize, int limit, int goal){
    /// 看提示想都不用想,直接累加超int
    long sum=0;
    for(int a=0;a<numsSize;a++){
        sum+=nums[a];
    }
    long lgoal=goal;
    long diff=abs(sum-lgoal);

    long time=diff/limit;
    if(diff%limit!=0){
        time++;
    }
    return time;
}
int main() {

    return 0;
}