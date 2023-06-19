#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*

 */
typedef struct {
//    int num;
    int inCnt;
    int outNum;
    int finish;
}Ele;
int cmp(Ele*a,Ele* b){
    if(a->finish==b->finish){
        if(a->inCnt==b->inCnt){
            return b->outNum-a->outNum;
        }
        return a->inCnt-b->inCnt;
    }
    return a->finish-b->finish;
}
int minNumberOfSemesters(int n, int** relations, int relationsSize, int* relationsColSize, int k){
    Ele* eles=malloc(sizeof(Ele)*n);
    memset(eles,0,sizeof(Ele)*n);
    for (int i = 0; i < relationsSize; ++i){
        // [2,1] in[1]++ 节点0的入度+1
        eles[relations[i][1]-1].inCnt++;
        // out[2]=1 节点1的出度节点是0
        eles[relations[i][0]-1].outNum=relations[i][1]-1;
    }


    qsort(eles,n,sizeof(Ele),cmp);
    int round=0;
    int a=1;
    for(;a<=n;a++){
        for (int i = 0; i < k; ++i){
            if(eles[i].finish==1){
                break;
            }
            eles[i].finish = 1;
            eles[eles[i].outNum].inCnt--;
        }

    }
    return a;
}
int main() {
    // @formatter:off
    int n=4;
    int relations[]={{2,1},{3,1},{1,4}};
    int rSize=sizeof(relations)/sizeof(relations[0]);
    int rcolSize=3;
    int* rr[rSize];
    for (int i = 0; i < rSize; ++i){
        rr[i]=relations[i];
    }
    int ret=0;
    int k=2;
    printf("%d \n",minNumberOfSemesters(n,rr,rSize,&rcolSize,k));fflush(stdout);
    return 0;
    // @formatter:on
}