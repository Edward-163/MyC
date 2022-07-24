#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给一个锚点(posX,posY)，一个数组arr=[[x1,y1],[x2,y2],…]，在数组arr中找到能与锚点匹配的点，匹配的规则是：posX=xi，或者posY=yi，
 将所有匹配的点存放在一起，在其中找到与锚点曼哈顿距离最近的点的个数，曼哈顿距离的定义为：|xi-xj|+|yi-yj|，输出该个数。
例：输入：锚点(15,20)，
	 数组[[35,20],[30,10],[20,23],[15,30],[20,15],[25,20]];
 */
#define ABS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int Fn(int **arr, int size, int x, int y)
{
    // 05
    int distance = INT_MAX;
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        int new = ABS(x, arr[i][0]) + ABS(y, arr[i][1]);
        if (new < distance) {
            ans = 1;
            distance = new;
        } else if (new == distance) {
            ans++;
        }
    }
    return ans;
}

int main()
{
    // @formatter:off
    int ar[][2] = {{35, 20}, {30, 10}, {20, 23}, {15, 30}, {20, 15}, {25, 20}};
    int size = sizeof(ar) / sizeof(ar[0]);
    int* arr[size];
    for (int a = 0; a < size; ++a){
        arr[a] = ar[a];
    }
    int x = 15;
    int y = 20;
    int i = Fn(arr, size, x, y);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}