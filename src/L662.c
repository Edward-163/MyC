#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*
把二叉树玩出花了 1 23 4567 root编号1,left==1*2,right==2*1+1,以此类推左子节点的编号是父节点编号的2倍,右子节点是...
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int arr[3002]; // 空间的节约,记录每层的minNum,并不需要arr2来记录每层的maxNum
int ans;
void widthOfBinaryTree2(struct TreeNode* root,int level,int num){
    if(root==NULL)return;
    if(num<arr[level])arr[level]=num; // 先左后右,特定把最小值给设置完
    widthOfBinaryTree2(root->left,level+1,num*2);
    widthOfBinaryTree2(root->right,level+1,num*2+1);
    if(num-arr[level]+1>ans){
        /// bug 加了这行发现是3002引起的bug,例如树只有右腿,明显每层的宽度都是1,而我初始化3002的bug会引起,rightNum越来也大,leftNum确实固定的3002
        printf("%d %d %d \n",level,arr[level],num );fflush(stdout);
        ans=num-arr[level]+1;
    }
}
int widthOfBinaryTree(struct TreeNode* root){
    ans=0;
    for(int a=0;a<3002;a++){
        arr[a]=3002;
    }
    widthOfBinaryTree2(root,0,1);

    return ans;
}
int main() {
    // @formatter:off 19
    struct TreeNode five={5,NULL,NULL};
    struct TreeNode six={6,NULL,NULL};
    struct TreeNode three={3,&five,&six};
    struct TreeNode nine={9,NULL,NULL};
    struct TreeNode two={2,NULL,&nine};

    struct TreeNode one={1,&three,&two};
    int i = widthOfBinaryTree(&one);
    printf("%d \n", i);fflush(stdout);
    return 0;
    // @formatter:on
}