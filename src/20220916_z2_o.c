#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
/*
 材料实验室研究员正在研究激光在新型透光玻璃中传输时的衰减效果。
给定多层上下叠放的介质，每层介质等长，并划分成若干个单位长度为 1 的格子。planks记录了从上到下每层的介质信息，planks[i] 表示第 i 层介质从左到右的透光玻璃放置情况，其中：
·         1 表示该位置有透光玻璃，可穿过激光；每层至少包含了一块透光玻璃；
·         0 表示该位置为不透光介质，无法穿过激光；
图中有三层介质，如下所示：
image.png
研究员从最上方、任意位置垂直向下发射激光，每次移动可以将任意一层介质左移（或右移）一个单位长度。
请问研究员最少需要移动多少次介质，可使激光能垂直穿过所有介质（即每层介质都需要被穿过）。
示例 1：
输入：planks = [[1,0,0,0,0],[0,0,0,0,1],[1,0,0,0,0]]
输出：4
解释：planks 的行表示层、列表示位置：从上往下依次为第 0 层、第 1 层、第 2 层，如上图所示。
最佳方案为：第 1 层介质向左移动 4 次。激光从位置 0 （即第 0 层未移动前的下标）向下发射，可穿过这三层介质。
注：将第 1 层介质向右移动 1 次的方案是不可行的，因为此时任意位置都无法穿过所有介质。
示例 2：
输入：planks = [[0,1,0,0,0],[1,0,0,0,0],[0,0,1,0,0],[0,0,0,1,1]]
输出：4
解释：
一种可行方案：
第 0 层介质右移 1 次；
第 1 层介质右移 2 次；
第 2 层介质不移动；
第 3 层介质左移 1 次；
一共移动 4 次，激光从位置 2 （即第 0 层未移动前的下标）向下发射，可穿过所有介质。
image.png
示例 3：
输入：planks = [[1,1,1,1,1],[1,1,1,1,1],[1,1,1,1,1]]
输出：0
提示：
2 <= planks[i].length <= 1000
2 <= planks.length <= 1000
0 <= planks[i][j] <= 1
 */
int GetMinMovesNum(int **planks, int planksSize, int *planksColSize){
    
    return 0;
}
int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}
/*
 * planks是长度为planksSize的数组，其元素为指针，
 * planksColSize[i] 表示 planks[i] 所指向内容的长度，
 * planksColSize的长度也为planksSize。
 */
#define START 0
#define MAXL 1000
int GetMinMovesNum(int **planks, int planksSize, int *planksColSize)
{
    int cnt[planksSize][planksColSize[START]];
    for (int i = 0; i < planksSize; i++) {
        if (planks[i][START] == 1) {
            cnt[i][START] = 0;
        } else {
            cnt[i][START] = MAXL;
        }
    }
    for (int i = 0; i < planksSize; i++) {
        for (int j = 1; j < planksColSize[START]; j++) {
            if (planks[i][j] == 1) {
                cnt[i][j] = 0;
            } else {
                cnt[i][j] = cnt[i][j - 1] + 1;
            }
        }
        for (int j = planksColSize[START] - 2; j >= 0; j--) {
            if (cnt[i][j] > cnt[i][j + 1] + 1) {
                cnt[i][j] = cnt[i][j + 1] + 1;
            }
        }
    }
    int ct = planksSize * planksColSize[START];
    for (int i = 0; i < planksColSize[START]; i++) {
        int cn = 0;
        for (int j = 0; j < planksSize; j++) {
            cn += cnt[j][i];
        }
        if (cn < ct) {
            ct = cn;
        }
    }
    return ct;
}