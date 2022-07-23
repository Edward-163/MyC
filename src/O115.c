#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/**
做之前,1,2,3  seq 1,3 1,2 居然是false !!
 */
bool sequenceReconstruction(int* nums, int numsSize, int** sequences, int sequencesSize, int* sequencesColSize){

}
int main() {
    // @formatter:off
    int num[]={1,2,3};
    int size=sizeof(num)/sizeof(num[0]);
    int seqsize=2;
    int* seq[seqsize];
    int colsize[]={2,2};
    int tmp[]={1,3};
    seq[0]=tmp;
    int tmp1[]={1,2};
    seq[1]=tmp1;
//    int tmp2[]={2,3};
//    seq[2]=tmp2;
    bool b = sequenceReconstruction(num,size,seq,seqsize,colsize);
    printf("%d \n", b);fflush(stdout);
    return 0;
    // @formatter:on
}

/*

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
}Hash;
Hash* g_head;
Hash* g_set;
bool sequenceReconstruction(int* nums, int numsSize, int** sequences, int sequencesSize, int* sequencesColSize){
    g_set=NULL;
    for (int r = 0; r < sequencesSize; ++r){
        for (int c = 0; c < sequencesColSize[r]; ++c){
            Hash* tmp=NULL;
//            int key=sequences[r][c];
//            HASH_FIND_INT(g_set, &key, tmp);
            HASH_FIND_INT(g_set, &sequences[r][c], tmp);
            if(tmp==NULL){
                tmp=malloc(sizeof(Hash));
                tmp->key=sequences[r][c];
                HASH_ADD_INT(g_set,key,tmp);
            }
        }
    }
    int setsize=HASH_COUNT(g_set);
    if(setsize!=numsSize){
        return false;
    }
    g_head=NULL;
    for (int i = 0; i < numsSize; ++i){
        Hash* tmp= malloc(sizeof(Hash));
        tmp->key=nums[i];
        tmp->val=i;
        HASH_ADD_INT(g_head,key,tmp);
    }
    for(int r=0; r < sequencesSize; r++){
        int idx=-1;
        for(int c=0; c < sequencesColSize[r]; c++){
            Hash* tmp=NULL;
            HASH_FIND_INT(g_head,&sequences[r][c],tmp);
            if(tmp==NULL){
                return false;
            }else{
                int newidx=tmp->val;
                if(newidx<=idx){
                    return false;
                }else{
                    idx=newidx;
                }
            }
        }
    }
    return true;
}
 */