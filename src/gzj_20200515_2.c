#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给定一个杂志编号数组 array = [6,2,4,10,3,5]；现在依次从array中取一本书放到另一个展柜上，要求展柜上的书是递增排列；而且每次只能将书籍放到展柜首尾两端，若不符合则需要将已经存在的书取出后再放入，
 再还原之前已经放入的书籍（取出和放入都需要步骤），写一个程序计算最少需要多少步将书籍完整的放入到展柜上。
order = [6, 2, 10, 4, 3, 5];
1. 放入6号图书，操作1次。陈列架为[6]，总操作1次
2. 从左侧放入2号图书，操作1次。陈列架为[2,6] ，总操作2次
3. 从右侧放入10号图书，操作1次。陈列架为[2,6,10] ，总操作3次
4. 先从左侧拿出2号，放入4号，再放入2号，操作3次，陈列架为[2,4,6,10] ，总操作6次
5. 先从左侧拿出2号，放入3号，再放入2号，操作3次，陈列架为[2,3,4,6,10] ，总操作9次
6. 先从右侧拿出10、6号，放入5号，再放入6、10号，操作5次，陈列架为[2,3,4,5,6,10] ，总操作14次
 */
int Fn(int *arr, int arrSize)
{
    int *stack = malloc(sizeof(int) * (2 * arrSize + 1));
    // 0 n-1 n  n+1 2n
    stack[arrSize] = arr[0];
    int left = arrSize;
    int righ = arrSize;
    int mid = (left + righ) / 2;
    int ans = 1;
    for (int a = 1; a < arrSize; a++) {
        if (arr[a] < stack[mid]) {
            int move = left;
            while (stack[move] < arr[a]) {
                stack[move - 1] = stack[move];
                ans++;
                ans++;
                // step
                move++;
            }
            stack[move - 1] = arr[a];
            left--;
        } else {
            int move = righ;
            while (stack[move] > arr[a]) {
                stack[move + 1] = stack[move];
                ans += 2; // step 2
                move--;
            }
            stack[move + 1] = arr[a];
            righ++;
        }
        ans++;
        mid = (left + righ) / 2; // mid 2 这种魔鬼数字的检测还要故意加上数字,有点
    }
    return ans;
}

int main()
{
    // @formatter:off
    int arr[] = {6, 2, 4, 10, 3, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int i = Fn(arr, arrSize);
    printf("%d \n", i);
    fflush(stdout);
    return 0;
    // @formatter:on
}