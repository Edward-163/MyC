/*
 *
 */
#include <uthash.h>
#include <stdio.h>

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} Hashlist;

/**
 * leet评判机制bug??    https://zhuanlan.zhihu.com/p/433732178
 * 推荐做法：不使用「全局变量」或者「类内的静态变量」；
 * or在类内/函数内 对「全局变量」或者「类内的静态变量」执行初始化。
 */
// Hashlist *g_hashlist = NULL;
Hashlist * g_hashlist;

Hashlist * Find(int key)
{
    Hashlist *tmp = NULL;
    HASH_FIND_INT(g_hashlist, &key, tmp);
    return tmp;
}

void Insert(int key, int val)
{
    Hashlist *tmp = (Hashlist *) malloc(sizeof(Hashlist));
    tmp->key = key;
    tmp->val = val;
    HASH_ADD_INT(g_hashlist, key, tmp);
}

int *TwoSum(int *nums, int numsSize, int target, int *returnSize)
{
    g_hashlist = NULL;/// leet的bug
    for (int a = 0; a < numsSize; a++) {
        Hashlist *tmp = Find(target - nums[a]);
        if (tmp == NULL) {
            Insert(nums[a], a);
        } else {
            int *res = (int *) malloc(sizeof(int) * 2);
            res[0] = tmp->val;
            res[1] = a;
            *returnSize = 2;
            return res;
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[] = {1, 2, 3, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 6;
    /**
     * int* returnSize=Null;
     * bug:无论上面下面都是segmentation fault
     * int* returnSize;
     * *returnSize=0;
     **/
    int *returnSize = (int *) malloc(sizeof(int)); // right
    int *res = TwoSum(nums, numsSize, target, returnSize);
    if (res != NULL) {
        for (int a = 0; a < 2; a++) {
            printf("%d\n", res[a]);
        }
    }
    return 0;
}