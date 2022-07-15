#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*

 */
typedef struct{
    int key;//只存小数
    UT_hash_handle hh;
}Hash;
typedef struct{
    int key;//只存大数,如3,5
    UT_hash_handle hh;
}Hash2;
Hash* g_hash;
Hash* hash2;
int cmp(const void*a ,const void*b){
    return *(int*)a-*(int*)b;
}
int findPairs(int* nums, int numsSize, int k){
    g_hash=NULL;
    hash2=NULL;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int a=0;a<numsSize;a++){
        Hash* tmp;
        /// bug
//        HASH_FIND_INT(hash,&(nums[a]-k),tmp);
        int key=(nums[a]-k);
        HASH_FIND_INT(g_hash, &key, tmp);
        if(tmp!=NULL){
            // 发现这是个大数,且这个大数不重复,就要往存大数的hash里塞;
            HASH_FIND_INT(hash2,&(nums[a]),tmp);
            if(tmp==NULL){
                tmp=(Hash*)malloc(sizeof(Hash));
                tmp->key=nums[a];
                HASH_ADD_INT(hash2,key,tmp);
            }

        }
        // 只要这数不重复,就要往存小数的hash里赛;
        HASH_FIND_INT(g_hash, &(nums[a]), tmp);
        if(tmp==NULL){

            tmp=(Hash*)malloc(sizeof(Hash));
            tmp->key=nums[a];
            HASH_ADD_INT(g_hash, key, tmp);
        }

    }
    return HASH_COUNT(hash2);
}
int main() {
    int one=1;
    int two=2;
    int key=two-one;
    printf("%p ",&key );fflush(stdout);
//    printf("%p ",&(two-one) );fflush(stdout);
    return 0;
}