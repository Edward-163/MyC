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
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAX 10002
typedef struct {
    struct TreeNode *root;
} CBTInserter;
// 个人不喜欢把变量写在CBT中,因为下面方法只要用到obj,obj->肯定少不了,干脆用全局变量算了
struct TreeNode **g_arr; // 指针数组,不管你怎么插,节点3插完了,可能是4,可能是5,总之是递增的.大不了挨个挨个判断,能插就插,不能就下一个节点
int g_asize;
int g_qsize;
int g_insertidx;

CBTInserter *cBTInserterCreate(struct TreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    // init global var
    g_arr = malloc(sizeof(struct TreeNode *) * MAX);
    g_asize = 0;
    g_arr[g_asize++] = root;
    g_qsize = 1; // 模拟queue大小
    g_insertidx = 0;
    int popidx = 0; // 模拟queue队首弹出
    while (g_qsize != 0) {
        struct TreeNode *pop = g_arr[popidx++];
        // step
        g_qsize--;
        if (pop->left != NULL) {
            g_arr[g_asize++] = pop->left;
            g_qsize++;
        }
        if (pop->right != NULL) {
            g_arr[g_asize++] = pop->right;
            g_qsize++;
        }
    }
    CBTInserter *obj = malloc(sizeof(CBTInserter));
    obj->root = root;
    return obj;
}

int cBTInserterInsert(CBTInserter *obj, int val)
{
    struct TreeNode *vnode = malloc(sizeof(struct TreeNode));
    vnode->val = val;
    vnode->left = NULL;
    vnode->right = NULL;
    g_arr[g_asize++] = vnode; // 仅仅只是数组尾部加了vnode,但root树没有加vnode
    int ans;
    // 思考:有必要每次都从0开始遍历吗??
    for (int i = g_insertidx; i < g_asize; ++i) {
        if (g_arr[i]->left != NULL && g_arr[i]->right != NULL) {
            continue;
        }
        if (g_arr[i]->left == NULL) {
            g_arr[i]->left = vnode;
            g_insertidx = i;
            ans = g_arr[i]->val;
            break;
        }
        if (g_arr[i]->right == NULL) {
            g_arr[i]->right = vnode;
            g_insertidx = i;
            ans = g_arr[i]->val;
            break;
        }
    }
    return ans;
}

struct TreeNode *cBTInserterGet_root(CBTInserter *obj)
{
    return obj->root;
}

void cBTInserterFree(CBTInserter *obj)
{
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