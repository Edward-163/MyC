#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
并查集入门
可以采用2个数组,
 data 记录节点的值
 pare 记录父节点的值
 下面我的写法是没有按模板来漏写方法,union,所以会多次挨个挨个找父节点(其中肯定有重复计算),时间慢
 标准模板是有union过程的
 */
int findP(int* arr,int f){
    while(f>=0 && arr[f]!=-1){
        f=arr[f];
    }
    return f;
}
bool equationsPossible(char ** equations, int equationsSize){
    int arr[26];//idx代表节点的值,arr[idx]代表父节点的值
    memset(arr,-1,sizeof(int)*26);

    for(int a=0;a<equationsSize;a++){
        if(equations[a][1]=='='){
            int p1=findP(arr,equations[a][0]-'a');
            int p2=findP(arr,equations[a][3]-'a');
            //若2节点不同,让后节点指向前节点
            if(p1!=p2){
                arr[p2]=p1;
            }
        }
    }

    for(int a=0;a<equationsSize;a++){
        if(equations[a][1]=='!'){
            int p1=findP(arr,equations[a][0]-'a');
            int p2=findP(arr,equations[a][3]-'a');
            if(p1==p2){
                return false;
            }
        }
    }
    return true;
}

int main() {
    char arr[][4]={"a==b","b!=a"};
    int equationsSize = sizeof(arr) / sizeof(arr[0]);
    char* equations[equationsSize];
    for (int a = 0; a < equationsSize; ++a){
        equations[a]=arr[a];
    }
    printf("%d", equationsPossible(equations,equationsSize));
    return 0;
}

/*

#define MaxSize 26

typedef struct SetType SetType;
struct SetType{
    int Data;
    int Parent;
};

int Find(SetType S[], int X){   //查找X所在集合的顶点下标
    int i;
    for(i = 0; i < MaxSize && S[i].Data != X; i++);
    if(i >= MaxSize) return -1; //未找到元素X
    for(; S[i].Parent >= 0; i = S[i].Parent);
    return i;
}

void Union(SetType S[], int X1, int X2){    //联合X1和X2的集合
    int Root1, Root2;
    Root1 = Find(S, X1);
    Root2 = Find(S, X2);
    if(Root1 != Root2) S[Root2].Parent = Root1;
}

bool equationsPossible(char ** equations, int equationsSize){
    SetType* S = (SetType*)calloc(MaxSize, sizeof(SetType));
    for(int i = 0; i < MaxSize; i++){
        S[i].Data = i;
        S[i].Parent = -(i + 1);
    }
    for(int i = 0; i < equationsSize; i++)
        if(equations[i][1] == '=')
            Union(S, equations[i][0] - 'a', equations[i][3] - 'a');

    for(int i = 0; i < equationsSize; i++){
        if(equations[i][1] == '!'){ //出现!号就检查是否在同一个集合中
            int pos1 = Find(S, equations[i][0] - 'a');    //查找左侧元素parent的下标
            int pos2 = Find(S, equations[i][3] - 'a');    //查找右侧元素parent的下标
            if(pos1 == pos2) return false;
        }
    }
    free(S);
    return true;
}
 */


























/*

 * */