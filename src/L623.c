#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
///bug:总之不能像java那样直接构造,原因有待看书
struct TreeNode* addOneRow2(struct TreeNode* root, int val, int depth){
    if(root==NULL)return root;
    if(depth==1){
        struct TreeNode* v={val,root,NULL};
        return v;
    }
    if(depth==0)return root;

    if(depth==2){
        if(root->left!=NULL){

            struct TreeNode* vall={val,root->left,NULL};
            root->left=vall;
        }
        if(root->right!=NULL){

            struct TreeNode* valr={val,NULL,root->right};
            root->right=valr;
        }
        return root;
    }

    root->left=addOneRow2(root->left,val,depth-1);
    root->right=addOneRow2(root->right,val,depth-1);

    return root;
}
///bug:测过了30用例 [1,2,3,4] 5 4
struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth){
    if(root==NULL)return root;
    if(depth==1){
        struct TreeNode* v=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        v->val=val;
        v->left=root;
        v->right=NULL;
        return v;
    }
    if(depth==0)return root;

    if(depth==2){
        ///bug:空的我没给它造出来
//        if(root->left!=NULL){

            struct TreeNode* vall=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            vall->val=val;
            vall->left=root->left;
            vall->right=NULL;
            root->left=vall;
//        }
//        if(root->right!=NULL){

            struct TreeNode* valr=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            valr->val=val;
            valr->left=NULL;
            valr->right=root->right;
            root->right=valr;
//        }
        return root;
    }

    root->left=addOneRow(root->left,val,depth-1);
    root->right=addOneRow(root->right,val,depth-1);

    return root;
}

int main(){

    return 0;
}