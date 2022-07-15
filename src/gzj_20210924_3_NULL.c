#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 设计一个闹钟系统需要有以下功能：

添加闹钟：如果该闹钟id已经存在，返回false；如果不存在，添加对应小时hour，分钟minute，周几weekdays[]，类型typeId（0：睡觉，1：工作，2：游戏）的闹钟
删除闹钟：如果该闹钟id不存在，返回false；如果存在，删除该id的闹钟
查询闹钟：给定周几weekday，hour，startMinute，endMinute，查询出在周几weekday，某个小时hour内，startMinute，endMinute之间的所有闹钟（包括startMinute，endMinute），
 以查询结果的minute先后排序，如果相同，typeId小的排在前面，如果也相同，按照id小的排在前面
添加、删除、查询的总操作数不超过1000
释放内存

AlarmSystem *AlarmSystemCreate()
bool AlarmSystemAddAlarm(AlarmSystem *obj, int id, int hour, int minute, int *weekdays, int weekdaysSize, int typeId)
bool AlarmSystemDeleteAlarm(AlarmSystem *obj, int id)
// 注意：返回的数组必须在给定的函数内进行内存分配，由框架代码进行内存释放。返回的数组长度存在 *retSize 中。
int *AlarmSystemQueryAlarm(AlarmSystem *obj, int weekday, int hour, int startMinute, int endMinute, int *retSize)
void AlarmSystemFree(AlarmSystem *obj)

数据范围
0 <= hour < 24
0 <= minute < 60
1 <= weeday <= 7
0 <= id <= 1000
 */
typedef struct {
    int id;
    int hour;
    int minute;
    int* weekdays;
    int weekdaysSize;
    int typeId;
    UT_hash_handle hh;
}AlarmSystem;
AlarmSystem* g_hash;
AlarmSystem *AlarmSystemCreate(){
    g_hash=NULL;
    return g_hash;
}
bool AlarmSystemAddAlarm(AlarmSystem *obj, int id, int hour, int minute, int *weekdays, int weekdaysSize, int typeId){
    AlarmSystem * tmp;
    HASH_FIND_INT(g_hash, &id, tmp);
    if(tmp!=NULL)return false;//已存在
    tmp=(AlarmSystem*)malloc(sizeof(AlarmSystem));
    tmp->id=id;
    tmp->hour=hour;
    tmp->minute=minute;
    tmp->weekdays=weekdays;
    tmp->weekdaysSize=weekdaysSize;
    tmp->typeId=typeId;
    HASH_ADD_INT(g_hash, id, tmp);
    return true;
}
bool AlarmSystemDeleteAlarm(AlarmSystem *obj, int id){
    AlarmSystem * tmp;
    HASH_FIND_INT(g_hash, &id, tmp);
    if(tmp==NULL)return false;
    HASH_DELETE(hh, g_hash, tmp);
    return true;
}
// 注意：返回的数组必须在给定的函数内进行内存分配，由框架代码进行内存释放。返回的数组长度存在 *retSize 中。
int cmp(const void* a,const void* b){
    int aa = *(int *) a;
    int bb = *(int *) b;
    AlarmSystem * tmpa;
    AlarmSystem * tmpb;
    HASH_FIND_INT(g_hash, &aa, tmpa);
    HASH_FIND_INT(g_hash, &bb, tmpb);
    if(tmpa->minute==tmpb->minute){
        if(tmpa->typeId==tmpb->typeId){
            return tmpa->typeId-tmpb->typeId;
        }
        return tmpa->typeId-tmpb->typeId;
    }else{
        return tmpa->minute-tmpb->minute;
    }
}
int *AlarmSystemQueryAlarm(AlarmSystem *obj, int weekday, int hour, int startMinute, int endMinute, int *retSize){
    int* res=(int*)malloc(sizeof(int)*1001);
    
    int rlen=0;
    AlarmSystem * el;
    AlarmSystem * tmp;
    HASH_ITER(hh, g_hash, el, tmp){
        if (el->hour==hour && startMinute<=el->minute && el->minute<=endMinute) {
            for (int i = 0; i < el->weekdaysSize; ++i) {
                if((el->weekdays)[i]==weekday ){
                    res[rlen++]=el->id;
                    break;
                }
            }
        }
    }
    qsort(res,rlen,sizeof(int),cmp);
    /// sig 因实参是NULL,永远不要对NULL解引用!!
    *retSize=rlen;
    return res;
}
void AlarmSystemFree(AlarmSystem *obj){
    free(obj->weekdays);
    free(obj);
}


int main() {
    AlarmSystem *alarmSystem = AlarmSystemCreate();
    int* weekdays=(int*)malloc(sizeof(int));
    weekdays[0]=1;
    AlarmSystemAddAlarm(alarmSystem,0,7,0,weekdays,1,0);
    AlarmSystemAddAlarm(alarmSystem,1,7,1,weekdays,1,0);
    AlarmSystemAddAlarm(alarmSystem,3,7,1,weekdays,1,1);
    AlarmSystemAddAlarm(alarmSystem,2,7,1,weekdays,1,1);
    //虽然上面插入的顺序是0132,但按题意应该返回0123
    int* retSize;
    int *pInt = AlarmSystemQueryAlarm(alarmSystem, 1, 7, 0, 59, retSize);
    for (int a = 0; a < *retSize; ++a) {
        printf("%d ",pInt[a] );fflush(stdout);
    }

//    printf("%d\n", alarmSystem->alarms[55].weekdays[2]);
//    printf("%d\n", alarmSystem->ids[155]);
//    int *weekdays = (int *) malloc(sizeof(int) * 3);
//    weekdays[0] = 1;
//    weekdays[1] = 4;
//    weekdays[2] = 7;
//
//    printf("add success: %d %d\n", 50, AlarmSystemAddAlarm(alarmSystem, 50, 4, 45, weekdays, 3, 2));
//    printf("add success: %d\n", AlarmSystemAddAlarm(alarmSystem, 50, 4, 45, weekdays, 3, 2));
//
//    Alarm *alarm = alarmSystem->alarms + 50;
//    printf("id: %d\n", alarmSystem->ids[50]);
//    printf("hour: %d\n", alarm->hour);
//    printf("minute:%d\n", alarm->minute);
//    printf("typeId: %d\n", alarm->typeId);
//    for (int i = 1; i < 8; i++) {
//        printf("weekday %d :%d\n", i, alarm->weekdays[i]);
//    }
//
//    printf("delete success: %d\n", AlarmSystemDeleteAlarm(alarmSystem, 50));
//    printf("delete success: %d\n", AlarmSystemDeleteAlarm(alarmSystem, 50));
//
//    Alarm *alarm1 = alarmSystem->alarms + 50;
//    printf("id: %d\n", alarmSystem->ids[50]);
//    printf("hour: %d\n", alarm1->hour);
//    printf("minute:%d\n", alarm1->minute);
//    printf("typeId: %d\n", alarm1->typeId);
//    for (int i = 1; i < 8; i++) {
//        printf("weekday %d :%d\n", i, alarm1->weekdays[i]);
//    }
//
//    printf("\nquery DT\n");
//    // query DT
//    int *weekdays1 = (int *) malloc(sizeof(int) * 6);
//    weekdays1[0] = 1;
//    weekdays1[1] = 2;
//    weekdays1[2] = 4;
//    weekdays1[3] = 5;
//    weekdays1[4] = 6;
//    weekdays1[5] = 7;
//    printf("add success: %d %d\n", 10, AlarmSystemAddAlarm(alarmSystem, 10, 23, 30, weekdays1, 6, 2));
//
//    int *weekdays2 = (int *) malloc(sizeof(int) * 6);
//    weekdays2[0] = 1;
//    weekdays2[1] = 2;
//    weekdays2[2] = 4;
//    weekdays2[3] = 3;
//    weekdays2[4] = 6;
//    weekdays2[5] = 7;
//    printf("add success: %d %d\n", 9, AlarmSystemAddAlarm(alarmSystem, 9, 4, 45, weekdays2, 6, 2));
//
//    int *weekdays3 = (int *) malloc(sizeof(int) * 6);
//    weekdays3[0] = 1;
//    weekdays3[1] = 2;
//    weekdays3[2] = 4;
//    weekdays3[3] = 3;
//    weekdays3[4] = 6;
//    weekdays3[5] = 7;
//    printf("add success: %d %d\n", 11, AlarmSystemAddAlarm(alarmSystem, 11, 23, 46, weekdays3, 6, 1));
//
//    int *weekdays4 = (int *) malloc(sizeof(int) * 6);
//    weekdays4[0] = 1;
//    weekdays4[1] = 2;
//    weekdays4[2] = 4;
//    weekdays4[3] = 3;
//    weekdays4[4] = 6;
//    weekdays4[5] = 7;
//    printf("add success: %d %d\n", 12, AlarmSystemAddAlarm(alarmSystem, 12, 23, 14, weekdays4, 6, 1));
//
//    int *weekdays5 = (int *) malloc(sizeof(int) * 6);
//    weekdays5[0] = 1;
//    weekdays5[1] = 2;
//    weekdays5[2] = 4;
//    weekdays5[3] = 3;
//    weekdays5[4] = 6;
//    weekdays5[5] = 7;
//    printf("add success: %d %d\n", 1, AlarmSystemAddAlarm(alarmSystem, 1, 23, 45, weekdays5, 6, 0));
//
//    int *weekdays6 = (int *) malloc(sizeof(int) * 6);
//    weekdays6[0] = 1;
//    weekdays6[1] = 2;
//    weekdays6[2] = 4;
//    weekdays6[3] = 3;
//    weekdays6[4] = 6;
//    weekdays6[5] = 7;
//    printf("add success: %d %d\n", 2, AlarmSystemAddAlarm(alarmSystem, 2, 23, 40, weekdays6, 6, 1));
//
//    int *weekdays7 = (int *) malloc(sizeof(int) * 6);
//    weekdays7[0] = 1;
//    weekdays7[1] = 2;
//    weekdays7[2] = 4;
//    weekdays7[3] = 3;
//    weekdays7[4] = 6;
//    weekdays7[5] = 7;
//    printf("add success: %d %d\n", 3, AlarmSystemAddAlarm(alarmSystem, 3, 23, 30, weekdays7, 6, 1));
//
//    int *weekdays8 = (int *) malloc(sizeof(int) * 6);
//    weekdays8[0] = 1;
//    weekdays8[1] = 2;
//    weekdays8[2] = 4;
//    weekdays8[3] = 3;
//    weekdays8[4] = 6;
//    weekdays8[5] = 7;
//    printf("add success: %d %d\n", 4, AlarmSystemAddAlarm(alarmSystem, 4, 23, 30, weekdays8, 6, 2));
//
//    int *weekdays9 = (int *) malloc(sizeof(int) * 6);
//    weekdays9[0] = 1;
//    weekdays9[1] = 2;
//    weekdays9[2] = 4;
//    weekdays9[3] = 3;
//    weekdays9[4] = 6;
//    weekdays9[5] = 7;
//    printf("add success: %d %d\n", 5, AlarmSystemAddAlarm(alarmSystem, 5, 23, 30, weekdays9, 6, 2));
//
//    int *weekdays10 = (int *) malloc(sizeof(int) * 6);
//    weekdays10[0] = 1;
//    weekdays10[1] = 2;
//    weekdays10[2] = 4;
//    weekdays10[3] = 3;
//    printf("add success: %d %d\n", 7, AlarmSystemAddAlarm(alarmSystem, 7, 23, 20, weekdays10, 4, 0));
//
//    int *weekdays11 = (int *) malloc(sizeof(int) * 6);
//    weekdays11[0] = 3;
//    printf("add success: %d %d\n", 6, AlarmSystemAddAlarm(alarmSystem, 6, 23, 20, weekdays11, 1, 0));
//
//    int *weekdays12 = (int *) malloc(sizeof(int) * 6);
//    weekdays12[0] = 3;
//    printf("add success: %d %d\n", 8, AlarmSystemAddAlarm(alarmSystem, 8, 23, 15, weekdays12, 1, 2));
//
//    int retSize = 0;
//    int *res = AlarmSystemQueryAlarm(alarmSystem, 3, 23, 15, 45, &retSize);
//    for (int i = 0; i < retSize; i++) {
//        printf("%d ", res[i]);
//    }
//
//    AlarmSystemFree(alarmSystem);
//    while (1);
    return 1;
}

/*
 	#include <stdio.h>
	#include <stdlib.h>
	#include "securec.h"
	#include <math.h>

	#define ALARMNUM 1001
	#define DAYSINAWEEK 7
	#define EXCHANGE 1
	#define STAY 0

	typedef struct {
	    int hour;
	    int minute;
	    int *weekdays;
	    int typeId;
	} Alarm;

	void InitAlarm(Alarm *alarm)
	{
	    int *weekdays = (int *)malloc(sizeof(int) * (DAYSINAWEEK + 1));
	    for (int i = 0; i <= DAYSINAWEEK; i++) {
	        weekdays[i] = 0;
	    }
	    alarm->weekdays = weekdays;
	}

	typedef struct {
	    Alarm *alarms;
	    int *ids;
	    int alarmNum;
	} AlarmSystem;

	AlarmSystem *AlarmSystemCreate()
	{
	    AlarmSystem *alarmSystem = (AlarmSystem *)malloc(sizeof(AlarmSystem));
	    Alarm *alarms = (Alarm *)malloc(sizeof(Alarm) * ALARMNUM);
	    int *ids = (int *)malloc(sizeof(int) * ALARMNUM);
	    for (int i = 0; i < ALARMNUM; i++) {
	        InitAlarm(alarms + i);
	        ids[i] = 0;
	    }
	    alarmSystem->alarms = alarms;
	    alarmSystem->ids = ids;
	    alarmSystem->alarmNum = 0;
	    return alarmSystem;
	}

	bool AlarmSystemAddAlarm(AlarmSystem *obj, int id, int hour, int minute, int *weekdays, int weekdaysSize, int typeId)
	{
	    if (obj->ids[id] != 0) {
	        return false;
	    }
	    obj->ids[id] = 1;
	    Alarm *newAlarm = obj->alarms + id;
	    newAlarm->hour = hour;
	    newAlarm->minute = minute;
	    for (int i = 0; i < weekdaysSize; i++) {
	        newAlarm->weekdays[weekdays[i]] = 1;
	    }
	    newAlarm->typeId = typeId;
	    return true;
	}

	bool AlarmSystemDeleteAlarm(AlarmSystem *obj, int id)
	{
	    if (obj->ids[id] == 0) {
	        return false;
	    }
	    obj->ids[id] = 0;
	    Alarm *oldAlarm = obj->alarms + id;
	    for (int i = 0; i <= DAYSINAWEEK; i++) {
	        oldAlarm->weekdays[i] = 0;
	    }
	    return true;
	}

	typedef struct {
	    int id;
	    int minute;
	    int typeId;
	} AlarmQueryInfo;

	int cmp(const void *voidInfoA, const void *voidInfoB)
	{
	    const AlarmQueryInfo *infoA = (const AlarmQueryInfo *)voidInfoA;
	    const AlarmQueryInfo *infoB = (const AlarmQueryInfo *)voidInfoB;
	    if (infoA->minute > infoB->minute) {
	        return EXCHANGE;
	    } else if (infoA->minute < infoB->minute) {
	        return STAY;
	    }

	    if (infoA->typeId > infoB->typeId) {
	        return EXCHANGE;
	    } else if (infoA->typeId < infoB->typeId) {
	        return STAY;
	    }

	    if (infoA->id > infoB->id) {
	        return EXCHANGE;
	    } else if (infoA->id < infoB->id) {
	        return STAY;
	    }
	    return STAY;
	}

	// 注意：返回的数组必须在给定的函数内进行内存分配，由框架代码进行内存释放。返回的数组长度存在 *retSize 中。
int *AlarmSystemQueryAlarm(AlarmSystem *obj, int weekday, int hour, int startMinute, int endMinute, int *retSize)
{
    int *ret = (int *)malloc(sizeof(int) * ALARMNUM);
    AlarmQueryInfo *alarmInfo = (AlarmQueryInfo *)malloc(sizeof(AlarmQueryInfo) * ALARMNUM);
    int infoIndex = 0;
    for (int i = 0; i < ALARMNUM; i++) {
        if (obj->ids[i] == 0) {
            continue;
        }
        Alarm *alarm = obj->alarms + i;
        if (alarm->weekdays[weekday] != 1) {
            continue;
        }
        if (alarm->hour != hour) {
            continue;
        }
        if (alarm->minute < startMinute || alarm->minute > endMinute) {
            continue;
        }
        alarmInfo[infoIndex].id = i;
        alarmInfo[infoIndex].minute = alarm->minute;
        alarmInfo[infoIndex].typeId = alarm->typeId;
        infoIndex++;
    }
    qsort(alarmInfo, infoIndex, sizeof(AlarmQueryInfo), cmp);
    for (int i = 0; i < infoIndex; i++) {
        ret[i] = alarmInfo[i].id;
    }
    *retSize = infoIndex;
    free(alarmInfo);
    alarmInfo = NULL;
    return ret;
}

void AlarmSystemFree(AlarmSystem *obj)
{
    for (int i = 0; i < ALARMNUM; i++) {
        Alarm *alarm = obj->alarms + i;
        free(alarm->weekdays);
        alarm->weekdays = NULL;
    }
    free(obj->alarms);
    obj->alarms = NULL;
    free(obj->ids);
    obj->ids = NULL;
    free(obj);
    obj = NULL;
}
 * */