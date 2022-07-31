#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"

/*

 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int *g_arr;
int g_level;

void Fn(struct TreeNode *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level > g_level) {
        g_level = level;
        printf("%d \n", g_level);fflush(stdout);
    }
    if (root->left == NULL && root->right == NULL) {
        g_arr[level] += root->val;
        return;
    }
    g_arr[level] += root->val;
    Fn(root->left, level + 1);
    Fn(root->right, level + 1);
}

int maxLevelSum(struct TreeNode *root) {
    // 2^14 maxlevel==14
    g_arr = malloc(sizeof(int) * 15);
    memset(g_arr, 0, sizeof(int) * 15);
    g_level = 0;
    Fn(root, 1);
    int ans = g_level;
    for (int m = g_level - 1; m >= 1; m--) {
        if (g_arr[m] >= g_arr[ans]) {
            ans = m;
        }
    }
    return ans;
}

int main() {
    // @formatter:off

    // @formatter:on
    return 0;
}