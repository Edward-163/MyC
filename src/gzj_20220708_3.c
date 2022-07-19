#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <uthash.h>


/*
有一个工厂具有多条流水线，流水线上均可生产多种产品，产品生产有一定的周期。完成 ProductionLineMgmtSys类。
①ProductionLineMgmtSys()函数为初始化函数，入参是流水线条数num，以及各编号产品的生产周期，在一个数组中periods中。

②Produce()函数为生产函数，入参是开始生产时间date，流水线编号assemblyId，以及产品编号productId。规则是：
 i)若该流水线未被占用，则从此开始生产 时间开始生产该编号的产品，并返回1；
 ii)若该流水线正在被占用，且恰好是同一产品，则该流水线继续生产该产品，并返回0；
 iii)若该流水线正在被占用，并且是 另外一种产品，则直接在此开始生产时间开始生产新的产品，并返回-1；
 iv)切换规则，比如上个产品在时刻2开始生产， 其生产周期为3，则在时刻8切换生产新的产 品时，上个产品已经生产了2个；而在时刻10切换生产新的产品时，由于最后一个产品还没有生产完全，丢弃最后一个，仍然只算成功生产2个。

③GetProductCount()函数为统计函数，入参是时刻date，以及产品编号productId，统计的是时刻date时，工厂生产编号为productId的产品的总数量，返回这个值。
注：保证date是递增的。
 最恶心的是这里,论坛上分享的没有数据,题目意思结果全靠猜,而且tm的题目的描述坛友还不是全记下来,只是模糊记得
 ["ProductionLineMgmtSys","produce","getProductCount","getProductCount"]
[[2,[1,3]],[0,1,1],[8,1],[9,1]]
[null,1,2,3]
["ProductionLineMgmtSys","produce","produce","getProductCount","produce","produce","getProductCount","produce","produce","produce","getProductCount","produce"]
[[5,[1,4,5,8,2,3]],[0,1,0],[1,1,5], [4,0], [5,0,5],[7,0,0],[7,5],[8,1,5],[8,4,0],[9,1,0],[10,0],[1000,4,0]]
[null,1,-1, 1, 1,-1,2,0,1,-1,7,0]
 */
// 某工厂有多条只能生产线，每条生产线都可生产出不同型号的产品，请设计一个生产线管理系统 初始化生产线和产品的生命周期
// num生产线数量，periods下标是产品编号，内容是每个产品需要的生产周期，如period[0]=3 指的是0号产品需要3天才能生产出1个
typedef struct {
    int productId;
    int date; // 记录当前prodId从date这天开始生产的
} Assem;
typedef struct {
    Assem *asseArr;
    int num;
    int *periods;
    int *prodCount;
} Sys;
Sys *g_sys;

ProductionLineMgmtSys(int num, int *periods, int periodSize)
{
    g_sys = malloc(sizeof(Sys));
    Assem *asseArr = malloc(sizeof(Assem) * num); // idx==asseId val==struct(prodId+date)
    for (int i = 0; i < num; ++i) {
        asseArr[i].productId = -1;
    }
    g_sys->asseArr = asseArr;
    g_sys->num = num;
    g_sys->periods = periods;
    int *prodCount = malloc(sizeof(int) * periodSize);
    memset(prodCount, 0, sizeof(int) * periodSize);
    g_sys->prodCount = prodCount;
    return g_sys;
}

// i)若该流水线未被占用，则从此开始生产 时间开始生产该编号的产品，并返回1；
// ii)若该流水线正在被占用，且恰好是同一产品，则该流水线继续生产该产品，并返回0；
// iii)若该流水线正在被占用，并且是 另外一种产品，则直接在此开始生产时间开始生产新的产品，并返回-1；
produce(int date, int assemblyId, int productId)
{
    if (g_sys->asseArr[assemblyId].productId == -1) {
        g_sys->asseArr[assemblyId].productId = productId;
        g_sys->asseArr[assemblyId].date = date;
        return 1;
    } else if (g_sys->asseArr[assemblyId].productId == productId) {
        return 0;
    } else {
        // 切换prodId时候,需要把旧的prodId计算下产量
        int datediff = date - g_sys->asseArr[assemblyId].date;
        int lifecycle = g_sys->periods[g_sys->asseArr[assemblyId].productId];
        int num = datediff / lifecycle;
        g_sys->prodCount[g_sys->asseArr[assemblyId].productId] += num;
        g_sys->asseArr[assemblyId].productId = productId;
        g_sys->asseArr[assemblyId].date = date;
        return -1;
    }
}

getProductCount(int date, int productId)
{
    int lifecycle = g_sys->periods[productId];
    int sum = 0;
    for (int i = 0; i < g_sys->num; ++i) {
        if (g_sys->asseArr[i].productId == productId) {
            int datediff = date - g_sys->asseArr[i].date;
            int num = datediff / lifecycle;
            sum += num;
        }
    }
    return sum + g_sys->prodCount[productId];
}

int main()
{
    // @formatter:off
    // ["ProductionLineMgmtSys","produce","getProductCount","getProductCount"]
    // [[2,[1,3]],[0,1,1],[8,1],[9,1]]
    // [null,1,2,3]
    // int periods[]={1,3};
    // int size=sizeof(periods)/sizeof(periods[0]);
    // ProductionLineMgmtSys(2,periods,size);
    // printf("%d \n",produce(0,1,1));fflush(stdout);
    // printf("%d \n",getProductCount(8,1));fflush(stdout);
    // printf("%d \n",getProductCount(9,1));fflush(stdout);

    // ["ProductionLineMgmtSys","produce","produce","getProductCount","produce","produce","getProductCount","produce","produce","produce","getProductCount","produce"]
    // [[5,[1,4,5,8,2,3]],[0,1,0],[1,1,5], [4,0], [5,0,5],[7,0,0],[7,5],[8,1,5],[8,4,0],[9,1,0],[10,0],[1000,4,0]]
    // [null,1,-1, 1, 1,-1,2,0,1,-1,7,0]
    int periods[]={1,4,5,8,2,3};
    int size=sizeof(periods)/sizeof(periods[0]);
    ProductionLineMgmtSys(5,periods,size);
    printf("%d \n",produce(0,1,0));fflush(stdout);
    printf("%d \n",produce(1,1,5));fflush(stdout);
    printf("%d \n",getProductCount(4,0));fflush(stdout);
    printf("%d \n",produce(5,0,5));fflush(stdout);
    printf("%d \n",produce(7,0,0));fflush(stdout);
    printf("%d \n",getProductCount(7,5));fflush(stdout);
    printf("%d \n",produce(8,1,5));fflush(stdout);
    printf("%d \n",produce(8,4,0));fflush(stdout);
    printf("%d \n",produce(9,1,0));fflush(stdout);
    printf("%d \n",getProductCount(10,0));fflush(stdout);
    printf("%d \n",produce(1000,4,0));fflush(stdout);
    return 0;
    // @formatter:on
}