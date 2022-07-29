#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
给你一支股票价格的数据流。数据流中每一条记录包含一个 时间戳 和该时间点股票对应的 价格 。 不巧的是，由于股票市场内在的波动性，
 股票价格记录可能不是按时间顺序到来的。某些情况下，有的记录可能是错的。如果两个有相同时间戳的记录出现在数据流中，
 前一条记录视为错误记录，后出现的记录 更正 前一条错误的记录。
请你设计一个算法，实现：
更新 股票在某一时间戳的股票价格，如果有之前同一时间戳的价格，这一操作将 更正 之前的错误价格。
找到当前记录里 最新股票价格 。最新股票价格 定义为时间戳最晚的股票价格。
找到当前记录里股票的 最高价格 。
找到当前记录里股票的 最低价格 。
请你实现 StockPrice 类：
StockPrice() 初始化对象，当前无股票价格记录。
void update(int timestamp, int price) 在时间点 timestamp 更新股票价格为 price 。
int current() 返回股票 最新价格 。
int maximum() 返回股票 最高价格 。
int minimum() 返回股票 最低价格 。
示例 1：
输入：
["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
[[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
输出：
[null, null, null, 5, 10, null, 5, null, 2]
解释：
StockPrice stockPrice = new StockPrice();
stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                          // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
 手搓大小堆
 */
typedef struct Queue { // 真名
    int price;
    struct Queue *pre;
    struct Queue *aft;
} Queue; // 别名
Queue *g_head;
Queue *g_tail;

void insert(int price)
{
    Queue new = {price, NULL, NULL};
    if (price <= g_head->price) {
        new.aft = g_head;
        g_head->pre = &new;
        g_head = &new;
    } else if (price >= g_tail->price) {
        new.pre = g_tail;
        g_tail->aft = &new;
        g_tail = &new;
    } else {
        Queue *move = g_head;
        while (move != g_tail) {
            // 匿名结构体下行会报错
            // if(g_head->price<price && price <= g_head->aft-> price){
            Queue *next = move->aft;
            if (move->price < price && price <= next->price) {
                move->aft = &new;
                new.pre = move;
                new.aft = next;
                next->pre = &new;
                break;
            }
        }
    }
}

void delete(int price)
{
    if (price == g_head->price) {
        g_head = g_head->aft;
    } else if (price == g_tail->price) {
        g_tail = g_tail->pre;
    } else {
        Queue *move = g_head;
        while (move != g_tail) {
            if (price == move->price) {
                move->pre->aft = move->aft;
                move->aft->pre = move->pre;
                break;
            }
        }
    }
}

typedef struct {
    int timestamp;
    int price;
    int lasttime;
    UT_hash_handle hh;
} StockPrice;
StockPrice *g_hash;

StockPrice *stockPriceCreate()
{
    g_hash = NULL;
    StockPrice *obj = malloc(sizeof(StockPrice));
    printf("null \n");
    fflush(stdout);
    return obj;
}

void stockPriceUpdate(StockPrice *obj, int timestamp, int price)
{
    StockPrice *tmp = NULL;
    HASH_FIND_INT(g_hash, &timestamp, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(StockPrice));
        tmp->timestamp = timestamp;
        tmp->price = price;
        if (g_hash == NULL) {
            obj->lasttime = timestamp; // init
            Queue q = {price, NULL, NULL};
            g_head = &q;
            g_tail = &q;
        }else{
            if (timestamp > obj->lasttime) {
                obj->lasttime = timestamp;
            }
            insert(price);
        }
        HASH_ADD_INT(g_hash, timestamp, tmp); // 双节点正常
    } else {
        delete(tmp->price);
        tmp->price = price;
        insert(price);
    }
    printf("null \n");
    fflush(stdout); // 双节点正常,走出函数就不正常了!!
}

/// 这种没有维护time max min,直接暴力排序,超时了
// 考察点:把max换小,倒数第二大是谁?把倒数第二大换小,倒数第三小是谁?
int stockPriceCurrent(StockPrice* obj){
    StockPrice * tmp=NULL;
    HASH_FIND_INT(g_hash,&(obj->lasttime),tmp);
    return tmp->price;
}
int stockPriceMaximum(StockPrice *obj)
{
    return g_tail->price;
}

int stockPriceMinimum(StockPrice *obj)
{
    return g_head->price;
}

void stockPriceFree(StockPrice *obj)
{
    free(obj);
}

int main()
{
    // @formatter:off
    // ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
    // [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
    StockPrice *obj = stockPriceCreate();
    stockPriceUpdate(obj,1,10);
    stockPriceUpdate(obj,2,5); // 结束后链表正常
    printf("%d \n",stockPriceCurrent(obj));fflush(stdout);
    printf("%d \n",stockPriceMaximum(obj));fflush(stdout); // 链表突然就不正常了??
    stockPriceUpdate(obj,1,3);
    printf("%d \n",stockPriceMaximum(obj));fflush(stdout);
    stockPriceUpdate(obj,4,2);
    printf("%d \n",stockPriceMinimum(obj));fflush(stdout); // [null, null, null, 5, 10, null, 5, null, 2]
    return 0;
    // @formatter:on
}