#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*

 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *constructMaximumBinaryTree2(int *nums, int numsSize, int lidx, int ridx) {
    if (ridx < lidx) {
        return NULL;
    }
    struct TreeNode *newt = malloc(sizeof(struct TreeNode));
    if (ridx == lidx) {
        newt->val = nums[lidx];
        newt->left = NULL;
        newt->right = NULL;
        return newt;
    }
    int maxidx = lidx;
    for (int a = lidx + 1; a <= ridx; a++) {
        if (nums[a] > nums[maxidx]) {
            maxidx = a;
        }
    }
    newt->val = nums[maxidx];
    newt->left = constructMaximumBinaryTree2(nums, numsSize, lidx, maxidx - 1);
    newt->right = constructMaximumBinaryTree2(nums, numsSize, maxidx + 1, ridx);
    return newt;
}

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize) {
    return constructMaximumBinaryTree2(nums, numsSize, 0, numsSize - 1);
}

int main() {
    // @formatter:off
    int arr[]={3,2,1,6,0,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct TreeNode *ans = constructMaximumBinaryTree(arr,size);
    return 0;
    // @formatter:on
}