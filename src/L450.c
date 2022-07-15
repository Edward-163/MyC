#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
/*
 
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX 10000
void recur(struct TreeNode* root,int* parr,int* plen){//中序
    if(root==NULL)return;

    recur(root->left,parr,plen);

    parr[*plen]=root->val;
    *plen+=1;

    recur(root->right,parr,plen);
}
struct TreeNode* buildAscList(struct TreeNode* root,int key){
    int* parr=(int*)malloc(sizeof(int)*MAX);
    int plen=0;
    recur(root,parr,&plen);
    struct TreeNode* tail=NULL;
    struct TreeNode* tmp=NULL;
    for(int a=plen-1;a>=0;a--){
        if(parr[a]!=key){
            tmp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            tmp->val=parr[a];
            tmp->left=NULL;
            tmp->right=tail==NULL?NULL:tail;
            tail=tmp;
        }
    }
    return tmp;
}
struct TreeNode* buildDescList(struct TreeNode* root,int key){
    int* parr=(int*)malloc(sizeof(int)*MAX);
    int plen=0;
    recur(root,parr,&plen);
    struct TreeNode* tail=NULL;
    struct TreeNode* tmp=NULL;
    for(int a=0;a<plen;a++){
        if(parr[a]!=key){
            tmp=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            tmp->val=parr[a];
            tmp->left=tail==NULL?NULL:tail;
            tmp->right=NULL;
            tail=tmp;
        }
    }
    return tmp;
}

struct TreeNode* fn(struct TreeNode* root,int key,bool* flag){
    if(root->left!=NULL&&root->left->val==key){
        root->left=buildDescList(root->left,key);
        *flag=true;
        return root;
    }
    if(root->right!=NULL&&root->right->val==key){
        root->right=buildAscList(root->right,key);
        *flag=true;
        return root;
    }
    ///bug 没写* 多写&
    //if(flag==false)Fn(root->left,key,&flag);
    if(root->left!=NULL && *flag==false)fn(root->left,key,flag);
    if(root->right!=NULL && *flag==false)fn(root->right,key,flag);
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    //思考:找3简单,删除3后返回newtree难,如2 2.5 3 3.5 4
    //find key,重构左树or右树or左右树,我呢暴力点全部重构左右树为链表
    struct TreeNode* dummy=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    dummy->val=0;
    dummy->left=root;
    dummy->right=NULL;

    bool flag=false;
    fn(dummy,key,&flag);
    return dummy->left;
}

int main() {
    struct TreeNode* six=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    six->val=6;
    six->left=NULL;
    six->right=NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=5;
    root->left=NULL;
    root->right=six;
    deleteNode(root,6);
    return 0;
}