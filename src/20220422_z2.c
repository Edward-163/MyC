#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/*
 Excel工作表中对选定区域的数值进行统计的功能非常实用。仿照Excel的这个功能，请对给定表格中选中区域中单元格进行求和统计，并输出统计结果。
为简化统计，假设当前输入中每个单元格内容仅为数字或公式两种。
l  如果为数字，则是一个非负整数，形如 0、11
l  如果为公式，则固定以=开头，且仅包含下面三种情况：
Ø  等于某单元格的值，形如=B12
Ø  两个单元格的双目运算（仅为 + 或 -），形如=C1-C2、C10+B2
Ø  单元格和数字的双目运算（仅为 + 或 -），形如=B12+1、=100-B12
公式不存在嵌套，例如 =C1-C2，其中C1和C2单元格的内容只会是数字，不会是公式。
公式内容都是合法的，例如不存在“=C+2”,“=C1-C2+B3”,“=5”,“=1+10”； 内容中不存在空格、括号
输入
第一行两个整数 rows cols，表示给定表格区域的行数和列数， 1 <= rows <= 20，1 <= cols <= 26
接下来 rows 行，每行 cols 个以空格分隔的字符串，表示给定表格 values 的单元格内容
最后一行输入的字符串，表示给定的选中区域，形如A1:C2
l  表格的行号 1~20，列号 A~Z，例如单元格 B3 对应 values[2][1]
l  输入的单元格内容（含公式）中的数字均为十进制，值范围 [0, 100]
l  选中区域: 冒号左侧单元格表示选中区域的左上角，右侧表示右下角，如可以为 B2:C10、B2:B5、B2:Y2、B2:B2，无类似 C2:B2、C2:A1 的输入
输出
一个整数，表示选中区域的数值之和
样例
输入样例 1
5 3
10 12 =C5
15 5 6
7 8 =3+C2
6 =B2-A1 =C2
7 5 3
B2:C4
输出样例 1
29

 其中几个单元格内容为公式，这几个单元格的值计算过程如下：
C1 = C5 = 3
C3 = 3+C2 = 3+6 = 9
B4 = B2-A1 = 5-10 = -5
C4 = C2 = 6
选中区域 B2:C4 包含6个单元格（图中蓝色区域），统计结果为：5 + 8 - 5 + 6 + 9 + 6 = 29
输入样例 2
1 3
1 =A1+C1 3
A1:C1
输出样例 2
8
提示样例 2
选定区域为整行。B1单元格按公式计算为4，结果为1+4+3=8
 */

int Fn()
{

}

/*
如果为数字，则是一个非负整数，形如 0、11
等于某单元格的值，形如=B12
两个单元格的双目运算（仅为 + 或 -），形如=C1-C2、C10+B2
单元格和数字的双目运算（仅为 + 或 -），形如=B12+1、=100-B12
 */
int GetInt(int row, int col, char arr[row][col][9], int r, int c)
{
    if (arr[r][c][0] != '=') { // 只能是数字
        return atoi(arr[r][c]);
    }
    int addsubidx = -1;
    for (int a = 0; a < strlen(arr[r][c]); a++) {
        if (arr[r][c][a] == '+' || arr[r][c][a] == '-') {
            addsubidx = a;
            break;
        }
    }
    if (addsubidx == -1) { // 只能是=A99之类的
        char c;
        int d;
        scanf("=%c%d", &c, &d);
        return atoi(arr[d - 1][c - 'A']); // 公式不嵌套
    }
    char c1;
    int d1;
    char c2;
    int d2;
    if (arr[r][c][addsubidx] == '+') {
        if ('0' <= arr[r][c][1] && arr[r][c][1] <= '9') {
            scanf("=%d+%c%d2", &d1, &c2, &d2);
            return d1 + atoi(arr[d2 - 1][c2 - 'A']);
        } else if ('0' <= arr[r][c][addsubidx + 1] && arr[r][c][addsubidx + 1] <= '9') {
            scanf("=%c%d+%d2", &d1, &c1, &d2);
            return atoi(arr[d1 - 1][c1 - 'A']) + d2;
        } else {
            scanf("=%c%d+%c%d2", &c1, &d1, &c2, &d2);
            return atoi(arr[d1 - 1][c1 - 'A']) + atoi(arr[d2 - 1][c2 - 'A']);
        }
    } else {
        if ('0' <= arr[r][c][1] && arr[r][c][1] <= '9') {
            scanf("=%d-%c%d2", &d1, &c2, &d2);
            return d1 - atoi(arr[d2 - 1][c2 - 'A']);
        } else if ('0' <= arr[r][c][addsubidx + 1] && arr[r][c][addsubidx + 1] <= '9') {
            scanf("=%c%d-%d2", &d1, &c1, &d2);
            return atoi(arr[d1 - 1][c1 - 'A']) - d2;
        } else {
            scanf("=%c%d-%c%d2", &c1, &d1, &c2, &d2);
            return atoi(arr[d1 - 1][c1 - 'A']) - atoi(arr[d2 - 1][c2 - 'A']);
        }
    }
}

int main()
{
    // @formatter:off 06
    int row;
    int col;
    scanf("%d %d",&row,&col);
    char arr[row][col][9];
    for (int r = 0; r < row; ++r){
        for (int c = 0; c < col; ++c){
            scanf("%s",&arr[r][c]); // \n \t space都会截取
        }
    }
    // 验证
    for (int i = 0; i < row; ++i){
        for (int c = 0; c < col; ++c){
            printf("%s ",arr[i][c]);fflush(stdout);
        }
        printf("\n");fflush(stdout);
    }

    int ans=0;
    for (int r = 0; r < row; ++r){
        for (int c = 0; c < col; ++c){
            ans+=GetInt(row,col,arr, r, c);
        }
    }
    printf("%d \n",ans);fflush(stdout);
    // char rowbegin;
    // int rowend;
    // char colbegin;
    // int colend;
    // scanf("%c%d:%c%d",&colbegin,&rowbegin,&colend,&rowend); // 尴尬,加_s反而报错
    // printf("%c %d %c %d\n",colbegin,rowbegin,colend,rowend);fflush(stdout);
    return 0;
    // @formatter:on
}



