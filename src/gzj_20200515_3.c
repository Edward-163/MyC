#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 请你完善一个火车票查询系统，补齐如下函数。
火车票价计算公式为基本运营成本 + 里程浮动成本*里程(km)。 而基本运营成本与里程浮动成本分为二等座(economy)、一等座(premium)、商务座(business) ，以及淡季(slack)与旺季(peak)。请你完善如下火车票查询系统。


typedef struct {

} RailwayTicket;

RailwayTicket* RailwayTicketCreate(){}

// 按坐票等级与时段向系统加入基础运营成本与里程浮动成本，如果系统中已经存在此坐票等级与时段的信息则添加失败，返回-1；添加成功则返回1。
int RailwayTicketAdd(RailwayTicket* obj, char* level, char* period, int basicCost, int floatingCost){}

// 按坐票等级与时段向系统修改基础运营成本， 如果系统中不存在此坐票等级与时段的信息则修改失败，返回-1；修改成功则返回修改前的值。
int RailwayTicketUpdateBasicCost(RailwayTicket* obj, char* level, char* period, int basicCost){}

// 按坐票等级与时段向系统修改里程浮动成本， 如果系统中不存在此坐票等级与时段的信息则修改失败，返回-1；修改成功则返回修改前的值。
int RailwayTicketUpdateFloatingCost(RailwayTicket* obj, char* level, char* period, int floatingCost){}

// 按坐票等级删除票价信息， 如果系统中不存在此坐票等级则修改失败，返回-1；修改成功则返回1。
int RailwayTicketRemove(RailwayTicket* obj, char* level){}

// 按坐票等级与时段查询票价， 如果系统中不存在此坐票等级与时段的信息则返回-1；否则按火车票价计算公式返回票价。
int RailwayTicketQuery(RailwayTicket* obj, char* level, char* period, int distance){}

void RailwayTicketFree(RailwayTicket* obj) {}
 */
#define LEVEL 3
#define PERIOD 2
typedef struct {
    int basic[LEVEL][PERIOD];
    int floa[LEVEL][PERIOD];
} RailwayTicket;

RailwayTicket *RailwayTicketCreate()
{
    RailwayTicket *obj = malloc(sizeof(RailwayTicket));
    for (int a = 0; a < LEVEL; ++a) {
        for (int b = 0; b < PERIOD; ++b) {
            obj->basic[a][b] = -1;
            obj->floa[a][b] = -1;
        }
    }
    return obj;
}

int toInt(char *str)
{
    if (strcmp(str, "economy") == 0 || strcmp(str, "slack") == 0) {
        return 0;
    }
    if (strcmp(str, "preminum") == 0 || strcmp(str, "peak") == 0) {
        return 1;
    }
    if (strcmp(str, "business") == 0) {
        return 2;
    }
}

// 按坐票等级与时段向系统加入基础运营成本与里程浮动成本，如果系统中已经存在此坐票等级与时段的信息则添加失败，返回-1；添加成功则返回1。
int RailwayTicketAdd(RailwayTicket *obj, char *level, char *period, int basic, int floa)
{
    if (obj->basic[toInt(level)][toInt(period)] != -1) {
        return -1;
    }
    obj->basic[toInt(level)][toInt(period)] = basic;
    obj->floa[toInt(level)][toInt(period)] = floa;
    return 1;
}

// 按坐票等级与时段向系统修改基础运营成本， 如果系统中不存在此坐票等级与时段的信息则修改失败，返回-1；修改成功则返回修改前的值。
int RailwayTicketUpdateBasicCost(RailwayTicket *obj, char *level, char *period, int basic)
{
    if (obj->basic[toInt(level)][toInt(period)] == -1) {
        return -1;
    }
    int tmp = obj->basic[toInt(level)][toInt(period)];
    obj->basic[toInt(level)][toInt(period)] = basic;
    return tmp;
}

// 按坐票等级与时段向系统修改里程浮动成本， 如果系统中不存在此坐票等级与时段的信息则修改失败，返回-1；修改成功则返回修改前的值。
int RailwayTicketUpdateFloatingCost(RailwayTicket *obj, char *level, char *period, int floa)
{
    if (obj->basic[toInt(level)][toInt(period)] == -1) {
        return -1;
    }
    int tmp = obj->floa[toInt(level)][toInt(period)];
    obj->floa[toInt(level)][toInt(period)] = floa;
    return tmp;
}

// 按坐票等级删除票价信息， 如果系统中不存在此坐票等级则修改失败，返回-1；修改成功则返回1。
int RailwayTicketRemove(RailwayTicket *obj, char *level)
{
    for (int i = 0; i < PERIOD; ++i) {
        if (obj->basic[toInt(level)][i] != -1) {
            return 1;
        }
    }
    return -1;
}

// 按坐票等级与时段查询票价， 如果系统中不存在此坐票等级与时段的信息则返回-1；否则按火车票价计算公式返回票价。
int RailwayTicketQuery(RailwayTicket *obj, char *level, char *period, int distance)
{
    if()
    int basic = obj->basic[toInt(level)][toInt(period)];
    int floa = obj->floa[toInt(level)][toInt(period)];
    return basic + floa * distance;
}

void RailwayTicketFree(RailwayTicket *obj)
{
    free(obj);
}

int main()
{
    // @formatter:off
    char cpy[99];
    printf("%s \n",strcpy(cpy,"hyj"));fflush(stdout);
    printf("%d \n",strcmp(cpy,"hyj"));fflush(stdout);

    RailwayTicket *r = RailwayTicketCreate();
    char economy[] = "economy";
    char premium[] = "premium";
    char business[] = "business";
    char slack[] = "slack";
    char peak[] = "peak";

//    //char father[] = "annabelle";
//    int g_arr[3][2][2];
//    g_arr[3][2][2] = r->g_arr;/// no 看上去可以,但打印出来的值全是乱的
//
////    int arr2[3][2][2]= r->g_arr;/// no
//
//    for (int a = 0; a < 3; ++a) {
//        for (int b = 0; b < 2; ++b) {
//            for (int c = 0; c < 2; ++c) {
//                printf("%d ", g_arr[a][b][c]);
//                fflush(stdout);
////                printf("%d ",r->g_arr[a][b][c]);fflush(stdout);/// 这种可以
//            }
//            printf("|");
//            fflush(stdout);
//        }
//        printf("\n");
//        fflush(stdout);
//    }



    // 成功加入坐票等级 "economy" 的 "slack" 时段，运营成本为 0，里程浮动成本为 2
    int a = RailwayTicketAdd(r, economy, slack, 0, 2);
    printf("%d ", a);fflush(stdout);

    // 成功加入坐票等级 "economy" 的 "peak" 时段，运营成本为 10，里程浮动成本为 2
    a = RailwayTicketAdd(r, economy, peak, 10, 2);
    printf("%d ", a);fflush(stdout);

    // 成功加入坐票等级 "business" 的 "slack" 时段，运营成本为 20，里程浮动成本为 2
    a = RailwayTicketAdd(r, business, slack, 20, 2);
    printf("%d ", a);fflush(stdout);

    // 成功加入坐票等级 "business" 的 "peak" 时段，运营成本为 50，里程浮动成本为 4
    a = RailwayTicketAdd(r, business, peak, 50, 4);
    printf("%d ", a);fflush(stdout);

    // 系统中已存在坐票等级 "business" 在 "peak" 时段的运营成本为与里程浮动成本，返回 -1
    a = RailwayTicketAdd(r, business, peak, 50, 6);
    printf("%d ", a);fflush(stdout);

    // "economy" 等级的 "slack" 时段运营成本从 0 元/千米变更为 8 元/千米，返回 0
    a = RailwayTicketUpdateBasicCost(r, economy, slack, 8);
    printf("%d ", a);fflush(stdout);

    // 系统中没有 "premium" 等级，返回 -1
    a = RailwayTicketUpdateBasicCost(r, premium, slack, 3);
    printf("%d ", a);fflush(stdout);

    // "economy" 等级的 "slack" 时段里程浮动成本从 2 元/千米变更为 3 元/千米，返回 2
    a = RailwayTicketUpdateFloatingCost(r, economy, slack, 3);
    printf("%d ", a);fflush(stdout);

    // 删除 "economy" 等级相关信息，返回 1
    a = RailwayTicketRemove(r, economy);
    printf("%d ", a);fflush(stdout);

    // 系统中没有 "premium" 等级，返回 -1
    a = RailwayTicketRemove(r, premium);
    printf("%d ", a);fflush(stdout);

    // 系统中没有 "economy" 等级，返回 -1
    a = RailwayTicketQuery(r, economy, slack, 100);
    printf("%d ", a);fflush(stdout);

    // 50 + 4*100 = 450
    a = RailwayTicketQuery(r, business, peak, 100);
    printf("%d ", a);fflush(stdout);

    RailwayTicketFree(r);
    return 0;
    // @formatter:on
}

/*
 	#include <stdio.h>
	#include <string.h>
	#include "securec.h"
	#include "../../../cstl/hlist.h"
	#define LEVEL_ECO 0
	#define LEVEL_PRE 1
	#define LEVEL_BUS 2
	#define SLACK 0
	#define PEAK 1

	typedef struct {
	    int basic_cost[3][2];
	    int float_cost[3][2];
	    bool level[3][2];
	} RailwayTicket;

	RailwayTicket* RailwayTicketCreate()
	{
	    RailwayTicket *MyRailway = (RailwayTicket *)malloc(sizeof(RailwayTicket));
	    for (int i = LEVEL_ECO; i <= LEVEL_BUS; i++) {
	        MyRailway->level[i][SLACK] = false;
	        MyRailway->level[i][PEAK] = false;
	        MyRailway->basic_cost[i][SLACK] = 0;
	        MyRailway->basic_cost[i][PEAK] = 0;
	        MyRailway->float_cost[i][SLACK] = 0;
	        MyRailway->float_cost[i][PEAK] = 0;
	    }
	    return MyRailway;
	}
	int RailwayTicketAdd(RailwayTicket* obj, char* level, char* period, int basicCost, int floatingCost)
	{
	    int levelNum, periodNum;
	    if (strcmp(level, "economy") == 0) {
	        levelNum = LEVEL_ECO;
	    } else if (strcmp(level, "premium") == 0) {
	        levelNum = LEVEL_PRE;
	    } else if (strcmp(level, "business") == 0) {
	        levelNum = LEVEL_BUS;
	    } else {
	        return -1;
	    }
	    if (strcmp(period, "slack") == 0) {
	        periodNum = SLACK;
	    } else if (strcmp(period, "peak") == 0) {
	        periodNum = PEAK;
	    } else {
	        return -1;
	    }
	    if (obj->level[levelNum][periodNum] == true) {
	        return -1;
	    }
	    obj->level[levelNum][periodNum] = true;
	    obj->float_cost[levelNum][periodNum] = floatingCost;
	    obj->basic_cost[levelNum][periodNum] = basicCost;
	    return 1;
	}
	int RailwayTicketUpdateBasicCost(RailwayTicket* obj, char* level, char* period, int basicCost)
	{
	    int levelNum, periodNum;
	    if (strcmp(level, "economy") == 0) {
	        levelNum = LEVEL_ECO;
	    } else if (strcmp(level, "premium") == 0) {
	        levelNum = LEVEL_PRE;
	    } else if (strcmp(level, "business") == 0) {
	        levelNum = LEVEL_BUS;
	    } else {
	        return -1;
	    }
	    if (strcmp(period, "slack") == 0) {
	        periodNum = SLACK;
	    } else if (strcmp(period, "peak") == 0) {
	        periodNum = PEAK;
	    } else {
	        return -1;
	    }
	    if (obj->level[levelNum][periodNum] == false) {
	        return -1;
	    }
	    int oldValue = obj->basic_cost[levelNum][periodNum];
	    obj->basic_cost[levelNum][periodNum] = basicCost;
	    return oldValue;
	}
	int RailwayTicketUpdateFloatingCost(RailwayTicket* obj, char* level, char* period, int floatingCost)
	{
	    int levelNum, periodNum;
	    if (strcmp(level, "economy") == 0) {
	        levelNum = LEVEL_ECO;
	    } else if (strcmp(level, "premium") == 0) {
	        levelNum = LEVEL_PRE;
	    } else if (strcmp(level, "business") == 0) {
	        levelNum = LEVEL_BUS;
	    } else {
	        return -1;
	    }
	    if (strcmp(period, "slack") == 0) {
	        periodNum = SLACK;
	    } else if (strcmp(period, "peak") == 0) {
	        periodNum = PEAK;
	    } else {
	        return -1;
	    }
	    if (obj->level[levelNum][periodNum] == false) {
	        return -1;
	    }
	    int oldValue = obj->float_cost[levelNum][periodNum];
	    obj->float_cost[levelNum][periodNum] = floatingCost;
	    return oldValue;
	}
	int RailwayTicketRemove(RailwayTicket* obj, char* level)
	{
	    int levelNum;
	    if (strcmp(level, "economy") == 0) {
	        levelNum = LEVEL_ECO;
	    } else if (strcmp(level, "premium") == 0) {
	        levelNum = LEVEL_PRE;
	    } else if (strcmp(level, "business") == 0) {
	        levelNum = LEVEL_BUS;
	    } else {
	        return -1;
	    }
	    if ((obj->level[levelNum][SLACK] == false) && (obj->level[levelNum][PEAK] == false)) {
	        return -1;
	    }
	    obj->level[levelNum][SLACK] = false;
	    obj->level[levelNum][PEAK] = false;
	    return 1;
	}
	int RailwayTicketQuery(RailwayTicket* obj, char* level, char* period, int distance)
	{
	    int levelNum, periodNum;
	    if (strcmp(level, "economy") == 0) {
	        levelNum = LEVEL_ECO;
	    } else if (strcmp(level, "premium") == 0) {
	        levelNum = LEVEL_PRE;
	    } else if (strcmp(level, "business") == 0) {
	        levelNum = LEVEL_BUS;
	    } else {
	        return -1;
	    }
	    if (strcmp(period, "slack") == 0) {
	        periodNum = SLACK;
	    } else if (strcmp(period, "peak") == 0) {
	        periodNum = PEAK;
	    } else {
	        return -1;
	    }
	    if (obj->level[levelNum][periodNum] == false) {
	        return -1;
	    }
	    int cost = obj->basic_cost[levelNum][periodNum];
	    cost = cost + (obj->float_cost[levelNum][periodNum] * distance);
	    return cost;
	}
	void RailwayTicketFree(RailwayTicket* obj)
	{
	    free(obj);
	    return;
	}

	int main(int argc, char *argv[]) {
	    //char father[] = "annabelle";
	    char economy[] = "economy";
	    char premium[] = "premium";
	    char business[] = "business";
	    char slack[] = "slack";
	    char peak[] = "peak";
	    // 返回 null 表示无输出
	    RailwayTicket *r = RailwayTicketCreate();
	    // 成功加入坐票等级 "economy" 的 "slack" 时段，运营成本为 0，里程浮动成本为 2
	    int a = RailwayTicketAdd(r, economy, slack,0,2);
	    // 成功加入坐票等级 "economy" 的 "peak" 时段，运营成本为 10，里程浮动成本为 2
	    a = RailwayTicketAdd(r, economy,peak,10,2);
	    // 成功加入坐票等级 "business" 的 "slack" 时段，运营成本为 20，里程浮动成本为 2
	    a = RailwayTicketAdd(r, business,slack,20,2);
	    // 成功加入坐票等级 "business" 的 "peak" 时段，运营成本为 50，里程浮动成本为 4
	    a = RailwayTicketAdd(r, business,peak,50,4);
	    // 系统中已存在坐票等级 "business" 在 "peak" 时段的运营成本为与里程浮动成本，返回 -1
	    a = RailwayTicketAdd(r, business,peak,50,6);
	    // "economy" 等级的 "slack" 时段运营成本从 0 元/千米变更为 8 元/千米，返回 0
	    a = RailwayTicketUpdateBasicCost(r, economy,slack,8);
	    // 系统中没有 "premium" 等级，返回 -1
	    a = RailwayTicketUpdateBasicCost(r, premium,slack,3);
	      // "economy" 等级的 "slack" 时段里程浮动成本从 2 元/千米变更为 3 元/千米，返回 2
	    a = RailwayTicketUpdateFloatingCost(r, economy,slack,3);
	    // 删除 "economy" 等级相关信息，返回 1
	    a = RailwayTicketRemove(r, economy);
	    // 系统中没有 "premium" 等级，返回 -1
	    a = RailwayTicketRemove(r, premium);
	    // 系统中没有 "economy" 等级，返回 -1
	    a = RailwayTicketQuery(r, economy,slack,100);
	    // 50 + 4*100 = 450
	    a = RailwayTicketQuery(r, business,peak,100);
	    RailwayTicketFree(r);
	}
 */