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

void maxdepth(struct TreeNode *root, int *max, int level) {
    if (root == NULL) {
        return;
    }
    if (level >= *max) {
        *max = level;
    }
    maxdepth(root->left, max, level + 1);
    maxdepth(root->right, max, level + 1);
}

void count(struct TreeNode *root, int *sum, int level, int max) {
    if (root == NULL) {
        return;
    }
    if (level == max) {
        *sum += root->val;
    }
    count(root->left, sum, level + 1, max);
    count(root->right, sum, level + 1, max);
}

int deepestLeavesSum(struct TreeNode *root) {
    int max = 0;
    maxdepth(root, &max, 1);
    int sum = 0;
    count(root, &sum, 1, max);
    return sum;
}

int main() {
    // @formatter:off
    struct TreeNode two={2,NULL,NULL};
    struct TreeNode root={1,&two,NULL};
    printf("%d \n", deepestLeavesSum(&root));fflush(stdout);
    return 0;
    // @formatter:on
}