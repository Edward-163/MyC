#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    //到达x边,尝试往右,若往右出界,改为往下
    //到达y边,尝试往右,若往右出界,改为往下
    int x=0;
    int y=0;
    int col=matColSize[0];
//    int col=matColSize[0];
    int* res=(int*)malloc(sizeof(int)*matSize*matColSize[0]);
    int rlen=0;
    bool torightup=true;
    do{
        res[rlen++]=mat[x][y];
        if(x==matSize-1 && y==col-1)break;
        if(torightup && x==0){
            if(y+1<=col-1){
                y++;
            }else{
                x++;
            }
            torightup=false;
            continue;
        }
        if(torightup==false && y==0){
            if(x+1<=matSize-1){
                x++;
            }else{
                y++;
            }
            torightup=true;
            continue;
        }
        if(torightup==false && x==matSize-1){
            y++;
            torightup=true;
            continue;
        }
        if(torightup && y==col-1){
            x++;
            torightup=false;
            continue;
        }
        if(torightup){
            x--;
            y++;
        }else{
            x++;
            y--;
        }
    }while(true);
    *returnSize=rlen;
    return res;

}
int main() {
//    int g_arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr[][3]={{1,2,3},{4,5,6}};
//    int g_arr[][3]={{1,2},{4,5}};
    int matSize=sizeof(arr)/sizeof(arr[0]);
    int* mat[3];
    for (int a = 0; a < matSize; ++a) {
        mat[a]=arr[a];
    }
    int* matColSize=(int*)malloc(sizeof(int)*matSize);
    for (int i = 0; i < matSize; ++i) {
        matColSize[i] = sizeof(arr[i]) / sizeof(arr[i][0]);
    }
    int* returnSize=(int*)malloc(sizeof(int));
    int *pInt = findDiagonalOrder(mat, matSize, matColSize, returnSize);
    for (int i = 0; i < (*returnSize); ++i) {
        printf("%d ", pInt[i]);fflush(stdout);
    }
    return 0;
}