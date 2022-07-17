#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <uthash.h>

/*
先做L1094,再来这
 这两道题目理解下啥是差分

 */
/**
思考:为啥此题换了个描述,我就想不出来怎么套用差分?!!
 我后来反思了自己,画图理解比较清晰,这种类似多条横线(每条横线有它自己的数值)画好后,纵向切很多刀,求每一刀砍到的多条横线的数值总和
 我们就以极端例子
 1~99 此横线数值为1
 1~99 此横线数值为1
 ...
 中间每一刀都纵向有必要叠加么??
 其实需要一个sum,我们知道啥时候有新的横线出现啥时候sum累加,但sum一般也不可能一直加,旧的横线消失的时候,sum就要累减
 所以你看,理解到这了后,题目其实就已经转化成了 L1094
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
//    int* ans=malloc(sizeof(int)*n); // overtime
//    memset(ans,0,sizeof(int)*n);
//    for(int a=0;a<bookingsSize;a++){
//        for(int b=bookings[a][0]-1;b<=bookings[a][1]-1;b++){
//            ans[b]+=bookings[a][2];
//        }
//    }
//    *returnSize=n;
//    return ans;
}
int main() {
    // @formatter:off
    
    return 0;
    // @formatter:on
}