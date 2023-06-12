#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
/*
 
 */
#define MAX 50002
// #define MAX 10
typedef struct {
    // int mm[MAX][MAX];
    int *m[MAX];
    int parentSize;
} TreeAncestor;
TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize) {
    TreeAncestor *obj=malloc(sizeof(TreeAncestor));
    obj->parentSize=parentSize;
    int mm[parentSize][parentSize];
    memset(mm,-1,sizeof(mm));
    for (int i = 1; i < parentSize; ++i){
        mm[i][1]=parent[i];
        for (int b = 2; b < parentSize; ++b){
            mm[i][b] = mm[parent[i]][b - 1];
        }
    }
    for (int i = 0; i < parentSize; ++i){
        obj->m[i]=mm[i];
    }
    return obj;
}
int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    return k>=obj->parentSize?-1:obj->m[node][k];
}
void treeAncestorFree(TreeAncestor* obj) {
    free(obj);
}
int main()
{
    // @formatter:off
    //[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
    int parent[]={-1,0,0,1,1,2,2};
    int psize=sizeof(parent)/sizeof(parent[0]);
    TreeAncestor *obj = treeAncestorCreate(psize,parent,psize);
    printf("%d \n",treeAncestorGetKthAncestor(obj,3,1));fflush(stdout);
    printf("%d \n",treeAncestorGetKthAncestor(obj,5,2));fflush(stdout);
    printf("%d \n",treeAncestorGetKthAncestor(obj,6,3));fflush(stdout);
    return 0;
    // @formatter:on
}
