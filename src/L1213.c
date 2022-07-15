#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 L1213
给出三个均为 严格递增排列 的整数数组 arr1，arr2 和 arr3。
返回一个由 仅 在这三个数组中 同时出现 的整数所构成的有序数组。
示例：
输入: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
输出: [1,5]
解释: 只有 1 和 5 同时在这三个数组中出现.
提示：

1 <= arr1.length, arr2.length, arr3.length <= 1000
1 <= arr1[i], arr2[i], arr3[i] <= 2000
 */
typedef struct {
    int key;
    int cnt;
    UT_hash_handle hh;
} Hash;
Hash *g_hash;

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 4, 5, 7, 9};
    int arr3[] = {1, 3, 4, 5, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    g_hash = NULL;
    for (int a = 0; a < len1; ++a) {
        Hash *tmp = NULL;
        HASH_FIND_INT(g_hash, &arr1[a], tmp);
        if (tmp == NULL) {
            tmp = (Hash *) malloc(sizeof(Hash));
            tmp->key = arr1[a];
            tmp->cnt = 1;
            HASH_ADD_INT(g_hash, key, tmp);
        } else {
            tmp->cnt++;
        }
    }
    for (int a = 0; a < len2; ++a) {
        Hash *tmp = NULL;
        HASH_FIND_INT(g_hash, &arr2[a], tmp);
        if (tmp == NULL) {
            tmp = (Hash *) malloc(sizeof(Hash));
            tmp->key = arr2[a];
            tmp->cnt = 1;
            HASH_ADD_INT(g_hash, key, tmp);
        } else {
            tmp->cnt++;
        }
    }
    for (int a = 0; a < len3; ++a) {
        Hash *tmp = NULL;
        HASH_FIND_INT(g_hash, &arr3[a], tmp);
        if (tmp == NULL) {
            tmp = (Hash *) malloc(sizeof(Hash));
            tmp->key = arr3[a];
            tmp->cnt = 1;
            HASH_ADD_INT(g_hash, key, tmp);
        } else {
            tmp->cnt++;
        }
    }

    Hash *el = NULL;
    Hash *tmp2 = NULL;
    int *res = (int *) malloc(sizeof(int) * 1000);
    int rlen = 0;
    HASH_ITER(hh, g_hash, el, tmp2) {
        if (el->cnt == 3) {
            res[rlen] = el->key;
            rlen++;
        }
    }
    for (int a = 0; a < rlen; a++) {
        printf("%d ", res[a]);
    }
    return 0;
}