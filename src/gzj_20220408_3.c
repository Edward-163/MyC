#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*



第3题
请你设计一个滑雪竞速排行榜
addRecord(int userId, int duration)：实现添加运动员的滑雪成绩，可以存多个
getTopAthletes(int num)：获取滑雪成绩最快的 num 名运动员的 id 数组，按滑雪成绩升序，成绩好的在前面；当成绩相同时，【先取得该最好成绩的】排在前面；当运动员不足 num 位时，按实际人数返回
queryTop3Record(int userId)：查询userId的运动员的前 3 次最好成绩，按成绩升序返回，不足3次按实际返回

输入：
[“SkiRankingSystem”,“addRecord”,“addRecord”,“getTopAthletes”,“queryTop3Record”]
[[],[1,10],[2,8],[3],[1]]
输出：
[null,null,null,[2,1],[10]]

输入：
[“SkiRankingSystem”,“addRecord”,“addRecord”,“addRecord”,
 “getTopAthletes”,“addRecord”,“addRecord”,“addRecord”,
 “getTopAthletes”,“addRecord”,“queryTop3Record”,“addRecord”,“queryTop3Record”]
[[],[20,8],[22,6],[20,6],
 [4],[33,5],[22,9],[31,4],
 [4],[20,8],[20],[20,6],[20]]
输出：
[null,null,null,null,
 [22,20],null,null,null,
 [31,33,22,20],null,[6,8,8],null,[6,6,8]]
 */
typedef struct {
    int userId;
    int* duration;
    int durationSize;
    int min;
    int time;//第几次
    UT_hash_handle hh;
}Person;
Person * g_hash;
int g_time;

void createSys(){
    g_hash=NULL;
    g_time=0;
}
//实现添加运动员的滑雪成绩，可以存多个
addRecord(int userId, int duration){
    g_time++;
    Person* tmp=NULL;
    HASH_FIND_INT(g_hash, &userId, tmp);
    if(tmp==NULL){
        Person* tmp=(Person*)malloc(sizeof(Person));
        tmp->userId=userId;
        tmp->duration=(int*)malloc(sizeof(int)*999);
        tmp->durationSize=0;
        (tmp->duration)[tmp->durationSize++]=duration;
        tmp->min=(tmp->duration)[0];
        tmp->time=g_time;
        HASH_ADD_INT(g_hash, userId, tmp);
    }else{
        tmp->duration[tmp->durationSize++]=duration;
        // 变现更小值,更新time
        if(duration<tmp->min){
            tmp->min=duration;
            tmp->time=g_time;
        }
    }
}
int cmp(const void*a,const void* b){
    if(((Person*)a)->min==((Person*)b)->min){
        return ((Person*)a)->time==((Person*)b)->time;
    }else{
        return ((Person*)a)->min-((Person*)b)->min;
    }
}
//获取滑雪成绩最快的 num 名运动员的 id 数组，按滑雪成绩升序，成绩好的在前面；当成绩相同时，【先取得该最好成绩的】排在前面；当运动员不足 num 位时，按实际人数返回
int* getTopAthletes(int num,int* rlen){
    int count=HASH_COUNT(g_hash);
    *rlen=count<num?count:num;
    int* ids=(int*)malloc(sizeof(int)**rlen);
    HASH_SORT(g_hash, cmp);
    Person* el;
    Person* tmp;
    int sum=0;
    HASH_ITER(hh, g_hash, el, tmp){
        ids[sum++]=el->userId;
        if(sum>=*rlen)break;
    }
    return ids;
}
int cmp2(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}
//查询userId的运动员的前 3 次最好成绩，按成绩升序返回，不足3次按实际返回
int* queryTop3Record(int userId,int* rlen){
    Person* tmp=NULL;
    HASH_FIND_INT(g_hash, &userId, tmp);
    qsort(tmp->duration,tmp->durationSize,sizeof(int),cmp2);
    *rlen=tmp->durationSize<3?tmp->durationSize:3;
    int* res=(int*)malloc(sizeof(int)**rlen);
    memcpy(res,tmp->duration,sizeof(int)**rlen);
    return res;
}
int main() {
    /*
     [“SkiRankingSystem”,“addRecord”,“addRecord”,“addRecord”,
 “getTopAthletes”,“addRecord”,“addRecord”,“addRecord”,
 “getTopAthletes”,“addRecord”,“queryTop3Record”,“addRecord”,“queryTop3Record”]
[[],[20,8],[22,6],[20,6],
 [4],[33,5],[22,9],[31,4],
 [4],[20,8],[20],[20,6],[20]]
输出：
[null,null,null,null,
 [22,20],null,null,null,
 [31,33,22,20],null,[6,8,8],null,[6,6,8]]
     */
    createSys();
    addRecord(20,8);
    addRecord(22,6);
    addRecord(20,6);
    int rlen;
    int *pInt = getTopAthletes(4,&rlen);
    for(int a=0;a<rlen;a++){
        printf("%d ",pInt[a] );fflush(stdout);
    }
    printf("\n" );fflush(stdout);
    addRecord(33,5);
    addRecord(22,9);
    addRecord(31,4);
    int *athletes = getTopAthletes(4, &rlen);
    for(int a=0;a<rlen;a++){
        printf("%d ",athletes[a] );fflush(stdout);
    }
    addRecord(20,8);
    int *record = queryTop3Record(20,&rlen);
    for(int a=0;a<rlen;a++){
        printf("%d ",record[a] );fflush(stdout);
    }
    printf("\n");fflush(stdout);
    addRecord(20,6);
    int *top3Record = queryTop3Record(20, &rlen);
    for (int a = 0; a < rlen; ++a) {
        printf("%d ",top3Record[a]);fflush(stdout);
    }
    printf("\n");fflush(stdout);

    return 0;
}