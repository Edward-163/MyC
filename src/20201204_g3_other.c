#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
/*
 任务列表 tasks 中有 N 个任务，任务编号 Ni​ 的值范围为 [0, N-1]。
由于存在资源竞争，某些任务间存在两两互斥关系，并记录在二维数组 mutexPairs 中，该二维数组元素为 [Ni​, Nj​]，其中 Ni​，Nj​ 为互斥的两个任务编号。
现在需要对任务列表 tasks 进行切割分组。要求：
l  存在互斥关系的任务不能分在同一组
l  单个任务也可以单独一组
l  一个任务可能和多个任务互斥
请判断 最少 可以将任务列表 tasks 切割 成几组？（即：切割后的小组是原列表的 连续子数组）
示例 1：
输入：tasks = [1,4,2,3,0], mutexPairs = []
输出：1
解释：无互斥关系，所有任务可分在同一组。
示例 2：
输入：tasks = [1,3,2,4,6,5,0], mutexPairs = [[1,3],[4,5]]
输出：3
解释：任务1，3 不能被分在同一组；4，5 不能被分在同一组，所以最终只能将任务列表分成3组。例如，[1],[3,2,4,6],[5,0] 为其中一种分法；[1],[3,2,4],[6,5,0] 为另一种分法。
注意：切割后的小组是原列表的连续子数组。
示例 3：
输入：tasks = [0,1,2,3,4,5], mutexPairs = [[1,3],[3,5]]
输出：3
解释：最少分成 3 组。例如，[0,1,2],[3,4],[5] 为其中一种分法。
 1<=task.length<=10^5
 0<=mutexPairs.length<=1000 mutexPairs[i].length==2
 0<=mutexPairs[i][0]<mutexPairs[i][1]<task.length
 */
int DivideGroup(int* tasks, int tasksSize, int** mutexPairs, int mutexPairsSize)
{
    int group[100000] = {0};
    int temp = 1;
    int res = 0;
    group[tasks[0]] = temp;
    for (int i = 0; i < tasksSize; i++) {
        for (int j = 0; j < mutexPairsSize; j++) {
            if ((mutexPairs[j][0] == tasks[i] && group[mutexPairs[j][1]] == temp)
                || (mutexPairs[j][1] == tasks[i] && group[mutexPairs[j][0]] == temp)) {
                res += 1;
                temp += 1;
            }
            group[tasks[i]] = temp;
        }
    }
    return res + 1;
}
int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}