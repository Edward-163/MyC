#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 HASH_DEL(g_hashlist,tmp)
 
 int com(const void* a,const void* b)
 HASH_SORT(g_hashlist,cmp)

 //tmp：就是前面提到的临时变量。这个变量从表面上来看没有什么意义，但是会在这个函数内部被使用，所以一定要声明一个tmp结构体指针（不用赋值），并送入函数。
 HASH_ITER(hh,g_hashlist,cur,tmp){
    printf("%d",cur->id);//hash节点数据在cur指针中,tmp没啥用
 }
 
 HASH_COUNT(g_hashlist);
 */
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
}Hashlist;

Hashlist * g_hashlist;/// leet中不要初始化这个全局var

int cmp(const void* a,const void*b){
    return *(int*)b-*(int*)a;
}

int main() {
    g_hashlist=NULL;
    for (int a = 0; a < 3; ++a) {
        /// 听说c有了void*后,下行显式转换不建议写,另外c隐式转换:字节少向字节多转,有符号向无符号转,
        Hashlist * tmp=(Hashlist*)malloc(sizeof(Hashlist));//add记得开堆空间
        tmp->key=a;
        tmp->val=a;
        HASH_ADD_INT(g_hashlist, key, tmp);
    }

    HASH_SORT(g_hashlist, cmp);

    unsigned int size = HASH_COUNT(g_hashlist);
    printf("size %d\n",size);fflush(stdout);

    Hashlist * el;
    Hashlist * tmp3;//tmp：就是前面提到的临时变量。这个变量从表面上来看没有什么意义，但是会在这个函数内部被使用，所以一定要声明一个tmp结构体指针（不用赋值），并送入函数。
    HASH_ITER(hh, g_hashlist, el, tmp3){
        printf("iter %d %d\n",el->val,el->val);fflush(stdout);
    }
    printf("------------\n");fflush(stdout);

    Hashlist * tmp4;//find只需声明就行
    int key=2;
    /// 注意char* key;时,直接传str,而不是&str!!!!!!!!!!!!!!!!!!!!!!!!!!
    HASH_FIND_INT(g_hashlist, &key, tmp4);
    HASH_DEL(g_hashlist, tmp4);//从hashlist中删除tmp4这个节点
    /// 这里是最容易忘的,迭代时是否支持删节点???实践是支持的
    HASH_ITER(hh, g_hashlist, el, tmp3){
        printf("iter %d %d\n",el->key,el->val);fflush(stdout);
        HASH_DEL(g_hashlist,el);
    }
    printf("------------\n");fflush(stdout);
    printf("after delete size %d", HASH_COUNT(g_hashlist));fflush(stdout);

    return 0;
}