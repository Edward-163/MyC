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

 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct {
    struct TreeNode key;
    UT_hash_handle hh;
}Hash;
Hash* g_hash;
struct TreeNode* Not_exit_then_add(struct TreeNode* t){
    Hash* out=NULL;
    HASH_FIND(hh,g_hash,t,sizeof(struct TreeNode),out);
    if(out==NULL){
        Hash* add=malloc(sizeof(struct TreeNode));
        add->key=*t;
        HASH_ADD(hh,g_hash,key,sizeof(struct TreeNode),add);
        return NULL;
    }else{
        return &(out->key);
    }
}
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize){
    g_hash=NULL;
    struct TreeNode* arr[10002];
    int queueleft=0;
    int queuerigh=1;
    while(queuerigh-queueleft!=0){
        int tmpqueuerigh=queuerigh;
        for(int a=queueleft;a<tmpqueuerigh;a++){
            queueleft++;
            if(arr[a]!=NULL){
                struct TreeNode* ans=Not_exit_then_add(arr[a]);
                if(ans!=NULL){
                    return ans;
                }
                arr[queuerigh++]=arr[a]->left;
                arr[queuerigh++]=arr[a]->right;
            }
        }
    }
    
    return NULL;
}
int main() {
    // @formatter:off 30

    return 0;
    // @formatter:on
}