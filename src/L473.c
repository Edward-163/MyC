#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int cmp(const void * a,const void* b){
    return (int*)a-(int*)b;
}

bool makesquare(int* matchsticks, int matchsticksSize){
    if(matchsticksSize<4)return false;

    int totalLen=0;
    for(int a=0;a<matchsticksSize;a++){
        totalLen+=matchsticks[a];
    }
    if(totalLen % 4 != 0)return false;

    int sideLen= totalLen / 4;
    ///bug:qsort参数记少了,错了
    //qsort(matchsticks,sizeof(int)*matchsticksSize,cmp);
    qsort(matchsticks,matchsticksSize,sizeof(int),cmp);
    int ridx=matchsticksSize-1;
    if(matchsticks[ridx] > sideLen)return false;

    ///bug:可能未初始化
    //int used[matchsticksSize]={0};

    //给出一个数,找出剩余的数==sideLen-m[ridx],如side==5,12223,1333
    //别想了,纯循环特别难写,此题转化为:从数组中选出和为side的数集

}

int main() {

    return 0;
}