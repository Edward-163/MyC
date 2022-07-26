#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PrintArrayA(int *array[3]) {
    printf("%d\n", array[0][0]);
}
void PrintArrayA2(int *array[2]) {
    printf("%d\n", array[1][1]);
}
void PrintArrayB(int (*array)[3]) {
    printf("%d\n", array[0][0]);
}
void PrintArrayC(int **array) {
    printf("%d\n", array[0][0]);
}
void PrintArrayD(int array[][3]) {
    printf("%d\n", array[0][0]);
}

/***
   答案在下面,刷leet后知道,C肯定是错的,D是可以的
   基础知识 数组作为函数参数会退化为指针
   解析A int* g_arr[3],[]优先级为1,很高,所以该写法是"指针数组",该数组有3个元素,元素类型是指针
        如果把int hyj[]理解为形参名hyj,类型是int[],卧槽这不就是java数组的写法么...那么int* g_arr[3]就可以理解为,形参名arr,类型是int*[],又因为数组作为函数参数会退化,所以int** g_arr
   解析B 把int (*g_arr)[3]理解为int hyj[3],得出*g_arr==hyj, 已知声明了指针变量*g_arr,hyj是数组,则arr指向hyj数组(含有3个int), 所以arr是数组指针,
        形参名arr,类型int (*g_arr)[3],这个没有解释
        int g_arr[2][3]理解为int[3] g_arr[2]:arr是长度为2的数组,数组的元素type为int[3]
        http://c.biancheng.net/view/227.html    悟了悟了
        int a[3][4] = {{1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23}};
        其中，a 是二维数组名。a 数组包含 3 行，即 3 个行元素：a[0]，a[1]，a[2]。每个行元素都可以看成含有 4 个元素的一维数组。而且 C 语言规定，a[0]、a[1]、a[2]分别是这三个一维数组的数组名。如下所示：
        a[0]、a[1]、a[2] 既然是一维数组名，一维数组的数组名表示的就是数组第一个元素的地址，所以 a[0] 表示的就是元素 a[0][0] 的地址，即 a[0]==&a[0][0]；a[1] 表示的就是元素 a[1][0] 的地址，即 a[1]==&a[1][0]；a[2] 表示的就是元素 a[2][0] 的地址，即 a[2]==&a[2][0]。
   解析C int ** array 形参名array,类型int**,通常理解为指针的指针(少数情况:如leet中int** returnColSize就应该理解为一级指针的地址),没啥说的
        c不行的更深层原因有待补充,
   解析D 把int g_arr[][3]理解为int hyj[3],得出arr[]==hyj,
        形参名arr,类型int (*g_arr)[3],这个没有解释,我暂且这么理解,int g_arr[][3]==int[3] g_arr[]==又因为arr[]作为函数参数会退化==int[3] *g_arr
    二级指针                    二维数组(元素是连续存放的,此arr就存2行!,最开始我不理解,一度以为下面画错了,后来看了上面的链接悟了)
    pp->p->int变量            g_arr->1==g_arr[0] 2 3
                                  4==g_arr[1] 5 6

   int* g_arr[3]==int** g_arr     int (*g_arr)[3]     左侧有两次指向,右侧只有一次指向,这区别够明显吧,思考一个问题,二维数组转int**的过程,
   g_arr->g_arr[0]->int变量        g_arr->1 2 3
        g_arr[1]->int变量             4 5 6
        g_arr[2]->int变量
错误反思:之前粗暴把int g_arr[][]==int** g_arr,错误推出arr[row]的类型是int*,就觉得arr[row]是一级指针,g_arr[row]就应该指向某个实际的数组
 现在回过头看看上图,再来好好想想arr[row]到底是啥,                      我觉得arr[row]是某个实际数组的首地址,所以本质的误会还是int*的理解,通常理解为数组,也可以理解为某个值的地址

 */
int main() {
    int arr[][3]={{1,2,3},{4,5,6}};
    PrintArrayA(arr);fflush(stdout);

    /// 这是常见的列相同的二维数组转一维数组的方式
    int* parr[2];
    for (int i = 0; i < 2; ++i){
        parr[i]=arr[i];
    }
    PrintArrayA2(parr);fflush(stdout);
    PrintArrayB(arr);fflush(stdout);
    PrintArrayC(arr);fflush(stdout);
    PrintArrayD(arr);fflush(stdout);
    return 0;
}








































//答案BD