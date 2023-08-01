#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "uthash.h"
//#include "securec.h"

/**
 -fsanitize=address -g
 */
int g_max;
int find(int* parent,int a){
    int inita=a;
    while(parent[a]!=a){
        a=parent[a];
    }
    // 压缩路径
    parent[inita]=a;
    return a;
}
void unionn(int* parent,int* lsland,int a,int b){
    int root=find(parent,a);
    int root2=find(parent,b);
    if (root != root2) {
        /// bug 当root不同的时候就得union,我少写了个else
        /// bug 我把下面f12写成了ab
        if (lsland[root] >= lsland[root2]) {
            parent[root2]=root;
            lsland[root]+=lsland[root2];
            g_max= lsland[root] > g_max ? lsland[root] : g_max;
        }else{
            parent[root]=root2;
            lsland[root2]+=lsland[root];
            g_max= lsland[root2] > g_max ? lsland[root2] : g_max;
        }
    }
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    g_max=0;
    int row=gridSize;
    int col=gridColSize[0];
    int parent[row*col]; // 把二维坐标转成一维坐标
    int island[row * col]; // 坐标为idx的岛经过"某种方式"合并后的面积
    for (int i = 0; i < row * col; ++i) {
        parent[i]=i;
        island[i]=1;
    }
    for (int r = 0; r < row; ++r){
        for (int c = 0; c < col; ++c) {
            if (grid[r][c] == 1 && r * col + c + 1 < row * col && grid[r][c+1]==1) {
                unionn(parent,island, r * col + c, r * col + c + 1);
            }
            if (grid[r][c] == 1 && r * col + c + col < row * col && grid[r+1][c]==1) {
                unionn(parent, island, r * col + c, r * col + c + col);
            }
        }
    }
    return g_max;
}
int main()
{
    // @formatter:off
    // int arr[][8]={{0,0,0,0,0,0,0,0}};
    // int arr[][8]={{0,0,0,0,1,1,0,0}};
    // int arr[][3]={{0,0,1},{1,1,1},{1,0,0}};
    int arr[][3]={{0,0,0},{0,1,1},{0,1,1}};
    // int arr[][13]={{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int asize=sizeof(arr)/sizeof(arr[0]);
    int acolsize=sizeof(arr[0])/sizeof(arr[0][0]);
    int* grid[asize];
    for (int i = 0; i < asize; ++i){
        /// 我自己,compilerEx测不出来
//        grid[i]=arr[i];
        /// 大神,可以侧出来
        grid[i]=(int*)malloc(sizeof(arr[i]));
        memcpy(grid[i], arr[i], sizeof(arr[i]));
    }
    int gcolsize[]={acolsize};
    int ans = maxAreaOfIsland(grid,asize,gcolsize);
    printf("%d \n",ans);fflush(stdout);
    return 0;
    // @formatter:on
}
