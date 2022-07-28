/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include <regex.h>

/*
 
 */
int largestRectangleArea(int *heights, int heightsSize)
{
    /// 不是吧阿sir,公司的codeCheck还要校验heightsSize?!!
    if (heightsSize <= 0) {
        return 0;
    }
    // 枚举柱子高,暴力左右拓宽得width
    // 优化上面暴力,得dp,didx==idx,dval=首次比当前idx柱子低的柱子的idx,"边界"取-1orSize
    int *leftdp = (int *) malloc(sizeof(int) * heightsSize);
    leftdp[0] = -1;
    for (int a = 1; a < heightsSize; a++) {
        if (heights[a - 1] < heights[a]) {
            leftdp[a] = a - 1;
            /// bug break;自己sb了
            continue;
        }
        int move = a - 1;
        while (move >= 0 && heights[move] >= heights[a]) {
            /// bug 写c是真的要小心
//            move=heights[move];
            move = leftdp[move];
        }
        leftdp[a] = move;
    }

    int *rightdp = (int *) malloc(sizeof(int) * heightsSize);
    rightdp[heightsSize - 1] = heightsSize;
    for (int a = heightsSize - 2; a >= 0; a--) {
        if (heights[a + 1] < heights[a]) {
            rightdp[a] = a + 1;
            continue;
        }
        int move = a + 1;
        while (move < heightsSize && heights[move] >= heights[a]) {
            move = rightdp[move];
        }
        rightdp[a] = move;
    }

    int ans = 0;
    for (int a = 0; a < heightsSize; a++) {
        int width = rightdp[a] - leftdp[a] - 1;
        int area = width * heights[a];
        if (area > ans) {
            ans = area;
        }
    }
    return ans;
}

int main()
{
    int heights[] = {2, 1, 5, 6, 2, 3};
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int i = largestRectangleArea(heights, heightsSize);
    printf("%d ", i);
    fflush(stdout);
    return 0;
}