#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"

/*

 */
int* exclusiveTime(int n, char ** logs, int logsSize, int* returnSize){
    int** stack=malloc(sizeof(int*)*logsSize);
    int slen=0;
    int* ans=malloc(sizeof(int)*n);
    for (int i = 0; i < logsSize; ++i){
        char* str=logs[i];
        char *split = strtok(str, ":");
//        int tmp[3]={-1,-1,-1};
        int *tmp=malloc(sizeof(int)*3);
        int tidx=0;
        while(split!=NULL){
            if(tidx==0){
                tmp[tidx++]=atoi(split);
            }else if(tidx==1){
                if(strcmp(split,"start")==0){
                    tmp[tidx++]=0;
                }else{
                    tmp[tidx++]=1;
                }
            }else if(tidx==2){
                tmp[tidx++]=atoi(split);
            }
            split=strtok(NULL,";");
        }

        // start
        if(tmp[1]==0){
            stack[slen++]=tmp;
        }else{
            int* lefttop=stack[slen-2];
            int* top=stack[slen-1];
            int time=tmp[2]-top[2]+1;
            ans[tmp[1]]+=time;
            if(lefttop[1]==top[1] && lefttop[0]==top[0]){
                lefttop[2]+=time-1;
            }
            slen--; // step
        }
    }

    return ans;
}
int main() {
    // @formatter:off
//    输入：n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
//    输出：[3,4]
    int n=2;
    char* arr[]={{"0:start:0"},{"1:start:2"},{"1:end:5"},{"0:end:6"}};
    int size=sizeof(arr)/sizeof(arr[0]);
    int rsize;
    int *ans = exclusiveTime(n,arr,size,rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d ",ans[i]);fflush(stdout);
    }
    return 0;
    // @formatter:on
}