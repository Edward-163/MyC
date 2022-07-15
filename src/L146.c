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
   18/21 超时
 */
typedef struct {
    int key;
    int val;
    int score;
    UT_hash_handle hh;
}Hash;

typedef struct {
    Hash* hash;
    int capacity;
    int score;
} LRUCache;

int Cmp(const void* a, const void* b)
{
    /// bug:入门时hash就塞int,所以直接按int排序没毛病,但这里是按结构体中score排序,
//    return *(int*)a-*(int*)b;
    // 有些不智能
    return ((Hash*)a)->score - ((Hash*)b)->score;
}
LRUCache* LRuCacheCreate(int capacity)
{
    LRUCache *lru = (LRUCache *) malloc(sizeof(LRUCache));
    lru->capacity = capacity;
    lru->hash=NULL;
    lru->score = 0;
    return lru;
}

int LRuCacheGet(LRUCache* obj, int key)
{
    Hash* tmp = NULL;
    HASH_FIND_INT(obj->hash, &key, tmp);
    if (tmp==NULL) {
        return -1;
    } else {
        tmp->score = obj->score;
        obj->score++;
        HASH_SORT(obj->hash, Cmp);
        Hash* el;
        Hash* tmp2;
        HASH_ITER(hh, obj->hash, el, tmp2){
            printf("%d %d\n",el->key,el->score);
            fflush(stdout);
        }
        return tmp->val;
    }
}

void LRuCachePut(LRUCache* obj, int key, int value)
{
    Hash* tmp = NULL;
    HASH_FIND_INT(obj->hash, &key, tmp);
    if (tmp!=NULL) {
        tmp->val = value;
        tmp->score = obj->score;
        obj->score++;
        HASH_SORT(obj->hash, Cmp);
    } else {
        Hash *newtmp = (Hash *) malloc(sizeof(Hash));
        newtmp->key = key;
        newtmp->val = value;
        newtmp->score = obj->score;
        obj->score++;
        HASH_ADD_INT(obj->hash, key, newtmp);
        HASH_SORT(obj->hash, Cmp);
        if (HASH_COUNT(obj->hash) > obj->capacity) {
//            Hash* deltmp;
//            HASH_FIND_INT(obj->hash,&key,deltmp);
            /// hash的头节点咋求??
            Hash* tmp3;
            Hash* el;
            Hash* tmp4;
            HASH_ITER(hh, obj->hash, el, tmp3){
                int headkey = el->key;
                HASH_FIND_INT(obj->hash, &headkey, tmp4);
                fflush(stdout);
                break;
            }
            HASH_DEL(obj->hash, tmp4);
        }
    }
}

void LRuCacheFree(LRUCache* obj)
{
    free(obj);
}
int main()
{
    int capacity = 2;
    LRUCache* obj = LRuCacheCreate(capacity);
    LRuCachePut(obj, 1, 1);
    LRuCachePut(obj, 2, 2);
    printf("%d \n",LRuCacheGet(obj, 1));
    fflush(stdout);
    LRuCachePut(obj, 3, 3);
    printf("%d \n",LRuCacheGet(obj, 2));
    fflush(stdout);
    LRuCachePut(obj, 4, 4);
    printf("%d \n",LRuCacheGet(obj, 1));
    fflush(stdout);

    LRuCacheFree(obj);
    return 0;
}