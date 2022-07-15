#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 将投标方 userId 对项目 projectId 的投标金额 price 录入系统；若系统中已存在 userId 对项目 projectId 的投标金额，则不作处理。
AddTender(int userId, int projectId, int price)
 若系统中存在投标方 userId 对项目 projectId 的投标金额，则将该金额更新为 price，并返回更新前的投标金额；否则请返回 -1。
UpdateTender(int userId, int projectId, int price)
 若系统中存在投标方 userId 对项目 projectId 的投标金额，删除该投标记录，返回被删除的投标金额；否则返回 -1
RemoveTender(int userId, int projectId)
 查询并返回系统中项目 projectId 的投标记录中，投标金额大于 price 且最接近 price 的投标方 userId；
    若有多个投标方投标金额相同，比较投标方最后一次投标时间，返回投标时间最早的投标方 userId；（AddTender 和 UpdateTender 都是投标）
    若不存在符合要求的投标记录，请返回 -1；
QueryTender(int projectId, int price)
示例：
输入：
["TenderSystem","addTender","addTender","addTender",
 "updateTender","updateTender","removeTender","removeTender",
 "addTender","addTender","addTender","queryTender","queryTender"]
[[],[1,1,10],[2,2,20],[2,2,30],
 [1,1,40],[1,3,40],[1,1],[1,3],
 [1,2,20],[3,2,10],[4,2,40],[2,15],[5,10]]
输出：
 [null,null,null,null,
 10,-1,40,-1,
 null,null,null,2,-1]

示例 2：
输入：["TenderSystem","addTender","addTender","updateTender","queryTender"]
[[],[1,1,10],[2,1,20],[1,1,20],[1,10]]

输出：[null,null,null,10,2]

解释：
TenderSystem t = TenderSystem()
t.AddTender(1,1,10) // 在系统中添加 userId 为 1，projectId 为 1 的投标金额 10
t.AddTender(2,1,20) // 在系统中添加 userId 为 2，projectId 为 1 的投标金额 20
t.UpdateTender(1,1,20) // 在系统中将 userId 为 1，projectId 为 1 的投标金额更新为 20，并返回更新前的金额 10
t.QueryTender(1,10) // 查询系统中 projectId 为 1，投标金额大于 10 且最接近 10 的 userId，1 与 2 均符合条件，由于 userId 1 更新时间晚（虽然 userId 1先做了首次投标，但是取其最后一次更新投标的时间来进行比较），因此返回最早录入系统的 userId 2

提示：
  1 <= userId <= 10^4
  1 <= projectId <= 10^6
  1 <= price <= 10^8
  addTender、updateTender、removeTender、queryTender 累计操作数 <= 1000
 */
typedef struct {
    int userId;
    int projectId;
}Key;
int g_time;
typedef struct {
    Key key;
    int price;
    int timestamp;
    UT_hash_handle hh;
}Hash;
Hash* g_hash;
void TenderSystem(){
    g_time=0;
    g_hash=NULL;
}
//将投标方 userId 对项目 projectId 的投标金额 price 录入系统；若系统中已存在 userId 对项目 projectId 的投标金额，则不作处理。
void AddTender(int userId, int projectId, int price){
    Key key={userId,projectId};
    Hash* tmp;
    HASH_FIND(hh, g_hash, &key, sizeof(Key), tmp);
    if(tmp==NULL){
        tmp=(Hash*)malloc(sizeof(Hash));
        tmp->key=key;
        tmp->price=price;
        tmp->timestamp=++g_time;
        HASH_ADD(hh, g_hash, key, sizeof(Key), tmp);
        printf("add\n");fflush(stdout);
    }else{
        printf("do nothing\n");fflush(stdout);
    }
}
//若系统中存在投标方 userId 对项目 projectId 的投标金额，则将该金额更新为 price，并返回更新前的投标金额；否则请返回 -1。
int UpdateTender(int userId, int projectId, int price){
    Key key={userId,projectId};
    Hash* tmp;
    HASH_FIND(hh, g_hash, &key, sizeof(Key), tmp);
    if(tmp==NULL){
        return -1;
    }else{
        int oldprice=tmp->price;
        tmp->price=price;
        tmp->timestamp=++g_time;
        return oldprice;
    }
}
//若系统中存在投标方 userId 对项目 projectId 的投标金额，删除该投标记录，返回被删除的投标金额；否则返回 -1
int RemoveTender(int userId, int projectId){
    Key key={userId,projectId};
    Hash* tmp;
    HASH_FIND(hh, g_hash, &key, sizeof(Key), tmp);
    if(tmp==NULL){
        return -1;
    }else{
        int oldprice=tmp->price;
        HASH_DEL(g_hash, tmp);
        return oldprice;
    }
}
int cmp(const void*a,const void*b){
    const Hash* aa=(Hash*)a;
    const Hash* bb=(Hash*)b;
    if(bb->price!=aa->price){
        /// bug
//        return bb->price-aa->price;
        return aa->price-bb->price;
    }else{
        return aa->timestamp-bb->timestamp;
    }
}
//查询并返回系统中项目 projectId 的投标记录中，投标金额大于 price 且最接近 price 的投标方 userId；
//若有多个投标方投标金额相同，比较投标方最后一次投标时间，返回投标时间最早的投标方 userId；（AddTender 和 UpdateTender 都是投标）
//若不存在符合要求的投标记录，请返回 -1；
int QueryTender(int projectId, int price){
    HASH_SORT(g_hash, cmp);
    Hash* el;
    Hash* tmp;
    HASH_ITER(hh, g_hash, el, tmp){
        if(el->key.projectId==projectId && el->price>price){
            return el->key.userId;
        }
    }
    return -1;
}
int main() {
    /*
["TenderSystem","addTender","addTender","addTender",
 "updateTender","updateTender","removeTender","removeTender",
 "addTender","addTender","addTender","queryTender","queryTender"]
[[],[1,1,10],[2,2,20],[2,2,30],
 [1,1,40],[1,3,40],[1,1],[1,3],
 [1,2,20],[3,2,10],[4,2,40],[2,15],[5,10]]
输出：
 [null,null,null,null,
 10,-1,40,-1,
 null,null,null,2,-1]
     */
    TenderSystem();
    AddTender(1,1,10);
    AddTender(2,2,20);
    AddTender(2,2,30);
    printf("%d \n", UpdateTender(1,1,40));fflush(stdout);
    printf("%d \n", UpdateTender(1,3,40));fflush(stdout);
    printf("%d \n", RemoveTender(1,1));fflush(stdout);
    printf("%d \n", RemoveTender(1,3));fflush(stdout);
    AddTender(1,2,20);
    AddTender(3,2,10);
    AddTender(4,2,40);
    printf("%d \n",QueryTender(2,15));fflush(stdout);
    printf("%d \n",QueryTender(5,10));fflush(stdout);
    return 0;
}









































/*
 #define MAX_LENGTH 1005

#define MAX_NUMBER 2147483647

int g_size;

typedef struct {
    int userId;
    int projectId;
    int price;
} TenderSystem;



TenderSystem *TenderSystemCreate()
{
    TenderSystem *tenderSystem = (TenderSystem *)malloc(sizeof(TenderSystem) * MAX_LENGTH);
    memset_s(tenderSystem, sizeof(TenderSystem) * MAX_LENGTH, 0, sizeof(TenderSystem) * MAX_LENGTH);
    g_size = 0;
    return tenderSystem;
}



void TenderSystemAddTender(TenderSystem *obj, int userId, int projectId, int price)

{

    for (int i = 0; i < g_size; i++) {

        if (obj[i].projectId == projectId && obj[i].userId == userId) {

            return;

        }

    }

    obj[g_size].userId = userId;

    obj[g_size].projectId = projectId;

    obj[g_size].price = price;

    ++g_size;

    return;

}



int TenderSystemUpdateTender(TenderSystem *obj, int userId, int projectId, int price)

{

    int temp = TenderSystemRemoveTender(obj, userId, projectId);

    if (temp == -1) {

        return temp;

    }

    TenderSystemAddTender(obj, userId, projectId, price);

    return temp;

}



int TenderSystemRemoveTender(TenderSystem *obj, int userId, int projectId)

{

    int temp;

    for (int i = 0; i < g_size; i++) {

        if (obj[i].projectId == projectId && obj[i].userId == userId) {

            obj[i].userId = 0;

            obj[i].projectId = 0;

            temp = obj[i].price;

            obj[i].price = 0;

            return temp;

        }

    }

    return -1;

}



int TenderSystemQueryTender(TenderSystem *obj, int projectId, int price)

{

    int min = MAX_NUMBER;

    int resultId = -1;

    for (int i = g_size - 1; i >= 0; i--) {

        if (obj[i].projectId == projectId) {

            if (obj[i].price > price && (obj[i].price - price) <= min) {

                min = obj[i].price - price;

                resultId = obj[i].userId;

            }

        }

    }

    return resultId;

}



void TenderSystemFree(TenderSystem *obj)

{

    free(obj);

    return;

}
 */