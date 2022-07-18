#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
#define MAX 501
typedef struct {
    int key;
    UT_hash_handle hh;
} Hash;

int numBusesToDestination(int **routes, int routesSize, int *routesColSize, int source, int target)
{
    // 特例,特殊处理,当时没想到呀
    if (source == target) {
        return 0;
    }
    // 因为rou[i]的最大长度100000,所以routes的每一段都整个hash
    Hash **hashs = malloc(sizeof(Hash *) * routesSize);
    for (int ridx = 0; ridx < routesSize; ++ridx) {
        // 每次hash头都是新的
        Hash *hash = NULL;
        for (int colsize = 0; colsize < routesColSize[ridx]; ++colsize) {
            Hash *tmp = malloc(sizeof(Hash));
            tmp->key = routes[ridx][colsize];
            HASH_ADD_INT(hash, key, tmp);
        }
        hashs[ridx] = hash;
    }
    // 找出包含source的hashs段(可能多段),构造出第一层queue,queue[i]==ridx
    int *queue = malloc(sizeof(int) * routesSize);
    int *queue2 = malloc(sizeof(int) * routesSize);
    int qlen = 0;
    int qlen2 = 0;
    for (int ridx = 0; ridx < routesSize; ++ridx) {
        Hash *tmp2 = NULL;
        HASH_FIND_INT(hashs[ridx], &source, tmp2);
        if (tmp2 != NULL) {
            queue[qlen++] = ridx;
        }
    }
    // 因为后续while bfs搜索时需要排除搜索过的,所以需要used
    int *used = malloc(sizeof(int) * routesSize);
    memset(used, 0, sizeof(int) * routesSize);
    // 有了第一层queue,准备while bfs搜索
    int ans = 1;
    while (qlen >= 1) {
        int ridx = queue[qlen - 1];
        // 当前段直接就有target,直接返回ans
        Hash *tmp3 = NULL;
        HASH_FIND_INT(hashs[ridx], &target, tmp3);
        if (tmp3 != NULL) {
            return ans;
        }
        // 标记当前段被使用过
        used[ridx] = 1;
        for (int colsize = 0; colsize < routesColSize[ridx]; ++colsize) {
            int key = routes[ridx][colsize];
            for (int rr = 0; rr < routesSize; ++rr) {
                if (used[rr] == 0) {
                    Hash *tmp4 = NULL;
                    HASH_FIND_INT(hashs[rr], &key, tmp4);
                    if (tmp4 != NULL) {
                        used[rr] = 1;
                        queue2[qlen2++] = rr;
                    }
                }
            }
        }

        qlen--;
        if (qlen == 0) {
            memcpy(queue, queue2, sizeof(int) * qlen2);
            qlen = qlen2;
            // 清空queue2
            qlen2 = 0;
            ans++;
        }
    }

    return -1;
}

int main()
{
    // @formatter:off
//    int arr[][3]= {{7,12,0},{4,5,15},{6,0,0},{15,19,0},{9,12,13}};
   int arr[][3]= {{7,12,0},{7,12,15},{6,0,0},{15,19,0},{9,12,13}};
    // int arr[][3]= {{1,2,7},{3,6,7}};
//    int arr[][5]= {{7,12},{4,5,15},{6},{15,19},{9,12,13}};
//    int arr[][3]={{7,12},{4,5,15},{6},{15,19},{9,12,13}}; // sig
//    int* arr[]={{7,12},{4,5,15},{6},{15,19},{9,12,13}}; //
    int size=sizeof(arr)/sizeof(arr[0]); // 1 6
    int* rou[size];
    for (int i = 0; i < size; ++i){
        rou[i]=arr[i];
    }
//    int colSize[size];
   int colSize[]={2,3,1,2,3};
    // int colSize[]={3,3};
   int source=15;
   int target=13;
    // int source=1;
    // int target=6;

//    for (int i = 0; i < size; ++i){
//        colSize[i]=sizeof(arr[i])/sizeof(arr[i][0]);
//    }

//    int size=5;
//    int* arr[size]; // sig
//    int arr[size][3]; //
//    int arr0[]={7,12};
//    int arr1[]={4,5,15};
//    int arr2[]={6};
//    int arr3[]={15,19};
//    int arr4[]={9,12,13};
//    arr[0]=arr0;
//    arr[1]=arr1;
//    arr[2]=arr2;
//    arr[3]=arr3;
//    arr[4]=arr4;

//    int** arr=malloc(sizeof(int*)*5);// sig
//    int arr0[]={7,12};
//    int arr1[]={4,5,15};
//    int arr2[]={6};
//    int arr3[]={15,19};
//    int arr4[]={9,12,13};
//    int* tmp0=malloc(sizeof(int)*2);
//    int* tmp1=malloc(sizeof(int)*3);
//    int* tmp2=malloc(sizeof(int)*1);
//    int* tmp3=malloc(sizeof(int)*2);
//    int* tmp4=malloc(sizeof(int)*3);
//    tmp0=arr0;
//    tmp1=arr1;
//    tmp2=arr2;
//    tmp3=arr3;
//    tmp4=arr4;
    int ans = numBusesToDestination(rou,size,colSize,source,target);
    printf("%d \n",ans);fflush(stdout);
    return 0;
    // @formatter:on
}