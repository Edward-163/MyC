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
②Produce()函数为生产函数，入参是开始生产时间date，流水线编号assemblyId，以及产品编号productId。规则是：i)若该流水线未被占用，则从此开始生产
 时间开始生产该编号的产品，并返回1；ii)若该流水线正在被占用，且恰好是同一产品，则该流水线继续生产该产品，并返回0；iii)若该流水线正在被占用，并且是
 另外一种产品，则直接在此开始生产时间开始生产新的产品，并返回-1；iv)切换规则，比如上个产品在时刻2开始生产，其生产周期为3，则在时刻8切换生产新的产
 品时，上个产品已经生产了2个；而在时刻10切换生产新的产品时，由于最后一个产品还没有生产完全，丢弃最后一个，仍然只算成功生产2个。
③GetProductCount()函数为统计函数，入参是时刻date，以及产品编号productId，统计的是时刻date时，工厂生产编号为productId的产品的总数量，返回这个值。
注：保证date是递增的。
 */
// 某工厂有多条只能生产线，每条生产线都可生产出不同型号的产品，请设计一个生产线管理系统 初始化生产线和产品的生命周期
// num生产线数量，periods下标是产品编号，内容是每个产品需要的生产周期，如period[0]=3 指的是0号产品需要3天才能生产出1个
typedef struct{
    int num;
    int idle;
    int* periods;
    int productId;
}Sys;
ProductionLineMgmtSys(int num, int* periods){
    Sys* s=malloc(sizeof(Sys));
    s->num=num;
    s->idle=-1;
    s->periods = periods;
    return s;
}
int g_date;
// 在生产线assemblyId上，从日期date开始持续生产型号productID的产品 assemblyid是生产线编号
produce(int date, int assemblyId, int productId){

}
// 生产线空闲，开始生产，返回1；生产线在生产该产品，忽略此指令，返回0；在生产别的产品，立刻切换，返回-1；查询截止到date（含），累计生产完成型号productID的产品和数量，返回数量
getProductCount(int date, int productId){

}

int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}