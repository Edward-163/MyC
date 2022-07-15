#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
有一种速记方式，针对重复内容有一套独特的缩写规则：
1.     重复的部分会被以 "(重复内容)<重复次数>" 形式记录，并且可能存在嵌套缩写关系。不重复的部分按照原样记录。
现给一个符合此速记方式的字符串 records，请以字符串形式返回复原后的内容。
注： records 仅由小写字母、数字及<, >, (, )组成。
示例 1：
输入：records = "abc(d)<2>e"
输出："abcdde"
解释：字符串中出现 "(d)<2>"，表示 "d" 重复出现 2 次，因此返回复原后的内容 "abcdde"。
示例 2：
输入：records = "a(b(c)<3>d)<2>e"
输出："abcccdbcccde"
解释：字符串中出现 "a(b(c)<3>d)<2>"，其中 "(c)<3>" 表示 "c" 出现 3 次，复原为 "ccc"；"(bcccd)<2>" 表示 "bcccd" 重复出现 2 次，复原为 "bcccdbcccd"。最终返回复原后内容 "abcccdbcccde"
提示：
·         1 <= records.length <= 200
·         2 <= 重复次数 <= 10
·         题目保证返回结果字符串长度小于等于 10^4
·         输入保证合法，确保括号与尖括号成对出现
·         嵌套深度不超过 13
答题要求：结果可信和过程可信同样重要，您编写的代码需要符合可信的要求（包括通用编码规范、安全编码规范和圈复杂度）。

 */
/// 考官总结:抽象能力对于软件开发非常重要，在理解题意后要能够正确提取数据的特征；如果不能正确提取特征，找到合适的实现方式，就会导致代码很多
/// 自己错误反思,我直觉就是dfs,没说dfs错,而是我习惯于用递归写dfs,对于这题来说,代码量就会很大,容错率也低
char* UnzipString(char* records){
    char* ans=(char*)malloc(sizeof(char)*10002);
    int alen=0;
    int ridx=0;
    int stack[10002];//val是ans的某个idx,而这个idx就"出栈段"的最左字符在ans中的idx
    int slen=0;
    while(records[ridx]!='\0'){
        if(isalpha(records[ridx]) || isdigit(records)){
            ans[alen++]=records[ridx];
        }else if(records[ridx]=='('){
            /**
             * 如a((b)<2>c)<3> alen==1,当遇到>,
             */
            stack[slen++]=alen;
        }else if(records[ridx]=='>'){
            int repeat=records[ridx-2]=='1'?10:records[ridx-1]-'0';

            for (int i = 0; i < repeat; ++i){

            }
            slen--;
        }

        ridx++;
    }
}


int main() {

    return 0;
}





























/*
char* UnzipString(char* records)
{
    char* returnStr = (char*)malloc(10001 * sizeof(char));
    int i;
    int j = 0;
    int k = 0;
    int l;
    int m;
    int count;
    int index1[1000];
    if (records == NULL) {
        return NULL;
    }
    for (i = 0; records[i] != '\0'; i++) {
        if (records[i] >= 'a' && records[i] <= 'z') {
            returnStr[j++] = records[i];
        } else if (records[i] == '(') {
            index1[k++] = j;
        } else if (records[i] == '>') {
            if (records[i - 1] == '0') {
                count = 9;
            } else {
                count = records[i - 1] - '0' - 1;
            }
            l = j;
            while(count > 0) {
                for(m = 0; m < l - index1[k - 1]; m++) {
                    returnStr[j++] = returnStr[index1[k - 1] + m];
                }
                count--;
            }
            k--;
        }
    }
    returnStr[j] = '\0';
    return returnStr;
}
 */
