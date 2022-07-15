/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给定一个interval，表示会议间隔，那么第k次会议的时间区间为[(k-1)*interval, k*interval-1]，左闭右闭，k从1开始，例如:interval=2,表示每隔2
 天开一次会议，那么第一次会议的时间区间就是：[0,1],第二次会议时间为：[2,3],依次类推...
现在有100*100的座位（从0,0开始），给定一个已经按照时间升序排列的订单数组orders例如[[0,1,1], [0,0,2], [1,1,1], [1,0,2,0,0], [3,0,2]]，
 该二维数组中每一组vector<int>的含义：第一个数字表示day日期，剩余每一对数字表示座位的下标。
例如[0,1,1]表示:day为0，(1,1)表示要预订的座位号为1,1，day=0在第1次会议中，如果对应的第1次会议的（1,1）号座位没有被预订，则该order可以成交，
 如果第1次会议的(0,0)位置被预订，则继续预订下一个位置，预订成功即可停止该订单。
注：第k次会议的每个座位只能预订一次，也就是说，相同场次的会议，每个座位只能预约成功一次。
输出：统计订单列表中可以预订成功的订单数。
例如：
input: orders=[[0,1,1], [0,0,2], [1,1,1], [1,0,2,0,0], [3,0,2]]   interval=3
output: 4
对于订单[0,1,1],day=0, 在第一次会议区间内[0,1],第1次会议（1,1）号位置预订成功，该订单成交
对于订单[0,0,2],day=0, 在第一次会议区间内[0,1],第1次会议（0,2）号位置预订成功，该订单成交
对于订单[1,0,2,0,0],day=1,在第一次会议区间内[0,1],第一次会议(0,2)号位置已经被预订，不成功，继续预订(0,0)号位置，（0,0）号位置预订成功，所以
 该订单成功。
对于订单[3,0,2]，day=3,在第二次会议区间内[3,5],第二次会议(0,2)号位置预订成功，该订单成交。
所以总共三个订单成功，输出4.
 */
typedef struct {
    int x;
    int y;
} Key;
typedef struct {
    Key key;
    int day;
    UT_hash_handle hh;
} Hash;
Hash *g_hash;

/// 这两种写法都行,解释在下面
/// int fn(int* orders[5],int* orderSize,int** orderColSize,int interval){
int Fn(int **orders, int *orderSize, int **orderColSize, int interval)
{
    g_hash = NULL;
    int ans = 0;
    for (int row = 0; row < *orderSize; ++row) {
        int col = (*orderColSize)[row];
        int day = orders[row][0];
        for (int i = 1; i < col; i += 2) {
            int x = orders[row][i];
            int y = orders[row][i + 1];
            Key newkey = {x, y};
            Hash *tmp = NULL;
            HASH_FIND(hh, g_hash, &newkey, sizeof(Key), tmp);

            if (tmp == NULL) {
                tmp = (Hash *) malloc(sizeof(Hash));
                tmp->key = newkey;
                tmp->day = day;
                HASH_ADD(hh, g_hash, key, sizeof(Key), tmp);
                ans++;
            } else if (tmp->day <= day - (interval)) {
                tmp->day = day; // update
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    /// 死了这条心吧,网友说C语言不支持列不同的二维数组,只能"绕道"往int* hyj[5]里面塞一维数组
//    int arr[][5]={{0,1,1}, {0,0,2}, {1,1,1}, {1,0,2,0,0}, {3,0,2}};
//    int orderSize=sizeof(arr)/sizeof(arr[0]);
//    int* orders[orderSize];
//    for (int i = 0; i < orderSize; ++i){
//        orders[i]=arr[i];
//        /// bug:列固定为上面的5,上面不写5又会报错
//        orderColSize[i]=sizeof(arr[i])/sizeof(arr[i][0]);
//    }
    int orderSize = 5;
    int *arr[orderSize];
    int *orderColSize = (int *) malloc(sizeof(int) * orderSize);
    /// 我在想leetcode上万一有这种列长度不同的二维数组,手写不得疯??
    int row0[] = {0, 1, 1};
    arr[0] = row0;
    orderColSize[0] = 3;

    int row1[] = {0, 0, 2};
    arr[1] = row1;
    orderColSize[1] = 3;

    int row2[] = {1, 1, 1};
    arr[2] = row2;
    orderColSize[2] = 3;

    int row3[] = {1, 0, 2, 0, 0};
    arr[3] = row3;
    orderColSize[3] = 5;

    int row4[] = {3, 0, 2};
    arr[4] = row4;
    orderColSize[4] = 3;

    int interval = 3;
    /// arr是元素type为int*的数组,是指针数组,可以把arr的type理解为int*[5] arr,指针数组作为函数参数会退化int**
    int ans = Fn(arr, &orderSize, &orderColSize, interval);
    printf("%d ", ans);
    fflush(stdout);
    return 0;
}