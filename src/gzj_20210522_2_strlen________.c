#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/*
给定一个整数数组表示，按照给定的周期period、最大值maxnum、最小值minnum，按规则记录积分，返回积分总和；
积分规则：
遍历数组，当前索引为i，记录[i, i + period - 1] 范围内的和为sum，
如果sum > maxnum，+1分；
如果sum < minnum，-1分；
其它情况：0分；
不满一个周期，不记录分数。

例如：
输入[1, 2, 3, 4, 5] 周期period = 3， maxnum = 10， minnum = 8
[1，2，3] 求和后6 < minnum ,-1分；
[2，3，4] 求和后9，不满足规则，不计分；
[3，4，5] 求和后12 > maxnum  ,+1分；
[4，5] 不满一个周期，不计分；
[5] 不满一个周期，不计分；
 */
int fn(int * parr,int len,int period,int max,int min){
    int score=0;
    ///bug,严禁对非字符数组求strlen!!!
    //int len=strlen(parr);//len==1
    ///指针,当前64位,8字节,parr[0]是个int数,4字节,所以len==2,也是错的!!!c语言安全编程规范:严禁对指针sizeof
    //int len=sizeof(parr)/sizeof(parr[0]);
    if(len<period)return score;

    int presum=0;
    for(int a=0;a<len;a++){
        presum+=parr[a];
        // 0 1 2 p-1 p
        if(a>=period-1){
            //a==p-1时,不用减parr[0]
            if(a-period>=0)presum-=parr[a-period];
            if(presum>max){
                score++;
            }else if(presum<min){
                score--;
            }
        }
    }
    return score;
}

int main() {
    int arr[]={1,2,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    int period=3;
    int max=10;
    int min=8;
    printf("%d",fn(arr,len,period,max,min));
    fflush(stdout);
    return 0;
}