#include <stddef.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *res = NULL;
int find = 0;

void fn(struct TreeNode *root, int p) {
    if (root == NULL)return;

    fn(root->right, p);
    if (root->val == p) {
        find = 1;
    }
    if (find == 0)res = root;
    fn(root->left, p);
}

struct TreeNode *inorderSuccessor(struct TreeNode *root, struct TreeNode *p) {
    fn(root, p->val);
    return res;
}

/// 面试题 04.06. 后继者
int main() {
    struct TreeNode one = {1, NULL, NULL};
    struct TreeNode two = {2, &one, NULL};
    struct TreeNode four = {4, NULL, NULL};
    struct TreeNode three = {3, &two, &four};
    struct TreeNode six = {6, NULL, NULL};
    struct TreeNode five = {5, &three, &six};
//    inorderSuccessor(&two,&thr);
    inorderSuccessor(&five, &three);
    if (res != NULL)printf("%d", res->val);
    return 0;
}