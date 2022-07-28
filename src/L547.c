/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
ufs经典教学
 find
 union 注意它是c的关键字
 set
 */
int *g_parent; // set

int Find(int move)
{
    while (move != g_parent[move]) {
        // 没有下行,就是纯粹的"跳跃寻找",尤其是当set退化成链表时,move纯在大量重新查找的计算
        // 有些教程采用Map<son,parent>结构来压缩路径,这里采用每while一次,争取压缩一个节点,如a->b b->c压缩为a->c
        g_parent[move] = g_parent[g_parent[move]];
        move = g_parent[move];
    }
    return move;
}

void Union(int row, int col)
{
    int rowroot = Find(row);
    int colroot = Find(col);
    if (rowroot != colroot) {
        g_parent[rowroot] = colroot;
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
    /// bug:想用全局变量,结果写了个int*在头部
//    int* g_parent = (int *) malloc(sizeof(int) * isConnectedSize);
    if (isConnectedSize <= 0) {
        return 0;
    }
    // init g_parent
    g_parent = (int *) malloc(sizeof(int) * isConnectedSize);
    for (int i = 0; i < isConnectedSize; ++i) {
        g_parent[i] = i;
    }
    for (int row = 0; row < isConnectedSize; ++row) {
        for (int col = 0; col < isConnectedColSize[row]; ++col) {
            if (row >= col && row != col && isConnected[row][col] == 1) {
                Union(row, col);
            }
        }
    }
    // get ans
    int ans = 0;
    for (int i = 0; i < isConnectedSize; ++i) {
        if (i == g_parent[i]) {
            ans++;
        }
    }
    return ans;
}

int main()
{
    // formatter:off
//    int g_arr[][3] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int arr[][3] = {{1, 1, 0}, {1, 1, 0}};
//    int g_arr[][3] = {{1, 1, 1}};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *conn[size];
    int *colSize = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        conn[i] = arr[i];
        colSize[i] = 3;
    }
    int num = findCircleNum(conn, size, colSize);
    printf("%d \n", num);
    fflush(stdout);
    return 0;
    // formatter:on
}