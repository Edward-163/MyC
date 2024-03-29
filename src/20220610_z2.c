#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
/*
 某城市有一个共享单车管理系统，可用一棵树表示，其中包含了仓库和租借点两种节点：
l  根节点为仓库，能存放和提供不限量的共享单车；
l  其余为租借点，可以租赁和归还共享单车。
请你实现管理系统的如下功能：
Ø  BikeManager(int[] preNode, int capacity) —— 初始化系统。
l  共有 preNode.length 个节点，节点编号从 0 开始；节点 0 是根节点仓库，其他节点为租借点。
l  preNode[i] 表示节点 i 的父节点编号，preNode[0] 约定为 -1。
l  租借点的容量为 capacity，初始时均有 ⌊capacity / 2⌋ 辆共享单车。
Ø  rentBikes(int nodeId, int num) —— 在租借点 nodeId 处租借出 num 辆共享单车，返回借出后此节点剩余的共享单车数量。
l  若节点 nodeId 处的共享单车不足 num 辆，则不足的部分向其父节点索取，这一过程将向其父节点递归求解，直到成功借出。
Ø  returnBikes(int nodeId, int num) —— 在租借点 nodeId 处归还 num 辆共享单车，返回归还后此节点的共享单车数量。
l  若节点 nodeId 放满共享单车后还有剩余，则将多余的共享单车归还到其父节点，这一过程同样将向其父节点递归求解，直到成功归还。
Ø  reset() —— 重置租借点的共享单车数量，并返回被重置的节点数量。对于当前共享单车数量为 0 或者 capacity 的租借点，将它们的共享单车数量重置为 ⌊capacity / 2⌋，其他节点不重置。
Ø  getTop5Nodes() —— 按规则返回 top 5 的租借点编号，若租借点不足 5 个则按实际数量返回。规则：优先按剩余单车数量降序；若数量相同，则按编号升序。
注意：⌊ x ⌋ 表示向下取整，即floor(x)。
示例 1：
输入：
["BikeManager","rentBikes","returnBikes","reset","getTop5Nodes"]
[[[-1,0,0,0],10],[1,3],[2,6],[],[]]
输出：[null,2,10,1,[2,3,1]]
解释：
BikeManager sys = BikeManager([-1,0,0,0],10); // 初始化。除仓库外，其余节点初始有 5 辆共享单车，容量为 10。
根节点 0 值为 -1，其他节点 1、2、3的值均为 0，表示这些节点均挂在根节点 0 下。
sys.rentBikes(1,3); // 节点 1 借出 3 辆共享单车。返回 2。
sys.returnBikes(2,6); // 在节点 2 归还 6 辆共享单车，节点 2 只能收 5 辆，多出的 1 辆归还到其父节点（仓库节点 0）。返回 10。
sys.reset(); // 节点 2 的共享单车数量为 10，因此数量被重置为 5，返回 1。
sys.getTop5Nodes(); // 注意返回的是top 5 的租借点，不包含根节点。当前节点 1、2、3 的单车数量分别为 2、5、5，按照规则返回节点编号为 [2,3,1]，因为不足 5 个，按实际数量返回 3 个。
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
仓库和租借点连接关系示意图：
image.png
示例 2：
输入：
["BikeManager","rentBikes","rentBikes","getTop5Nodes","returnBikes","rentBikes","reset","rentBikes","getTop5Nodes"]
[[[-1,0,1,1,5,0,1,0],41],[2,31],[3,45],[],[5,29],[5,100],[],[3,12],[]]
输出：[null,0,0,[4,5,6,7,1],41,0,4,8,[1,2,4,5,6]]
解释：
BikeManager sys = BikeManager([-1,0,1,1,5,0,1,0],41); // 初始化。除仓库外，其余节点初始有 20 辆共享单车，容量为 41。
sys.rentBikes(2,31); // 20 辆来自节点 2，11 辆来自节点 1。返回 0。
sys.rentBikes(3,45); // 20 辆来自节点 3，9 辆来自节点 1，16 辆来自仓库（节点 0）。返回 0。
sys.getTop5Nodes(); // 返回 [4,5,6,7,1]。
sys.returnBikes(5,29); // 21 辆存入节点 5，8 辆存入仓库。返回 41。
sys.rentBikes(5,100); // 41 辆来自节点 5，59 辆来自仓库。返回 0。
sys.reset(); // 节点 1，2，3，5 均被重置为存有 20 辆共享单车。返回 4。
sys.rentBikes(3,12); // 返回 8。
sys.getTop5Nodes(); // 节点1-7所剩的单车数分别为[20,20,8,20,20,20,20]。返回 [1,2,4,5,6]。
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
仓库和租借点连接关系示意图：
image.png
提示：
1 <= RentBikes, ReturnBikes, Reset, GetTop5Nodes 总操作次数 <= 1000，GetTop5Nodes 操作次数不超过 100
2 <= preNode.length <= 2000，-1 <= preNode[i] < preNode.length，输入保证为一棵树
1 <= nodeId < preNode.length
1 <= num < 10000
2 <= capacity < 10000
 */
int *g_left;
int *g_parent;
int g_size;
int g_cap;

// —— 初始化系统.
void BikeManager(int *preNode, int psize, int capacity)
{
    g_parent = preNode;
    g_size = psize;
    g_cap = capacity;
    g_left = malloc(sizeof(int) * psize);
    for (int i = 1; i < psize; i++) {
        g_left[i] = capacity / 2;
    }
}

// 共有 preNode.length 个节点，节点编号从 0 开始；节点 0 是根节点仓库，其他节点为租借点。
// preNode[i] 表示节点 i 的父节点编号，preNode[0] 约定为 -1。
// 租借点的容量为 capacity，初始时均有 ⌊capacity / 2⌋ 辆共享单车。
// —— 在租借点 nodeId 处租借出 num 辆共享单车，返回借出后此节点剩余的共享单车数量.
int rentBikes(int nodeId, int num)
{
    // 需要int* left
    if (num > g_left[nodeId]) {
        rentBikes(g_parent[nodeId], num - g_left[nodeId]);
        g_left[nodeId] = 0;
    } else {
        g_left[nodeId] -= num;
    }
    return g_left[nodeId];
}

// 若节点 nodeId 处的共享单车不足 num 辆，则不足的部分向其父节点索取，这一过程将向其父节点递归求解，直到成功借出。
// —— 在租借点 nodeId 处归还 num 辆共享单车，返回归还后此节点的共享单车数量.
int returnBikes(int nodeId, int num)
{
    // 需要随时可以访问的(记录父子关系)数组
    if (num > g_cap - g_left[nodeId]) {
        returnBikes(g_parent[nodeId], num - (g_cap - g_left[nodeId]));
        g_left[nodeId] = g_cap;
    } else {
        g_left[nodeId] += num;
    }
    return g_left[nodeId];
}

// 若节点 nodeId 放满共享单车后还有剩余，则将多余的共享单车归还到其父节点，这一过程同样将向其父节点递归求解，直到成功归还。
// —— 重置租借点的共享单车数量，并返回被重置的节点数量。对于当前共享单车数量为 0 或者 capacity 的租借点，将它们的共享单车数量重置为 ⌊capacity / 2⌋，其他节点不重置.
int reset()
{
    int ans = 0;
    for (int i = 1; i < g_size; i++) {
        if (g_left[i] == 0 || g_left[i] == g_cap) {
            g_left[i] = g_cap / 2; // 2 divide
            ans++;
        }
    }
    return ans;
}

typedef struct {
    int idx;
    int leftnum;
} Ele;

int cmp(Ele *a, Ele *b)
{
    if (a->leftnum == b->leftnum) {
        return a->idx - b->idx;
    }
    return b->leftnum - a->leftnum;
}

// —— 按规则返回 top 5 的租借点编号，若租借点不足 5 个则按实际数量返回。规则：优先按剩余单车数量降序；若数量相同，则按编号升序.
int *getTop5Nodes(int *rsize)
{
    // 直接用left排序,因为不确定(没研究过qsort的源码)left[i]与left[i+1]相等时,会不会改动i与i+1的顺序,先试一下
    Ele *eles = malloc(sizeof(Ele) * (g_size - 1));
    for (int i = 1; i < g_size; i++) {
        Ele ele = {i, g_left[i]};
        eles[i - 1] = ele;
    }
    qsort(eles, g_size - 1, sizeof(Ele), cmp);
    int *ans = malloc(sizeof(int) * (g_size - 1));
    int min = g_size - 1 > 5 ? 5 : g_size - 1; // 5 top5
    for (int i = 0; i < min; ++i) {
        ans[i] = eles[i].idx;
    }
    *rsize = min;
    return ans;
}

int main()
{
    // @formatter:off
    // 差不多一个小时,写完加调试,幸运的是直接过,
    // ["BikeManager","rentBikes","returnBikes","reset","getTop5Nodes"]
    // [[[-1,0,0,0],10],[1,3],[2,6],[],[]]
    // 输出：[null,2,10,1,[2,3,1]]
    int prenode[]={-1,0,0,0};
    int psize=sizeof(prenode)/sizeof(prenode[0]);
    int cap=10;
    BikeManager(prenode,psize,cap);printf("null \n");fflush(stdout);
    printf("%d \n",rentBikes(1,3));fflush(stdout);
    printf("%d \n",returnBikes(2,6));fflush(stdout);
    printf("%d \n",reset());fflush(stdout);
    int rsize;
    int *ans = getTop5Nodes(&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d ",ans[i]);fflush(stdout);
    }
    printf("-------------\n");fflush(stdout);


    // ["BikeManager","rentBikes","rentBikes","getTop5Nodes","returnBikes","rentBikes","reset","rentBikes","getTop5Nodes"]
    // [[[-1,0,1,1,5,0,1,0],41],[2,31],[3,45],[],[5,29],[5,100],[],[3,12],[]]
    // 输出：[null,0,0,[4,5,6,7,1],41,0,4,8,[1,2,4,5,6]]
    
    int prenode2[]={-1,0,1,1,5,0,1,0}; // C语言不好复用数组??
    psize=sizeof(prenode2)/sizeof(prenode2[0]);
    cap=41;
    BikeManager(prenode2,psize,cap);printf("null \n");fflush(stdout);
    printf("%d \n",rentBikes(2,31));fflush(stdout);
    printf("%d \n",rentBikes(3,45));fflush(stdout);
    ans = getTop5Nodes(&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d ",ans[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    printf("%d \n",returnBikes(5,29));fflush(stdout);
    printf("%d \n",rentBikes(5,100));fflush(stdout);
    printf("%d \n",reset());fflush(stdout);
    printf("%d \n",rentBikes(3,12));fflush(stdout);
    ans = getTop5Nodes(&rsize);
    for (int i = 0; i < rsize; ++i){
        printf("%d ",ans[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    return 0;
    // @formatter:on
}