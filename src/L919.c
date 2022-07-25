#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
/*
 完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。
实现 CBTInserter 类:
CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点 TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
CBTInserter.get_root() 将返回树的头节点。
 */
#define MAX 26
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct {
    struct TreeNode **parents; /// 指向节点的指针所组成的数组,第一次写的时候,我用的是结构体数组,发现改变结构体数组的元素的子节点却改变不了root
    int psize;
    struct TreeNode *root;
} CBTInserter;

CBTInserter *cBTInserterCreate(struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    CBTInserter *obj = malloc(sizeof(CBTInserter));
    struct TreeNode **parents = malloc(sizeof(struct TreeNode *) * MAX);
    /// bug 修改parent的值,不会影响root的值,??
    parents[0] = root;
    int psize = 1;
    bool tonext = true; // 去下一层??
    struct TreeNode **new = malloc(sizeof(struct TreeNode *) * MAX);
    int newsize = 0;
    while (tonext) {
        for (int a = 0; a < psize; a++) {
            if (parents[a]->left != NULL) {
                new[newsize++] = parents[a]->left;
            } else {
                tonext = false;
            }
            if (parents[a]->right != NULL) {
                new[newsize++] = parents[a]->right;
            } else {
                tonext = false;
            }
        }
        if (tonext) {
            parents = new;
            psize = newsize;
            newsize = 0;
        }
    }

    obj->parents = parents;
    obj->psize = psize;
    obj->root = root;
    return obj;
}

int cBTInserterInsert(CBTInserter *obj, int val)
{
    bool tonext = true; // 去下一层??
    struct TreeNode **new = malloc(sizeof(struct TreeNode *) * MAX);
    int newsize = 0;
    int ans;
    bool sonisnull = true;
    // struct TreeNode vnode = {val, NULL, NULL};
    struct TreeNode *vnode = malloc(sizeof(struct TreeNode));
    vnode->val = val;
    vnode->left = NULL;
    vnode->right = NULL;
    for (int a = 0; a < obj->psize; ++a) {
        if (obj->parents[a]->left == NULL) {
            if (sonisnull) {
                obj->parents[a]->left = vnode;
                ans = obj->parents[a]->val;
                sonisnull = false;
            }
        } else {
            new[newsize++] = obj->parents[a]->left;
        }
        if (obj->parents[a]->right == NULL) {
            if (sonisnull) {
                obj->parents[a]->right = vnode;
                ans = obj->parents[a]->val;
                sonisnull = false;
                // 若插入是此层最后节点的右节点,则去下一层
                if (a == obj->psize - 1) {
                    tonext = true;
                    new[newsize++] = obj->parents[a]->right;
                }
            }
        } else {
            new[newsize++] = obj->parents[a]->right;
        }
    }
    if (tonext) {
        obj->parents = new;
        obj->psize = newsize;
    }
    return ans;
}

struct TreeNode *cBTInserterGet_root(CBTInserter *obj)
{
    return obj->root;
}

void cBTInserterFree(CBTInserter *obj)
{
    for (int i = 0; i < obj->psize; ++i) {
        free(obj->parents + i);
    }
    free(obj->parents);
    free(obj);
}

int main()
{
    // @formatter:off
    // struct TreeNode * root=malloc(sizeof(struct TreeNode));
    // root->val=1;
    struct TreeNode four={4,NULL,NULL};
    struct TreeNode five={5,NULL,NULL};
    struct TreeNode six={6,NULL,NULL};
    struct TreeNode two={2,&four,&five};
    struct TreeNode three={3,&six,NULL};
    struct TreeNode root={1,&two,&three}; //这么写可以,console可穷尽查看root的子节点,
    // struct TreeNode root3={1,{2,NULL,NULL},NULL}; // 这么写sig,且console不可穷尽查看root的子节点,这显然不正常
    CBTInserter *obj = cBTInserterCreate(&root);
    // printf("%d \n",cBTInserterInsert(obj,3));fflush(stdout);
    // printf("%d \n",cBTInserterInsert(obj,4));fflush(stdout);
    printf("%d \n",cBTInserterInsert(obj,7));fflush(stdout);
    printf("%d \n",cBTInserterInsert(obj,8));fflush(stdout);
    struct TreeNode *getRoot = cBTInserterGet_root(obj);
    return 0;
    // @formatter:on
}

/*

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct {
    struct TreeNode *parents;
    int psize;
    struct TreeNode *root;
} CBTInserter;

CBTInserter *cBTInserterCreate(struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    CBTInserter *obj = malloc(sizeof(CBTInserter));
    struct TreeNode *parents = malloc(sizeof(struct TreeNode) * MAX);
    /// bug 修改parent的值,不会影响root的值,??
    parents[0] = *root;
    int psize = 1;
    bool tonext = true; // 去下一层??
    struct TreeNode *new = malloc(sizeof(struct TreeNode) * MAX);
    int newsize = 0;
    while (tonext) {
        for (int a = 0; a < psize; a++) {
            if (parents[a].left != NULL) {
                new[newsize++] = *(parents[a].left);
            } else {
                tonext = false;
            }
            if (parents[a].right != NULL) {
                new[newsize++] = *(parents[a].right);
            } else {
                tonext = false;
            }
        }
        if (tonext) {
            parents = new;
            psize = newsize;
            newsize = 0;
        }
    }

    obj->parents = parents;
    obj->psize = psize;
    obj->root = root;
    return obj;
}

int cBTInserterInsert(CBTInserter *obj, int val)
{
    bool tonext = true; // 去下一层??
    struct TreeNode *new = malloc(sizeof(struct TreeNode) * MAX);
    int newsize = 0;
    int ans;
    bool sonisnull = true;
    // struct TreeNode vnode = {val, NULL, NULL};
    struct TreeNode *vnode = malloc(sizeof(struct TreeNode));
    vnode->val = val;
    vnode->left = NULL;
    vnode->right = NULL;
    for (int a = 0; a < obj->psize; ++a) {
        if (obj->parents[a].left == NULL) {
            if (sonisnull) {
                obj->parents[a].left = vnode;
                ans = obj->parents[a].val;
                sonisnull = false;
            }
        } else {
            new[newsize++] = *(obj->parents[a].left);
        }
        if (obj->parents[a].right == NULL) {
            if (sonisnull) {
                obj->parents[a].right = vnode;
                ans = obj->parents[a].val;
                sonisnull = false;
                // 若插入是此层最后节点的右节点,则去下一层
                if (a == obj->psize - 1) {
                    tonext = true;
                    new[newsize++] = *(obj->parents[a].right);
                }
            }
        } else {
            new[newsize++] = *(obj->parents[a].right);
        }
    }
    if (tonext) {
        obj->parents = new;
        obj->psize = newsize;
    }
    return ans;
}
 */