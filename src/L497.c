#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 难点
    先随机选一个矩形，再随机在选择的矩形内选一个点,因不同矩形面积不同4个点的矩形和400个点的矩形,被抽中的概率相同,你觉得合适吗?
    直接先计算出所有的点，然后随机返回（超时。。。）我就是这种

 */
typedef struct {
    int minx;
    int miny;
    int maxx;
    int maxy;
    int** rects;
    int rectsSize
} Solution;


Solution* solutionCreate(int** rects, int rectsSize, int* rectsColSize) {
    int minx=rects[0][0];
    int miny=rects[0][1];
    int maxx=rects[0][2];
    int maxy=rects[0][3];
    for(int a=1;a<rectsSize;a++){
        if(rects[a][0]<minx)minx=rects[a][0];
        if(rects[a][1]<miny)miny=rects[a][1];
        if(rects[a][0]>maxx)maxx=rects[a][2];
        if(rects[a][0]>maxy)maxy=rects[a][3];
    }
    Solution* sol=(Solution*)malloc(sizeof(Solution));
    sol->minx=minx;
    sol->miny=miny;
    sol->maxx=maxx;
    sol->maxy=maxy;
    sol->rects=rects;
    sol->rectsSize=rectsSize;
    return sol;
}

int* solutionPick(Solution* obj, int* retSize) {
    int** rects=obj->rects;
    do{
        /// bug,*1.0 写错位置了
        //double randxd=rand()/RAND_MAX*1.0*((obj->maxx)-(obj->minx))+obj->minx;
        double randxd=rand()*1.0/RAND_MAX*((obj->maxx)-(obj->minx))+obj->minx;
        double randyd=rand()*1.0/RAND_MAX*((obj->maxy)-(obj->miny))+obj->miny;
        int randx=(int)randxd;
        int randy=(int)randyd;
        for(int a=0;a<obj->rectsSize;a++){
            if(rects[a][0]<=randx && randx<=rects[a][2]
               && rects[a][1]<=randy && randy<=rects[a][3]){

                int* res=(int*)malloc(sizeof(int)*2);
                res[0]=randx;
                res[1]=randy;
                *retSize=2;
                return res;
            }
        }
    }while(true);
    *retSize=0;
    return NULL;
}

void solutionFree(Solution* obj) {
    free(obj->rects);
    free(obj);
}

int main() {
    int arr[][4]={{-2,-2,1,1},{2,2,4,6}};
    int rectsSize=sizeof(arr)/sizeof(arr[0]);
    int* rects[2];
    for(int a=0;a<rectsSize;a++){
        rects[a]=arr[a];
    }
    int* rectsColSize=NULL;
    Solution* obj = solutionCreate(rects, rectsSize, rectsColSize);
    /// bug sig
//    int* retSize=NULL;
    int* retSize=(int*)malloc(sizeof(int));
    int* param_1 = solutionPick(obj, retSize);
    solutionFree(obj);
    return 0;
}