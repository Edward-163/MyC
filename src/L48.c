#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 题目要求原地,首先假设xy都>0,好理解些,(x,y),意味着啥?意味着相对于原点(0,0)-->(0+x,0+y),所以xy本质就是偏移量
 现在顺时针转90,无非是原点更新为(0,size-1),-->(0+y,size-1-x)

 我是把4个要交换的点迭代算出来并存入arr,加个tmp,然后换呀换
 官网一口气直接算出4个点,并以字面量的形式写死,加个tmp,换呀换,值得学习的是奇数行时,选取合适的1/4区域,眼前一亮

 还有一招几何,几何学得好,妙招少不了
  @ @ @ @     @ - > @   先左右反转,再正斜线对角线翻转
  ^ @ @ @     @ @ @ @
  | @ @ @     @ @ @ @
  @ @ @ @     @ @ @ @
 */
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int mid=(matrixSize-1)/2;//
    for(int r=0;r<matrixSize;r++){
        for(int c=0;c<=mid;c++){
            // (r,c)  (r,size-1-c)
            /// bug,写错了好恶心
//            int tmp=matrix[r][matrixSize-1-r];
            int tmp=matrix[r][matrixSize-1-c];
            matrix[r][matrixSize-1-c]=matrix[r][c];
            matrix[r][c]=tmp;
        }
    }

    for(int r=0;r<matrixSize;r++){
        for(int c=0;c<matrixSize-1-r;c++){
//            for(int a=0;a<matrixSize;a++){
//                for(int b=0;b<matrixSize;b++){
//                    printf("%d ",matrix[a][b]);
//                    fflush(stdout);
//                }
//                printf("\n");
//            }
//            printf("------------\n");

            //(r,c) (size-1-c,size-1-r)
            int tmp=matrix[r][c];
            matrix[r][c]=matrix[matrixSize-1-c][matrixSize-1-r];
            matrix[matrixSize-1-c][matrixSize-1-r]=tmp;

//            for(int a=0;a<matrixSize;a++){
//                for(int b=0;b<matrixSize;b++){
//                    printf("%d ",matrix[a][b]);
//                    fflush(stdout);
//                }
//                printf("\n");
//            }
//            printf("------------\n");
        }
    }
}

void rotate2(int** matrix, int matrixSize, int* matrixColSize){
    int used[matrixSize][matrixSize];
    for(int a=0;a<matrixSize;a++){
        for(int b=0;b<matrixSize;b++){
            used[a][b]=0;//代表未归位
        }
    }

    for(int a=0;a<matrixSize;a++){
        for(int b=0;b<matrixSize;b++){
            if(used[a][b]==0){
                int fromx=a;
                int fromy=b;
                int tox=0+fromy;
                int toy=matrixSize-1-fromx;
                /// 恶心在这,若用迭代难搞,干脆把4个坐标全算出来
                if(!(fromx==tox && fromy==toy)){
                    int arr[4][2];
                    for(int c=0;c<4;c++){
                        arr[c][0]=fromx;
                        arr[c][1]=fromy;
                        tox=0+fromy;
                        toy=matrixSize-1-fromx;
                        fromx=tox;
                        fromy=toy;
                    }

                    int tmpval=matrix[arr[3][0]][arr[3][1]];
                    for(int c=2;c>=0;c--){
                        matrix[arr[c+1][0]][arr[c+1][1]]=matrix[arr[c][0]][arr[c][1]];
                        used[arr[c+1][0]][arr[c+1][1]]=1;
                    }
                    matrix[arr[0][0]][arr[0][1]]=tmpval;
                }
            }
        }
    }
}

int main() {
    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrixSize=sizeof(arr)/sizeof(arr[0]);
    int* matrix[matrixSize];
    for(int a=0;a<matrixSize;a++){
        matrix[a]=arr[a];
    }
    int* matrixColSize=NULL;
    rotate(matrix,  matrixSize, matrixColSize);
    for(int a=0;a<matrixSize;a++){
        for (int b = 0; b < matrixSize; ++b){
            printf("%d ", matrix[a][b]);
        }
        printf("\n");
    }
    return 0;
}