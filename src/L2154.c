//#include <uthash.h>
#include <stdbool.h>
#include "uthash.h"

typedef struct {
    int key;
    UT_hash_handle hh;
} Hash;
///bug:少个*
//Hash hash;
Hash *g_hash;

int findFinalValue(int *nums, int numsSize, int original) {
    g_hash = NULL;

    for (int a = 0; a < numsSize; a++) {
        Hash *tmp = (Hash *) malloc(sizeof(Hash) * numsSize);
        tmp->key = nums[a];
        HASH_ADD_INT(g_hash, key, tmp);// put
    }

    Hash *tmp = (Hash *) malloc(sizeof(Hash));
    do {
        ///bug:下面这玩意压根没返回值??有没有结果具体看tmp
        //tmp=HASH_FIND_INT(hash,&original,tmp);
        HASH_FIND_INT(g_hash, &original, tmp);
        if (tmp != NULL) {
            original *= 2;
        } else {
            break;
        }
    } while (true);

    return original;
}