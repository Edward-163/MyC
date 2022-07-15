#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int start;
    int idx;
} Node;

int cmp(const void *pa, const void *pb) {
    return ((Node *) pa)->start - ((Node *) pb)->start;
}

/**
 写二维数组本地可以过,但leet不行,写int** leet可以过,但本地段错误
 二维数组实参,二级指针形参,
 https://blog.csdn.net/I_just_smile/article/details/89226136
 二维数组名是：数组指针
因为二维数组名只是一个一级指针，指向一个数组。而这个数组，又包含了指向每个一维数组的指针
 */
int *findRightInterval(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize) {
    //如何理解colsize是*
    /*
     以[[3,4],[2,3],[1,2]]为例,321抽出来做集合且保留下标,本质还是排序且之后要快速查找
     问集合有没有>=4,没有返-1
     问集合有没有>=3,有返下标0
     问集合有没有>=2,有返下标1
     */
//    printf("%s\n", intervals[0][0]);
//    Node *base = (Node *) malloc(sizeof(Node) * intervalsSize);
    Node base[intervalsSize];
    for (int a = 0; a < intervalsSize; a++) {
//        Node node = {intervals[a][0], a};
//        base[a] = node;
        /**
            bug:sigmentation falut
            可能是base出错了,打印后发现base[0]有值,那就可能是intervals错了
         */
        base[a].start = intervals[a][0];
        base[a].idx = a;
    }

    qsort(base, intervalsSize, sizeof(Node), cmp);

    int *res = (int *) malloc(sizeof(int) * intervalsSize);
    memset(res, -1, sizeof(int) * intervalsSize);
    for (int a = 0; a < intervalsSize; a++) {
        int lidx = 0;
        int ridx = intervalsSize - 1;
        while (lidx <= ridx) {
            //01 1/2==0 012 2/2==1
            int mid = (lidx + ridx) / 2;
            if (base[mid].start == intervals[a][1]) {
                res[a] = base[mid].idx;
                break;
            } else if (base[mid].start < intervals[a][1]) {
                lidx = mid + 1;
            } else {
                ridx = mid - 1;
            }
        }
    }
    *returnSize = intervalsSize;
    return res;
}


int main() {
    int arr[][2] = {{3, 4}, {2, 3}, {1, 2}};
    /***
     写成int* inter[3]我觉得更好理解,首先inter是一维数组,len==3,且数组元素类型是int*
     也就是说一维数组元素是指针,至于指针指向哪,指向的空间有多大不关心,
     version1  version3
     intervals是数组,这个数组存了3个指针
     */
    int* intervals[3];
    for (int a = 0; a < 3; a++) {
        intervals[a] = arr[a];
    }
    int intervalsSize = sizeof(intervals) / sizeof(intervals[0]);
    int *returnSize = (int *) malloc(sizeof(int));
    int *res = findRightInterval(intervals, intervalsSize, NULL, returnSize);
    for (int a = 0; a < intervalsSize; a++) {
        printf("%d ", res[a]);
    }
    return 0;
}
