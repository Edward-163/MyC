#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "uthash.h"
#include "securec.h"


/**
堆 大顶堆 最大堆

 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b, *b = tmp;
}
/**
       1
     2   3
    4 5 6 7
    从1开始的好处:规律一眼就能看出来   heap[i]==左or右节点 heap[i>>2]==父节点
 */
void push(int *heap, int *heapSize, int x) {
    heap[++(*heapSize)] = x;
    // 比如,第7个插入的元素最大,那么它会和第3个插入的元素换位置,后续也会和第1个插入的元素换位置,就有点二叉树版"冒泡排序"感觉
    for (int i = (*heapSize); i > 1 && heap[i] > heap[i >> 1]; i >>= 1) {
        swap(&heap[i], &heap[i >> 1]);
    }
}

void pop(int *heap, int *heapSize) {
    /**
     https://blog.csdn.net/xiaomucgwlmx/article/details/103522410
     c这种写法真是看着蛋疼,从右赋值到左,去掉最后一个元素last并放在堆顶,注意构建大堆时候的特性: 父元素绝对>=子元素
     第一层parent空缺,从第二层son选一个候选人,假设选中idx=??,又意味着第二层idx=??的空缺,从第三层他的儿子中选一个候选人...
     最终上面循环不下去的时候会有个结果,idx=???,然后把元素last放在idx=???处
     整个过程就是元素last下沉到合适位置
     */
    int tmp = heap[1] = heap[(*heapSize)--];
    int i = 1, j = 2; // 天杀的官方非要写ij,i==parent,j==son
    while (j <= (*heapSize)) {
        if (j != (*heapSize) && heap[j + 1] > heap[j]) ++j;
        if (heap[j] > tmp) {
            heap[i] = heap[j];
            i = j;
            j = i << 1;
        } else {
            break;
        }
    }
    heap[i] = tmp;
}

int top(int *heap) {
    return heap[1];
}

int lastStoneWeight(int *stones, int stonesSize) {
    if (stonesSize == 1) {
        return stones[0];
    }
    if (stonesSize == 2) {
        return fabs(stones[0] - stones[1]);
    }
    int heap[stonesSize + 2], heapSize = 0;
    for (int i = 0; i < stonesSize; i++) {
        push(heap, &heapSize, stones[i]);
    }

    while (heapSize > 1) {
        int a = top(heap);
        pop(heap, &heapSize);
        int b = top(heap);
        pop(heap, &heapSize);
        if (a > b) {
            push(heap, &heapSize, a - b);
        }
    }
    return heapSize ? top(heap) : 0;
}
int main() {
    // @formatter:off
    int arr[]={2,7,4,1,8,1};
    int asize=sizeof(arr)/sizeof(arr[0]);
    int ans = lastStoneWeight(arr,asize);
    printf("%d \n",ans);fflush(stdout);
    return 0;
    // @formatter:on
}