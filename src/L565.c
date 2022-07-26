#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <uthash.h>

/*

 */
int arrayNesting(int* nums, int numsSize){
    int moveidx=0;
    int* used=malloc(sizeof(int)*(numsSize+1));
    memset(used,0,sizeof(int)*numsSize);
    /// bug 5620 环长度为4,0->5620 0会找到5,起初我返回 0算一个字符 5开头的环长度4,所以我返回5,错了,就应该直接返回环长度,加了hash超时??
    int* hash=malloc(sizeof(int)*(numsSize+1)); // 索引idx代表子数组s由idx开头,值代表子数组s的长度
    memset(hash,-1,sizeof(int)*numsSize);
    int ans=1;
    for(int a=0;a<numsSize;a++){
        int key=nums[a];
        int sum=0;
        while(1!=used[key]){
            // 在hash中查找有没有记录过key开头的字数组s的长度
            if(hash[key]!=-1){
                sum=hash[key];
                break;
            }
            // 代表数组A的数字key已经被用过了
            used[key]=1;
            sum++;
            // 步进
            key=nums[key];
        }

        memset(used,0,sizeof(int)*numsSize);
        hash[key]=sum;
        if(sum>ans){
            ans=sum;
        }
    }
    return ans;
}
int main() {
    // @formatter:off
//    int g_arr[]={5,4,0,3,1,6,2};
    int arr[]={1,0,3,4,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i = arrayNesting(arr,size);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}