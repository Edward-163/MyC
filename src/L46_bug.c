#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
//#include <uthash.h>


/*

 */
void swap(int* nums,int curidx,int a){
    int tmp=nums[curidx];
    nums[curidx]=nums[a];
    nums[a]=tmp;
}
void fn(int* nums,int numsSize,int* returnSize,int** returnColumnSizes,int ellen,int curidx,int* rlen,int* el,int** res){
    if(ellen==numsSize){
        int* elcpy=(int*)malloc(sizeof(int)*numsSize);
        memcpy(elcpy,el,sizeof(int)*numsSize);
        res[*rlen]=elcpy;
        /// bug,++优先级高于*
//        *rlen++;
        *rlen=*rlen+1;
        return;
    }

    for(int a=curidx;a<=numsSize-1;a++){
        swap(nums,curidx,a);


        el[ellen]=nums[curidx];
        fn(nums,numsSize,returnSize,returnColumnSizes,ellen+1,curidx+1,rlen,el,res);

        swap(nums,a,curidx);
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int ellen=0;
    int curidx=0;
    int rlen=0;
    int* el=(int*)malloc(sizeof(int)*numsSize);
    int** res=(int**)malloc(sizeof(int*)*6*5*4*3*2);

    fn(nums,numsSize,returnSize,returnColumnSizes,ellen,curidx,&rlen,el,res);
    *returnSize=rlen;
    int* arr=(int*)malloc(sizeof(int)*rlen);
    memset(arr,numsSize,sizeof(int)*rlen);
    for (int i = 0; i < rlen; ++i){
        printf("%d ",arr[i]);
        fflush(stdout);
    }
    *returnColumnSizes=arr;
    return res;
}

int main() {
    int* arr=(int*)malloc(sizeof(int)*2);
    memset(arr,1,sizeof(int)*2);
    for (int i = 0; i < 2; ++i){
        printf("%d ",arr[i]);
        fflush(stdout);
    }

    int nums[]={0,1};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int* returnSize=(int*)malloc(sizeof(int));
    int** returnColmnSizes=NULL;
    permute(nums,numsSize,returnSize,returnColmnSizes);
    return 0;
}