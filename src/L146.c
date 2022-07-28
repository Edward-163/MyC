#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
   18/21 超时
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。 实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，
 则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出 [null, null,    null, 1,     null,  -1,   null,  -1,   3, 4]
 */
typedef struct {
    int key;
    int val;
    int cap;
    UT_hash_handle hh;
} LRUCache;
LRUCache *g_hash;

LRUCache *lRUCacheCreate(int capacity)
{
    g_hash = NULL;
    LRUCache *obj = malloc(sizeof(LRUCache));
    obj->cap = capacity;
    printf("null\n");
    fflush(stdout);
    return obj;
}

int lRUCacheGet(LRUCache *obj, int key)
{
    LRUCache *tmp = NULL;
    HASH_FIND_INT(g_hash, &key, tmp);
    if (tmp == NULL) {
        return -1;
    } else {
        /// 这个key没过期,要么物理删除重插hash尾,逻辑删除维护whenInsert不是那么容易的,错了好几次了
        HASH_DEL(g_hash, tmp);
        // LRUCache * el;
        // LRUCache * tmp2;
        // HASH_ITER(hh,g_hash,el,tmp2){
        //     printf("%d ----\n",el->key);fflush(stdout);
        // }
        /// 可以这样直接复用指针
        HASH_ADD_INT(g_hash, key, tmp);
        // LRUCache * tmp3;
        // HASH_ITER(hh,g_hash,el,tmp3){
        //     printf("%d ----\n",el->key);fflush(stdout);
        // }
        return tmp->val;
    }
}

void lRUCachePut(LRUCache *obj, int key, int value)
{
    int c = HASH_COUNT(g_hash);
    LRUCache *tmp = NULL;
    HASH_FIND_INT(g_hash, &key, tmp);
    // 满了且出现新key,则删头
    if (c == obj->cap && tmp == NULL) {
        // LRUCache *el;
        // LRUCache *tmp2;
        // HASH_ITER(hh, g_hash, el, tmp2) {
        //     printf("%d ----\n", el->key);
        //     fflush(stdout);
        // }
        HASH_DEL(g_hash, g_hash); /// 可以这么直接删除头
        // LRUCache *tmp3;
        // HASH_ITER(hh, g_hash, el, tmp3) {
        //     printf("%d ===\n", el->key);
        //     fflush(stdout);
        // }
    } else if (tmp != NULL) {
        // drop existed,insert tail
        HASH_DEL(g_hash, tmp);
    }
    // 无论如何都要插入
    tmp = malloc(sizeof(LRUCache));
    tmp->key = key;
    tmp->val = value;
    HASH_ADD_INT(g_hash, key, tmp);
    printf("null\n");
    fflush(stdout);
}

void lRUCacheFree(LRUCache *obj)
{
    free(obj);
}

int main()
{
    // @formatter:off
    LRUCache* obj = lRUCacheCreate(2);
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    printf("%d \n",lRUCacheGet(obj, 1));fflush(stdout);
    lRUCachePut(obj, 3, 3);
    printf("%d \n",lRUCacheGet(obj, 2));fflush(stdout);
    lRUCachePut(obj, 4, 4);
    printf("%d \n",lRUCacheGet(obj, 1));fflush(stdout);
    lRUCacheFree(obj);
    printf("%d \n",lRUCacheGet(obj, 3));fflush(stdout);
    printf("%d \n",lRUCacheGet(obj, 4));fflush(stdout);//[null,null,null,1,null,-1,null,-1,3,4]

    // LRUCache* obj = lRUCacheCreate(2);
    // printf("%d \n",lRUCacheGet(obj, 2));fflush(stdout);
    // lRUCachePut(obj, 2, 6);
    // printf("%d \n",lRUCacheGet(obj, 1));fflush(stdout);
    // lRUCachePut(obj, 1, 5);
    // lRUCachePut(obj, 1, 2);
    // printf("%d \n",lRUCacheGet(obj, 1));fflush(stdout);
    // printf("%d \n",lRUCacheGet(obj, 2));fflush(stdout);//[null,-1,null,-1,null,null,2,6]
    return 0;
    // @formatter:on
}
