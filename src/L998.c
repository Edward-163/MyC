#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：a = [1,4,2,3], b = [1,4,2,3,5]
示例 2：

输入：root = [5,2,4,null,1], val = 3
输出：[5,2,4,null,1,null,3]
解释：a = [2,1,5,4], b = [2,1,5,4,3]
示例 3：

输入：root = [5,2,3,null,1], val = 4
输出：[5,2,4,null,1,3]
解释：a = [2,1,5,3], b = [2,1,5,3,4]
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertIntoMaxTree(struct TreeNode *root, int val)
{
    // 暴力:root转数组,数组末尾加val,数组转newRoot
    // 非暴力如下,val比根还大,根不变,整个root就是val的左子树
    if (val > root->val) {
        struct TreeNode *ans = malloc(sizeof(struct TreeNode));
        ans->val = val;
        ans->left = root;
        ans->right = NULL;
        return ans;
    } else if (val < root->val) {
        // root的右树为NULL或者val比右树最大值还大,说白了就是在root和右树之间插个val节点
        if (root->right == NULL || val > root->right->val) {
            struct TreeNode *ans = malloc(sizeof(struct TreeNode));
            ans->val = val;
            ans->left = root->right;
            ans->right = NULL;
            root->right = ans;
        } else {
            // 开始递归,简易手画图理解
            root->right = insertIntoMaxTree(root->right, val);
        }
    }
    return root; // leet自带编译器有毒,一定要写在这才不报错
}

int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}