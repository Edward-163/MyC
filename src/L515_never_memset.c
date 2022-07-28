#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 答案都不用初始化ans,巧妙利用g_level,做好了初始化和更新的操作
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAX 10000
int *g_ans;
int g_level;

void Fn(struct TreeNode *root, int level)
{
    if (level > g_level) {
        g_level = level;
    }
    /// 打印看一眼只有首位元素的intMin,其他全是0???
//    for (int i = 0; i < 10; ++i){
//        printf("%d ", g_ans[i]);fflush(stdout);
//    }
    /// g_ans[1]==0???
    if (root->val > g_ans[level]) {
        g_ans[level] = root->val;
    }
    if (root->left == NULL && root->right == NULL) {
        return;
    }

//    g_level++;
//    if (root->val > g_ans[level])g_ans[level] = root->val;
    if (root->left != NULL)Fn(root->left, level + 1);
    if (root->right != NULL)Fn(root->right, level + 1);
}

int *largestValues(struct TreeNode *root, int *returnSize)
{
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    g_ans = (int *) malloc(sizeof(int) * MAX);
    /// memset坑 函数按字节对内存块进行初始化，所以不能用它将int数组初始化为0和-1之外的其他值（除非该值高字节和低字节相同）
//    memset(g_ans, 2, sizeof(int) * MAX);
    for (int i = 0; i < MAX; ++i) {
        g_ans[i] = INT_MIN;
    }
    g_level = -1;
    int level = 0;
    Fn(root, level);
    *returnSize = g_level + 1;
    return g_ans;
}

int main()
{
    struct TreeNode fuyi = {-1, NULL, NULL};
    struct TreeNode ling = {0, &fuyi, NULL};
    int returnSize = 0;
    int *ans = largestValues(&ling, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", ans[i]);
        fflush(stdout);
    }
    return 0;
}