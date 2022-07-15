#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
typedef struct {
    int userId;
    int projectId;
}Key;
typedef struct {
    /// bug:直接写结构体,不要写结构体指针!!
//    Key* key;
    Key key;
    UT_hash_handle hh;
}Hash;
Hash* g_hash;
int cmp(const void*a,const void*b){
    const Hash* aa=(Hash*)a;
    const Hash* bb=(Hash*)b;
    if(aa->key.userId!=bb->key.userId){
        return bb->key.userId-aa->key.userId;
    }else{
        return bb->key.projectId-aa->key.projectId;
    }
}
int main() {
    g_hash=NULL;
    Hash* tmp=(Hash*)malloc(sizeof(Hash));
    tmp->key.userId=0;
    tmp->key.projectId=1;
    HASH_ADD(hh, g_hash, key, sizeof(Key), tmp);
    /// bug:newkey is null??? 语法都写错了
//    Key* newkey={0,1};
    Key newkey={0,1};
    Hash* tmp2;
    /// 实践都行,那选哪种?来个权威解释?
        HASH_FIND(hh, g_hash, &newkey, sizeof(newkey), tmp2);
//    HASH_FIND(hh,hash,&newkey,sizeof(Key),tmp2);
    if(tmp2==NULL){

    }else{
        printf("find: %d %d\n", tmp2->key.userId,tmp2->key.projectId);fflush(stdout);
    }

    tmp=(Hash*)malloc(sizeof(Hash));
    Key newkey2={1,0};
    tmp->key=newkey2;
    HASH_ADD(hh, g_hash, key, sizeof(Key), tmp);
    tmp=(Hash*)malloc(sizeof(Hash));
    Key newkey22={1,1};
    tmp->key=newkey22;
    HASH_ADD(hh, g_hash, key, sizeof(Key), tmp);

    HASH_SORT(g_hash, cmp);
    Hash* el;
    Hash* tmp4;
    HASH_ITER(hh, g_hash, el, tmp4){
        printf("%d %d \n",el->key.userId,el->key.projectId );fflush(stdout);
    }
    return 0;
}