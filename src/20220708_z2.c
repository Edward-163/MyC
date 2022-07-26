#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
/*
某工厂使用激光刀切割材料。激光刀具有开启和关闭两种状态，并可转向和移动。支持指令如下：
·         O —— 开启激光刀（即 "OPEN"），指令执行后激光刀处于开启状态
·         C —— 关闭激光刀（即 "CLOSE"），指令执行后激光刀处于关闭状态
·         M —— 激光刀沿着当前方向前进一段距离（即 "MOV")，若激光刀在开启状态下，会同步进行材料切割，否则只移动不切割
·         U，D，L，R —— 改变激光刀的前进方向、但不移动（上：U，下：D，左：L，右：R）
给定一块高为 height，宽为 width 的材料。初始时，激光刀位于材料左上角，处于关闭状态，前进方向为朝下 (D)。
激光刀的操作指令依次记录于字符串 operations，所有 M 指令的移动距离依次记录于数组 distances，distances[i] 表示第 i 个 M 指令的移动距离。
请计算完成操作指令后，材料板上被切割出了多少个 1 x 1 的方块。
 注意：输入数据保证激光刀始终在材料初始范围内，可在材料边上，即：激光刀的位置 [row, col] 始终满足 0 <= row <= height，0 <= col <= width。
        1 <= height, width <= 100
·         0 <= operations.length <= 10^4
·         distances.length 等于 operations 中 M 的个数
·         operations[i] 仅为 'O'、'C'、'U'、'D'、'L'、'R'、'M'
·         一条边可能会被多次切割
 
示例 1：
输入：
height = 3
width = 4
operations = "MRMOMDMLMUMCRMODMC"
distances =  [1,1,2,1,2,2, 1, 2]
输出：3
 输入：
height = 3
width = 4
operations = "MRMOMDMLMUMC"
distances = [1,1,2,1,2,2]
输出：0
 height = 3
width = 3
operations = "MROMDMLMUMRMDMRMUMLMC"
distances = [1,2,1,2,1,1,1,1,1,1]
输出：2
 */

int GetUnitBlockNum(int height, int width, char *operations, int *distances, int distancesSize){

}
int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}