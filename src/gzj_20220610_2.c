#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
给定一个数组num和数字k,要求该数组中去掉K个数字后数组剩余的数字种类最少，并输出种类数目
例如：
input : num=[1,2,3,1,2,4,1,3,5], k=3
output: 3
解析：去掉一个4，一个5，一个3，剩余了三种种类（1,2,3）。
解法：
通过map<int,int>记录每个数字及其出现频率，按照频率升序排序，然后去掉前k个（这里处理要注意，可能部分数字的频数要大于要去掉的数目，这时候该数字还需保留），剩下的数字种类最少。
 */

int main() {

    return 0;
}