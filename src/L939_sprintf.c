#include "uthash.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define HEIGHT(a,b) (a)-(b)>0?(a)-(b):(b)-(a)
typedef struct{
    char* key;
    UT_hash_handle hh;
}Hash;

Hash* g_hash;

bool find(int** points,int a,int b,int hei){
    Hash* tmp=NULL;

    char str[9]={0};
    /// 把...按格式输入到str中,返回写入的字符总数，不包括字符串追加在字符串末尾的空字符。如果失败，则返回一个负数
    sprintf(str,"%d@%d",points[a][0]+hei,points[a][1]);
    HASH_FIND_STR(g_hash, str, tmp);//find传 地址
    if(tmp==NULL)return false;

    char str2[9]={0};
    sprintf(str2,"%d@%d",points[b][0]+hei,points[b][1]);
    HASH_FIND_STR(g_hash, str2, tmp);//find传 地址
    if(tmp==NULL)return false;
    return true;
}

int minAreaRect(int** points, int pointsSize, int* pointsColSize){
    g_hash=NULL;

    for(int a=0;a<pointsSize;a++){
        char str[9]={0};
        sprintf(str,"%d@%d",points[a][0],points[a][1]);
        Hash* tmp=(Hash*)malloc(sizeof(Hash));
        tmp->key=str;
        HASH_ADD_STR(g_hash, key, tmp);//add时传key的名字
    }

    int min=-1;
    for(int a=0;a<pointsSize-1;a++){
        for(int b=a+1;b<pointsSize;b++){
            //先找出同列的
            if(b!=a && points[a][0]==points[b][0]){
                printf("%d@%d %d@%d\n", points[a][0], points[a][1], points[b][0], points[b][1]);
                //stdout有缓存,还得刷新
                fflush(stdout);

                int hei = HEIGHT(points[a][1], points[b][1]);

                if(find(points,a,b,hei)==true){
                    if(min==-1)min=hei*hei;
                    else if(hei*hei<min)min=hei*hei;
                }
            }
        }
    }

    return min==-1?0:min;
}

int main(){
    int arr[][2]={{1,1},{1,3},{3,1},{3,3},{2,2}};
    int intervalsSize = sizeof(arr) / sizeof(arr[0]);
    int* intervals[intervalsSize];
    for(int a=0;a<intervalsSize;a++){
        intervals[a]=arr[a];
    }
    printf("%d",minAreaRect(intervals,intervalsSize,NULL));
    return 0;
}

