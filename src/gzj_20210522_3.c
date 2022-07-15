#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
设计一个租房系统，房源信息：（房屋编号id，面积area，价格price、卧室数量rooms、位置坐标address[]）。
实现如下函数功能：
1. 初始化：RentingSystem *RentingSystemCreate()
2. 添加房源信息：bool RentingSystemAddRoom(RentingSystem *obj, int id, int area, int price, int rooms, int *address, int addressSize)
    根据房源编号id添加房源，如果已有该房源，则覆盖面积、价格、数量、坐标等信息，并返回false；
    如果该房源id不存在，则添加该房源，并返回true。
3. 删除房源信息：bool RentingSystemDeleteRoom(RentingSystem *obj, int id)
    删除房源编号为id的房源信息，如果确实存在该房源，删除并返回true；如果不存在该房源，返回false；
4. 筛选房源信息：int *RentingSystemQueryRoom(RentingSystem *obj, int area, int price, int rooms, int *address, int addressSize, int **orderBy, int orderBySize, int *retSize)
   筛选满足要求的房源信息，并按指定顺序返回房源编号；
   满足要求：面积>=area、价格<=price、卧室数量==rooms；
   指定顺序：orderBy[]=[orderNum，order]给出指定顺序；
                    order == 1升序；order == -1降序；
                    orderNum==1 按面积area排序；orderNum==2 按价格price排序；orderNum==3 按曼哈顿距离排序；
                    优先按照orderBy给出的排序规则排序，如果还排不出先后，就按照房源编号升序排序；
                    例如：orderBy = [[3, 1], [2, -1]] 表示，先按照曼哈顿距离升序排序，如果排不出先后，就按照价格price降序排序，再不行，就按照房源编号升序排序；
5. 销毁系统：void RentingSystemFree(RentingSystem *obj)
提示：
房源编号id是唯一的；
(x1, y1)与(x2，y2)之间的曼哈顿距离=|x1 - x2| + |y1 - y2| ；
思路：
1、基本的插入、删除、查找等操作就用力扣自带的uthash解决；
2、排序调用一次qsort，重点是qsort的比较函数MyCmp该如何写；
     MyCmp中根据orderBy给出的规则排列两个房源的先后顺序即可；
     由于qsort的比较函数MyCmp只能传入两个比较元素（本题传入房源id），因此orderBy排序规则要用全局变量来保存好，在MyCmp中调用；
 */


int main() {

    return 0;
}
/*
struct RoomEntry {
    int id;
    int area;
    int price;
    int rooms;
    int address[2];
    UT_hash_handle hh;
};

struct RoomEntry *gEntrys = NULL;
int **gOrderBy = NULL;
int gOrderBySize = 0;
int *gAddress = NULL;

typedef struct {
    int num;
    struct RoomEntry *entry;
} RentingSystem;

RentingSystem *RentingSystemCreate()
{
    RentingSystem *obj = NULL;
    gEntrys = NULL;
    obj = (RentingSystem *)malloc(sizeof(RentingSystem));
    obj->entry = gEntrys;
    obj->num = 0;
    return obj;
}

bool RentingSystemAddRoom(RentingSystem *obj, int id, int area, int price, int rooms, int *address, int addressSize)
{
    struct RoomEntry *cur = NULL;
    bool ret = false;

    HASH_FIND_INT(gEntrys, &id, cur);
    if (cur == NULL) {
        cur = (struct RoomEntry *)malloc(sizeof(struct RoomEntry));
        cur->id = id;
        HASH_ADD_INT(gEntrys, id, cur);
        obj->num++;
        ret = true;
    }
    cur->area = area;
    cur->price = price;
    cur->rooms = rooms;
    cur->address[0] = address[0];
    cur->address[1] = address[1];
    return ret;
}

bool RentingSystemDeleteRoom(RentingSystem *obj, int id)
{
    struct RoomEntry *cur = NULL;

    HASH_FIND_INT(gEntrys, &id, cur);
    if (cur == NULL) {
        return false;
    }
    HASH_DEL(gEntrys, cur);
    obj->num--;
    free(cur);
    cur = NULL;
    return true;
}


// 输入orderBy是长度为orderBySize的数组指针的数组，其中每个元素也是一个数组，此数组长度固定为2。
// 注意：返回的数组必须由实现者进行内存分配，由框架代码进行内存释放。
// 返回的数组长度存在 *retSize 中。

void GetFitRoom(int *ret, int *retSize, int area, int price, int rooms)
{
    struct RoomEntry *cur = NULL;
    struct RoomEntry *tmp = NULL;
    HASH_ITER(hh, gEntrys, cur, tmp) {
        if (cur->area >= area && cur->price <= price && cur->rooms == rooms) {
            ret[*retSize] = cur->id;
            (*retSize)++;
        }
    }
}

int MyAbs(int a, int b)
{
    return ((a > b) ? (a - b) : (b - a));
}

int MyCmp(const void *a, const void *b)
{
    int idA = *(int *)a;
    int idB = *(int *)b;
    int orderBySize = gOrderBySize;
    struct RoomEntry *roomA = NULL;
    struct RoomEntry *roomB = NULL;

    HASH_FIND_INT(gEntrys, &idA, roomA);
    HASH_FIND_INT(gEntrys, &idB, roomB);

    for (int i = 0; i < orderBySize; i++) {
        if (gOrderBy[i][0] == 1) {
            if (roomA->area == roomB->area) {
                continue;
            }
            return (roomA->area - roomB->area) * gOrderBy[i][1];
        }

        if (gOrderBy[i][0] == 2) {
            if (roomA->price == roomB->price) {
                continue;
            }
            return (roomA->price - roomB->price) * gOrderBy[i][1];
        }

        if (gOrderBy[i][0] == 3) {
            int dstA = MyAbs(roomA->address[0], gAddress[0]) + MyAbs(roomA->address[1], gAddress[1]);
            int dstB = MyAbs(roomB->address[0], gAddress[0]) + MyAbs(roomB->address[1], gAddress[1]);
            if (dstA == dstB) {
                continue;
            }
            return (dstA - dstB) * gOrderBy[i][1];
        }
    }

    return (idA - idB);
}

int *RentingSystemQueryRoom(RentingSystem *obj, int area, int price, int rooms, int *address, int addressSize,int **orderBy, int orderBySize, int *retSize)
{
    *retSize = 0;
    int *ret = (int *)malloc(sizeof(int) * (obj->num));
    GetFitRoom(ret, retSize, area, price, rooms);

    if ((*retSize) == 0) {
        free(ret);
        ret = NULL;
        return NULL;
    }
    gAddress = address;
    gOrderBy = orderBy;
    gOrderBySize = orderBySize;
    qsort(ret, *retSize, sizeof(int), MyCmp);

    return ret;
}

void RentingSystemFree(RentingSystem *obj) {
    struct RoomEntry *cur = NULL;
    struct RoomEntry *tmp = NULL;

    HASH_ITER(hh, gEntrys, cur, tmp) {
        HASH_DEL(gEntrys, cur);
        free(cur);
        cur = NULL;
    }
    free(obj);
    ///构造函数中,obj因malloc而指向堆上某块内存,free上解除obj对某块内存的占用,obj本身没有删除,正确做法把指针指向NULL
    obj = NULL;
}
*/