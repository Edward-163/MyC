#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//dfs+iterate 没有选择自底向上
///一次ac,值得注意的是:我比别人多写的不用res,今晚看下
void iter(struct TreeNode* root,int* res,int sum){
    if(root->left==NULL && root->right==NULL){
        *res+=sum;
        return;
    }

    if(root->left!=NULL)iter(root->left,res,sum*2+root->left->val);
    if(root->right!=NULL)iter(root->right,res,sum*2+root->right->val);
}

int sumRootToLeaf(struct TreeNode* root){
    int res=0;
    iter(root,&res,0*2+root->val);
    return res;
}

int main() {

    return 0;
}