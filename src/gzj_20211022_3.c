#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给一个messages和一个keys，在messages中截取包含所有keys中所有元素的子字符串，求截取的不同方法数。messages和keys都只包含大写字符，keys中的字符是不重复的。截取的起始位置或者末尾位置不同即认为是不同的截取方式
例如：messages="ABBCDCDAB",keys="BAC"；
a. ABBC包含keys中的所有字母,因此ABBC,ABBCD,ABBCDC,ABBCDCD,ABBCDCDA,ABBCDCDAB,6种截取方式可以满足条件
b. BBCDCDA包含keys中的所有字母,因此BBCDCDA和BBCDCDAB,2种截取方式可以满足条件
c. BCDCDA包含keys中的所有字符，因此BCDCDA和BCDCDAB,2中截取方式可以满足条件
d. CDCDAB包含keys中的所有字符，1种截取方式满足条件
e. DCDAB包含keys中的所有字符，1种截取方式满足条件
f. CDAB包含keys中的所有字符，1中截取方式满足条件
因此答案输出13;

例如：messages="ZZ",keys="Z";
输出：3

例如：messages="GR",keys="F";
输出：0
 */

int main() {

    return 0;
}