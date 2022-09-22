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
Ø  排序要求：按orderBy中的排序条件依次进行排序；若按orderBy排序结果仍相同（含orderBy为空???），则按房源编号升序排列。
orderBy的元素格式为 [parameter,order]。
²  parameter取值范围[1,3]， 1（表示 area）、2（表示 price）、3（表示房源坐标与address的曼哈顿距离）；
²  order取值仅为 1 和 -1，1（表示升序）、-1（表示降序）。
例如 orderBy = [[3,1],[1,-1]] 表示先按照曼哈顿距离升序排列；若曼哈顿距离相同，再按照面积降序排列；若依然相同，则按编号升序排列。
queryRoom(int area, int price, int rooms, int[] address, int[][] orderBy)
 示例 1：
输入：
["RentingSystem","addRoom","addRoom","queryRoom","deleteRoom"]
[[],[3,24,200,2,[0,1]],[1,10,400,2,[1,0]],[1,400,2,[1,1],[[3,1],[2,-1]]],[3]]
输出：[null,true,true,[1,3],true]
解释：
RentingSystem obj = RentingSystem();
obj.addRoom(3,24,200,2,[0,1]); // 在系统中添加编号为 3，面积为 24，月租金为 200，卧室数为 2，坐标为 [0,1] 的房源，返回 true
obj.addRoom(1,10,400,2,[1,0]); // 在系统中添加编号为 1，面积为 10，月租金为 400，卧室数为 2，坐标为 [1,0] 的房源，返回 true
obj.queryRoom(1,400,2,[1,1],[[3,1],[2,-1]]); // 查询系统中面积大于等于 1，月租金小于等于 400，卧室数为 2 的房源，查询所在地坐标为 [1,1]，先按照距离升序排序，结果相同，再按照月租金降序排序，编号为 1 的月租金大于编号为 3 的月租金，所以返回 [1,3]
obj.deleteRoom(3); // 删除编号为 3 的房源，返回 true
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
 
示例 2：
输入：
["RentingSystem","deleteRoom","addRoom","addRoom","addRoom","addRoom","addRoom","addRoom","queryRoom","queryRoom"]
[[],[10],[3,24,200,2,[0,1]],[3,24,500,2,[0,1]],[3,27,500,4,[1,1]],[1,27,500,4,[20,43]],[6,35,227,4,[2,4]],[9,20,3540,4,[4,321]],[25,900,4,[10,1],[[1,1],[2,-1],[3,1]]],[25,900,4,[10,1],[]]]
输出：[null,false,true,false,false,true,true,true,[3,1,6],[1,3,6]]
解释：
RentingSystem obj = RentingSystem();
obj.deleteRoom(10); // 返回 false
obj.addRoom(3,24,200,2,[0,1]); // 返回 true
obj.addRoom(3,24,500,2,[0,1]); // 返回 false
obj.addRoom(3,27,500,4,[1,1]); // 返回 false
obj.addRoom(1,27,500,4,[20,43]) // 返回 true
obj.addRoom(6,35,227,4,[2,4]) // 返回 true
obj.addRoom(9,20,3540,4,[4,321]) // 返回 true
obj.queryRoom(25,900,4,[10,1],[[1,1],[2,-1],[3,1]]) // 查询系统中面积大于等于 25，月租金小于等于 900，卧室数为 4 的房源，先按照面积升序排列，接着按月租金降序排列，最后按曼哈顿距离升序排列。返回 [3,1,6]。
obj.queryRoom(25,900,4,[10,1],[]) // 查询系统中面积大于等于 25，月租金小于等于 900，卧室数为 4 的房源，由于orderBy为空，则按房源编号升序排列。返回 [1,3,6]。
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
 
提示：
3 <= addRoom, deleteRoom, queryRoom 累计操作数 <= 1000
1 <= id <= 1000
1 <= area <= 1000
1 <= price <= 10^4
1 <= rooms <= 10
address.length == 2
0 <= address[0], address[1] <= 10^4
0 <= orderBy.length <= 3, orderBy[i].length == 2
1 <= orderBy[i][0] <= 3
orderBy[i][1] == -1 or 1
若 i != j 则 orderBy[i][0] != orderBy[j][0]
曼哈顿距离：地址1(x1, y1) 与 地址2(x2, y2)的曼哈顿距离，计算公式 = |x1 - x2| + |y1 - y2|。
 */
typedef struct {
    bool valid;
    int area;
    int price;
    int rooms;
    int addr[2];
} RentingSystem;
#define CAP 1001
#define ABS(a) (a) > 0 ? (a) : -(a)     // stdlib.h中有abs(int i)
int order[3] = {0};
RentingSystem *rs = NULL;
RentingSystem *RentingSystemCreate()
{
    RentingSystem *rentSys = (RentingSystem *)malloc(sizeof(RentingSystem) * CAP);
    memset_s(rentSys, sizeof(RentingSystem) * CAP, 0, sizeof(RentingSystem) * CAP);
    return rentSys;
}
bool RentingSystemAddRoom(RentingSystem *obj, int id, int area, int price, int rooms, int *address, int addressSize)
{
    bool res = obj[id].valid ? false : true;
    obj[id].valid = true;
    obj[id].area = area;
    obj[id].price = price;
    obj[id].rooms = rooms;
    obj[id].addr[0] = address[0];
    obj[id].addr[1] = address[1];
    return res;
}
bool RentingSystemDeleteRoom(RentingSystem *obj, int id)
{
    if (obj[id].valid) {
        obj[id].valid = false;
        return true;
    } else {
        return false;
    }
}
int cmp(const void *a, const void *b)
{
    int *ai = (int *)a;
    int *bi = (int *)b;
    /// 要理解order[i]整个值只是int[4] rec[ridx]中的ridx
    if (order[0] != 0 && ai[ABS(order[0])] == bi[ABS(order[0])]) {
        if (order[1] != 0 && ai[ABS(order[1])] == bi[ABS(order[1])]) {
            return (ai[ABS(order[2])] - bi[ABS(order[2])]) * order[2];
        } else {
            return (ai[ABS(order[1])] - bi[ABS(order[1])]) * order[1];
        }
    } else {
        return (ai[ABS(order[0])] - bi[ABS(order[0])]) * order[0]; /// 为0,qsort就是"保持完全不动"??待证明
    }
}
/*
 * 输入orderBy是长度为orderBySize的数组指针的数组，其中每个元素也是一个数组，此数组长度固定为2。
 * 注意：返回的数组必须由实现者进行内存分配，由框架代码进行内存释放。
 * 返回的数组长度存在 *retSize 中。
 */
int *RentingSystemQueryRoom(RentingSystem *obj, int area, int price, int rooms, int *address, int addressSize, int **orderBy, int orderBySize, int *retSize)
{
    int i = 0;
    int cnt = 0;
    int rec[CAP][4] = {0}; /// 感觉{}仅仅是分配空间作用,附加全元素初始化??
    memset_s(order, sizeof(order), 0, sizeof(order));
    rs = obj;
    for (i = 0 ; i < CAP; i++) {
        if (obj[i].valid && obj[i].area >= area && obj[i].price <= price && obj[i].rooms == rooms) {
            /// 人家是先把要排序的字段计算好,再把核心的字段组合元素,用元素排序,"先计算再组装"比我的"先组装再排序"清晰多了
            rec[cnt][0] = i;
            rec[cnt][1] = obj[i].area;
            rec[cnt][2] = obj[i].price;
            rec[cnt][3] = (ABS(obj[i].addr[0] - address[0])) + (ABS(obj[i].addr[1] - address[1]));
            cnt++;
        }
    }
    *retSize = cnt;
    for (i = 0; i < orderBySize; i++) {
        order[i] = orderBy[i][0] * orderBy[i][1];
    }
    qsort(rec, cnt, sizeof(rec[0]), cmp);
    int *ret = (int *)malloc(sizeof(int) * cnt);
    for (i = 0; i < cnt; i++) {
        ret[i] = rec[i][0];
    }
    return ret;
}
void RentingSystemFree(RentingSystem *obj)
{
    free(obj);
}
int main()
{
    // @formatter:off
    /*["RentingSystem","addRoom","addRoom","queryRoom","deleteRoom"]
    [[],[3,24,200,2,[0,1]],[1,10,400,2,[1,0]],[1,400,2,[1,1],[[3,1],[2,-1]]],[3]]
    输出：[null,true,true,[1,3],true]
    */
    RentingSystem *obj = RentingSystemCreate();
    int address[]={0,1};
    int addrSize=sizeof(address)/sizeof(address[0]);
    RentingSystemAddRoom(obj,3,24,200,2,address,addrSize);
    int address2[]={1,0};
    int addrSize2=sizeof(address2)/sizeof(address2[0]);
    RentingSystemAddRoom(obj,1,10,400,2,address2,addrSize2);
    int arr[][2]={{3,1},{2,-1}};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    int* orderby[arrSize];
    for (int i = 0; i < arrSize; ++i){
        orderby[i]=arr[i];
    }
    int address3[]={1,1};
    int addrSize3=sizeof(address3)/sizeof(address3[0]);
    int retSize=0;
    int *ans = RentingSystemQueryRoom(obj,1,400,2,address3,addrSize3,orderby,arrSize,&retSize);
    for (int i = 0; i < retSize; ++i){
        printf("%d ",ans[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    return 0;
    // @formatter:on
}
