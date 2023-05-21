#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/*

 */
typedef struct {

}Coord;
typedef struct{

}Command;
int GetMatrixSum(int rows,int cols,const Coord* stations,int stationCnt,const Command* commands,int cmdCnt){

}

int main() {
    // @formatter:off
    int rows;
    int cols;
    scanf("%d %d",&rows,&cols);
    int stationCnt;
    scanf("%d",&stationCnt);
    // 我在想我写此题,int二维数组代替stations,-1代表*,多行命令直接解析完后调用函数
    return 0;
    // @formatter:on
}