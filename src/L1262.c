#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
//#include "uthash.h"
//#include "securec.h"


/*

 */
int cmp(int* a,int* b){
    return *a-*b;
}
bool greedy(int *num2,int idx,int left,int sum){
    if(idx<0){
        return false;
    }
    int ll = num2[idx]%3;
    if(left==ll){
        return true;
    }
    bool flag=false;
    if(left<ll){
        left+=3;
        flag=true;
    }
    if(greedy(num2,idx-1,left-ll,sum+num2[idx])){
        return sum+num2[idx];
    }
    if(flag){
        left-=3;
    }
    return greedy(num2,idx-1,left,sum);
}
int maxSumDivThree(int* nums, int numsSize){
    int *nums2=malloc(sizeof(int)*numsSize);
    int n2size=0;
    int ans=0;
    for (int i = 0; i < numsSize; ++i){
        if(nums[i]%3==0){
            ans+=nums[i];
            continue;
        }
        nums2[n2size++]=nums[i];
    }

    qsort(nums2,n2size,sizeof(int),cmp);

    int g=greedy(nums2,n2size-1,3,0);
    ans+=g;
    return ans;
}
int main() {
    // @formatter:off
    int nums[]={3,6,5,1,8};
    int nSize=sizeof(nums)/sizeof(nums[0]);
    int ans=maxSumDivThree(nums,nSize);
    printf("%d \n",ans);fflush(stdout);
    return 0;
    // @formatter:on
}