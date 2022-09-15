#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
/*
在系统中增加一套编号为 id，面积为 area，月租金为 price，卧室数量为 rooms，地址坐标为 address（格式为 [横坐标x, 纵坐标y]）的房源：
若系统中不存在编号为 id的房源，则添加该房源，返回 true；
若已存在，则将对应房源信息 更新 为新传入的 area、price、rooms 与 address，并返回 false；
addRoom(int id, int area, int price, int rooms, int[] address)

 删除系统中编号为 id 的房源：
deleteRoom(int id)

若存在编号为 id 的房源，删除此房源并返回 true；若不存在，返回 false。
查询系统中符合筛选条件的房源，并按排序要求返回房源编号的序列。其中：
Ø  筛选条件：面积大于等于 area，月租金小于等于 price，卧室数为 rooms 的房源；
Ø  排序要求：按orderBy中的排序条件依次进行排序；若按orderBy排序结果仍相同（含orderBy为空），则按房源编号升序排列。
orderBy的元素格式为 [parameter,order]。
²  parameter取值范围[1,3]， 1（表示 area）、2（表示 price）、3（表示房源坐标与address的曼哈顿距离）；
²  order取值仅为 1 和 -1，1（表示升序）、-1（表示降序）。
例如 orderBy = [[3,1],[1,-1]] 表示先按照曼哈顿距离升序排列；若曼哈顿距离相同，再按照面积降序排列；若依然相同，则按编号升序排列。
queryRoom(int area, int price, int rooms, int[] address, int[][] orderBy)
 */
typedef struct {
    int id;
    int area;
    int price;
    int rooms;
    int *address;
    bool deleted;
}Room;
typedef struct {
    Room* roomArr;
    int rsize;

}Sys;
Sys * g_sys;
int g_param;
int g_order;
int g_param2;
int g_order2;
int *g_addr;
void RentingSystem(){
    g_sys=malloc(sizeof(Sys));
    Room* newRoom=malloc(sizeof(Room)*1001);
    newRoom->id=-1;
    newRoom->area=-1;
    newRoom->price=-1;
    newRoom->rooms=-1;
    int* address=malloc(sizeof(int)*2);
    memset(address,0,sizeof(int)*2);
    newRoom->address=address;
    newRoom->deleted=false;

    g_sys->roomArr=newRoom;
    g_sys->rsize=0;

    g_param=-1;
    g_order=0;
    g_param2=-1;
    g_order2=0;
    g_addr=malloc(sizeof(int)*2);
}
void addRoom(int id, int area, int price, int rooms, int address[]){

}
void deleteRoom(int id){
    for (int i = 0; i < g_sys->rsize; ++i){
        if( g_sys->roomArr[i].deleted=true){
            continue;
        }
        if(g_sys->roomArr[i].id==id){
            g_sys->roomArr[i].deleted=true;
        }
    }
}
int cmp(Room* a,Room* b){
    return a->id-b->id;
}
int mhd(int roomAddr[2]){
    int a=roomAddr[0]>g_addr[0]?roomAddr[0]-g_addr[0]:g_addr[0]-roomAddr[0];
    int b=roomAddr[1]>g_addr[1]?roomAddr[1]-g_addr[1]:g_addr[1]-roomAddr[1];
    return a+b;
}
int cmp2(Room* a,Room* b){
    int aval;
    int bval;
    if(g_param==1){
        aval=a->area;
        bval=b->area;
    }else if(g_param==2){
        aval=a->price;
        bval=b->price;
    }else if(g_param==3){
        aval=mhd(a->address);
        bval=mhd(b->address);
    }
    int aaval;
    int bbval;
    if(g_param2==1){
        aaval=a->area;
        bbval=b->area;
    }else if(g_param2==2){
        aaval=a->price;
        bbval=b->price;
    }else if(g_param2==3){
        aaval=mhd(a->address);
        bbval=mhd(b->address);
    }
    if(aval==bval){
        if(aaval==bbval){
            return a->id-b->id;
        }
        return g_order2==1?aaval-bbval:bbval-aaval;
    }
    return g_order==1?aval-bval:bval-aval;
}
Room* queryRoom(int area, int price, int rooms, int address[2], int** orderBy,int* returnSize){
    Room* roomPicked=malloc(sizeof(Room)*(g_sys->rsize));
    int roomPickedSize=0;
    for (int i = 0; i < g_sys->rsize; ++i){
        if(rooms==g_sys->roomArr[i].rooms && area>=g_sys->roomArr[i].area && price<=g_sys->roomArr[i].price){
            roomPicked[roomPickedSize++]=g_sys->roomArr[i];
        }
    }
    if(orderBy==NULL){
        qsort(roomPicked,roomPicked,sizeof(Room),cmp);
    } else {
        g_param=orderBy[0][0];
        g_order=orderBy[1][0];
        g_param2=orderBy[0][1];
        g_order2=orderBy[1][1];
        g_addr[0]=address[0];
        g_addr[1]=address[1];
        qsort(roomPicked,roomPicked,sizeof(Room),cmp2);
    }
    *returnSize=roomPickedSize;
    return roomPicked;
}
int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}