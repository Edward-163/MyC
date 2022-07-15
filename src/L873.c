#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*

 */
typedef struct {
    int key;
    UT_hash_handle hh;
} Hash;
Hash *hash;

int lenLongestFibSubseq(int *arr, int arrSize) {
    hash = NULL;
    for (int i = 0; i < arrSize; ++i) {
        Hash *add = malloc(sizeof(Hash));
        add->key = arr[i];
        HASH_ADD_INT(hash, key, add);
    }

    int max = 0;
    /// bug ans作用域写大了;
    //    int ans = 0;
    for (int a = 0; a <= arrSize - 3; a++) {
        for (int b = a + 1; b <= arrSize - 2; b++) {
            int ans = 0;
            /// i i1 i2 已知i i1,暴力查找i2,找到了,"先拼个更大的i2",接着找新i2
            int i1 = arr[b];
            int i2 = arr[a] + i1;
            Hash *out = NULL;
            HASH_FIND_INT(hash, &i2, out);
            while (out != NULL) {
                ans = ans == 0 ? 2 : ans;
                ans++;

                int tmp = i2 + i1; // next to find
                i1 = i2; // 旧的i2>>新的i1
                i2 = tmp;
                HASH_FIND_INT(hash, &i2, out);
            }
            if (ans > max) {
                max = ans;
            }
        }
    }

    return max;
}

int main() {
    // @formatter:off
//    int arr[]={1,2,3,4,5,6,7,8}; // 5
    int arr[]={1,3,7,11,12,14,18}; // 3
    int size=sizeof(arr)/sizeof(arr[0]);
    int i = lenLongestFibSubseq(arr,size);
    printf("%d \n",i);fflush(stdout);
    return 0;
    // @formatter:on
}